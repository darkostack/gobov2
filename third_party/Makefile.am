include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

# Always package (e.g. for 'make dist') these subdirectories.

DIST_SUBDIRS                            = \
    mbedtls                               \
    $(NULL)

if GOBO_ENABLE_BUILTIN_MBEDTLS
SUBDIRS                                 = \
    mbedtls                               \
    $(NULL)
endif # GOBO_ENABLE_BUILTIN_MBEDTLS

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
