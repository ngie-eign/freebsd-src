SHLIBDIR?=	/lib
.if !defined(LIBCRYPTO_WITHOUT_SUBDIRS) && !defined(BOOTSTRAPPING)
SUBDIR=		engines modules
.endif
.ifdef BOOTSTRAPPING
CFLAGS+=	-DOPENSSL_NO_SCTP
.endif

.include <bsd.own.mk>
.include <src.opts.mk>

LIB=		crypto
SHLIB_MAJOR=	35
VERSION_MAP=	${.CURDIR}/Version.map

NO_LINT=
PCFILES=	libcrypto.pc

.include "Makefile.man"
.include "Makefile.inc"

# crypto
SRCS+= asn1_dsa.c
SRCS+= bsearch.c
SRCS+= comp_methods.c
SRCS+= context.c
SRCS+= core_algorithm.c
SRCS+= core_fetch.c
SRCS+= core_namemap.c
SRCS+= cpt_err.c
SRCS+= cpuid.c
SRCS+= cryptlib.c
SRCS+= ctype.c
SRCS+= cversion.c
SRCS+= defaults.c
SRCS+= der_writer.c
SRCS+= deterministic_nonce.c
SRCS+= ebcdic.c
SRCS+= ex_data.c
SRCS+= getenv.c
SRCS+= indicator_core.c
SRCS+= info.c
SRCS+= init.c
SRCS+= initthread.c
SRCS+= mem.c
SRCS+= mem_sec.c
SRCS+= o_dir.c
SRCS+= o_fopen.c
SRCS+= o_init.c
SRCS+= o_str.c
SRCS+= o_time.c
SRCS+= packet.c
SRCS+= param_build.c
SRCS+= param_build_set.c
SRCS+= params.c
SRCS+= params_dup.c
SRCS+= params_from_text.c
SRCS+= params_idx.c
SRCS+= passphrase.c
SRCS+= provider.c
SRCS+= provider_child.c
SRCS+= provider_conf.c
SRCS+= provider_core.c
SRCS+= provider_predefined.c
SRCS+= punycode.c
SRCS+= quic_vlint.c
SRCS+= self_test_core.c
SRCS+= sleep.c
SRCS+= sparse_array.c
SRCS+= ssl_err.c
SRCS+= threads_lib.c
SRCS+= threads_none.c
SRCS+= threads_pthread.c
SRCS+= threads_win.c
SRCS+= time.c
SRCS+= trace.c
SRCS+= uid.c

# crypto/aes
SRCS+= aes_cfb.c
SRCS+= aes_ecb.c
SRCS+= aes_ige.c
SRCS+= aes_misc.c
SRCS+= aes_ofb.c
SRCS+= aes_wrap.c

# crypto/asn1
SRCS+= a_bitstr.c
SRCS+= a_d2i_fp.c
SRCS+= a_digest.c
SRCS+= a_dup.c
SRCS+= a_gentm.c
SRCS+= a_i2d_fp.c
SRCS+= a_int.c
SRCS+= a_mbstr.c
SRCS+= a_object.c
SRCS+= a_octet.c
SRCS+= a_print.c
SRCS+= a_sign.c
SRCS+= a_strex.c
SRCS+= a_strnid.c
SRCS+= a_time.c
SRCS+= a_type.c
SRCS+= a_utctm.c
SRCS+= a_utf8.c
SRCS+= a_verify.c
SRCS+= ameth_lib.c
SRCS+= asn1_err.c
SRCS+= asn1_gen.c
SRCS+= asn1_item_list.c
SRCS+= asn1_lib.c
SRCS+= asn1_parse.c
SRCS+= asn_mime.c
SRCS+= asn_moid.c
SRCS+= asn_mstbl.c
SRCS+= asn_pack.c
SRCS+= bio_asn1.c
SRCS+= bio_ndef.c
SRCS+= d2i_param.c
SRCS+= d2i_pr.c
SRCS+= d2i_pu.c
SRCS+= evp_asn1.c
SRCS+= f_int.c
SRCS+= f_string.c
SRCS+= i2d_evp.c
SRCS+= n_pkey.c
SRCS+= nsseq.c
SRCS+= p5_pbe.c
SRCS+= p5_pbev2.c
SRCS+= p5_scrypt.c
SRCS+= p8_pkey.c
SRCS+= t_bitst.c
SRCS+= t_pkey.c
SRCS+= t_spki.c
SRCS+= tasn_dec.c
SRCS+= tasn_enc.c
SRCS+= tasn_fre.c
SRCS+= tasn_new.c
SRCS+= tasn_prn.c
SRCS+= tasn_scn.c
SRCS+= tasn_typ.c
SRCS+= tasn_utl.c
SRCS+= x_algor.c
SRCS+= x_bignum.c
SRCS+= x_info.c
SRCS+= x_int64.c
SRCS+= x_long.c
SRCS+= x_pkey.c
SRCS+= x_sig.c
SRCS+= x_spki.c
SRCS+= x_val.c

# crypto/async
SRCS+= async.c
SRCS+= async_err.c
SRCS+= async_wait.c

# crypto/async/arch
SRCS+= async_null.c
SRCS+= async_posix.c
SRCS+= async_win.c

# crypto/bf
SRCS+= bf_cfb64.c
SRCS+= bf_ecb.c
SRCS+= bf_ofb64.c
SRCS+= bf_skey.c

# crypto/bio
SRCS+= bf_buff.c
SRCS+= bf_lbuf.c
SRCS+= bf_nbio.c
SRCS+= bf_null.c
SRCS+= bf_prefix.c
SRCS+= bf_readbuff.c
SRCS+= bio_addr.c
SRCS+= bio_cb.c
SRCS+= bio_dump.c
SRCS+= bio_err.c
SRCS+= bio_lib.c
SRCS+= bio_meth.c
SRCS+= bio_print.c
SRCS+= bio_sock.c
SRCS+= bio_sock2.c
SRCS+= bss_acpt.c
SRCS+= bss_bio.c
SRCS+= bss_conn.c
SRCS+= bss_core.c
SRCS+= bss_dgram.c
SRCS+= bss_dgram_pair.c
SRCS+= bss_fd.c
SRCS+= bss_file.c
SRCS+= bss_log.c
SRCS+= bss_mem.c
SRCS+= bss_null.c
SRCS+= bss_sock.c
SRCS+= ossl_core_bio.c

# crypto/bn
SRCS+= bn_add.c
SRCS+= bn_blind.c
SRCS+= bn_const.c
SRCS+= bn_conv.c
SRCS+= bn_ctx.c
SRCS+= bn_depr.c
SRCS+= bn_dh.c
SRCS+= bn_div.c
SRCS+= bn_err.c
SRCS+= bn_exp.c
SRCS+= bn_exp2.c
SRCS+= bn_gcd.c
SRCS+= bn_gf2m.c
SRCS+= bn_intern.c
SRCS+= bn_kron.c
SRCS+= bn_lib.c
SRCS+= bn_mod.c
SRCS+= bn_mont.c
SRCS+= bn_mpi.c
SRCS+= bn_mul.c
SRCS+= bn_nist.c
SRCS+= bn_prime.c
SRCS+= bn_print.c
SRCS+= bn_rand.c
SRCS+= bn_recp.c
SRCS+= bn_rsa_fips186_4.c
SRCS+= bn_shift.c
SRCS+= bn_sqr.c
SRCS+= bn_sqrt.c
SRCS+= bn_srp.c
SRCS+= bn_word.c
SRCS+= bn_x931p.c

