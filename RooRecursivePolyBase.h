/*****************************************************************************
 * RooRecursivePolyBase
 * Justin Hugon
 * Base class for recursive RooAbsPdf's
 *       
 *****************************************************************************/
#ifndef RooRecursivePolyBase_h
#define RooRecursivePolyBase_h

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooListProxy.h"
#include "RooChangeTracker.h"
#include "TMath.h"

class RooRealVar;
class RooArgList;

class RooRecursivePolyBase : public RooAbsPdf {

protected:

  RooRealProxy _x;
  RooListProxy _coefList;
  Int_t _order;
  Double_t _xFuncMax;
  Double_t _xFuncMin;

  Double_t evalPureFunc(const & Double_t x, const & RooListProxy coefList, const & Int_t kCurr, const & Int_t kGoal, const & Double_t evalCurr, const & Double_t evalLast ) const {return -1.};
  
  Double_t evaluate() const
  {

    Double_t xScaleFactor = (xFuncMax - xFuncMin) / (_x.max()-_x.min());
    Double_t xScaled = (_x - (_x.min()-_xFuncMin)) / xScaleFactor;

    Double_t result = evalPureFunc(xScaled,_coefList,2,_order,xScaled,1.);
    return result;
  };

public:
  
  RooRecursivePolyBase() {}
  
  RooRecursivePolyBase(const char *name, const char *title,
              RooAbsReal& x, const RooArgList& coefList) :
  RooAbsPdf(name, title),
  _x("x", "Dependent", this, x),
  _coefList("coefList","List of coefficients",this),
  _order(-1),
  _xFuncMax(0.),
  _xFuncMin(0.)
  {
    _coefList.add(coefList);
    
  }                
                

  RooRecursivePolyBase(const RooRecursivePolyBase& other, const char* name = 0) :
    RooAbsPdf(other, name), 
  _x("x", this, other._x), 
  _coefList("coefList",this,other._coefList),
  _order(other._order),
  _xFuncMax(order._xFuncMax),
  _xFuncMin(order._xFuncMin) {}
  
  
  virtual TObject* clone(const char* newname) const { return new RooRecursivePolyBase(*this, newname); }
  virtual ~RooRecursivePolyBase() { }
  
  ClassDef(RooRecursivePolyBase,1) // Polynomial PDF
};

#endif
