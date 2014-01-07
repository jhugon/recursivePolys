/*****************************************************************************
 * RooRecursiveChebyshev
 * Justin Hugon
 *       
 *****************************************************************************/
#ifndef RooRecursiveChebyshev_h
#define RooRecursiveChebyshev_h

#include "RooRecursivePolyBase.h"

class RooRecursiveChebyshev : public RooRecursivePolyBase {

protected:

  Double_t evalPureFunc(const & Double_t x, const & RooListProxy coefList, const & Int_t kCurr, const & Int_t kGoal, const & Double_t evalCurr, const & Double_t evalLast ) const {return -1.};

public:
  
  RooRecursiveChebyshev(const char *name, const char *title,
              RooAbsReal& x, const RooArgList& coefList) :
  RooRecursivePolyBase(name, title,x,coefList),
  {
    _order = coefList.getSize();
    _xFuncMax =  1.;
    _xFuncMin = -1.;
  }                
  
  
  ClassDef(RooRecursiveChebyshev,1) // Polynomial PDF
};

#endif