# crypto/bn/asm

# crypto/buffer
SRCS+= buf_err.c
SRCS+= buffer.c

# crypto/camellia
SRCS+= cmll_cfb.c
SRCS+= cmll_ctr.c
SRCS+= cmll_ecb.c
SRCS+= cmll_ofb.c

# crypto/cast
SRCS+= c_cfb64.c
SRCS+= c_ecb.c
SRCS+= c_enc.c
SRCS+= c_ofb64.c
SRCS+= c_skey.c

# crypto/cmac
SRCS+= cmac.c

# crypto/cmp
SRCS+= cmp_asn.c
SRCS+= cmp_client.c
SRCS+= cmp_ctx.c
SRCS+= cmp_err.c
SRCS+= cmp_genm.c
SRCS+= cmp_hdr.c
SRCS+= cmp_http.c
SRCS+= cmp_msg.c
SRCS+= cmp_protect.c
SRCS+= cmp_server.c
SRCS+= cmp_status.c
SRCS+= cmp_util.c
SRCS+= cmp_vfy.c

# crypto/cms
SRCS+= cms_asn1.c
SRCS+= cms_att.c
SRCS+= cms_cd.c
SRCS+= cms_dd.c
SRCS+= cms_dh.c
SRCS+= cms_ec.c
SRCS+= cms_enc.c
SRCS+= cms_env.c
SRCS+= cms_err.c
SRCS+= cms_ess.c
SRCS+= cms_io.c
SRCS+= cms_kari.c
SRCS+= cms_lib.c
SRCS+= cms_pwri.c
SRCS+= cms_rsa.c
SRCS+= cms_sd.c
SRCS+= cms_smime.c

# crypto/comp
SRCS+= c_brotli.c
SRCS+= c_zlib.c
SRCS+= c_zstd.c
SRCS+= comp_err.c
SRCS+= comp_lib.c

# crypto/conf
SRCS+= conf_api.c
SRCS+= conf_def.c
SRCS+= conf_err.c
SRCS+= conf_lib.c
SRCS+= conf_mall.c
SRCS+= conf_mod.c
SRCS+= conf_sap.c
SRCS+= conf_ssl.c

# crypto/crmf
SRCS+= crmf_asn.c
SRCS+= crmf_err.c
SRCS+= crmf_lib.c
SRCS+= crmf_pbm.c

# crypto/ct
SRCS+= ct_b64.c
SRCS+= ct_err.c
SRCS+= ct_log.c
SRCS+= ct_oct.c
SRCS+= ct_policy.c
SRCS+= ct_prn.c
SRCS+= ct_sct.c
SRCS+= ct_sct_ctx.c
SRCS+= ct_vfy.c
SRCS+= ct_x509v3.c

# crypto/des
SRCS+= cbc_cksm.c
SRCS+= cbc_enc.c
SRCS+= cfb64ede.c
SRCS+= cfb64enc.c
SRCS+= cfb_enc.c
SRCS+= ecb3_enc.c
SRCS+= ecb_enc.c
SRCS+= fcrypt.c
SRCS+= ofb64ede.c
SRCS+= ofb64enc.c
SRCS+= ofb_enc.c
SRCS+= pcbc_enc.c
SRCS+= qud_cksm.c
SRCS+= rand_key.c
SRCS+= set_key.c
SRCS+= str2key.c
SRCS+= xcbc_enc.c

# crypto/dh
SRCS+= dh_ameth.c
SRCS+= dh_asn1.c
SRCS+= dh_backend.c
SRCS+= dh_check.c
SRCS+= dh_depr.c
SRCS+= dh_err.c
SRCS+= dh_gen.c
SRCS+= dh_group_params.c
SRCS+= dh_kdf.c
SRCS+= dh_key.c
SRCS+= dh_lib.c
SRCS+= dh_meth.c
SRCS+= dh_pmeth.c
SRCS+= dh_prn.c
SRCS+= dh_rfc5114.c

# crypto/dsa
SRCS+= dsa_ameth.c
SRCS+= dsa_asn1.c
SRCS+= dsa_backend.c
SRCS+= dsa_check.c
SRCS+= dsa_depr.c
SRCS+= dsa_err.c
SRCS+= dsa_gen.c
SRCS+= dsa_key.c
SRCS+= dsa_lib.c
SRCS+= dsa_meth.c
SRCS+= dsa_ossl.c
SRCS+= dsa_pmeth.c
SRCS+= dsa_prn.c
SRCS+= dsa_sign.c
SRCS+= dsa_vrf.c

# crypto/dso
SRCS+= dso_dl.c
SRCS+= dso_dlfcn.c
SRCS+= dso_err.c
SRCS+= dso_lib.c
SRCS+= dso_openssl.c
SRCS+= dso_vms.c
SRCS+= dso_win32.c

# crypto/ec
SRCS+= curve25519.c
SRCS+= ec2_oct.c
SRCS+= ec2_smpl.c
SRCS+= ec_ameth.c
SRCS+= ec_asn1.c
SRCS+= ec_backend.c
SRCS+= ec_check.c
SRCS+= ec_curve.c
SRCS+= ec_cvt.c
SRCS+= ec_deprecated.c
SRCS+= ec_err.c
SRCS+= ec_key.c
SRCS+= ec_kmeth.c
SRCS+= ec_lib.c
SRCS+= ec_mult.c
SRCS+= ec_oct.c
SRCS+= ec_pmeth.c
SRCS+= ec_print.c
SRCS+= ecdh_kdf.c
SRCS+= ecdh_ossl.c
SRCS+= ecdsa_ossl.c
SRCS+= ecdsa_sign.c
SRCS+= ecdsa_vrf.c
SRCS+= eck_prn.c
SRCS+= ecp_mont.c
SRCS+= ecp_nist.c
SRCS+= ecp_oct.c
SRCS+= ecp_smpl.c
SRCS+= ecx_backend.c
SRCS+= ecx_key.c
SRCS+= ecx_meth.c

# crypto/ec/curve448
SRCS+= curve448.c
SRCS+= curve448_tables.c
SRCS+= eddsa.c
SRCS+= f_generic.c
SRCS+= scalar.c

# crypto/ec/curve448/arch_32
SRCS+= f_impl32.c

# crypto/ec/curve448/arch_64
SRCS+= f_impl64.c

# crypto/encode_decode
SRCS+= decoder_err.c
SRCS+= decoder_lib.c
SRCS+= decoder_meth.c
SRCS+= decoder_pkey.c
SRCS+= encoder_err.c
SRCS+= encoder_lib.c
SRCS+= encoder_meth.c
SRCS+= encoder_pkey.c

# crypto/engine
SRCS+= eng_all.c
SRCS+= eng_cnf.c
SRCS+= eng_ctrl.c
SRCS+= eng_dyn.c
SRCS+= eng_err.c
SRCS+= eng_fat.c
SRCS+= eng_init.c
SRCS+= eng_lib.c
SRCS+= eng_list.c
SRCS+= eng_openssl.c
SRCS+= eng_pkey.c
SRCS+= eng_rdrand.c
SRCS+= eng_table.c
SRCS+= tb_asnmth.c
SRCS+= tb_cipher.c
SRCS+= tb_dh.c
SRCS+= tb_digest.c
SRCS+= tb_dsa.c
SRCS+= tb_eckey.c
SRCS+= tb_pkmeth.c
SRCS+= tb_rand.c
SRCS+= tb_rsa.c

