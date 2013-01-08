# ================================================================
# Makefile for project ff2mathop
# Automatically generated from "ff2mathop.mki" at Mon Jan  7 22:27:09 2013

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

build: mk_obj_dir ./ff2mathop

mk_obj_dir:
	mkdir -p ./ff2mathop_objs

./ff2mathop_objs/ff2mathlib.o:  ff2mathlib.c
	gcc -g $(COMPILE_FLAGS)  ff2mathlib.c -o ./ff2mathop_objs/ff2mathlib.o

./ff2mathop_objs/ff2mathop.o:  ff2mathlib.h ff2mathop.c
	gcc -g $(COMPILE_FLAGS)  ff2mathop.c -o ./ff2mathop_objs/ff2mathop.o

OBJS = \
	./ff2mathop_objs/ff2mathlib.o \
	./ff2mathop_objs/ff2mathop.o

./ff2mathop: $(OBJS) $(EXTRA_DEPS)
	gcc $(OBJS) -o ./ff2mathop $(LINK_FLAGS)

install: build
	cp ./ff2mathop $(HOME)/bin

clean:
	-@rm -f $(OBJS)
	-@rm -f ./ff2mathop
