// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GeomFill_LocationGuide_HeaderFile
#define _GeomFill_LocationGuide_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_GeomFill_LocationGuide_HeaderFile
#include <Handle_GeomFill_LocationGuide.hxx>
#endif

#ifndef _Handle_GeomFill_TrihedronWithGuide_HeaderFile
#include <Handle_GeomFill_TrihedronWithGuide.hxx>
#endif
#ifndef _Handle_GeomFill_SectionLaw_HeaderFile
#include <Handle_GeomFill_SectionLaw.hxx>
#endif
#ifndef _Handle_Adaptor3d_HCurve_HeaderFile
#include <Handle_Adaptor3d_HCurve.hxx>
#endif
#ifndef _Handle_TColgp_HArray2OfPnt2d_HeaderFile
#include <Handle_TColgp_HArray2OfPnt2d.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _gp_Mat_HeaderFile
#include <gp_Mat.hxx>
#endif
#ifndef _math_Vector_HeaderFile
#include <math_Vector.hxx>
#endif
#ifndef _GeomFill_PipeError_HeaderFile
#include <GeomFill_PipeError.hxx>
#endif
#ifndef _GeomFill_LocationLaw_HeaderFile
#include <GeomFill_LocationLaw.hxx>
#endif
#ifndef _Handle_GeomFill_LocationLaw_HeaderFile
#include <Handle_GeomFill_LocationLaw.hxx>
#endif
#ifndef _GeomAbs_Shape_HeaderFile
#include <GeomAbs_Shape.hxx>
#endif
#ifndef _Handle_Geom_Curve_HeaderFile
#include <Handle_Geom_Curve.hxx>
#endif
class GeomFill_TrihedronWithGuide;
class GeomFill_SectionLaw;
class Adaptor3d_HCurve;
class TColgp_HArray2OfPnt2d;
class Standard_NotImplemented;
class Standard_ConstructionError;
class Standard_OutOfRange;
class gp_Mat;
class GeomFill_LocationLaw;
class gp_Vec;
class TColgp_Array1OfPnt2d;
class TColgp_Array1OfVec2d;
class TColStd_Array1OfReal;
class gp_Pnt;
class Geom_Curve;



class GeomFill_LocationGuide : public GeomFill_LocationLaw {

public:

  
  Standard_EXPORT   GeomFill_LocationGuide(const Handle(GeomFill_TrihedronWithGuide)& Triedre);
  
  Standard_EXPORT     void Set(const Handle(GeomFill_SectionLaw)& Section,const Standard_Boolean rotat,const Standard_Real SFirst,const Standard_Real SLast,const Standard_Real PrecAngle,Standard_Real& LastAngle) ;
  
  Standard_EXPORT     void EraseRotation() ;
  
  Standard_EXPORT   virtual  void SetCurve(const Handle(Adaptor3d_HCurve)& C) ;
  
  Standard_EXPORT   virtual const Handle_Adaptor3d_HCurve& GetCurve() const;
  
  Standard_EXPORT   virtual  void SetTrsf(const gp_Mat& Transfo) ;
  
