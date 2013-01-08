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

unsigned iff2mul(unsigned a, unsigned b, unsigned r, int degr);
// This handles positive powers only.
unsigned iff2power(unsigned  a, unsigned power, unsigned r, int degr);
unsigned iff2recip(unsigned b, unsigned r, int degr);
unsigned iff2div(unsigned a, unsigned b, unsigned r, int degr);

#endif // IFF2MATHLIB_H
