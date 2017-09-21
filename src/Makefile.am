lib_LTLIBRARIES = libtscpaq.la
libtscpaq_la_SOURCES = tscpaq.c
include_HEADERS	= tscpaq.h
libtscpaq_la_LIBADD = -lcpaq -lpthread
#libtscpaq_la_CFLAGS =

bin_PROGRAMS = tscpaq-test
tscpaq_test_SOURCES = tscpaq-test.c
tscpaq_test_LDADD = libtscpaq.la -lcpaq -lpthread
#tscpaq_test_CFLAGS =

AM_CPPFLAGS = -D__STDC_INT64__
