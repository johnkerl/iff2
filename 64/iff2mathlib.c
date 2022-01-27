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

static unsigned long long f2polydeg(unsigned long long b)
{
	int d = 0;
	if (b == 0) {
		return 0;
		// Or, treat this as an error condition, depending on
		// how you want to handle the degree of the zero polynomial.
		// For my purposes, it suffices to assign it degree zero, just
		// like all the other constant polynomials.
	}
	while (b >>= 1)
		d++;
	return d;
}

unsigned long long iff2mul(unsigned long long a, unsigned long long b, unsigned long long r, int degr)
{
	int degb = f2polydeg(b);
	unsigned long long bit_before_degr = 1 << (degr-1);
	unsigned long long prod = 0;
	unsigned long long temp;
	int i, power;

	for (i = 0; i <= degb; i++) {
		// Test if this bit position is set.
		if (!((b >> i) & 1))
			continue;

		// Now multiply by the power of x on the current term
		// of b, reducing mod r en route.
		temp = a;
		for (power = 1; power <= i; power++) {
			if (temp & bit_before_degr) {
				temp ^= bit_before_degr;
				temp <<= 1;
				temp ^= r;
			}
			else {
				temp <<= 1;
			}
		}
		// Add in this partial product.
		prod ^= temp;
	}

	return prod;
}

// Repeated-squaring algorithm.  This handles positive powers only.
unsigned long long iff2power(unsigned long long  a, unsigned long long power, unsigned long long  r, unsigned long long degr)
{
	unsigned long long a2 = a;
	unsigned long long out = 1;

	while (power != 0) {
		if (power & 1) // Test current bit
			out = iff2mul(out, a2, r, degr);
		power = power >> 1; // Shift
		a2 = iff2mul(a2, a2, r, degr);
	}
	return out;
}

unsigned long long iff2recip(unsigned long long b, unsigned long long r, int degr)
{
	unsigned long long pn2 = (degr == 32) ? -2 : (1 << degr) - 2;
	return iff2power(b, pn2, r, degr);
}

unsigned long long iff2div(unsigned long long a, unsigned long long b, unsigned long long r, int degr)
{
	unsigned long long binv;
	binv = iff2recip(b, r, degr);
	return iff2mul(a, binv, r, degr);
}
