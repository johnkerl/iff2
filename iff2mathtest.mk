# ================================================================
# Makefile for project iff2mathtest
# Automatically generated from "iff2mathtest.mki" at Mon Jan  7 22:27:09 2013

# yamm v1.0
# John Kerl
# 2002/05/04
# ================================================================


INCLUDE_DIRS =
LIB_DIRS =
DEFINES = -DUNIX
MISC_CFLAGS =
MISC_LFLAGS =
EXTRA_DEPS =
COMPILE_FLAGS = -c $(INCLUDE_DIRS) $(DEFINES) $(MISC_CFLAGS)
LINK_FLAGS =  $(LIB_DIRS) $(MISC_LFLAGS)

build: mk_obj_dir ./iff2mathtest

mk_obj_dir:
	mkdir -p ./iff2mathtest_objs

./iff2mathtest_objs/iff2mathlib.o:  iff2mathlib.c
	gcc -g $(COMPILE_FLAGS)  iff2mathlib.c -o ./iff2mathtest_objs/iff2mathlib.o

./iff2mathtest_objs/iff2mathtest.o:  iff2mathlib.h iff2mathtest.c
	gcc -g $(COMPILE_FLAGS)  iff2mathtest.c -o ./iff2mathtest_objs/iff2mathtest.o

OBJS = \
	./iff2mathtest_objs/iff2mathlib.o \
	./iff2mathtest_objs/iff2mathtest.o

./iff2mathtest: $(OBJS) $(EXTRA_DEPS)
	gcc $(OBJS) -o ./iff2mathtest $(LINK_FLAGS)

install: build
	cp ./iff2mathtest $(HOME)/bin

clean:
	-@rm -f $(OBJS)
	-@rm -f ./iff2mathtest
