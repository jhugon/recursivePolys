/*****************************************************************************
 * RooRecursivePolyBase
 * Justin Hugon
 * Base class for recursive RooAbsPdf's
 *       
 * In a subclass, you must define a constructor with the limits of the
 * polynomial domain: _xFuncMax and  _xFuncMin(0.)
 * You must also define getNextPolyTerm(x,iGet) using a recurrance relation.
 *****************************************************************************/
#ifndef RooRecursivePolyBase_h
#define RooRecursivePolyBase_h

#include <vector>
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
  std::vector<Double_t> _termArr;

  // Const function that finds the term at value of the polynomial
  // term iGet using only terms < iGet.  Usually you set the lowest
  // term values manually.
  Double_t getNextPolyTerm(const & Double_t x, const & Int_t iGet) const {return -1.};
  
  Double_t evaluate() const
  {
    Double_t xScaleFactor = (xFuncMax - xFuncMin) / (_x.max()-_x.min());
    Double_t xScaled = (_x - (_x.min()-_xFuncMin)) / xScaleFactor;
    Double_t result = 0.;

    for (Int_t iTerm = 0; iTerm < _order; iTerm++)
    {
      _termArr[iTerm] = evalPureFunc(xScaled,iTerm);

      //result += _termArr[iTerm] * static_cast<RooAbsReal*>(_coefList.at(iTerm))->getVal();
      Double_t thisTermVal = _termArr[iTerm] ;
      Double_t thisCoefVal =  static_cast<RooAbsReal*>(_coefList.at(iTerm))->getVal();
      result += thisTermVal*thisCoefVal;
    }

    return result;
  };

public:
  
  RooRecursivePolyBase() {}
  
  RooRecursivePolyBase(const char *name, const char *title,
              RooAbsReal& x, const RooArgList& coefList) :
  RooAbsPdf(name, title),
  _x("x", "Dependent", this, x),
  _coefList("coefList","List of coefficients",this),
  _termArr(coefList.getSize());
  _order(coefList.getSize()),
  _xFuncMax(0.),
  _xFuncMin(0.)
  {
    _coefList.add(coefList);
    
  }                
                

  RooRecursivePolyBase(const RooRecursivePolyBase& other, const char* name = 0) :
    RooAbsPdf(other, name), 
  _x("x", this, other._x), 
  _coefList("coefList",this,other._coefList),
  _termArr(other._termArr);
  _order(other._order),
  _xFuncMax(order._xFuncMax),
  _xFuncMin(order._xFuncMin) {}
  
  
  virtual TObject* clone(const char* newname) const { return new RooRecursivePolyBase(*this, newname); }
  virtual ~RooRecursivePolyBase() { }
  
  ClassDef(RooRecursivePolyBase,1) // Polynomial PDF
};

#endif
