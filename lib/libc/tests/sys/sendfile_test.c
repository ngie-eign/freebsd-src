/*-
 * Copyright (c) 2018 Enji Cooper.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <atf-c.h>

const char DETERMINISTIC_PATTERN[] =
    "The past is already gone, the future is not yet here. There's only one moment for you to live.\n";

#define	SOURCE_FILE		"source"
#define	DESTINATION_FILE	"dest"

/* XXX: remove these hardcoded values. */
#define	XXX_TEST_DOMAIN	AF_INET
#define	XXX_TEST_PORT_BASE	20000

static void
resolve_localhost(struct addrinfo **res, int domain, int type, int port)
{
	char *serv;
	struct addrinfo hints;
	int error;

	ATF_REQUIRE_MSG(domain == AF_INET || domain == AF_INET6,
	    "unhandled domain: %d", domain);

	ATF_REQUIRE_MSG(asprintf(&serv, "%d", port) >= 0,
	    "asprintf failed: %s", strerror(errno));

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = domain;
	hints.ai_flags = AI_ADDRCONFIG|AI_NUMERICSERV;
	hints.ai_socktype = type;

	error = getaddrinfo("localhost", serv, &hints, res);
	ATF_REQUIRE_EQ_MSG(error, 0,
	    "getaddrinfo failed: %s", gai_strerror(errno));
	free(serv);
}

static int
make_socket(int domain, int type, int protocol)
{
	int sock;

	sock = socket(domain, type, protocol);
	ATF_REQUIRE_MSG(sock != -1, "socket(%d, %d, 0) failed: %s",
	    domain, type, strerror(errno));

	return (sock);
}

static int
setup_client(int domain, int type, int port)
{
	struct addrinfo *res;
	char host[NI_MAXHOST+1];
	int error, sock;

	resolve_localhost(&res, domain, type, port);
	error = getnameinfo(
	    (const struct sockaddr*)res->ai_addr, res->ai_addrlen,
	    host, nitems(host) - 1, NULL, 0, NI_NUMERICHOST);
	ATF_REQUIRE_EQ_MSG(error, 0,
	    "getnameinfo failed: %s", gai_strerror(error));
	printf(
	    "Will try to connect to host='%s', address_family=%d, "
	    "socket_type=%d\n",
	    host, res->ai_family, res->ai_socktype);
	sock = make_socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	error = connect(sock, (struct sockaddr*)res->ai_addr, res->ai_addrlen);
	freeaddrinfo(res);
	ATF_REQUIRE_EQ_MSG(error, 0, "connect failed: %s", strerror(errno));
	return (sock);
}

/*
 * XXX: use linear probing to find a free port and eliminate `port` argument as
 * a [const] int (it will need to be a pointer so it can be passed back out of
 * the function and can influence which port `setup_client(..)` connects on.
 */
static int
setup_server(int domain, int type, int port)
{
	struct addrinfo *res;
	char host[NI_MAXHOST+1];
	int error, sock;

	resolve_localhost(&res, domain, type, port);
	sock = make_socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	error = getnameinfo(
	    (const struct sockaddr*)res->ai_addr, res->ai_addrlen,
	    host, nitems(host) - 1, NULL, 0, NI_NUMERICHOST);
	ATF_REQUIRE_EQ_MSG(error, 0,
	    "getnameinfo failed: %s", gai_strerror(error));
	printf(
	    "Will try to bind socket to host='%s', address_family=%d, "
	    "socket_type=%d\n",
	    host, res->ai_family, res->ai_socktype);
	error = bind(sock, res->ai_addr, res->ai_addrlen);
	freeaddrinfo(res);
	ATF_REQUIRE_EQ_MSG(error, 0, "bind failed: %s", strerror(errno));
	error = listen(sock, 1);
	ATF_REQUIRE_EQ_MSG(error, 0, "listen failed: %s", strerror(errno));

	return (sock);
}

static void
server_cat(const char *dest_filename, int server_sock, size_t len)
{
	void *buffer;
	int recv_sock;
	ssize_t received_bytes;

	buffer = calloc(len + 1, sizeof(char));
	if (buffer == NULL)
		err(1, "malloc failed");

	recv_sock = accept(server_sock, NULL, 0);
	if (recv_sock == -1)
		err(1, "accept failed");

	/*
	 * XXX: this assumes the simplest case where all data is received in a
	 * single recv(2) call.
	 */
	if (recv(recv_sock, buffer, len, 0) == -1)
		err(1, "recv failed");

	atf_utils_create_file(dest_filename, "%s", buffer);

	received_bytes = recv(recv_sock, buffer, len, 0);
	switch (received_bytes) {
	case -1:
		err(1, "recv failed");
	case 0:
		break;
	default:
		errx(1, "received unexpected data: %s", buffer);
	}

	(void)close(recv_sock);
	(void)close(server_sock);
	free(buffer);

	_exit(0);
}

