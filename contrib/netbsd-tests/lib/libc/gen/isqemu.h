/*	$NetBSD: isqemu.h,v 1.6 2021/12/15 09:19:28 gson Exp $	*/

/*-
 * Copyright (c) 2013 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Christos Zoulas.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <sys/param.h>
#include <sys/sysctl.h>
#ifndef	__FreeBSD__
#include <sys/drvctlio.h>
#endif
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <err.h>
#include <unistd.h>

static __inline bool
isQEMU(void) {
#ifdef __FreeBSD__
	char *vm_guest_name_buf;
	size_t len;
	bool is_vm;

	if (sysctlbyname("kern.vm_guest", NULL, &len, NULL, 0) == -1)
		err(EXIT_FAILURE, "sysctl");

	if ((vm_guest_name_buf = malloc(len)) == NULL)
		err(EXIT_FAILURE, "malloc");

	if (sysctlbyname("kern.vm_guest", vm_guest_name_buf, &len, NULL, 0)
	    == -1)
		err(EXIT_FAILURE, "sysctl");

	is_vm = strcmp(vm_guest_name_buf, "none") == 0;
	free(vm_guest_name_buf);

	return is_vm;
#else
       struct devlistargs dla = {
	       .l_devname = "qemufwcfg0",
	       .l_childname = NULL,
	       .l_children = 0,
       };
       int fd = open(DRVCTLDEV, O_RDONLY, 0);
       if (fd == -1)
	       return false;
       if (ioctl(fd, DRVLISTDEV, &dla) == -1) {
	       close(fd);
	       return false;
       }
       close(fd);
       return true;
#endif
}

static __inline bool
isQEMU_TCG(void) {
#if (defined(__NetBSD__) && \
    (defined(__i386__) || defined(__x86_64__)))
	char name[1024];
	size_t len = sizeof(name);

	if (sysctlbyname("machdep.cpu_brand", name, &len, NULL, 0) == -1) {
		if (errno == ENOENT)
			return false;
		err(EXIT_FAILURE, "sysctl");
	}
	if (strstr(name, "QEMU") == NULL)
		return false;
	if (sysctlbyname("machdep.hypervisor", name, &len, NULL, 0) == -1) {
		if (errno == ENOENT)
			return true;
		err(EXIT_FAILURE, "sysctl");
	}
	if (strcmp(name, "KVM") == 0)
		return false;
	return true;
#else
	return false;
#endif
}

#ifdef TEST
int
main(void) {
	return isQEMU();
}
#endif
