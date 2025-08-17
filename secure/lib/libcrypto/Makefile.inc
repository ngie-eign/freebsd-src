.include <bsd.own.mk>

PACKAGE=	openssl
LIB_PACKAGE=

# OpenSSL version used for manual page generation
.include "Makefile.version"

LCRYPTO_SRC=	${SRCTOP}/crypto/openssl
LCRYPTO_DOC=	${LCRYPTO_SRC}/doc

CFLAGS+=	-I${LCRYPTO_SRC}
CFLAGS+=	-I${LCRYPTO_SRC}/include
CFLAGS+=	-I${LCRYPTO_SRC}/providers/common/include
CFLAGS+=	-I${LCRYPTO_SRC}/providers/fips/include
CFLAGS+=	-I${LCRYPTO_SRC}/providers/implementations/include

.SUFFIXES: .pc
.PATH.pc: ${LCRYPTO_SRC}

.include "Makefile.common"
