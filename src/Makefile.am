AM_CPPFLAGS = -D__STDC_INT64__

#include Makefile-LIBADD.inc
dist_bin_SCRIPTS = libtscpaq_config tscpaq_test_config

lib_LTLIBRARIES =
bin_PROGRAMS    =

lib_LTLIBRARIES += libtscpaq.la
include_HEADERS	= tscpaq.h
libtscpaq_la_LIBADD = @LIBTSCPAQ_LIBADD@

bin_PROGRAMS += tscpaq-test
#tscpaq_test_LDADD = libtscpaq.la $(LIBTSCPAQ_LIBADD)
tscpaq_test_LDADD = @TSCPAQ_TEST_LIBADD@
EXTRA_tscpaq_test_DEPENDENCIES = libtscpaq.la
