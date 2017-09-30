include $(top_srcdir)/CPAQ/src/Makefile-LIBADD.inc
LIBTSCPAQ_LIBADD  = ../CPAQ/src/.libs/libcpaq.la $(LIBCPAQ_LIBADD)
LIBTSCPAQ_LIBADD += -lpthread
