/*****************************************************************************
 * RooRecursiveChebyshev
 * Justin Hugon
 *       
 *****************************************************************************/

#include "RooRecursiveChebyshev.h"

Double_t 
RooRecursiveChebyshev::evalPureFunc(const & Double_t x, const & RooListProxy coefList, const & Int_t kCurr, const & Int_t kGoal, const & Double_t evalCurr, const & Double_t evalLast ) const 
{
  if (kGoal == 0) {return 1.;};
  if (kGoal == 1) {return x;};

  // Wrong!
  return 2.*x*evalPureFunc(x,coefList,kCurr,kGoal,evalCurr,evalLast) - evalPureFunc(x,coefList,kCurr,kGoal,evalCurr,evalLast);
};

