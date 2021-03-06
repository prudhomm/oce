// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _NLPlate_HGPPConstraint_HeaderFile
#define _NLPlate_HGPPConstraint_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_NLPlate_HGPPConstraint_HeaderFile
#include <Handle_NLPlate_HGPPConstraint.hxx>
#endif

#ifndef _gp_XY_HeaderFile
#include <gp_XY.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class gp_XY;
class gp_XYZ;
class Plate_D1;
class Plate_D2;
class Plate_D3;


//! define a PinPoint geometric Constraint used to load a Non Linear Plate <br>
//! <br>
class NLPlate_HGPPConstraint : public MMgt_TShared {

public:

  
  Standard_EXPORT   virtual  void SetUVFreeSliding(const Standard_Boolean UVFree) ;
  
  Standard_EXPORT   virtual  void SetIncrementalLoadAllowed(const Standard_Boolean ILA) ;
  
  Standard_EXPORT   virtual  void SetActiveOrder(const Standard_Integer ActiveOrder) ;
  
  Standard_EXPORT   virtual  void SetUV(const gp_XY& UV) ;
  
  Standard_EXPORT   virtual  void SetOrientation(const Standard_Integer Orient = 0) ;
  
  Standard_EXPORT   virtual  void SetG0Criterion(const Standard_Real TolDist) ;
  
  Standard_EXPORT   virtual  void SetG1Criterion(const Standard_Real TolAng) ;
  
  Standard_EXPORT   virtual  void SetG2Criterion(const Standard_Real TolCurv) ;
  
  Standard_EXPORT   virtual  void SetG3Criterion(const Standard_Real TolG3) ;
  
  Standard_EXPORT   virtual  Standard_Boolean UVFreeSliding() const;
  
  Standard_EXPORT   virtual  Standard_Boolean IncrementalLoadAllowed() const;
  
  Standard_EXPORT   virtual  Standard_Integer ActiveOrder() const = 0;
  
  Standard_EXPORT   virtual const gp_XY& UV() const;
  
  Standard_EXPORT   virtual  Standard_Integer Orientation() ;
  
  Standard_EXPORT   virtual  Standard_Boolean IsG0() const = 0;
  
  Standard_EXPORT   virtual const gp_XYZ& G0Target() const;
  
  Standard_EXPORT   virtual const Plate_D1& G1Target() const;
  
  Standard_EXPORT   virtual const Plate_D2& G2Target() const;
  
  Standard_EXPORT   virtual const Plate_D3& G3Target() const;
  
  Standard_EXPORT   virtual  Standard_Real G0Criterion() const;
  
  Standard_EXPORT   virtual  Standard_Real G1Criterion() const;
  
  Standard_EXPORT   virtual  Standard_Real G2Criterion() const;
  
  Standard_EXPORT   virtual  Standard_Real G3Criterion() const;




  DEFINE_STANDARD_RTTI(NLPlate_HGPPConstraint)

protected:


gp_XY myUV;
Standard_Integer myActiveOrder;


private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
