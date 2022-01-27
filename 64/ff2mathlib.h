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

#ifndef FF2MATHLIB_H
#define FF2MATHLIB_H

unsigned long long f2polydeg(unsigned long long r);
unsigned long long ff2mul(unsigned long long a, unsigned long long b, unsigned long long r);
// This handles positive powers only.
unsigned long long ff2power(unsigned long long  a, unsigned long long power, unsigned long long  r);
unsigned long long ff2recip(unsigned long long b, unsigned long long r);
unsigned long long ff2div(unsigned long long a, unsigned long long b, unsigned long long r);

#endif // FF2MATHLIB_H
