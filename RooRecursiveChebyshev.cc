/*****************************************************************************
 * RooRecursiveChebyshev
 * Justin Hugon
 *       
 *****************************************************************************/

#include "RooRecursiveChebyshev.h"

Double_t 
RooRecursiveChebyshev::getNextPolyTerm(const Double_t& x, const Int_t& iGet, const std::vector<Double_t> termArr) const
{
  if (iGet == 0) 
  {
    return 1.;
  }
  if (iGet == 1) 
  {
    return x;
  }
  return 2. * x * termArr[iGet-1] - termArr[iGet-2];
}


ClassImp(RooRecursiveChebyshev)
