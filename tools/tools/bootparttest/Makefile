# $FreeBSD$

.PATH:		${SRCTOP}/stand/common ${SRCTOP}/stand/libsa

BINDIR?=	/usr/bin

PROG=		bootparttest
MAN=

SRCS=		bootparttest.c crc32.c stub.c part.c disk.c

CFLAGS=		-I${SRCTOP}/stand/common -I${SRCTOP}/stand/libsa \
		-DLOADER_GPT_SUPPORT -DLOADER_MBR_SUPPORT -DPART_DEBUG \
		-DDISK_DEBUG

LIBADD+=	geom

.include <bsd.prog.mk>
