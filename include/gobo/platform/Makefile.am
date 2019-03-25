include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

go_platform_headers                     = \
    alarm-micro.h                         \
    alarm-milli.h                         \
    debug_uart.h                          \
    logging.h                             \
    misc.h                                \
    random.h                              \
    time.h                                \
    toolchain.h                           \
    uart.h                                \
    $(NULL)

noinst_HEADERS                          = \
    $(NULL)

go_platformdir = $(includedir)/gobo/platform
dist_go_platform_HEADERS = $(go_platform_headers)

install-headers: install-includeHEADERS

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
