// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepLib_MakeSolid_HeaderFile
#define _BRepLib_MakeSolid_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopTools_ListOfShape_HeaderFile
#include <TopTools_ListOfShape.hxx>
#endif
#ifndef _BRepLib_MakeShape_HeaderFile
#include <BRepLib_MakeShape.hxx>
#endif
#ifndef _BRepLib_ShapeModification_HeaderFile
#include <BRepLib_ShapeModification.hxx>
#endif
class StdFail_NotDone;
class TopoDS_CompSolid;
class TopoDS_Shell;
class TopoDS_Solid;
class TopoDS_Face;


//! Makes a solid from compsolid  or  shells. <br>
class BRepLib_MakeSolid  : public BRepLib_MakeShape {
public:

  DEFINE_STANDARD_ALLOC

  //! Solid covers whole space. <br>
  Standard_EXPORT   BRepLib_MakeSolid();
  //! Make a solid from a CompSolid. <br>
  Standard_EXPORT   BRepLib_MakeSolid(const TopoDS_CompSolid& S);
  //! Make a solid from a shell. <br>
  Standard_EXPORT   BRepLib_MakeSolid(const TopoDS_Shell& S);
  //! Make a solid from two shells. <br>
  Standard_EXPORT   BRepLib_MakeSolid(const TopoDS_Shell& S1,const TopoDS_Shell& S2);
  //! Make a solid from three shells. <br>
  Standard_EXPORT   BRepLib_MakeSolid(const TopoDS_Shell& S1,const TopoDS_Shell& S2,const TopoDS_Shell& S3);
  //! Make a solid from a solid. Usefull for adding later. <br>
  Standard_EXPORT   BRepLib_MakeSolid(const TopoDS_Solid& So);
  //! Add a shell to a solid. <br>
  Standard_EXPORT   BRepLib_MakeSolid(const TopoDS_Solid& So,const TopoDS_Shell& S);
  //! Add the shell to the current solid. <br>
  Standard_EXPORT     void Add(const TopoDS_Shell& S) ;
  //! Returns the new Solid. <br>
//! <br>
  Standard_EXPORT    const TopoDS_Solid& Solid() const;
Standard_EXPORT operator TopoDS_Solid() const;
  //! returns the status of the Face after <br>
//!          the shape creation. <br>
  Standard_EXPORT   virtual  BRepLib_ShapeModification FaceStatus(const TopoDS_Face& F) const;





protected:



TopTools_ListOfShape myDeletedFaces;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
