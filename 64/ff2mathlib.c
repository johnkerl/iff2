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

unsigned long long f2polydeg(unsigned long long r)
{
	int d = 0;
	if (r == 0) {
		return 0;
		// Or, treat this as an error condition, depending on
		// how you want to handle the degree of the zero polynomial.
		// For my purposes, it suffices to assign it degree zero, just
		// like all the other constant polynomials.
	}
	while (r >>= 1)
		d++;
	return d;
}

unsigned long long ff2mul(unsigned long long a, unsigned long long b, unsigned long long r)
{
	int degb = f2polydeg(b);
	int degr = f2polydeg(r);
	unsigned long long bit_at_degr = 1 << degr;
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
			temp <<= 1;
			if (temp & bit_at_degr)
				temp ^= r;
		}
		// Add in this partial product.
		prod ^= temp;
	}

	return prod;
}

// Repeated-squaring algorithm.  This handles positive powers only.
unsigned long long ff2power(unsigned long long  a, unsigned long long power, unsigned long long  r)
{
	unsigned long long a2 = a;
	unsigned long long out = 1;

	while (power != 0) {
		if (power & 1) // Test current bit
			out = ff2mul(out, a2, r);
		power = power >> 1; // Shift
		a2 = ff2mul(a2, a2, r);
	}
	return out;
}

unsigned long long ff2recip(unsigned long long b, unsigned long long r)
{
	int n = f2polydeg(r);
	unsigned long long pn2 = (1 << n) - 2;
	return ff2power(b, pn2, r);
}

unsigned long long ff2div(unsigned long long a, unsigned long long b, unsigned long long r)
{
	unsigned long long binv;
	binv = ff2recip(b, r);
	return ff2mul(a, binv, r);
}
