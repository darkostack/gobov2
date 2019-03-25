include $(abs_top_nlbuild_autotools_dir)/automake/pre.am

# Always package (e.g. for 'make dist') these subdirectories.

DIST_SUBDIRS                            = \
    unit                                  \
    $(NULL)

# Always build (e.g. for 'make all') these subdirectories.

SUBDIRS                                 = \
    $(NULL)

# Always pretty (e.g. for 'make pretty') these subdirectories.

PRETTY_SUBDIRS                          = \
    unit                                  \
    $(NULL)

if GOBO_POSIX
SUBDIRS                                += \
    unit                                  \
    $(NULL)
endif

if GOBO_BUILD_TESTS
if GOBO_BUILD_COVERAGE
CLEANFILES                             	= $(wildcard *.gcda *.gcno)

if GOBO_BUILD_COVERAGE_REPORTS
# The bundle should positively be qualified with the absolute build
# path. Otherwise, VPATH will get auto-prefixed to it if there is
# already such a directory in the non-colocated source tree.

GOBO_COVERAGE_BUNDLE             		= ${abs_builddir}/${PACKAGE}${NL_COVERAGE_BUNDLE_SUFFIX}
GOBO_COVERAGE_INFO               		= ${GOBO_COVERAGE_BUNDLE}/${PACKAGE}${NL_COVERAGE_INFO_SUFFIX}

$(GOBO_COVERAGE_BUNDLE):
	$(call create-directory)

$(GOBO_COVERAGE_INFO): check | $(dir $(GOBO_COVERAGE_INFO))
	$(call generate-coverage-report,${top_builddir})

coverage-local: $(GOBO_COVERAGE_INFO)

clean-local: clean-local-coverage

.PHONY: clean-local-coverage
clean-local-coverage:
	-$(AM_V_at)rm -rf $(GOBO_COVERAGE_BUNDLE)
endif # GOBO_BUILD_COVERAGE_REPORTS
endif # GOBO_BUILD_COVERAGE
endif # GOBO_BUILD_TESTS

include $(abs_top_nlbuild_autotools_dir)/automake/post.am