# crypto/err
SRCS+= err.c
SRCS+= err_all.c
SRCS+= err_all_legacy.c
SRCS+= err_blocks.c
SRCS+= err_mark.c
SRCS+= err_prn.c
SRCS+= err_save.c

# crypto/ess
SRCS+= ess_asn1.c
SRCS+= ess_err.c
SRCS+= ess_lib.c

# crypto/evp
SRCS+= asymcipher.c
SRCS+= bio_b64.c
SRCS+= bio_enc.c
SRCS+= bio_md.c
SRCS+= bio_ok.c
SRCS+= c_allc.c
SRCS+= c_alld.c
SRCS+= cmeth_lib.c
SRCS+= ctrl_params_translate.c
SRCS+= dh_ctrl.c
SRCS+= dh_support.c
SRCS+= digest.c
SRCS+= dsa_ctrl.c
SRCS+= e_aes.c
SRCS+= e_aes_cbc_hmac_sha1.c
SRCS+= e_aes_cbc_hmac_sha256.c
SRCS+= e_aria.c
SRCS+= e_bf.c
SRCS+= e_camellia.c
SRCS+= e_cast.c
SRCS+= e_chacha20_poly1305.c
SRCS+= e_des.c
SRCS+= e_des3.c
SRCS+= e_idea.c
SRCS+= e_null.c
SRCS+= e_old.c
SRCS+= e_rc2.c
SRCS+= e_rc4.c
SRCS+= e_rc4_hmac_md5.c
SRCS+= e_rc5.c
SRCS+= e_seed.c
SRCS+= e_sm4.c
SRCS+= e_xcbc_d.c
SRCS+= ec_ctrl.c
SRCS+= ec_support.c
SRCS+= encode.c
SRCS+= evp_cnf.c
SRCS+= evp_enc.c
SRCS+= evp_err.c
SRCS+= evp_fetch.c
SRCS+= evp_key.c
SRCS+= evp_lib.c
SRCS+= evp_pbe.c
SRCS+= evp_pkey.c
SRCS+= evp_rand.c
SRCS+= evp_utils.c
SRCS+= exchange.c
SRCS+= kdf_lib.c
SRCS+= kdf_meth.c
SRCS+= kem.c
SRCS+= keymgmt_lib.c
SRCS+= keymgmt_meth.c
SRCS+= legacy_blake2.c
SRCS+= legacy_md4.c
SRCS+= legacy_md5.c
SRCS+= legacy_md5_sha1.c
SRCS+= legacy_ripemd.c
SRCS+= legacy_sha.c
SRCS+= legacy_wp.c
SRCS+= m_null.c
SRCS+= m_sigver.c
SRCS+= mac_lib.c
SRCS+= mac_meth.c
SRCS+= names.c
SRCS+= p5_crpt.c
SRCS+= p5_crpt2.c
SRCS+= p_dec.c
SRCS+= p_enc.c
SRCS+= p_legacy.c
SRCS+= p_lib.c
SRCS+= p_open.c
SRCS+= p_seal.c
SRCS+= p_sign.c
SRCS+= p_verify.c
SRCS+= pbe_scrypt.c
SRCS+= pmeth_check.c
SRCS+= pmeth_gn.c
SRCS+= pmeth_lib.c
SRCS+= s_lib.c
SRCS+= signature.c
SRCS+= skeymgmt_meth.c

# crypto/ffc
SRCS+= ffc_backend.c
SRCS+= ffc_dh.c
SRCS+= ffc_key_generate.c
SRCS+= ffc_key_validate.c
SRCS+= ffc_params.c
SRCS+= ffc_params_generate.c
SRCS+= ffc_params_validate.c

# crypto/hashtable
SRCS+= hashfunc.c
SRCS+= hashtable.c

# crypto/hmac
SRCS+= hmac.c

# crypto/hpke
SRCS+= hpke.c
SRCS+= hpke_util.c

# crypto/http
SRCS+= http_client.c
SRCS+= http_err.c
SRCS+= http_lib.c

# crypto/kdf
SRCS+= kdf_err.c

# crypto/lhash
SRCS+= lh_stats.c
SRCS+= lhash.c

# crypto/md4
SRCS+= md4_dgst.c
SRCS+= md4_one.c

# crypto/md5
SRCS+= md5_dgst.c
SRCS+= md5_one.c
SRCS+= md5_sha1.c

# crypto/ml_dsa
SRCS+= ml_dsa_encoders.c
SRCS+= ml_dsa_key.c
SRCS+= ml_dsa_key_compress.c
SRCS+= ml_dsa_matrix.c
SRCS+= ml_dsa_ntt.c
SRCS+= ml_dsa_params.c
SRCS+= ml_dsa_sample.c
SRCS+= ml_dsa_sign.c

# crypto/ml_kem
SRCS+= ml_kem.c

# crypto/modes
SRCS+= cbc128.c
SRCS+= ccm128.c
SRCS+= cfb128.c
SRCS+= ctr128.c
SRCS+= cts128.c
SRCS+= gcm128.c
SRCS+= ocb128.c
SRCS+= ofb128.c
SRCS+= siv128.c
SRCS+= wrap128.c
SRCS+= xts128.c
SRCS+= xts128gb.c

# crypto/objects
SRCS+= o_names.c
SRCS+= obj_dat.c
SRCS+= obj_err.c
SRCS+= obj_lib.c
SRCS+= obj_xref.c

# crypto/ocsp
SRCS+= ocsp_asn.c
SRCS+= ocsp_cl.c
SRCS+= ocsp_err.c
SRCS+= ocsp_ext.c
SRCS+= ocsp_http.c
SRCS+= ocsp_lib.c
SRCS+= ocsp_prn.c
SRCS+= ocsp_srv.c
SRCS+= ocsp_vfy.c
SRCS+= v3_ocsp.c

# crypto/pem
SRCS+= pem_all.c
SRCS+= pem_err.c
SRCS+= pem_info.c
SRCS+= pem_lib.c
SRCS+= pem_oth.c
SRCS+= pem_pk8.c
SRCS+= pem_pkey.c
SRCS+= pem_sign.c
SRCS+= pem_x509.c
SRCS+= pem_xaux.c
SRCS+= pvkfmt.c

# crypto/pkcs12
SRCS+= p12_add.c
SRCS+= p12_asn.c
SRCS+= p12_attr.c
SRCS+= p12_crpt.c
SRCS+= p12_crt.c
SRCS+= p12_decr.c
SRCS+= p12_init.c
SRCS+= p12_key.c
SRCS+= p12_kiss.c
SRCS+= p12_mutl.c
SRCS+= p12_npas.c
SRCS+= p12_p8d.c
SRCS+= p12_p8e.c
SRCS+= p12_sbag.c
SRCS+= p12_utl.c
SRCS+= pk12err.c

# crypto/pkcs7
SRCS+= bio_pk7.c
SRCS+= pk7_asn1.c
SRCS+= pk7_attr.c
SRCS+= pk7_doit.c
SRCS+= pk7_lib.c
SRCS+= pk7_mime.c
SRCS+= pk7_smime.c
SRCS+= pkcs7err.c

# crypto/poly1305
SRCS+= poly1305.c

# crypto/property
SRCS+= defn_cache.c
SRCS+= property.c
SRCS+= property_err.c
SRCS+= property_parse.c
SRCS+= property_query.c
SRCS+= property_string.c

# crypto/rand
SRCS+= prov_seed.c
SRCS+= rand_deprecated.c
SRCS+= rand_err.c
SRCS+= rand_lib.c
SRCS+= rand_meth.c
SRCS+= rand_pool.c
SRCS+= rand_uniform.c
SRCS+= randfile.c

