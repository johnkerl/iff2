# ================================================================
# Makefile for project iff2mathop
# Automatically generated from "iff2mathop.mki" at Mon Jan  7 22:27:09 2013

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

build: mk_obj_dir ./iff2mathop

mk_obj_dir:
	mkdir -p ./iff2mathop_objs

./iff2mathop_objs/iff2mathlib.o:  iff2mathlib.c
	gcc -g $(COMPILE_FLAGS)  iff2mathlib.c -o ./iff2mathop_objs/iff2mathlib.o

./iff2mathop_objs/iff2mathop.o:  iff2mathlib.h iff2mathop.c
	gcc -g $(COMPILE_FLAGS)  iff2mathop.c -o ./iff2mathop_objs/iff2mathop.o

OBJS = \
	./iff2mathop_objs/iff2mathlib.o \
	./iff2mathop_objs/iff2mathop.o

./iff2mathop: $(OBJS) $(EXTRA_DEPS)
	gcc $(OBJS) -o ./iff2mathop $(LINK_FLAGS)

install: build
	cp ./iff2mathop $(HOME)/bin

clean:
	-@rm -f $(OBJS)
	-@rm -f ./iff2mathop
