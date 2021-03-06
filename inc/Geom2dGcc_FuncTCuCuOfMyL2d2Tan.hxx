// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Geom2dGcc_FuncTCuCuOfMyL2d2Tan_HeaderFile
#define _Geom2dGcc_FuncTCuCuOfMyL2d2Tan_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Geom2dAdaptor_Curve_HeaderFile
#include <Geom2dAdaptor_Curve.hxx>
#endif
#ifndef _gp_Circ2d_HeaderFile
#include <gp_Circ2d.hxx>
#endif
#ifndef _GccIter_Type3_HeaderFile
#include <GccIter_Type3.hxx>
#endif
#ifndef _math_FunctionSetWithDerivatives_HeaderFile
#include <math_FunctionSetWithDerivatives.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_ConstructionError;
class Geom2dAdaptor_Curve;
class Geom2dGcc_CurveTool;
class gp_Circ2d;
class math_Vector;
class gp_Pnt2d;
class gp_Vec2d;
class math_Matrix;



class Geom2dGcc_FuncTCuCuOfMyL2d2Tan  : public math_FunctionSetWithDerivatives {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   Geom2dGcc_FuncTCuCuOfMyL2d2Tan(const Geom2dAdaptor_Curve& Curv1,const Geom2dAdaptor_Curve& Curv2);
  
  Standard_EXPORT   Geom2dGcc_FuncTCuCuOfMyL2d2Tan(const gp_Circ2d& Circ1,const Geom2dAdaptor_Curve& Curv2);
  
  Standard_EXPORT     void InitDerivative(const math_Vector& X,gp_Pnt2d& Point1,gp_Pnt2d& Point2,gp_Vec2d& Tan1,gp_Vec2d& Tan2,gp_Vec2d& D21,gp_Vec2d& D22) ;
  
  Standard_EXPORT     Standard_Integer NbVariables() const;
  
  Standard_EXPORT     Standard_Integer NbEquations() const;
  
  Standard_EXPORT     Standard_Boolean Value(const math_Vector& X,math_Vector& F) ;
  
  Standard_EXPORT     Standard_Boolean Derivatives(const math_Vector& X,math_Matrix& Deriv) ;
  
  Standard_EXPORT     Standard_Boolean Values(const math_Vector& X,math_Vector& F,math_Matrix& Deriv) ;





protected:





private:



Geom2dAdaptor_Curve TheCurve1;
Geom2dAdaptor_Curve TheCurve2;
gp_Circ2d TheCirc1;
GccIter_Type3 TheType;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
