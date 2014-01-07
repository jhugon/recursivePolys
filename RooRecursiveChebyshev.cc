/*****************************************************************************
 * RooRecursiveChebyshev
 * Justin Hugon
 *       
 *****************************************************************************/

#include "RooRecursiveChebyshev.h"

Double_t 
RooRecursiveChebyshev::getNextPolyTerm(const & Double_t x, const & Int_t iGet) const;
{
  if (iGet == 0) 
  {
    return 1.;
  }
  if (iGet == 1) 
  {
    return x;
  }
  return 2.*x*_termArr[iGet-1] - _termArr[iGet-2];
};