  Standard_EXPORT   virtual  Handle_GeomFill_LocationLaw Copy() const;
  //! compute Location <br>
  Standard_EXPORT   virtual  Standard_Boolean D0(const Standard_Real Param,gp_Mat& M,gp_Vec& V) ;
  //! compute Location and 2d points <br>
  Standard_EXPORT   virtual  Standard_Boolean D0(const Standard_Real Param,gp_Mat& M,gp_Vec& V,TColgp_Array1OfPnt2d& Poles2d) ;
  //! compute location 2d  points and  associated <br>
//!          first derivatives. <br>
//!  Warning : It used only for C1 or C2 aproximation <br>
  Standard_EXPORT   virtual  Standard_Boolean D1(const Standard_Real Param,gp_Mat& M,gp_Vec& V,gp_Mat& DM,gp_Vec& DV,TColgp_Array1OfPnt2d& Poles2d,TColgp_Array1OfVec2d& DPoles2d) ;
  //! compute location 2d  points and associated <br>
//!          first and seconde  derivatives. <br>
//!  Warning : It used only for C2 aproximation <br>
  Standard_EXPORT   virtual  Standard_Boolean D2(const Standard_Real Param,gp_Mat& M,gp_Vec& V,gp_Mat& DM,gp_Vec& DV,gp_Mat& D2M,gp_Vec& D2V,TColgp_Array1OfPnt2d& Poles2d,TColgp_Array1OfVec2d& DPoles2d,TColgp_Array1OfVec2d& D2Poles2d) ;
  //! Say if the first restriction is defined in this class. <br>
//!           If it  is true the  first element  of poles array   in <br>
//!          D0,D1,D2... Correspond to this restriction. <br>
//!  Returns Standard_False (default implementation) <br>
  Standard_EXPORT   virtual  Standard_Boolean HasFirstRestriction() const;
  //! Say if the last restriction is defined in this class. <br>
//!           If it is  true the  last element  of poles array in <br>
//!          D0,D1,D2... Correspond to this restriction. <br>
//!          Returns Standard_False (default implementation) <br>
  Standard_EXPORT   virtual  Standard_Boolean HasLastRestriction() const;
  //! Give the number of trace (Curves 2d wich are not restriction) <br>
//!          Returns 1 (default implementation) <br>
  Standard_EXPORT   virtual  Standard_Integer TraceNumber() const;
  //!Give a status to the Law <br>
//!          Returns PipeOk (default implementation) <br>
  Standard_EXPORT   virtual  GeomFill_PipeError ErrorStatus() const;
  //! Returns  the number  of  intervals for  continuity <br>
//!          <S>. <br>
//!          May be one if Continuity(me) >= <S> <br>
  Standard_EXPORT   virtual  Standard_Integer NbIntervals(const GeomAbs_Shape S) const;
  //! Stores in <T> the  parameters bounding the intervals <br>
//!          of continuity <S>. <br>
//! <br>
//!          The array must provide  enough room to  accomodate <br>
//!          for the parameters. i.e. T.Length() > NbIntervals() <br>
  Standard_EXPORT   virtual  void Intervals(TColStd_Array1OfReal& T,const GeomAbs_Shape S) const;
  //! Sets the bounds of the parametric interval on <br>
//!          the function <br>
//!          This determines the derivatives in these values if the <br>
//!          function is not Cn. <br>
  Standard_EXPORT   virtual  void SetInterval(const Standard_Real First,const Standard_Real Last) ;
  //! Gets the bounds of the parametric interval on <br>
//!          the function <br>
  Standard_EXPORT   virtual  void GetInterval(Standard_Real& First,Standard_Real& Last) const;
  //! Gets the bounds of the function parametric domain. <br>
//!  Warning: This domain it is  not modified by the <br>
//!          SetValue method <br>
  Standard_EXPORT   virtual  void GetDomain(Standard_Real& First,Standard_Real& Last) const;
  //! Is usefull, if (me) have to run numerical <br>
//!          algorithm to perform D0, D1 or D2 <br>
//! The default implementation make nothing. <br>
  Standard_EXPORT   virtual  void SetTolerance(const Standard_Real Tol3d,const Standard_Real Tol2d) ;
  //! Returns the resolutions in the  sub-space 2d <Index> <br>
//!          This information is usfull to find an good tolerance in <br>
//!          2d approximation. <br>
//!  Warning: Used only if Nb2dCurve > 0 <br>
  Standard_EXPORT   virtual  void Resolution(const Standard_Integer Index,const Standard_Real Tol,Standard_Real& TolU,Standard_Real& TolV) const;
  //!  Get the maximum Norm  of the matrix-location part.  It <br>
//!           is usful to find an good Tolerance to approx M(t). <br>
  Standard_EXPORT   virtual  Standard_Real GetMaximalNorm() ;
  //! Get average value of M(t) and V(t) it is usfull to <br>
//!          make fast approximation of rational  surfaces. <br>
  Standard_EXPORT   virtual  void GetAverageLaw(gp_Mat& AM,gp_Vec& AV) ;
  //! Say if the Location  Law, is an translation of  Location <br>
//! The default implementation is " returns False ". <br>
  Standard_EXPORT   virtual  Standard_Boolean IsTranslation(Standard_Real& Error) const;
  //! Say if the Location  Law, is a rotation of Location <br>
//! The default implementation is " returns False ". <br>
  Standard_EXPORT   virtual  Standard_Boolean IsRotation(Standard_Real& Error) const;
  
  Standard_EXPORT   virtual  void Rotation(gp_Pnt& Center) const;
  
  Standard_EXPORT     Handle_Geom_Curve Section() const;
  
  Standard_EXPORT     Handle_Adaptor3d_HCurve Guide() const;
  
  Standard_EXPORT     void SetOrigine(const Standard_Real Param1,const Standard_Real Param2) ;




  DEFINE_STANDARD_RTTI(GeomFill_LocationGuide)

protected:


Handle_TColgp_HArray2OfPnt2d myPoles2d;


private: 

  
  Standard_EXPORT     void SetRotation(const Standard_Real PrecAngle,Standard_Real& LastAngle) ;
  
  Standard_EXPORT     void InitX(const Standard_Real Param) const;

Handle_GeomFill_TrihedronWithGuide myLaw;
Handle_GeomFill_SectionLaw mySec;
Handle_Adaptor3d_HCurve myCurve;
Handle_Adaptor3d_HCurve myGuide;
Handle_Adaptor3d_HCurve myTrimmed;
Standard_Integer myNbPts;
Standard_Boolean rotation;
Standard_Real OrigParam1;
Standard_Real OrigParam2;
Standard_Real Uf;
Standard_Real Ul;
Standard_Real myFirstS;
Standard_Real myLastS;
Standard_Real ratio;
Standard_Boolean WithTrans;
gp_Mat Trans;
math_Vector TolRes;
math_Vector Inf;
math_Vector Sup;
math_Vector X;
math_Vector R;
GeomFill_PipeError myStatus;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif