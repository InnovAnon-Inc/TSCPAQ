# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libtscpaq.pc src/tscpaq-test.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libtscpaq.pc.in src/tscpaq-test.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

