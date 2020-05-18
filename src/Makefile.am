AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
bin_PROGRAMS    =

lib_LTLIBRARIES += libtscpaq.la
include_HEADERS	= tscpaq.h
libtscpaq_la_CPPFLAGS = $(GLITTER_CFLAGS) $(CPAQ_CFLAGS)
libtscpaq_la_LIBADD   = $(GLITTER_LIBS)   $(CPAQ_LIBS) -lpthread

bin_PROGRAMS += tscpaq-test
tscpaq_test_CPPFLAGS =          $(GLITTER_CFLAGS) $(CPAQ_CFLAGS)
tscpaq_test_LDADD    = -ltscpaq $(GLITTER_LIBS)   $(CPAQ_LIBS) -lpthread
EXTRA_tscpaq_test_DEPENDENCIES = libtscpaq.la

