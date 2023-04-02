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
	unsigned long long r = 0x0b, g = 0x02;
	int degr = 4;

	if (argc == 4) {
		(void)sscanf(argv[1], "%llx", &g);
		(void)sscanf(argv[2], "%llx", &r);
		(void)sscanf(argv[3], "%d", &degr);
	}

	unsigned long long a = g;
	for (int i = 0; i < 1000; i++) {
		printf("%llx\n", a);
		a = iff2mul(a, g, r, degr);
	}

	return 0;
}