static int
setup_tcp_server(int domain, int port)
{

	return (setup_server(domain, SOCK_STREAM, port));
}

static int
setup_tcp_client(int domain, int port)
{

	return (setup_client(domain, SOCK_STREAM, port));
}

static off_t
file_size_from_fd(int fd)
{
	struct stat st;

	ATF_REQUIRE_EQ_MSG(0, fstat(fd, &st),
	    "fstat failed: %s", strerror(errno));

	return (st.st_size);
}

static void
verify_source_and_dest(const char* dest_filename, int src_fd, off_t offset,
    size_t nbytes)
{
	void *dest_pointer, *src_pointer;
	off_t dest_file_size, src_file_size;
	size_t length;
	int dest_fd;

	printf("=== DEST FILE ===\n");
	atf_utils_cat_file(dest_filename, "dest_file: ");
	printf("=== DEST FILE ===\n");

	dest_fd = open(dest_filename, O_RDONLY);
	ATF_REQUIRE_MSG(dest_fd != -1, "open failed");

	dest_file_size = file_size_from_fd(dest_fd);
	src_file_size = file_size_from_fd(src_fd);

	/*
	 * Per sendfile(2), "send the whole file" (paraphrased). This means
	 * that we need to grab the file size, as passing in length = 0 with
	 * mmap(2) will result in a failure with EINVAL (length = 0 is invalid).
	 */
	length = (nbytes == 0) ? (size_t)(src_file_size - offset) : nbytes;

	ATF_REQUIRE_EQ_MSG(dest_file_size, length,
	    "number of bytes written out to %s (%ju) doesn't match the "
	    "expected number of bytes (%ju)", dest_filename, dest_file_size,
	    length);

	ATF_REQUIRE_EQ_MSG(0, lseek(src_fd, offset, SEEK_SET),
	    "lseek failed: %s", strerror(errno));

	printf("Will mmap in the destination (%s) and source files from "
	    "offset=%jd to length=%zu\n", dest_filename, offset, length);

	dest_pointer = mmap(NULL, length, PROT_READ, MAP_PRIVATE, dest_fd, offset);
	ATF_REQUIRE_MSG(dest_pointer != MAP_FAILED, "mmap failed: %s",
	    strerror(errno));

	src_pointer = mmap(NULL, length, PROT_READ, MAP_PRIVATE, src_fd, offset);
	ATF_REQUIRE_MSG(src_pointer != MAP_FAILED, "mmap failed: %s",
	    strerror(errno));

	ATF_REQUIRE_EQ_MSG(0, memcmp(src_pointer, dest_pointer, length),
	    "Contents of source and destination do not match. '%s' != '%s'",
	    src_pointer, dest_pointer);

	(void)munmap(dest_pointer, length);
	(void)munmap(src_pointer, length);
}

ATF_TC(fd_positive_file);
ATF_TC_HEAD(fd_positive_file, tc)
{

	atf_tc_set_md_var(tc, "descr", "Positive file testcase");
}

ATF_TC_BODY(fd_positive_file, tc)
{
	off_t offset;
	size_t nbytes, pattern_size;
	int client_sock, error, fd, port, server_sock;
	pid_t server_pid;

	pattern_size = strlen(DETERMINISTIC_PATTERN);

	atf_utils_create_file(SOURCE_FILE, "%s", DETERMINISTIC_PATTERN);
	fd = open(SOURCE_FILE, O_RDONLY);
	ATF_REQUIRE_MSG(fd != -1, "open failed: %s", strerror(errno));

	port = XXX_TEST_PORT_BASE + __LINE__;
	server_sock = setup_tcp_server(XXX_TEST_DOMAIN, port);
	client_sock = setup_tcp_client(XXX_TEST_DOMAIN, port);

	server_pid = atf_utils_fork();
	if (server_pid == 0) {
		(void)close(client_sock);
		server_cat(DESTINATION_FILE, server_sock, pattern_size);
	} else
		(void)close(server_sock);

	nbytes = 0;
	offset = 0;
	error = sendfile(fd, client_sock, offset, nbytes, NULL, NULL,
	    SF_FLAGS(0, 0));
	ATF_REQUIRE_EQ_MSG(0, error, "sendfile failed: %s", strerror(errno));
	(void)close(client_sock);

	atf_utils_wait(server_pid, 0, "", "");
	verify_source_and_dest(DESTINATION_FILE, fd, offset, nbytes);

	(void)close(fd);
}

