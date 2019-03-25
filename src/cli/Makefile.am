include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

lib_LIBRARIES                           = \
    libgobo-cli.a                         \
    $(NULL)

CPPFLAGS_COMMON                         = \
    -I$(top_srcdir)/include               \
    -I$(top_srcdir)/src                   \
    -I$(top_srcdir)/src/core              \
    $(GOBO_TARGET_DEFINES)                \
    $(NULL)

if GOBO_POSIX
CPPFLAGS_COMMON                        += \
    -DGOBO_POSIX=1                        \
    $(NULL)
endif

libgobo_cli_a_CPPFLAGS                  = \
    $(CPPFLAGS_COMMON)                    \
    $(NULL)

SOURCES_COMMON                          = \
    cli.cpp                               \
    cli_uart.cpp                          \
    $(NULL)

libgobo_cli_a_SOURCES                   = \
    $(SOURCES_COMMON)                     \
    $(NULL)

noinst_HEADERS                          = \
    cli.hpp                               \
    cli_server.hpp                        \
    cli_uart.hpp                          \
    $(NULL)

if GOBO_BUILD_COVERAGE
CLEANFILES                              = $(wildcard *.gcda *.gcno)
endif # GOBO_BUILD_COVERAGE

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
