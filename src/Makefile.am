LIBTSCPAQ_LIBADD = -L $(top_srcdir)/CPAQ/src/.libs -lcpaq
#LIBTSCPAQ_LIBADD = -L $(top_srcdir)/CPAQ/src/.libs/libcpaq.la
LIBTSCPAQ_LIBADD += -lpthread

lib_LTLIBRARIES = libtscpaq.la
libtscpaq_la_SOURCES = tscpaq.c
include_HEADERS	= tscpaq.h
libtscpaq_la_LIBADD = $(LIBTSCPAQ_LIBADD)
#libtscpaq_la_CFLAGS =

bin_PROGRAMS = tscpaq-test
tscpaq_test_SOURCES = tscpaq-test.c
tscpaq_test_LDADD = $(LIBTSCPAQ_LIBADD)
#tscpaq_test_CFLAGS =

AM_CPPFLAGS = -D__STDC_INT64__
AM_CPPFLAGS += -I $(top_srcdir)/glitter/src
AM_CPPFLAGS += -I $(top_srcdir)/CPAQ/src
