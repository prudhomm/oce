// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeCustom_Curve_HeaderFile
#define _ShapeCustom_Curve_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_Geom_Curve_HeaderFile
#include <Handle_Geom_Curve.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class Geom_Curve;


//! Converts BSpline curve to periodic <br>
class ShapeCustom_Curve  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   ShapeCustom_Curve();
  
  Standard_EXPORT   ShapeCustom_Curve(const Handle(Geom_Curve)& C);
  
  Standard_EXPORT     void Init(const Handle(Geom_Curve)& C) ;
  //! Tries to convert the Curve to the Periodic form <br>
//!          Returns the resulting curve <br>
//!          Works only if the Curve is BSpline and is closed with <br>
//!          Precision::Confusion() <br>
//!          Else, or in case of failure, returns a Null Handle <br>
  Standard_EXPORT     Handle_Geom_Curve ConvertToPeriodic(const Standard_Boolean substitute,const Standard_Real preci = -1) ;





protected:





private:



Handle_Geom_Curve myCurve;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
