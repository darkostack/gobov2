include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

# Always package (e.g. for 'make dist') these subdirectories.

DIST_SUBDIRS                            = \
    posix                                 \
    $(NULL)

# Always build (e.g. for 'make all') these subdirectories.

SUBDIRS                                 = \
    utils                                 \
    $(NULL)

if GOBO_EXAMPLES_POSIX
SUBDIRS                                += posix
endif

noinst_HEADERS                          = \
    gobo-system.h                         \
    $(NULL)

# Always pretty (e.g. for 'make pretty') these subdirectories.

PRETTY_SUBDIRS                          = \
    posix                                 \
    $(NULL)

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
