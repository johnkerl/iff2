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
#include "ff2mathlib.h"

// ----------------------------------------------------------------
int main(int argc, char ** argv)
{
	unsigned long long r = 0x13, a = 0x0a, b = 0x0b;

	if (argc == 4) {
		(void)sscanf(argv[1], "%llx", &a);
		(void)sscanf(argv[2], "%llx", &b);
		(void)sscanf(argv[3], "%llx", &r);
	}

	printf("sum  %llx\n", a ^ b);
	printf("prod %llx\n", ff2mul(a, b, r));
	printf("quot %llx\n", ff2div(a, b, r));

	return 0;
}