# crypto/rc2
SRCS+= rc2_cbc.c
SRCS+= rc2_ecb.c
SRCS+= rc2_skey.c
SRCS+= rc2cfb64.c
SRCS+= rc2ofb64.c

# crypto/ripemd
SRCS+= rmd_dgst.c
SRCS+= rmd_one.c

# crypto/rsa
SRCS+= rsa_ameth.c
SRCS+= rsa_asn1.c
SRCS+= rsa_backend.c
SRCS+= rsa_chk.c
SRCS+= rsa_crpt.c
SRCS+= rsa_depr.c
SRCS+= rsa_err.c
SRCS+= rsa_gen.c
SRCS+= rsa_lib.c
SRCS+= rsa_meth.c
SRCS+= rsa_mp.c
SRCS+= rsa_mp_names.c
SRCS+= rsa_none.c
SRCS+= rsa_oaep.c
SRCS+= rsa_ossl.c
SRCS+= rsa_pk1.c
SRCS+= rsa_pmeth.c
SRCS+= rsa_prn.c
SRCS+= rsa_pss.c
SRCS+= rsa_saos.c
SRCS+= rsa_schemes.c
SRCS+= rsa_sign.c
SRCS+= rsa_sp800_56b_check.c
SRCS+= rsa_sp800_56b_gen.c
SRCS+= rsa_x931.c
SRCS+= rsa_x931g.c

# crypto/seed
SRCS+= seed.c
SRCS+= seed_cbc.c
SRCS+= seed_cfb.c
SRCS+= seed_ecb.c
SRCS+= seed_ofb.c

# crypto/sha
SRCS+= sha1_one.c
SRCS+= sha1dgst.c
SRCS+= sha256.c
SRCS+= sha3.c
SRCS+= sha512.c

# crypto/siphash
SRCS+= siphash.c

# crypto/slh_dsa
SRCS+= slh_adrs.c
SRCS+= slh_dsa.c
SRCS+= slh_dsa_hash_ctx.c
SRCS+= slh_dsa_key.c
SRCS+= slh_fors.c
SRCS+= slh_hash.c
SRCS+= slh_hypertree.c
SRCS+= slh_params.c
SRCS+= slh_wots.c
SRCS+= slh_xmss.c

# crypto/srp
SRCS+= srp_lib.c
SRCS+= srp_vfy.c

# crypto/stack
SRCS+= stack.c

# crypto/store
SRCS+= store_err.c
SRCS+= store_init.c
SRCS+= store_lib.c
SRCS+= store_meth.c
SRCS+= store_register.c
SRCS+= store_result.c
SRCS+= store_strings.c

# crypto/thread
SRCS+= api.c
SRCS+= arch.c
SRCS+= internal.c

# crypto/thread/arch
SRCS+= thread_none.c
SRCS+= thread_posix.c
SRCS+= thread_win.c

# crypto/ts
SRCS+= ts_asn1.c
SRCS+= ts_conf.c
SRCS+= ts_err.c
SRCS+= ts_lib.c
SRCS+= ts_req_print.c
SRCS+= ts_req_utils.c
SRCS+= ts_rsp_print.c
SRCS+= ts_rsp_sign.c
SRCS+= ts_rsp_utils.c
SRCS+= ts_rsp_verify.c
SRCS+= ts_verify_ctx.c

# crypto/txt_db
SRCS+= txt_db.c

# crypto/ui
SRCS+= ui_err.c
SRCS+= ui_lib.c
SRCS+= ui_null.c
SRCS+= ui_openssl.c
SRCS+= ui_util.c

# crypto/whrlpool
SRCS+= wp_dgst.c

# crypto/x509
SRCS+= by_dir.c
SRCS+= by_file.c
SRCS+= by_store.c
SRCS+= pcy_cache.c
SRCS+= pcy_data.c
SRCS+= pcy_lib.c
SRCS+= pcy_map.c
SRCS+= pcy_node.c
SRCS+= pcy_tree.c
SRCS+= t_acert.c
SRCS+= t_crl.c
SRCS+= t_req.c
SRCS+= t_x509.c
SRCS+= v3_aaa.c
SRCS+= v3_ac_tgt.c
SRCS+= v3_addr.c
SRCS+= v3_admis.c
SRCS+= v3_akeya.c
SRCS+= v3_akid.c
SRCS+= v3_asid.c
SRCS+= v3_attrdesc.c
SRCS+= v3_attrmap.c
SRCS+= v3_audit_id.c
SRCS+= v3_authattid.c
SRCS+= v3_battcons.c
SRCS+= v3_bcons.c
SRCS+= v3_bitst.c
SRCS+= v3_conf.c
SRCS+= v3_cpols.c
SRCS+= v3_crld.c
SRCS+= v3_enum.c
SRCS+= v3_extku.c
SRCS+= v3_genn.c
SRCS+= v3_group_ac.c
SRCS+= v3_ia5.c
SRCS+= v3_ind_iss.c
SRCS+= v3_info.c
SRCS+= v3_int.c
SRCS+= v3_iobo.c
SRCS+= v3_ist.c
SRCS+= v3_lib.c
SRCS+= v3_ncons.c
SRCS+= v3_no_ass.c
SRCS+= v3_no_rev_avail.c
SRCS+= v3_pci.c
SRCS+= v3_pcia.c
SRCS+= v3_pcons.c
SRCS+= v3_pku.c
SRCS+= v3_pmaps.c
SRCS+= v3_prn.c
SRCS+= v3_purp.c
SRCS+= v3_rolespec.c
SRCS+= v3_san.c
SRCS+= v3_sda.c
SRCS+= v3_single_use.c
SRCS+= v3_skid.c
SRCS+= v3_soa_id.c
SRCS+= v3_sxnet.c
SRCS+= v3_timespec.c
SRCS+= v3_tlsf.c
SRCS+= v3_usernotice.c
SRCS+= v3_utf8.c
SRCS+= v3_utl.c
SRCS+= v3err.c
SRCS+= x509_acert.c
SRCS+= x509_att.c
SRCS+= x509_cmp.c
SRCS+= x509_d2.c
SRCS+= x509_def.c
SRCS+= x509_err.c
SRCS+= x509_ext.c
SRCS+= x509_lu.c
SRCS+= x509_meth.c
SRCS+= x509_obj.c
SRCS+= x509_r2x.c
SRCS+= x509_req.c
SRCS+= x509_set.c
SRCS+= x509_trust.c
SRCS+= x509_txt.c
SRCS+= x509_v3.c
SRCS+= x509_vfy.c
SRCS+= x509_vpm.c
SRCS+= x509aset.c
SRCS+= x509cset.c
SRCS+= x509name.c
SRCS+= x509rset.c
SRCS+= x509spki.c
SRCS+= x509type.c
SRCS+= x_all.c
SRCS+= x_attrib.c
SRCS+= x_crl.c
SRCS+= x_exten.c
SRCS+= x_ietfatt.c
SRCS+= x_name.c
SRCS+= x_pubkey.c
SRCS+= x_req.c
SRCS+= x_x509.c
SRCS+= x_x509a.c

# providers
SRCS+= baseprov.c
SRCS+= defltprov.c
SRCS+= nullprov.c
SRCS+= prov_running.c

# providers/common
SRCS+= bio_prov.c
SRCS+= capabilities.c
SRCS+= digest_to_nid.c
SRCS+= provider_ctx.c
SRCS+= provider_err.c
SRCS+= provider_seeding.c
SRCS+= provider_util.c
SRCS+= securitycheck.c
SRCS+= securitycheck_default.c

