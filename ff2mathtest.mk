# ================================================================
# Makefile for project ff2mathtest
# Automatically generated from "ff2mathtest.mki" at Mon Jan  7 22:27:09 2013

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

build: mk_obj_dir ./ff2mathtest

mk_obj_dir:
	mkdir -p ./ff2mathtest_objs

./ff2mathtest_objs/ff2mathlib.o:  ff2mathlib.c
	gcc -g $(COMPILE_FLAGS)  ff2mathlib.c -o ./ff2mathtest_objs/ff2mathlib.o

./ff2mathtest_objs/ff2mathtest.o:  ff2mathlib.h ff2mathtest.c
	gcc -g $(COMPILE_FLAGS)  ff2mathtest.c -o ./ff2mathtest_objs/ff2mathtest.o

OBJS = \
	./ff2mathtest_objs/ff2mathlib.o \
	./ff2mathtest_objs/ff2mathtest.o

./ff2mathtest: $(OBJS) $(EXTRA_DEPS)
	gcc $(OBJS) -o ./ff2mathtest $(LINK_FLAGS)

install: build
	cp ./ff2mathtest $(HOME)/bin

clean:
	-@rm -f $(OBJS)
	-@rm -f ./ff2mathtest
