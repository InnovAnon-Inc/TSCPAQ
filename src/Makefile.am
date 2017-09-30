AM_CPPFLAGS = -D__STDC_INT64__

SUBDIRS = ../glitter
AM_CPPFLAGS += -I ../glitter/src

SUBDIRS += ../CPAQ
AM_CPPFLAGS += -I ../CPAQ/src

#LIBTSCPAQ_LIBADD = -L$(top_srcdir)/CPAQ/src/.libs -lcpaq
#LIBTSCPAQ_LIBADD = $(top_srcdir)/CPAQ/src/.libs/libcpaq.la
LIBTSCPAQ_LIBADD = ../CPAQ/src/.libs/libcpaq.la
#LIBTSCPAQ_LIBADD = -l$(top_srcdir)/CPAQ/src/.libs/libcpaq.la
LIBTSCPAQ_LIBADD += -lpthread

lib_LTLIBRARIES = libtscpaq.la
include_HEADERS	= tscpaq.h
libtscpaq_la_LIBADD = $(LIBTSCPAQ_LIBADD)

bin_PROGRAMS = tscpaq-test
tscpaq_test_LDADD = libtscpaq.la $(LIBTSCPAQ_LIBADD)