# providers/common/der
SRCS+= der_digests_gen.c
SRCS+= der_dsa_gen.c
SRCS+= der_dsa_key.c
SRCS+= der_dsa_sig.c
SRCS+= der_ec_gen.c
SRCS+= der_ec_key.c
SRCS+= der_ec_sig.c
SRCS+= der_ecx_gen.c
SRCS+= der_ecx_key.c
SRCS+= der_ml_dsa_gen.c
SRCS+= der_ml_dsa_key.c
SRCS+= der_rsa_gen.c
SRCS+= der_rsa_key.c
SRCS+= der_rsa_sig.c
SRCS+= der_slh_dsa_gen.c
SRCS+= der_slh_dsa_key.c
SRCS+= der_wrap_gen.c

# providers/implementations/asymciphers
SRCS+= rsa_enc.c

# providers/implementations/ciphers
SRCS+= cipher_aes.c
SRCS+= cipher_aes_cbc_hmac_sha.c
SRCS+= cipher_aes_cbc_hmac_sha1_hw.c
SRCS+= cipher_aes_cbc_hmac_sha256_hw.c
SRCS+= cipher_aes_ccm.c
SRCS+= cipher_aes_ccm_hw.c
SRCS+= cipher_aes_gcm.c
SRCS+= cipher_aes_gcm_hw.c
SRCS+= cipher_aes_gcm_siv.c
SRCS+= cipher_aes_gcm_siv_hw.c
SRCS+= cipher_aes_gcm_siv_polyval.c
SRCS+= cipher_aes_hw.c
SRCS+= cipher_aes_ocb.c
SRCS+= cipher_aes_ocb_hw.c
SRCS+= cipher_aes_siv.c
SRCS+= cipher_aes_siv_hw.c
SRCS+= cipher_aes_wrp.c
SRCS+= cipher_aes_xts.c
SRCS+= cipher_aes_xts_fips.c
SRCS+= cipher_aes_xts_hw.c
SRCS+= cipher_camellia.c
SRCS+= cipher_camellia_hw.c
SRCS+= cipher_chacha20.c
SRCS+= cipher_chacha20_hw.c
SRCS+= cipher_chacha20_poly1305.c
SRCS+= cipher_chacha20_poly1305_hw.c
SRCS+= cipher_cts.c
SRCS+= cipher_null.c
SRCS+= cipher_tdes.c
SRCS+= cipher_tdes_common.c
SRCS+= cipher_tdes_default.c
SRCS+= cipher_tdes_default_hw.c
SRCS+= cipher_tdes_hw.c
SRCS+= cipher_tdes_wrap.c
SRCS+= cipher_tdes_wrap_hw.c
SRCS+= ciphercommon.c
SRCS+= ciphercommon_block.c
SRCS+= ciphercommon_ccm.c
SRCS+= ciphercommon_ccm_hw.c
SRCS+= ciphercommon_gcm.c
SRCS+= ciphercommon_gcm_hw.c
SRCS+= ciphercommon_hw.c

# providers/implementations/digests
SRCS+= blake2_prov.c
SRCS+= blake2b_prov.c
SRCS+= blake2s_prov.c
SRCS+= digestcommon.c
SRCS+= md5_prov.c
SRCS+= md5_sha1_prov.c
SRCS+= null_prov.c
SRCS+= ripemd_prov.c
SRCS+= sha2_prov.c
SRCS+= sha3_prov.c

# providers/implementations/encode_decode
SRCS+= decode_der2key.c
SRCS+= decode_epki2pki.c
SRCS+= decode_msblob2key.c
SRCS+= decode_pem2der.c
SRCS+= decode_pvk2key.c
SRCS+= decode_spki2typespki.c
SRCS+= encode_key2any.c
SRCS+= encode_key2blob.c
SRCS+= encode_key2ms.c
SRCS+= encode_key2text.c
SRCS+= endecoder_common.c
SRCS+= ml_common_codecs.c
SRCS+= ml_dsa_codecs.c
SRCS+= ml_kem_codecs.c

# providers/implementations/exchange
SRCS+= dh_exch.c
SRCS+= ecdh_exch.c
SRCS+= ecx_exch.c
SRCS+= kdf_exch.c

# providers/implementations/kdfs
SRCS+= argon2.c
SRCS+= hkdf.c
SRCS+= hmacdrbg_kdf.c
SRCS+= kbkdf.c
SRCS+= krb5kdf.c
SRCS+= pbkdf2.c
SRCS+= pbkdf2_fips.c
SRCS+= pkcs12kdf.c
SRCS+= scrypt.c
SRCS+= sshkdf.c
SRCS+= sskdf.c
SRCS+= tls1_prf.c
SRCS+= x942kdf.c

# providers/implementations/kem
SRCS+= ec_kem.c
SRCS+= ecx_kem.c
SRCS+= kem_util.c
SRCS+= ml_kem_kem.c
SRCS+= mlx_kem.c
SRCS+= rsa_kem.c

# providers/implementations/keymgmt
SRCS+= dh_kmgmt.c
SRCS+= dsa_kmgmt.c
SRCS+= ec_kmgmt.c
SRCS+= ecx_kmgmt.c
SRCS+= kdf_legacy_kmgmt.c
SRCS+= mac_legacy_kmgmt.c
SRCS+= ml_dsa_kmgmt.c
SRCS+= ml_kem_kmgmt.c
SRCS+= mlx_kmgmt.c
SRCS+= rsa_kmgmt.c
SRCS+= slh_dsa_kmgmt.c

# providers/implementations/macs
SRCS+= blake2b_mac.c
SRCS+= blake2s_mac.c
SRCS+= cmac_prov.c
SRCS+= gmac_prov.c
SRCS+= hmac_prov.c
SRCS+= kmac_prov.c
SRCS+= poly1305_prov.c
SRCS+= siphash_prov.c

# providers/implementations/rands
SRCS+= drbg.c
SRCS+= drbg_ctr.c
SRCS+= drbg_hash.c
SRCS+= drbg_hmac.c
SRCS+= seed_src.c
SRCS+= seed_src_jitter.c
SRCS+= test_rng.c

# providers/implementations/rands/seeding
SRCS+= rand_cpu_x86.c
SRCS+= rand_tsc.c
SRCS+= rand_unix.c
SRCS+= rand_win.c

# providers/implementations/signature
SRCS+= dsa_sig.c
SRCS+= ecdsa_sig.c
SRCS+= eddsa_sig.c
SRCS+= mac_legacy_sig.c
SRCS+= ml_dsa_sig.c
SRCS+= rsa_sig.c
SRCS+= slh_dsa_sig.c

# providers/implementations/skeymgmt
SRCS+= aes_skmgmt.c
SRCS+= generic.c

# providers/implementations/storemgmt
SRCS+= file_store.c
SRCS+= file_store_any2obj.c

# ssl/record/methods
SRCS+= ssl3_cbc.c
SRCS+= tls_pad.c

# Target architecture specific sources.
.if defined(ASM_aarch64)
SRCS+=	arm64cpuid.S armcap.c
ACFLAGS.arm64cpuid.S=	-march=armv8-a+crypto
.elif defined(ASM_amd64)
SRCS+=	x86_64cpuid.S
.elif defined(ASM_arm)
SRCS+=	armv4cpuid.S armcap.c
.elif defined(ASM_i386)
SRCS+=	x86cpuid.S
.elif defined(ASM_powerpc)
SRCS+=	ppccpuid.S ppccap.c
.elif defined(ASM_powerpc64)
SRCS+=	ppccpuid.S ppccap.c
.elif defined(ASM_powerpc64le)
SRCS+=	ppccpuid.S ppccap.c
.else
SRCS+=	mem_clr.c
.endif

