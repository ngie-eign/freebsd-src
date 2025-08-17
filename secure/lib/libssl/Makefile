.include <src.opts.mk>

LIB=		ssl
SHLIB_MAJOR=	35
VERSION_MAP=	${.CURDIR}/Version.map

NO_LINT=

PCFILES=	libssl.pc openssl.pc

.include "../libcrypto/Makefile.inc"

# crypto
SRCS+= ctype.c
SRCS+= getenv.c
SRCS+= packet.c
SRCS+= quic_vlint.c
SRCS+= time.c

# crypto/hashtable
SRCS+= hashfunc.c

# crypto/siphash
SRCS+= siphash.c

# crypto/thread
SRCS+= arch.c

# crypto/thread/arch
SRCS+= thread_none.c
SRCS+= thread_posix.c
SRCS+= thread_win.c

# ssl
SRCS+= bio_ssl.c
SRCS+= d1_lib.c
SRCS+= d1_msg.c
SRCS+= d1_srtp.c
SRCS+= methods.c
SRCS+= pqueue.c
SRCS+= priority_queue.c
SRCS+= s3_enc.c
SRCS+= s3_lib.c
SRCS+= s3_msg.c
SRCS+= ssl_asn1.c
SRCS+= ssl_cert.c
SRCS+= ssl_cert_comp.c
SRCS+= ssl_ciph.c
SRCS+= ssl_conf.c
SRCS+= ssl_err_legacy.c
SRCS+= ssl_init.c
SRCS+= ssl_lib.c
SRCS+= ssl_mcnf.c
SRCS+= ssl_rsa.c
SRCS+= ssl_rsa_legacy.c
SRCS+= ssl_sess.c
SRCS+= ssl_stat.c
SRCS+= ssl_txt.c
SRCS+= ssl_utst.c
SRCS+= t1_enc.c
SRCS+= t1_lib.c
SRCS+= t1_trce.c
SRCS+= tls13_enc.c
SRCS+= tls_depr.c
SRCS+= tls_srp.c

# ssl/quic
SRCS+= cc_newreno.c
SRCS+= json_enc.c
SRCS+= qlog.c
SRCS+= qlog_event_helpers.c
SRCS+= quic_ackm.c
SRCS+= quic_cfq.c
SRCS+= quic_channel.c
SRCS+= quic_demux.c
SRCS+= quic_engine.c
SRCS+= quic_fc.c
SRCS+= quic_fifd.c
SRCS+= quic_impl.c
SRCS+= quic_lcidm.c
SRCS+= quic_method.c
SRCS+= quic_obj.c
SRCS+= quic_port.c
SRCS+= quic_rcidm.c
SRCS+= quic_reactor.c
SRCS+= quic_reactor_wait_ctx.c
SRCS+= quic_record_rx.c
SRCS+= quic_record_shared.c
SRCS+= quic_record_tx.c
SRCS+= quic_record_util.c
SRCS+= quic_rstream.c
SRCS+= quic_rx_depack.c
SRCS+= quic_sf_list.c
SRCS+= quic_srt_gen.c
SRCS+= quic_srtm.c
SRCS+= quic_sstream.c
SRCS+= quic_statm.c
SRCS+= quic_stream_map.c
SRCS+= quic_thread_assist.c
SRCS+= quic_tls.c
SRCS+= quic_tls_api.c
SRCS+= quic_trace.c
SRCS+= quic_tserver.c
SRCS+= quic_txp.c
SRCS+= quic_txpim.c
SRCS+= quic_types.c
SRCS+= quic_wire.c
SRCS+= quic_wire_pkt.c
SRCS+= uint_set.c

# ssl/record
SRCS+= rec_layer_d1.c
SRCS+= rec_layer_s3.c

# ssl/record/methods
SRCS+= dtls_meth.c
SRCS+= ssl3_cbc.c
SRCS+= ssl3_meth.c
SRCS+= tls13_meth.c
SRCS+= tls1_meth.c
SRCS+= tls_common.c
SRCS+= tls_multib.c
SRCS+= tls_pad.c
SRCS+= tlsany_meth.c

# ssl/rio
SRCS+= poll_builder.c
SRCS+= poll_immediate.c
SRCS+= rio_notifier.c

# ssl/statem
SRCS+= extensions.c
SRCS+= extensions_clnt.c
SRCS+= extensions_cust.c
SRCS+= extensions_srvr.c
SRCS+= statem.c
SRCS+= statem_clnt.c
SRCS+= statem_dtls.c
SRCS+= statem_lib.c
SRCS+= statem_srvr.c

.if ${MK_OPENSSL_KTLS} == "no" || defined(BOOTSTRAPPING)
CFLAGS+=-DOPENSSL_NO_KTLS
.else
SRCS+=	ktls_meth.c
.endif

LIBADD=		pthread crypto

CFLAGS+=	-I${LCRYPTO_SRC}/ssl
CFLAGS+=	-I${.OBJDIR:H}/libcrypto

.include <bsd.lib.mk>

PICFLAG+=	-DOPENSSL_PIC

.PATH:	${LCRYPTO_SRC}/crypto \
	${LCRYPTO_SRC}/crypto/hashtable \
	${LCRYPTO_SRC}/crypto/siphash \
	${LCRYPTO_SRC}/crypto/thread \
	${LCRYPTO_SRC}/crypto/thread/arch \
	${LCRYPTO_SRC}/ssl \
	${LCRYPTO_SRC}/ssl/quic \
	${LCRYPTO_SRC}/ssl/record \
	${LCRYPTO_SRC}/ssl/record/methods \
	${LCRYPTO_SRC}/ssl/rio \
	${LCRYPTO_SRC}/ssl/statem \
