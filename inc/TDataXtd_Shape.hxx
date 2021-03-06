// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TDataXtd_Shape_HeaderFile
#define _TDataXtd_Shape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_TDataXtd_Shape_HeaderFile
#include <Handle_TDataXtd_Shape.hxx>
#endif

#ifndef _TDF_Attribute_HeaderFile
#include <TDF_Attribute.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_TDF_Attribute_HeaderFile
#include <Handle_TDF_Attribute.hxx>
#endif
#ifndef _Handle_TDF_RelocationTable_HeaderFile
#include <Handle_TDF_RelocationTable.hxx>
#endif
#ifndef _Handle_TDF_DataSet_HeaderFile
#include <Handle_TDF_DataSet.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
class TDF_Label;
class TopoDS_Shape;
class Standard_GUID;
class TDF_Attribute;
class TDF_RelocationTable;
class TDF_DataSet;


//! A Shape is associated in the framework with : <br>
//!          a NamedShape attribute <br>
class TDataXtd_Shape : public TDF_Attribute {

public:

  //! class methods <br>
//!          ============= <br>//! try to retrieve a Shape attribute at <current> label <br>
//!           or in  fathers  label of  <current>. Returns True  if <br>
//!          found and set <S>. <br>
  Standard_EXPORT   static  Standard_Boolean Find(const TDF_Label& current,Handle(TDataXtd_Shape)& S) ;
  //! Find, or create, a Shape attribute.  the Shape attribute <br>
//!          is returned. Raises if <label> has attribute. <br>
  Standard_EXPORT   static  Handle_TDataXtd_Shape New(const TDF_Label& label) ;
  //! Create or update associated NamedShape attribute.  the <br>
//!          Shape attribute is returned. <br>
  Standard_EXPORT   static  Handle_TDataXtd_Shape Set(const TDF_Label& label,const TopoDS_Shape& shape) ;
  //!   the Shape from  associated NamedShape attribute <br>
//!            is returned. <br>
  Standard_EXPORT   static  TopoDS_Shape Get(const TDF_Label& label) ;
  //! Shape methods <br>
//!          ============ <br>
  Standard_EXPORT   static const Standard_GUID& GetID() ;
  
  Standard_EXPORT   TDataXtd_Shape();
  
  Standard_EXPORT    const Standard_GUID& ID() const;
  
  Standard_EXPORT     void Restore(const Handle(TDF_Attribute)& with) ;
  
  Standard_EXPORT     Handle_TDF_Attribute NewEmpty() const;
  
  Standard_EXPORT     void Paste(const Handle(TDF_Attribute)& into,const Handle(TDF_RelocationTable)& RT) const;
  
  Standard_EXPORT   virtual  void References(const Handle(TDF_DataSet)& DS) const;
  
  Standard_EXPORT   virtual  Standard_OStream& Dump(Standard_OStream& anOS) const;




  DEFINE_STANDARD_RTTI(TDataXtd_Shape)

protected:




private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
