// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESToBRep_TopoCurve_HeaderFile
#define _IGESToBRep_TopoCurve_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TColGeom_SequenceOfCurve_HeaderFile
#include <TColGeom_SequenceOfCurve.hxx>
#endif
#ifndef _TColGeom2d_SequenceOfCurve_HeaderFile
#include <TColGeom2d_SequenceOfCurve.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _IGESToBRep_CurveAndSurface_HeaderFile
#include <IGESToBRep_CurveAndSurface.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_IGESData_IGESEntity_HeaderFile
#include <Handle_IGESData_IGESEntity.hxx>
#endif
#ifndef _Handle_IGESGeom_Point_HeaderFile
#include <Handle_IGESGeom_Point.hxx>
#endif
#ifndef _Handle_IGESGeom_CompositeCurve_HeaderFile
#include <Handle_IGESGeom_CompositeCurve.hxx>
#endif
#ifndef _Handle_IGESGeom_OffsetCurve_HeaderFile
#include <Handle_IGESGeom_OffsetCurve.hxx>
#endif
#ifndef _Handle_IGESGeom_CurveOnSurface_HeaderFile
#include <Handle_IGESGeom_CurveOnSurface.hxx>
#endif
#ifndef _Handle_IGESGeom_Boundary_HeaderFile
#include <Handle_IGESGeom_Boundary.hxx>
#endif
#ifndef _Handle_Geom_BSplineCurve_HeaderFile
#include <Handle_Geom_BSplineCurve.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Geom_Curve_HeaderFile
#include <Handle_Geom_Curve.hxx>
#endif
#ifndef _Handle_Geom2d_BSplineCurve_HeaderFile
#include <Handle_Geom2d_BSplineCurve.hxx>
#endif
#ifndef _Handle_Geom2d_Curve_HeaderFile
#include <Handle_Geom2d_Curve.hxx>
#endif
class IGESToBRep_CurveAndSurface;
class TopoDS_Shape;
class IGESData_IGESEntity;
class TopoDS_Face;
class gp_Trsf2d;
class TopoDS_Vertex;
class IGESGeom_Point;
class IGESGeom_CompositeCurve;
class IGESGeom_OffsetCurve;
class IGESGeom_CurveOnSurface;
class IGESGeom_Boundary;
class Geom_BSplineCurve;
class Geom_Curve;
class Geom2d_BSplineCurve;
class Geom2d_Curve;


//! Provides methods to transfer topologic curves entities <br>
//!           from IGES to CASCADE. <br>
class IGESToBRep_TopoCurve  : public IGESToBRep_CurveAndSurface {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  //! Creates  a tool TopoCurve  ready  to  run, with <br>
//!           epsilons  set  to  1.E-04,  TheModeTopo  to  True,  the <br>
//!           optimization of  the continuity to False. <br>
  Standard_EXPORT   IGESToBRep_TopoCurve();
  //! Creates a tool TopoCurve ready to run and sets its <br>
//!           fields as CS's. <br>
  Standard_EXPORT   IGESToBRep_TopoCurve(const IGESToBRep_CurveAndSurface& CS);
  //! Creates a tool TopoCurve ready to run and sets its <br>
//!           fields as CS's. <br>
  Standard_EXPORT   IGESToBRep_TopoCurve(const IGESToBRep_TopoCurve& CS);
  //! Creates a tool TopoCurve ready to run. <br>
  Standard_EXPORT   IGESToBRep_TopoCurve(const Standard_Real eps,const Standard_Real epsGeom,const Standard_Real epsCoeff,const Standard_Boolean mode,const Standard_Boolean modeapprox,const Standard_Boolean optimized);
  
  Standard_EXPORT     TopoDS_Shape TransferTopoCurve(const Handle(IGESData_IGESEntity)& start) ;
  
  Standard_EXPORT     TopoDS_Shape Transfer2dTopoCurve(const Handle(IGESData_IGESEntity)& start,const TopoDS_Face& face,const gp_Trsf2d& trans,const Standard_Real uFact) ;
  