.if defined(ASM_aarch64)
SRCS+=	aes_cbc.c aes_core.c aesv8-armx.S vpaes-armv8.S
ACFLAGS.aesv8-armx.S=	-march=armv8-a+crypto
.elif defined(ASM_amd64)
SRCS+=	aes-x86_64.S aesni-mb-x86_64.S aesni-sha1-x86_64.S aesni-sha256-x86_64.S
SRCS+=	aesni-x86_64.S aesni-xts-avx512.S bsaes-x86_64.S vpaes-x86_64.S
.elif defined(ASM_arm)
SRCS+=	aes_cbc.c aes-armv4.S aesv8-armx.S bsaes-armv7.S
.elif defined(ASM_i386)
SRCS+=	aes-586.S aesni-x86.S vpaes-x86.S
.elif defined(ASM_powerpc)
SRCS+=	aes_cbc.c aes_core.c aes-ppc.S vpaes-ppc.S aesp8-ppc.S
.elif defined(ASM_powerpc64)
SRCS+=	aes_cbc.c aes_core.c aes-ppc.S vpaes-ppc.S aesp8-ppc.S
.elif defined(ASM_powerpc64le)
SRCS+=	aes_cbc.c aes_core.c aes-ppc.S vpaes-ppc.S aesp8-ppc.S
.else
SRCS+=	aes_cbc.c aes_core.c
.endif

.if defined(ASM_i386)
SRCS+=	bf-586.S
.else
SRCS+=	bf_enc.c
.endif

.if defined(ASM_aarch64)
SRCS+=	armv8-mont.S bn_asm.c
.elif defined(ASM_amd64)
SRCS+=	rsaz-2k-avx512.S rsaz-2k-avxifma.S
SRCS+=	rsaz-3k-avx512.S rsaz-3k-avxifma.S
SRCS+=	rsaz-4k-avx512.S rsaz-4k-avxifma.S
SRCS+=	rsaz-avx2.S rsaz-x86_64.S rsaz_exp.c rsaz_exp_x2.c
SRCS+=	x86_64-gcc.c x86_64-gf2m.S x86_64-mont.S x86_64-mont5.S
.elif defined(ASM_arm)
SRCS+=	armv4-gf2m.S armv4-mont.S bn_asm.c
.elif defined(ASM_i386)
SRCS+=	bn-586.S co-586.S x86-gf2m.S x86-mont.S
.elif defined(ASM_powerpc)
SRCS+=	bn_ppc.c bn-ppc.S ppc-mont.S
.elif defined(ASM_powerpc64)
SRCS+=	bn_ppc.c bn-ppc.S ppc-mont.S
.elif defined(ASM_powerpc64le)
SRCS+=	bn_ppc.c bn-ppc.S ppc-mont.S
.else
SRCS+=	bn_asm.c
.endif

.if defined(ASM_amd64)
SRCS+=	cmll-x86_64.S cmll_misc.c
.elif defined(ASM_i386)
SRCS+=	cmll-x86.S
.else
SRCS+=	camellia.c cmll_cbc.c cmll_misc.c
.endif

.if defined(ASM_aarch64)
SRCS+=	chacha-armv8.S chacha-armv8-sve.S
.elif defined(ASM_amd64)
SRCS+=	chacha-x86_64.S
.elif defined(ASM_arm)
SRCS+=	chacha-armv4.S
.elif defined(ASM_i386)
SRCS+=	chacha-x86.S
.elif defined(ASM_powerpc)
SRCS+=	chacha_ppc.c chacha-ppc.S chachap10-ppc.S
.elif defined(ASM_powerpc64)
SRCS+=	chacha_ppc.c chacha-ppc.S chachap10-ppc.S
.elif defined(ASM_powerpc64le)
SRCS+=	chacha_ppc.c chacha-ppc.S chachap10-ppc.S
.else
SRCS+=	chacha_enc.c
.endif

.if defined(ASM_i386)
SRCS+=	crypt586.S des-586.S
.else
SRCS+=	des_enc.c fcrypt_b.c
.endif

# see OPENSSL_NO_EC_NISTP_64_GCC_128 in configuration.h
.if ${MACHINE_ABI:Mlittle-endian} && ${MACHINE_ABI:Mlong64}
SRCS+=	ecp_nistp224.c ecp_nistp256.c ecp_nistp384.c ecp_nistp521.c ecp_nistputil.c
.else
CFLAGS+=-DOPENSSL_NO_EC_NISTP_64_GCC_128
.endif
.if defined(ASM_aarch64)
SRCS+=	ecp_nistz256-armv8.S ecp_nistz256.c
.elif defined(ASM_amd64)
SRCS+=	ecp_nistz256-x86_64.S ecp_nistz256.c x25519-x86_64.S
.elif defined(ASM_arm)
SRCS+=	ecp_nistz256-armv4.S ecp_nistz256.c
.elif defined(ASM_i386)
SRCS+=	ecp_nistz256-x86.S ecp_nistz256.c
.elif defined(ASM_powerpc64)
SRCS+=	ecp_nistp521-ppc64.S ecp_nistz256-ppc64.S ecp_nistz256.c ecp_ppc.c x25519-ppc64.S
.elif defined(ASM_powerpc64le)
SRCS+=	ecp_nistp521-ppc64.S ecp_nistz256-ppc64.S ecp_nistz256.c ecp_ppc.c x25519-ppc64.S
.endif

.if defined(ASM_amd64)
SRCS+=	md5-x86_64.S
.elif defined(ASM_i386)
SRCS+=	md5-586.S
.endif

.if defined(ASM_aarch64)
SRCS+=	ghashv8-armx.S aes-gcm-armv8_64.S aes-gcm-armv8-unroll8_64.S
ACFLAGS.ghashv8-armx.S=	-march=armv8-a+crypto
.elif defined(ASM_amd64)
SRCS+=	aesni-gcm-x86_64.S aes-gcm-avx512.S ghash-x86_64.S
.elif defined(ASM_arm)
SRCS+=	ghash-armv4.S ghashv8-armx.S
.elif defined(ASM_i386)
SRCS+=	ghash-x86.S
.elif defined(ASM_powerpc)
SRCS+=	ghashp8-ppc.S
.elif defined(ASM_powerpc64)
SRCS+=	aes-gcm-ppc.S ghashp8-ppc.S
.elif defined(ASM_powerpc64le)
SRCS+=	aes-gcm-ppc.S ghashp8-ppc.S
.endif

.if defined(ASM_aarch64)
SRCS+=	poly1305-armv8.S
.elif defined(ASM_amd64)
SRCS+=	poly1305-x86_64.S
.elif defined(ASM_arm)
SRCS+=	poly1305-armv4.S
.elif defined(ASM_i386)
SRCS+=	poly1305-x86.S
.elif defined(ASM_powerpc)
SRCS+=	poly1305_ppc.c poly1305-ppc.S poly1305-ppcfp.S
.elif defined(ASM_powerpc64)
SRCS+=	poly1305_ppc.c poly1305-ppc.S poly1305-ppcfp.S
.elif defined(ASM_powerpc64le)
SRCS+=	poly1305_ppc.c poly1305-ppc.S poly1305-ppcfp.S
.endif

