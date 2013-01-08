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

unsigned f2polydeg(unsigned r)
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

unsigned ff2mul(unsigned a, unsigned b, unsigned r)
{
	int degb = f2polydeg(b);
	int degr = f2polydeg(r);
	unsigned bit_at_degr = 1 << degr;
	unsigned prod = 0;
	unsigned temp;
	int i, power;

	for (i = 0; i <= degb; i++) {
		// Test if this bit position is set.
		if (!((b >> i) & 1))
			continue;

		// Now multiply by the power of x on the current term
		// of b, reducing mod r en rprod.
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
unsigned ff2power(unsigned  a, unsigned power, unsigned  r)
{
	unsigned a2 = a;
	unsigned out = 1;

	while (power != 0) {
		if (power & 1) // Test current bit
			out = ff2mul(out, a2, r);
		power = power >> 1; // Shift
		a2 = ff2mul(a2, a2, r);
	}
	return out;
}

unsigned ff2recip(unsigned b, unsigned r)
{
	int n = f2polydeg(r);
	unsigned pn2 = (1 << n) - 2;
	return ff2power(b, pn2, r);
}

unsigned ff2div(unsigned a, unsigned b, unsigned r)
{
	unsigned binv;
	binv = ff2recip(b, r);
	return ff2mul(a, binv, r);
}