  Standard_EXPORT     TopoDS_Shape TransferTopoBasicCurve(const Handle(IGESData_IGESEntity)& start) ;
  
  Standard_EXPORT     TopoDS_Shape Transfer2dTopoBasicCurve(const Handle(IGESData_IGESEntity)& start,const TopoDS_Face& face,const gp_Trsf2d& trans,const Standard_Real uFact) ;
  
  Standard_EXPORT     TopoDS_Vertex TransferPoint(const Handle(IGESGeom_Point)& start) ;
  
  Standard_EXPORT     TopoDS_Vertex Transfer2dPoint(const Handle(IGESGeom_Point)& start) ;
  
  Standard_EXPORT     TopoDS_Shape TransferCompositeCurve(const Handle(IGESGeom_CompositeCurve)& start) ;
  
  Standard_EXPORT     TopoDS_Shape Transfer2dCompositeCurve(const Handle(IGESGeom_CompositeCurve)& start,const TopoDS_Face& face,const gp_Trsf2d& trans,const Standard_Real uFact) ;
  
  Standard_EXPORT     TopoDS_Shape TransferOffsetCurve(const Handle(IGESGeom_OffsetCurve)& start) ;
  
  Standard_EXPORT     TopoDS_Shape Transfer2dOffsetCurve(const Handle(IGESGeom_OffsetCurve)& start,const TopoDS_Face& face,const gp_Trsf2d& trans,const Standard_Real uFact) ;
  
  Standard_EXPORT     TopoDS_Shape TransferCurveOnSurface(const Handle(IGESGeom_CurveOnSurface)& start) ;
  //! Transfers a CurveOnSurface directly on a face to trim it. <br>
//!           The CurveOnSurface have to be defined Outer or Inner. <br>
  Standard_EXPORT     TopoDS_Shape TransferCurveOnFace(TopoDS_Face& face,const Handle(IGESGeom_CurveOnSurface)& start,const gp_Trsf2d& trans,const Standard_Real uFact,const Standard_Boolean IsCurv) ;
  
  Standard_EXPORT     TopoDS_Shape TransferBoundary(const Handle(IGESGeom_Boundary)& start) ;
  //! Transfers a Boundary directly on a face to trim it. <br>
  Standard_EXPORT     TopoDS_Shape TransferBoundaryOnFace(TopoDS_Face& face,const Handle(IGESGeom_Boundary)& start,const gp_Trsf2d& trans,const Standard_Real uFact) ;
  
  Standard_EXPORT     void ApproxBSplineCurve(const Handle(Geom_BSplineCurve)& start) ;
  //! Returns the count of Curves in "TheCurves" <br>
  Standard_EXPORT     Standard_Integer NbCurves() const;
  //! Returns a Curve given its rank, by default the first one <br>
//!           (null Curvee if out of range) in "TheCurves" <br>
  Standard_EXPORT     Handle_Geom_Curve Curve(const Standard_Integer num = 1) const;
  
  Standard_EXPORT     void Approx2dBSplineCurve(const Handle(Geom2d_BSplineCurve)& start) ;
  //! Returns the count of Curves in "TheCurves2d" <br>
  Standard_EXPORT     Standard_Integer NbCurves2d() const;
  //! Returns a Curve given its rank, by default the first one <br>
//!           (null Curvee if out of range) in "TheCurves2d" <br>
  Standard_EXPORT     Handle_Geom2d_Curve Curve2d(const Standard_Integer num = 1) const;
  //! Sets TheBadCase flag <br>
  Standard_EXPORT     void SetBadCase(const Standard_Boolean value) ;
  //! Returns TheBadCase flag <br>
  Standard_EXPORT     Standard_Boolean BadCase() const;





protected:





private:

  
  Standard_EXPORT     TopoDS_Shape TransferCompositeCurveGeneral(const Handle(IGESGeom_CompositeCurve)& start,const Standard_Boolean is2d,const TopoDS_Face& face,const gp_Trsf2d& trans,const Standard_Real uFact) ;


TColGeom_SequenceOfCurve TheCurves;
TColGeom2d_SequenceOfCurve TheCurves2d;
Standard_Boolean TheBadCase;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif