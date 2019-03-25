include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

# Always package (e.g. for 'make dist') these subdirectories.

DIST_SUBDIRS                            = \
    platform                              \
    $(NULL)

# Always build (e.g. for 'make all') these subdirectories.

SUBDIRS                                 = \
    platform                              \
    $(NULL)

# Always pretty (e.g. for 'make pretty') these subdirectories.

PRETTY_SUBDIRS                          = \
    platform                              \
    $(NULL)

gobo_headers                            = \
    cli.h                                 \
    config.h                              \
    error.h                               \
    instance.h                            \
    tasklet.h                             \
    $(NULL)

gobodir = $(includedir)/gobo
dist_gobo_HEADERS = $(gobo_headers)

include_HEADERS                         = \
    $(NULL)

install-headers: install-includeHEADERS

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
