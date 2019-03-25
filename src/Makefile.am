include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

# Always package (e.g. for 'make dist') these subdirectories.

DIST_SUBDIRS                            = \
    core                                  \
    cli                                   \
    $(NULL)

# Always build (e.g. for 'make all') these subdirectories.

SUBDIRS                                 = \
    core                                  \
    $(NULL)

if GOBO_ENABLE_CLI
SUBDIRS                                += cli
endif

# Always pretty (e.g. for 'make pretty') these subdirectories.

PRETTY_SUBDIRS                          = \
    core                                  \
    cli                                   \
    $(NULL)

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
