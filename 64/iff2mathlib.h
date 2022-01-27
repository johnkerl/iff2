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

#ifndef IFF2MATHLIB_H
#define IFF2MATHLIB_H

// Same as ff2mathlib, but with implicit leading one on the modulus.

unsigned long long iff2mul(unsigned long long a, unsigned long long b, unsigned long long r, int degr);
// This handles positive powers only.
unsigned long long iff2power(unsigned long long  a, unsigned long long power, unsigned long long r, int degr);
unsigned long long iff2recip(unsigned long long b, unsigned long long r, int degr);
unsigned long long iff2div(unsigned long long a, unsigned long long b, unsigned long long r, int degr);

#endif // IFF2MATHLIB_H
