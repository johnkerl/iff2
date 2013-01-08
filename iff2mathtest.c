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
