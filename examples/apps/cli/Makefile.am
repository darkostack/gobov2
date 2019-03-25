include $(abs_top_nlbuild_autotools_dir)/automake/pre.am
include $(top_srcdir)/examples/platforms/Makefile.platform.am

bin_PROGRAMS                                                        = \
    $(NULL)

CPPFLAGS_COMMON                                                    += \
    -I$(top_srcdir)/include                                           \
    -I$(top_srcdir)/src/core                                          \
    -I$(top_srcdir)/examples/platforms                                \
    $(NULL)

LDADD_COMMON                                                       += \
    $(NULL)

LDFLAGS_COMMON                                                     += \
    $(NULL)

LIBTOOLFLAGS_COMMON                                                += \
    $(NULL)

SOURCES_COMMON                                                     += \
    main.c                                                            \
    $(NULL)

if GOBO_ENABLE_BUILTIN_MBEDTLS
LDADD_COMMON                                                       += \
    $(top_builddir)/third_party/mbedtls/libmbedcrypto.a               \
    $(NULL)
endif # GOBO_ENABLE_BUILTIN_MBEDTLS

bin_PROGRAMS                                                       += \
    go-cli                                                            \
    $(NULL)

go_cli_CPPFLAGS                                                     = \
    $(CPPFLAGS_COMMON)                                                \
    $(NULL)

go_cli_LDADD                                                        = \
    $(top_builddir)/src/cli/libgobo-cli.a                             \
    $(top_builddir)/src/core/libgobo-core.a                           \
    $(LDADD_COMMON)                                                   \
    $(top_builddir)/src/core/libgobo-core.a                           \
    $(LDADD_COMMON)                                                   \
    $(NULL)

go_cli_LDFLAGS                                                      = \
    $(LDFLAGS_COMMON)                                                 \
    $(NULL)

go_cli_LIBTOOLFLAGS                                                 = \
    $(LIBTOOLFLAGS_COMMON)                                            \
    $(NULL)

go_cli_SOURCES                                                      = \
    $(SOURCES_COMMON)                                                 \
    $(NULL)

if GOBO_ENABLE_LINKER_MAP
go_cli_LDFLAGS                                                      += -Wl,-Map=go-cli.map
endif

if GOBO_BUILD_COVERAGE
CLEANFILES                                                          = $(wildcard *.gcda *.gcno)
endif # GOBO_BUILD_COVERAGE

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
