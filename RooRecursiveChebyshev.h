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

  Double_t getNextPolyTerm(const Double_t& x, const Int_t& iGet, const std::vector<Double_t> termArr) const;

public:
  
  RooRecursiveChebyshev(const char *name, const char *title,
              RooAbsReal& x, const RooArgList& coefList) :
                RooRecursivePolyBase(name, title,x,coefList)
  {
    _xFuncMax =  1.;
    _xFuncMin = -1.;
  }                
  
  
  ClassDef(RooRecursiveChebyshev,1) // Polynomial PDF
};

#endif
