AM_CPPFLAGS = -D__STDC_INT64__

SUBDIRS = ../glitter
AM_CPPFLAGS += -I $(top_srcdir)/glitter/src

SUBDIRS += ../CPAQ
AM_CPPFLAGS += -I $(top_srcdir)/CPAQ/src

include Makefile-LIBADD.inc

lib_LTLIBRARIES = libtscpaq.la
include_HEADERS	= tscpaq.h
libtscpaq_la_LIBADD = $(LIBTSCPAQ_LIBADD)

bin_PROGRAMS = tscpaq-test
tscpaq_test_LDADD = libtscpaq.la $(LIBTSCPAQ_LIBADD)
