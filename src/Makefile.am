lib_LTLIBRARIES = libtscpaq.la
libtscpaq_la_SOURCES = tscpaq.c
include_HEADERS	= tscpaq.h
libtscpaq_la_LDFLAGS = -lcpaq -lpthread

libtscpaq_la_CFLAGS = -Wextra -pedantic -ansi -Werror -Wdouble-promotion \
                   -Wformat=2 -Wswitch-default -Wswitch-enum -Wuninitialized \
                   -Wstrict-aliasing=1 -Wstrict-overflow=5 \
                   -Wsuggest-attribute=pure -Wsuggest-attribute=const \
                   -Wsuggest-attribute=noreturn -Wsuggest-attribute=format \
                   -Warray-bounds=2 -Wtrampolines -Wfloat-equal \
                   -Wtraditional-conversion -Wdeclaration-after-statement \
                   -Wundef -Wshadow -Wunsafe-loop-optimizations \
                   -Wbad-function-cast -Wcast-qual -Wcast-align \
                   -Wwrite-strings -Wconversion -Wjump-misses-init \
                   -Wlogical-op -Waggregate-return \
                   -Wno-aggressive-loop-optimizations -Wstrict-prototypes \
                   -Wmissing-prototypes -Wmissing-declarations -Wpacked \
                   -Wpadded -Wredundant-decls -Wnested-externs -Winline \
                   -Wvector-operation-performance -Wdisabled-optimization \
                   -Wstack-protector -Wunsuffixed-float-constants \
                   -Winit-self

bin_PROGRAMS = tscpaq-test
tscpaq_test_SOURCES = tscpaq-test.c
tscpaq_test_LDADD = libtscpaq.la
tscpaq_test_LDFLAGS = -lcpaq -lpthread

tscpaq_test_CFLAGS = -Wextra -pedantic -ansi -Werror -Wdouble-promotion \
                   -Wformat=2 -Wswitch-default -Wswitch-enum -Wuninitialized \
                   -Wstrict-aliasing=1 -Wstrict-overflow=5 \
                   -Wsuggest-attribute=pure -Wsuggest-attribute=const \
                   -Wsuggest-attribute=noreturn -Wsuggest-attribute=format \
                   -Warray-bounds=2 -Wtrampolines -Wfloat-equal \
                   -Wtraditional-conversion -Wdeclaration-after-statement \
                   -Wundef -Wshadow -Wunsafe-loop-optimizations \
                   -Wbad-function-cast -Wcast-qual -Wcast-align \
                   -Wwrite-strings -Wconversion -Wjump-misses-init \
                   -Wlogical-op -Waggregate-return \
                   -Wno-aggressive-loop-optimizations -Wstrict-prototypes \
                   -Wmissing-prototypes -Wmissing-declarations -Wpacked \
                   -Wpadded -Wredundant-decls -Wnested-externs -Winline \
                   -Wvector-operation-performance -Wdisabled-optimization \
                   -Wstack-protector -Wunsuffixed-float-constants \
                   -Winit-self