.if defined(ASM_amd64)
SRCS+=	rc4-md5-x86_64.S rc4-x86_64.S
.elif defined(ASM_i386)
SRCS+=	rc4-586.S
.else
SRCS+=	rc4_enc.c rc4_skey.c
.endif

.if defined(ASM_i386)
SRCS+=	rmd-586.S
.endif

.if defined(ASM_aarch64)
SRCS+=	keccak1600-armv8.S sha1-armv8.S sha256-armv8.S sha512-armv8.S
.elif defined(ASM_amd64)
SRCS+=	keccak1600-x86_64.S sha1-mb-x86_64.S sha1-x86_64.S
SRCS+=	sha256-mb-x86_64.S sha256-x86_64.S sha512-x86_64.S
.elif defined(ASM_arm)
SRCS+=	keccak1600-armv4.S sha1-armv4-large.S sha256-armv4.S sha512-armv4.S
.elif defined(ASM_i386)
SRCS+=	keccak1600.c sha1-586.S sha256-586.S sha512-586.S
.elif defined(ASM_powerpc)
SRCS+=	keccak1600.c sha_ppc.c sha1-ppc.S sha256-ppc.S sha512-ppc.S sha256p8-ppc.S sha512p8-ppc.S
.elif defined(ASM_powerpc64)
SRCS+=	keccak1600-ppc64.S sha_ppc.c sha1-ppc.S sha256-ppc.S sha512-ppc.S sha256p8-ppc.S sha512p8-ppc.S
.elif defined(ASM_powerpc64le)
SRCS+=	keccak1600-ppc64.S sha_ppc.c sha1-ppc.S sha256-ppc.S sha512-ppc.S sha256p8-ppc.S sha512p8-ppc.S
.else
SRCS+=	keccak1600.c
.endif

.if defined(ASM_amd64)
SRCS+=	wp-x86_64.S
.elif defined(ASM_i386)
SRCS+=	wp-mmx.S wp_block.c
.else
SRCS+=	wp_block.c
.endif


# apps
INCS+= progs.h

# include/crypto
INCS+= bn_conf.h
INCS+= dso_conf.h

# include/openssl
INCS+= aes.h
INCS+= asn1.h
INCS+= asn1err.h
INCS+= asn1t.h
INCS+= async.h
INCS+= asyncerr.h
INCS+= bio.h
INCS+= bioerr.h
INCS+= blowfish.h
INCS+= bn.h
INCS+= bnerr.h
INCS+= buffer.h
INCS+= buffererr.h
INCS+= byteorder.h
INCS+= camellia.h
INCS+= cast.h
INCS+= cmac.h
INCS+= cmp.h
INCS+= cmp_util.h
INCS+= cmperr.h
INCS+= cms.h
INCS+= cmserr.h
INCS+= comp.h
INCS+= comperr.h
INCS+= conf.h
INCS+= conferr.h
INCS+= configuration.h
INCS+= conftypes.h
INCS+= core.h
INCS+= core_dispatch.h
INCS+= core_names.h
INCS+= core_object.h
INCS+= crmf.h
INCS+= crmferr.h
INCS+= crypto.h
INCS+= cryptoerr.h
INCS+= cryptoerr_legacy.h
INCS+= ct.h
INCS+= cterr.h
INCS+= decoder.h
INCS+= decodererr.h
INCS+= des.h
INCS+= dh.h
INCS+= dherr.h
INCS+= dsa.h
INCS+= dsaerr.h
INCS+= dtls1.h
INCS+= e_os2.h
INCS+= e_ostime.h
INCS+= ec.h
INCS+= ecdh.h
INCS+= ecdsa.h
INCS+= ecerr.h
INCS+= encoder.h
INCS+= encodererr.h
INCS+= engine.h
INCS+= engineerr.h
INCS+= err.h
INCS+= ess.h
INCS+= esserr.h
INCS+= evp.h
INCS+= evperr.h
INCS+= fips_names.h
INCS+= fipskey.h
INCS+= hmac.h
INCS+= hpke.h
INCS+= http.h
INCS+= httperr.h
INCS+= idea.h
INCS+= indicator.h
INCS+= kdf.h
INCS+= kdferr.h
INCS+= lhash.h
INCS+= macros.h
INCS+= md2.h
INCS+= md4.h
INCS+= md5.h
INCS+= mdc2.h
INCS+= ml_kem.h
INCS+= modes.h
INCS+= obj_mac.h
INCS+= objects.h
INCS+= objectserr.h
INCS+= ocsp.h
INCS+= ocsperr.h
INCS+= opensslconf.h
INCS+= opensslv.h
INCS+= ossl_typ.h
INCS+= param_build.h
INCS+= params.h
INCS+= pem.h
INCS+= pem2.h
INCS+= pemerr.h
INCS+= pkcs12.h
INCS+= pkcs12err.h
INCS+= pkcs7.h
INCS+= pkcs7err.h
INCS+= prov_ssl.h
INCS+= proverr.h
INCS+= provider.h
INCS+= quic.h
INCS+= rand.h
INCS+= randerr.h
INCS+= rc2.h
INCS+= rc4.h
INCS+= rc5.h
INCS+= ripemd.h
INCS+= rsa.h
INCS+= rsaerr.h
INCS+= safestack.h
INCS+= seed.h
INCS+= self_test.h
INCS+= sha.h
INCS+= srp.h
INCS+= srtp.h
INCS+= ssl.h
INCS+= ssl2.h
INCS+= ssl3.h
INCS+= sslerr.h
INCS+= sslerr_legacy.h
INCS+= stack.h
INCS+= store.h
INCS+= storeerr.h
INCS+= symhacks.h
INCS+= thread.h
INCS+= tls1.h
INCS+= trace.h
INCS+= ts.h
INCS+= tserr.h
INCS+= txt_db.h
INCS+= types.h
INCS+= ui.h
INCS+= uierr.h
INCS+= whrlpool.h
INCS+= x509.h
INCS+= x509_acert.h
INCS+= x509_vfy.h
INCS+= x509err.h
INCS+= x509v3.h
INCS+= x509v3err.h

# providers/common/include/prov
INCS+= der_digests.h
INCS+= der_dsa.h
INCS+= der_ec.h
INCS+= der_ecx.h
INCS+= der_ml_dsa.h
INCS+= der_rsa.h
INCS+= der_slh_dsa.h
INCS+= der_wrap.h

INCSDIR=${INCLUDEDIR}/openssl

LIBADD=	pthread

SRCS+=	buildinf.h

CLEANDIRS=	openssl
CLEANFILES=	buildinf.h

.if defined(ASM_${MACHINE_CPUARCH}) || defined(ASM_${MACHINE_ARCH})
_cmd1=/%%NO_ASM%%/d
.else
_cmd1=s/%%NO_ASM%%//
.endif
.if ${MK_OPENSSL_KTLS} != "no" && !defined(BOOTSTRAPPING)
_cmd2=/%%NO_KTLS%%/d
.else
_cmd2=s/%%NO_KTLS%%//
CFLAGS+= -DOPENSSL_NO_KTLS
.endif

buildinf.h: Makefile
	( echo "/*"; \
	echo " * WARNING: do not edit!"; \
	echo " * Generated by ${.ALLSRC}"; \
	echo " */"; \
	echo "#define PLATFORM \"platform: FreeBSD-${MACHINE_ARCH}\""; \
	echo "#define DATE \"built on: reproducible build, date unspecified\""; \
	echo "static const char compiler_flags[] = \"compiler: ${COMPILER_TYPE}\";" ) \
	> ${.TARGET}

