SHLIB_NAME?=	legacy.so
LIBADD=		crypto

# crypto
SRCS+= cpuid.c
SRCS+= ctype.c
SRCS+= params_idx.c

# crypto/des
SRCS+= des_enc.c
SRCS+= fcrypt_b.c

# crypto/md5
SRCS+= md5_dgst.c
SRCS+= md5_one.c
SRCS+= md5_sha1.c

# providers
SRCS+= legacyprov.c
SRCS+= prov_running.c

# providers/common
SRCS+= provider_ctx.c
SRCS+= provider_err.c
SRCS+= provider_util.c

# providers/implementations/ciphers
SRCS+= cipher_blowfish.c
SRCS+= cipher_blowfish_hw.c
SRCS+= cipher_cast5.c
SRCS+= cipher_cast5_hw.c
SRCS+= cipher_des.c
SRCS+= cipher_des_hw.c
SRCS+= cipher_desx.c
SRCS+= cipher_desx_hw.c
SRCS+= cipher_rc2.c
SRCS+= cipher_rc2_hw.c
SRCS+= cipher_rc4.c
SRCS+= cipher_rc4_hmac_md5.c
SRCS+= cipher_rc4_hmac_md5_hw.c
SRCS+= cipher_rc4_hw.c
SRCS+= cipher_seed.c
SRCS+= cipher_seed_hw.c
SRCS+= cipher_tdes_common.c
SRCS+= ciphercommon.c
SRCS+= ciphercommon_block.c
SRCS+= ciphercommon_ccm.c
SRCS+= ciphercommon_ccm_hw.c
SRCS+= ciphercommon_gcm.c
SRCS+= ciphercommon_gcm_hw.c
SRCS+= ciphercommon_hw.c

# providers/implementations/digests
SRCS+= digestcommon.c
SRCS+= md4_prov.c
SRCS+= ripemd_prov.c
SRCS+= wp_prov.c

# providers/implementations/kdfs
SRCS+= pbkdf1.c
SRCS+= pvkkdf.c

# ssl/record/methods
SRCS+= tls_pad.c

.include <bsd.lib.mk>

.PATH:	${LCRYPTO_SRC}/crypto \
	${LCRYPTO_SRC}/crypto/des \
	${LCRYPTO_SRC}/crypto/md5 \
	${LCRYPTO_SRC}/providers \
	${LCRYPTO_SRC}/providers/common \
	${LCRYPTO_SRC}/providers/common/der \
	${LCRYPTO_SRC}/providers/implementations/ciphers \
	${LCRYPTO_SRC}/providers/implementations/digests \
	${LCRYPTO_SRC}/providers/implementations/kdfs \
	${LCRYPTO_SRC}/ssl/record/methods \
