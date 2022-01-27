// ================================================================
// This is an intentionally minimalistic p=2 finite-field library.  For more
// features please see https://github.com/johnkerl/ruffl (Ruby) and
// https://github.com/johnkerl/spffl (C++).  For documentation please see
// http://johnkerl.org/doc/ffcomp.pdf.
//
// The ff2* files use explicit leading bit; the iff2* files use
// implicit leading bit.
//
// John Kerl | 2012-01-04
// ================================================================
// Sample output:
//
// +
// 0 1 2 3 4 5 6 7 8 9 a b c d e f
// 1 0 3 2 5 4 7 6 9 8 b a d c f e
// 2 3 0 1 6 7 4 5 a b 8 9 e f c d
// 3 2 1 0 7 6 5 4 b a 9 8 f e d c
// 4 5 6 7 0 1 2 3 c d e f 8 9 a b
// 5 4 7 6 1 0 3 2 d c f e 9 8 b a
// 6 7 4 5 2 3 0 1 e f c d a b 8 9
// 7 6 5 4 3 2 1 0 f e d c b a 9 8
// 8 9 a b c d e f 0 1 2 3 4 5 6 7
// 9 8 b a d c f e 1 0 3 2 5 4 7 6
// a b 8 9 e f c d 2 3 0 1 6 7 4 5
// b a 9 8 f e d c 3 2 1 0 7 6 5 4
// c d e f 8 9 a b 4 5 6 7 0 1 2 3
// d c f e 9 8 b a 5 4 7 6 1 0 3 2
// e f c d a b 8 9 6 7 4 5 2 3 0 1
// f e d c b a 9 8 7 6 5 4 3 2 1 0
//
// *
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 0 1 2 3 4 5 6 7 8 9 a b c d e f
// 0 2 4 6 8 a c e 3 1 7 5 b 9 f d
// 0 3 6 5 c f a 9 b 8 d e 7 4 1 2
// 0 4 8 c 3 7 b f 6 2 e a 5 1 d 9
// 0 5 a f 7 2 d 8 e b 4 1 9 c 3 6
// 0 6 c a b d 7 1 5 3 9 f e 8 2 4
// 0 7 e 9 f 8 1 6 d a 3 4 2 5 c b
// 0 8 3 b 6 e 5 d c 4 f 7 a 2 9 1
// 0 9 1 8 2 b 3 a 4 d 5 c 6 f 7 e
// 0 a 7 d e 4 9 3 f 5 8 2 1 b 6 c
// 0 b 5 e a 1 f 4 7 c 2 9 d 6 8 3
// 0 c b 7 5 9 e 2 a 6 1 d f 3 4 8
// 0 d 9 4 1 c 8 5 2 f b 6 3 e a 7
// 0 e f 1 d 3 2 c 9 7 6 8 4 a b 5
// 0 f d 2 9 6 4 b 1 e c 3 8 7 5 a
//
// /
//  1 9 e d b 7 6 f 2 c 5 a 4 3 8
//  2 1 f 9 5 e c d 4 b a 7 8 6 3
//  3 8 1 4 e 9 a 2 6 7 f d c 5 b
//  4 2 d 1 a f b 9 8 5 7 e 3 c 6
//  5 b 3 c 1 8 d 6 a 9 2 4 7 f e
//  6 3 2 8 f 1 7 4 c e d 9 b a 5
//  7 a c 5 4 6 1 b e 2 8 3 f 9 d
//  8 4 9 2 7 d 5 1 3 a e f 6 b c
//  9 d 7 f c a 3 e 1 6 b 5 2 8 4
//  a 5 6 b 2 3 9 c 7 1 4 8 e d f
//  b c 8 6 9 4 f 3 5 d 1 2 a e 7
//  c 6 4 3 d 2 e 8 b f 9 1 5 7 a
//  d f a e 6 5 8 7 9 3 c b 1 4 2
//  e 7 b a 8 c 2 5 f 4 3 6 d 1 9
//  f e 5 7 3 b 4 a d 8 6 c 9 2 1
//
// ================================================================

#include <stdio.h>
#include <stdlib.h>
#include "iff2mathlib.h"

// ----------------------------------------------------------------
int main(int argc, char ** argv)
{
	int degr = 4;
	unsigned r = 0x03; // 0x13 since the leading 1 is implicit
	unsigned a, b, c, max;
	int n;

	if (argc == 2)
		(void)sscanf(argv[1], "%x", &r);
	n = degr;
	max = 1 << n;

	printf("+\n");
	for (a = 0; a < max; a++) {
		for (b = 0; b < max; b++) {
			c = a ^ b;
			if (b > 0)
				printf(" ");
			printf("%x", c);
		}
		printf("\n");
	}
	printf("\n");

	printf("*\n");
	for (a = 0; a < max; a++) {
		for (b = 0; b < max; b++) {
			c = iff2mul(a, b, r, degr);
			if (b > 0)
				printf(" ");
			printf("%x", c);
		}
		printf("\n");
	}
	printf("\n");

	printf("/\n");
	for (a = 1; a < max; a++) {
		for (b = 1; b < max; b++) {
			c = iff2div(a, b, r, degr);
			if (b > 0)
				printf(" ");
			printf("%x", c);
		}
		printf("\n");
	}

	return 0;
}