buildasm cleanasm:
.for arch in aarch64 amd64 arm i386 powerpc powerpc64 powerpc64le
	make MK_AUTO_OBJ=no -DWITHOUT_AUTO_ASM -DASM_${arch} \
	    -f ${.CURDIR}/Makefile.asm -C ${SRCTOP}/sys/crypto/openssl/${arch} \
	    ${.TARGET:S/build/all/:S/asm$//}
.endfor

.include <bsd.lib.mk>

.if ${MACHINE} == "powerpc"
# Work around "relocation R_PPC_GOT16 out of range" errors
PICFLAG=	-fPIC
.endif
PICFLAG+=	-DOPENSSL_PIC

.if defined(ASM_${MACHINE_CPUARCH})
.PATH:	${SRCTOP}/sys/crypto/openssl/${MACHINE_CPUARCH}
.if defined(ASM_amd64)
.PATH:	${LCRYPTO_SRC}/crypto/bn/asm
.endif
.elif defined(ASM_${MACHINE_ARCH})
.PATH:	${SRCTOP}/sys/crypto/openssl/${MACHINE_ARCH}
.endif

.PATH:	${LCRYPTO_SRC}/include/openssl \
	${LCRYPTO_SRC}/crypto \
	${LCRYPTO_SRC}/crypto/aes \
	${LCRYPTO_SRC}/crypto/asn1 \
	${LCRYPTO_SRC}/crypto/async \
	${LCRYPTO_SRC}/crypto/async/arch \
	${LCRYPTO_SRC}/crypto/bf \
	${LCRYPTO_SRC}/crypto/bio \
	${LCRYPTO_SRC}/crypto/bn \
	${LCRYPTO_SRC}/crypto/bn/asm \
	${LCRYPTO_SRC}/crypto/buffer \
	${LCRYPTO_SRC}/crypto/camellia \
	${LCRYPTO_SRC}/crypto/cast \
	${LCRYPTO_SRC}/crypto/cmac \
	${LCRYPTO_SRC}/crypto/cmp \
	${LCRYPTO_SRC}/crypto/cms \
	${LCRYPTO_SRC}/crypto/comp \
	${LCRYPTO_SRC}/crypto/conf \
	${LCRYPTO_SRC}/crypto/crmf \
	${LCRYPTO_SRC}/crypto/ct \
	${LCRYPTO_SRC}/crypto/des \
	${LCRYPTO_SRC}/crypto/dh \
	${LCRYPTO_SRC}/crypto/dsa \
	${LCRYPTO_SRC}/crypto/dso \
	${LCRYPTO_SRC}/crypto/ec \
	${LCRYPTO_SRC}/crypto/ec/curve448 \
	${LCRYPTO_SRC}/crypto/ec/curve448/arch_32 \
	${LCRYPTO_SRC}/crypto/ec/curve448/arch_64 \
	${LCRYPTO_SRC}/crypto/encode_decode \
	${LCRYPTO_SRC}/crypto/engine \
	${LCRYPTO_SRC}/crypto/err \
	${LCRYPTO_SRC}/crypto/ess \
	${LCRYPTO_SRC}/crypto/evp \
	${LCRYPTO_SRC}/crypto/ffc \
	${LCRYPTO_SRC}/crypto/hashtable \
	${LCRYPTO_SRC}/crypto/hmac \
	${LCRYPTO_SRC}/crypto/hpke \
	${LCRYPTO_SRC}/crypto/http \
	${LCRYPTO_SRC}/crypto/kdf \
	${LCRYPTO_SRC}/crypto/lhash \
	${LCRYPTO_SRC}/crypto/md4 \
	${LCRYPTO_SRC}/crypto/md5 \
	${LCRYPTO_SRC}/crypto/ml_dsa \
	${LCRYPTO_SRC}/crypto/ml_kem \
	${LCRYPTO_SRC}/crypto/modes \
	${LCRYPTO_SRC}/crypto/objects \
	${LCRYPTO_SRC}/crypto/ocsp \
	${LCRYPTO_SRC}/crypto/pem \
	${LCRYPTO_SRC}/crypto/pkcs12 \
	${LCRYPTO_SRC}/crypto/pkcs7 \
	${LCRYPTO_SRC}/crypto/poly1305 \
	${LCRYPTO_SRC}/crypto/property \
	${LCRYPTO_SRC}/crypto/rand \
	${LCRYPTO_SRC}/crypto/rc2 \
	${LCRYPTO_SRC}/crypto/ripemd \
	${LCRYPTO_SRC}/crypto/rsa \
	${LCRYPTO_SRC}/crypto/seed \
	${LCRYPTO_SRC}/crypto/sha \
	${LCRYPTO_SRC}/crypto/siphash \
	${LCRYPTO_SRC}/crypto/slh_dsa \
	${LCRYPTO_SRC}/crypto/srp \
	${LCRYPTO_SRC}/crypto/stack \
	${LCRYPTO_SRC}/crypto/store \
	${LCRYPTO_SRC}/crypto/thread \
	${LCRYPTO_SRC}/crypto/thread/arch \
	${LCRYPTO_SRC}/crypto/ts \
	${LCRYPTO_SRC}/crypto/txt_db \
	${LCRYPTO_SRC}/crypto/ui \
	${LCRYPTO_SRC}/crypto/whrlpool \
	${LCRYPTO_SRC}/crypto/x509 \
	${LCRYPTO_SRC}/providers \
	${LCRYPTO_SRC}/providers/common \
	${LCRYPTO_SRC}/providers/common/der \
	${LCRYPTO_SRC}/providers/implementations/asymciphers \
	${LCRYPTO_SRC}/providers/implementations/ciphers \
	${LCRYPTO_SRC}/providers/implementations/digests \
	${LCRYPTO_SRC}/providers/implementations/encode_decode \
	${LCRYPTO_SRC}/providers/implementations/exchange \
	${LCRYPTO_SRC}/providers/implementations/kdfs \
	${LCRYPTO_SRC}/providers/implementations/kem \
	${LCRYPTO_SRC}/providers/implementations/keymgmt \
	${LCRYPTO_SRC}/providers/implementations/macs \
	${LCRYPTO_SRC}/providers/implementations/rands \
	${LCRYPTO_SRC}/providers/implementations/rands/seeding \
	${LCRYPTO_SRC}/providers/implementations/signature \
	${LCRYPTO_SRC}/providers/implementations/skeymgmt \
	${LCRYPTO_SRC}/providers/implementations/storemgmt \
	${LCRYPTO_SRC}/ssl/record/methods \
	${LCRYPTO_SRC}/crypto \
	${LCRYPTO_SRC}/crypto/aes \
	${LCRYPTO_SRC}/crypto/bf \
	${LCRYPTO_SRC}/crypto/bn \
	${LCRYPTO_SRC}/crypto/camellia \
	${LCRYPTO_SRC}/crypto/chacha \
	${LCRYPTO_SRC}/crypto/des \
	${LCRYPTO_SRC}/crypto/ec \
	${LCRYPTO_SRC}/crypto/poly1305 \
	${LCRYPTO_SRC}/crypto/rc4 \
	${LCRYPTO_SRC}/crypto/sha \
	${LCRYPTO_SRC}/crypto/whrlpool \
	${LCRYPTO_SRC}/apps \
	${LCRYPTO_SRC}/include/crypto \
	${LCRYPTO_SRC}/include/openssl \
	${LCRYPTO_SRC}/providers/common/include/prov \