ATF_TC(fd_positive_shm);
ATF_TC_HEAD(fd_positive_shm, tc)
{

	atf_tc_set_md_var(tc, "descr", "Positive shared memory testcase");
}

ATF_TC_BODY(fd_positive_shm, tc)
{
	void *shm_pointer;
	off_t offset;
	size_t nbytes, pattern_size;
	pid_t server_pid;
	int client_sock, error, fd, port, server_sock;

	pattern_size = strlen(DETERMINISTIC_PATTERN);

	printf("pattern size: %zu\n", pattern_size);

	fd = shm_open(SHM_ANON, O_RDWR|O_CREAT, 0600);
	ATF_REQUIRE_MSG(fd != -1, "shm_open failed: %s", strerror(errno));
	ATF_REQUIRE_EQ_MSG(0, ftruncate(fd, pattern_size),
	    "ftruncate failed: %s", strerror(errno));
	shm_pointer = mmap(NULL, pattern_size, PROT_READ|PROT_WRITE,
	    MAP_SHARED, fd, 0);
	ATF_REQUIRE_MSG(shm_pointer != MAP_FAILED,
	    "mmap failed: %s", strerror(errno));
	memcpy(shm_pointer, DETERMINISTIC_PATTERN, pattern_size);
	ATF_REQUIRE_EQ_MSG(0, lseek(fd, 0, SEEK_SET),
	    "lseek failed: %s", strerror(errno));
	ATF_REQUIRE_EQ_MSG(0,
	    memcmp(shm_pointer, DETERMINISTIC_PATTERN, pattern_size),
	    "memcmp showed data mismatch: '%s' != '%s'",
	    DETERMINISTIC_PATTERN, shm_pointer);

	port = XXX_TEST_PORT_BASE + __LINE__;
	server_sock = setup_tcp_server(XXX_TEST_DOMAIN, port);
	client_sock = setup_tcp_client(XXX_TEST_DOMAIN, port);

	server_pid = atf_utils_fork();
	if (server_pid == 0) {
		(void)close(client_sock);
		server_cat(DESTINATION_FILE, server_sock, pattern_size);
	} else
		(void)close(server_sock);

	nbytes = 0;
	offset = 0;
	error = sendfile(fd, client_sock, offset, nbytes, NULL, NULL,
	    SF_FLAGS(0, 0));
	ATF_REQUIRE_EQ_MSG(0, error, "sendfile failed: %s", strerror(errno));
	(void)close(client_sock);

	atf_utils_wait(server_pid, 0, "", "");
	verify_source_and_dest(DESTINATION_FILE, fd, offset, nbytes);

	(void)munmap(shm_pointer, sizeof(DETERMINISTIC_PATTERN));
	(void)close(fd);
}

ATF_TC(fd_negative_bad_fd);
ATF_TC_HEAD(fd_negative_bad_fd, tc)
{

	atf_tc_set_md_var(tc, "descr", "Positive shared memory testcase");
}

ATF_TC_BODY(fd_negative_bad_fd, tc)
{
	int client_sock, error, fd, port, server_sock;

	port = XXX_TEST_PORT_BASE + __LINE__;
	server_sock = setup_tcp_server(XXX_TEST_DOMAIN, port);
	client_sock = setup_tcp_client(XXX_TEST_DOMAIN, port);

	fd = -1;

	error = sendfile(fd, client_sock, 0, 0, NULL, NULL, SF_FLAGS(0, 0));
	ATF_REQUIRE_ERRNO(EBADF, error == -1);

	(void)close(client_sock);
	(void)close(server_sock);
}

ATF_TP_ADD_TCS(tp)
{

	ATF_TP_ADD_TC(tp, fd_positive_file);
	ATF_TP_ADD_TC(tp, fd_positive_shm);
	ATF_TP_ADD_TC(tp, fd_negative_bad_fd);

	return (atf_no_error());
}
