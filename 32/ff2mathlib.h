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

unsigned f2polydeg(unsigned r);
unsigned ff2mul(unsigned a, unsigned b, unsigned r);
// This handles positive powers only.
unsigned ff2power(unsigned  a, unsigned power, unsigned  r);
unsigned ff2recip(unsigned b, unsigned r);
unsigned ff2div(unsigned a, unsigned b, unsigned r);

#endif // FF2MATHLIB_H
