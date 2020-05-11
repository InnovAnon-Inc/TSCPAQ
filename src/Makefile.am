AM_CPPFLAGS = -D__STDC_INT64__

#if USE_SUBMODULES
#SUBDIRS = ../glitter
#AM_CPPFLAGS += -I $(top_srcdir)/glitter/src
#
#SUBDIRS += ../CPAQ
#AM_CPPFLAGS += -I $(top_srcdir)/CPAQ/src
#endif

#include Makefile-LIBADD.inc
dist_bin_SCRIPTS = libtscpaq_config tscpaq_test_config

lib_LTLIBRARIES = libtscpaq.la
include_HEADERS	= tscpaq.h
libtscpaq_la_LIBADD = $(LIBTSCPAQ_LIBADD)

bin_PROGRAMS = tscpaq-test
#tscpaq_test_LDADD = libtscpaq.la $(LIBTSCPAQ_LIBADD)
tscpaq_test_LDADD = $(TSCPAQ_TEST_LIBADD)
