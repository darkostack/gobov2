include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

# Always package (e.g. for 'make dist') these subdirectories.

DIST_SUBDIRS                            = \
    platforms                             \
    apps                                  \
    $(NULL)

# Always build (e.g. for 'make all') these subdirectories.

SUBDIRS                                 = \
    platforms                             \
    $(NULL)

if GOBO_EXAMPLES
SUBDIRS                                += \
    apps                                  \
    $(NULL)
endif

# Always pretty (e.g. for 'make pretty') these subdirectories.

PRETTY_SUBDIRS                          = \
    platforms                             \
    apps                                  \
    $(NULL)

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
