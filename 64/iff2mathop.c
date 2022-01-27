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
	unsigned long long r = 0x03, a = 0x0a, b = 0x0b;
	int degr = 4;

	if (argc == 5) {
		(void)sscanf(argv[1], "%llx", &a);
		(void)sscanf(argv[2], "%llx", &b);
		(void)sscanf(argv[3], "%llx", &r);
		(void)sscanf(argv[4], "%d", &degr);
	}

	printf("%llx + %llx = %llx\n", a, b, a ^ b);
	printf("%llx * %llx = %llx\n", a, b, iff2mul(a, b, r, degr));
	printf("%llx / %llx = %llx\n", a, b, iff2div(a, b, r, degr));

	return 0;
}
