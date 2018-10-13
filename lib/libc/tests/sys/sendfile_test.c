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

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <atf-c.h>

/* XXX: remove these hardcoded values. */
#define	XXX_TEST_DOMAIN	AF_INET
#define	XXX_TEST_PORT	36000

static void
resolve_address(struct addrinfo **res0, int domain, int type, int port)
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

	error = getaddrinfo("localhost", serv, &hints, res0);
	free(serv);
	ATF_REQUIRE_EQ_MSG(error, 0,
	    "getaddrinfo failed: %s", gai_strerror(errno));
}

static int
make_socket(int domain, int type)
{
	int sock;

	sock = socket(domain, type, 0);
	ATF_REQUIRE_MSG(sock != -1, "socket(%d, %d, 0) failed: %s",
	    domain, type, strerror(errno));

	return (sock);
}

static int
make_socket_from_res(struct addrinfo *res0, struct addrinfo *res)
{

	for (res = res0; res != NULL; res = res->ai_next) {
		return (make_socket(res->ai_family, res->ai_socktype));
	}
	freeaddrinfo(res0);
	atf_tc_fail("failed to resolve address");
}

static int
setup_client(int domain, int type, int port)
{
	struct addrinfo *res0, *res;
	int error, sock;

	resolve_address(&res0, domain, type, port);
	sock = make_socket_from_res(res0, res);
	error = connect(sock, (struct sockaddr*)res->ai_addr, res->ai_addrlen);
	freeaddrinfo(res0);
	ATF_REQUIRE_EQ_MSG(error, 0, "connect failed: %s", strerror(errno));

	return (sock);
}

static int
setup_server(int domain, int type, int port)
{
	struct addrinfo *res0, *res;
	int error, sock;

	resolve_address(&res0, domain, type, port);
	sock = make_socket_from_res(res0, res);
	error = bind(sock, res->ai_addr, res->ai_addrlen);
	freeaddrinfo(res0);
	ATF_REQUIRE_EQ_MSG(error, 0, "bind failed: %s", strerror(errno));
	error = listen(sock, 1);
	ATF_REQUIRE_EQ_MSG(error, 0, "listen failed: %s", strerror(errno));

	return (sock);
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

ATF_TC(fd_positive_file);
ATF_TC_HEAD(fd_positive_file, tc)
{

	atf_tc_set_md_var(tc, "descr", "Positive file testcase");
}

ATF_TC_BODY(fd_positive_file, tc)
{
	int client_sock, fd, server_sock;
	char template[] = "tmp.XXXXXXXX";

	fd = mkstemp(template);
	ATF_REQUIRE_MSG(fd != -1, "mkstemp failed: %s", strerror(errno));

	server_sock = setup_tcp_server(XXX_TEST_DOMAIN, XXX_TEST_PORT);
	client_sock = setup_tcp_client(XXX_TEST_DOMAIN, XXX_TEST_PORT);

	(void)close(client_sock);
	(void)close(server_sock);
	(void)close(fd);
}

ATF_TC(fd_positive_shm);
ATF_TC_HEAD(fd_positive_shm, tc)
{

	atf_tc_set_md_var(tc, "descr", "Positive shared memory testcase");
}

ATF_TC_BODY(fd_positive_shm, tc)
{
	int client_sock, fd, server_sock;

	fd = shm_open(SHM_ANON, O_RDWR|O_CREAT, 0600);
	ATF_REQUIRE_MSG(fd != -1, "shm_open failed: %s", strerror(errno));

	server_sock = setup_tcp_server(XXX_TEST_DOMAIN, XXX_TEST_PORT);
	client_sock = setup_tcp_client(XXX_TEST_DOMAIN, XXX_TEST_PORT);

	(void)close(client_sock);
	(void)close(server_sock);
	(void)close(fd);
}

ATF_TC(fd_negative_bad_fd);
ATF_TC_HEAD(fd_negative_bad_fd, tc)
{

	atf_tc_set_md_var(tc, "descr", "Positive shared memory testcase");
}

ATF_TC_BODY(fd_negative_bad_fd, tc)
{
	int client_sock, error, fd, server_sock;

	server_sock = setup_tcp_server(XXX_TEST_DOMAIN, XXX_TEST_PORT);
	client_sock = setup_tcp_client(XXX_TEST_DOMAIN, XXX_TEST_PORT);

	fd = -1;

	error = sendfile(fd, client_sock, 0, 0, NULL, NULL, SF_FLAGS(0, 0));
	ATF_REQUIRE_EQ_MSG(error, -1, "sendfile did not fail as expected");
	ATF_REQUIRE_EQ_MSG(errno, EBADF,
	    "sendfile didn't fail with errno=EBADF; failed with errno=%d",
	    errno);

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
