// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Storage_Schema_HeaderFile
#define _Storage_Schema_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Storage_Schema_HeaderFile
#include <Handle_Storage_Schema.hxx>
#endif

#ifndef _Storage_MapOfCallBack_HeaderFile
#include <Storage_MapOfCallBack.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Storage_CallBack_HeaderFile
#include <Handle_Storage_CallBack.hxx>
#endif
#ifndef _TCollection_AsciiString_HeaderFile
#include <TCollection_AsciiString.hxx>
#endif
#ifndef _Handle_Storage_HArrayOfSchema_HeaderFile
#include <Handle_Storage_HArrayOfSchema.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Handle_Storage_Data_HeaderFile
#include <Handle_Storage_Data.hxx>
#endif
#ifndef _Handle_Storage_HeaderData_HeaderFile
#include <Handle_Storage_HeaderData.hxx>
#endif
#ifndef _Handle_Storage_TypeData_HeaderFile
#include <Handle_Storage_TypeData.hxx>
#endif
#ifndef _Handle_Storage_RootData_HeaderFile
#include <Handle_Storage_RootData.hxx>
#endif
#ifndef _Handle_TColStd_HSequenceOfAsciiString_HeaderFile
#include <Handle_TColStd_HSequenceOfAsciiString.hxx>
#endif
#ifndef _Handle_Standard_Persistent_HeaderFile
#include <Handle_Standard_Persistent.hxx>
#endif
#ifndef _Storage_SolveMode_HeaderFile
#include <Storage_SolveMode.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
class Storage_CallBack;
class Storage_HArrayOfSchema;
class Storage_StreamFormatError;
class TCollection_AsciiString;
class Storage_BaseDriver;
class Storage_Data;
class Storage_HeaderData;
class Storage_TypeData;
class Storage_RootData;
class TColStd_SequenceOfAsciiString;
class TColStd_HSequenceOfAsciiString;
class Standard_Persistent;



//! Root class for basic storage/retrieval algorithms. <br>
//! A Storage_Schema object processes: <br>
//! -   writing of a set of persistent data into a <br>
//!   container (store mechanism), <br>
//! -   reading of a container to extract all the <br>
//!   contained persistent data (retrieve mechanism). <br>
//! A Storage_Schema object is based on the data <br>
//! schema for the persistent data of the application, i.e.: <br>
//! -   the list of all persistent objects which may be <br>
//!   known by the application, <br>
//! -   the organization of their data; a data schema <br>
//!   knows how to browse each persistent object it contains. <br>
//!   During the store or retrieve operation, only <br>
//! persistent objects known from the data schema <br>
//! can be processed; they are then stored or <br>
//! retrieved according to their description in the schema. <br>
//! A data schema is specific to the object classes to <br>
//! be read or written. Tools dedicated to the <br>
//! environment in use allow a description of the <br>
//! application persistent data structure. <br>
//! Storage_Schema algorithms are called basic <br>
//! because they do not support external references <br>
//! between containers. <br>
class Storage_Schema : public MMgt_TShared {

public:

  //! Builds a storage/retrieval algorithm based on a <br>
//! given data schema. <br>
//! Example <br>
//!   For example, if ShapeSchema is the class <br>
//! inheriting from Storage_Schema and containing <br>
//! the description of your application data schema, <br>
//! you create a storage/retrieval algorithm as follows: <br>
//! Handle(ShapeSchema) s = new <br>
//! ShapeSchema; <br>
//! -------- -- <br>
//! USER API -- -------------------------------------------------------------- <br>
//! -------- -- <br>
  Standard_EXPORT   Storage_Schema();
  //! returns version of the schema <br>
  Standard_EXPORT     void SetVersion(const TCollection_AsciiString& aVersion) ;
  //! returns the version of the schema <br>
  Standard_EXPORT     TCollection_AsciiString Version() const;
  //! set the schema's name <br>
  Standard_EXPORT     void SetName(const TCollection_AsciiString& aSchemaName) ;
  //! returns the schema's name <br>
  Standard_EXPORT     TCollection_AsciiString Name() const;
  //! Writes the data aggregated in aData into the <br>
//! container defined by the driver s. The storage <br>
//! operation is performed according to the data <br>
//! schema with which this algorithm is working. <br>
//! Note: aData may aggregate several root objects <br>
//! to be stored together. <br>
  Standard_EXPORT     void Write(Storage_BaseDriver& s,const Handle(Storage_Data)& aData) const;
  //!  Returns the data read from the container defined <br>
//! by the driver s. The retrieval operation is <br>
//! performed according to the data schema with <br>
//! which this algorithm is working. <br>
//! These data are aggregated in a Storage_Data <br>
//! object which may be browsed in order to extract <br>
//! the root objects from the container. <br>
  Standard_EXPORT     Handle_Storage_Data Read(Storage_BaseDriver& s) const;
  //! read the header part of the stream <br>
//!  Arguments: <br>
//!   s: driver to read <br>
  Standard_EXPORT     Handle_Storage_HeaderData ReadHeaderSection(Storage_BaseDriver& s) const;
  //! fill the TypeData with the  names of the type used <br>
//!          in a stream <br>
//!  Arguments: <br>
//!   s: driver to read <br>
  Standard_EXPORT     Handle_Storage_TypeData ReadTypeSection(Storage_BaseDriver& s) const;
  //! read root part of the file <br>
//!  Arguments: <br>
//!   s: driver to read <br>
  Standard_EXPORT     Handle_Storage_RootData ReadRootSection(Storage_BaseDriver& s) const;
  //! returns the known types of a schema <br>
  Standard_EXPORT   virtual const TColStd_SequenceOfAsciiString& SchemaKnownTypes() const;
  //! indicates whether  the  are  types  in  the driver <br>
//!          which are not known from  the schema and for which <br>
//!          no callbacks have been set. The unknown types can <br>
//!          be read in <theUnknownTypes>. <br>
  Standard_EXPORT     Standard_Boolean HasUnknownType(Storage_BaseDriver& aDriver,TColStd_SequenceOfAsciiString& theUnknownTypes) const;
  //! returns the all known types  of a schema and their <br>
//!          nested schemes. <br>
  Standard_EXPORT     Handle_TColStd_HSequenceOfAsciiString GetAllSchemaKnownTypes() const;
  
  Standard_EXPORT     void SetNestedSchemas(const Handle(Storage_HArrayOfSchema)& theSchemas) ;
  
  Standard_EXPORT     void ClearNestedSchemas() ;
  
  Standard_EXPORT     Handle_Storage_HArrayOfSchema NestedSchemas() const;
  //! return a current date string <br>
  Standard_EXPORT   static  TCollection_AsciiString ICreationDate() ;
  //! returns True if theType migration is identified <br>//! the callback support provides a way to read a file <br>
//!          with a incomplete schema. <br>
//!          ex. : A file contains 3 types a,b and c. <br>
//!                The  application's  schema  contains  only 2 <br>
//!                type a and b. If you try to read the file in <br>
//!                the application, you  will  have an error.To <br>
//!                bypass this  problem  you  can  give to your <br>
//!                application's schema  a  callback  used when <br>
//!                the schema dosent  know  how  to handle this <br>
//!                type. <br>
  Standard_EXPORT   static  Standard_Boolean CheckTypeMigration(const TCollection_AsciiString& theTypeName,TCollection_AsciiString& theNewName) ;
  //! add two functions to the callback list <br>
  Standard_EXPORT     void AddReadUnknownTypeCallBack(const TCollection_AsciiString& aTypeName,const Handle(Storage_CallBack)& aCallBack) ;
  //! remove a callback for a type <br>
  Standard_EXPORT     void RemoveReadUnknownTypeCallBack(const TCollection_AsciiString& aTypeName) ;
  //! returns  a  list  of   type  name  with  installed <br>
//!          callback. <br>
  Standard_EXPORT     Handle_TColStd_HSequenceOfAsciiString InstalledCallBackList() const;
  //! clear all callback from schema instance. <br>
  Standard_EXPORT     void ClearCallBackList() ;
  //! install  a  callback  for  all  unknown  type. the <br>
//!          objects with unknown types  will be skipped. (look <br>
//!          SkipObject method in BaseDriver) <br>
  Standard_EXPORT     void UseDefaultCallBack() ;
  //! tells schema to uninstall the default callback. <br>
  Standard_EXPORT     void DontUseDefaultCallBack() ;
  //! ask if the schema is using the default callback. <br>
  Standard_EXPORT     Standard_Boolean IsUsingDefaultCallBack() const;
  //! overload the  default  function  for build.(use to <br>
//!          set an  error  message  or  skip  an  object while <br>
//!          reading an unknown type). <br>
  Standard_EXPORT     void SetDefaultCallBack(const Handle(Storage_CallBack)& f) ;
  //! reset  the  default  function  defined  by Storage <br>
//!          package. <br>
  Standard_EXPORT     void ResetDefaultCallBack() ;
  //! returns   the   read   function   used   when  the <br>
//!          UseDefaultCallBack() is set. <br>
  Standard_EXPORT     Handle_Storage_CallBack DefaultCallBack() const;
  
  Standard_EXPORT   virtual  Handle_Storage_CallBack CallBackSelection(const TCollection_AsciiString& tName) const;
  
  Standard_EXPORT   virtual  Handle_Storage_CallBack AddTypeSelection(const Handle(Standard_Persistent)& sp) const;
  
        void WritePersistentObjectHeader(const Handle(Standard_Persistent)& sp,Storage_BaseDriver& s) ;
  
        void ReadPersistentObjectHeader(Storage_BaseDriver& s) ;
  
        void WritePersistentReference(const Handle(Standard_Persistent)& sp,Storage_BaseDriver& s) ;
  
  Standard_EXPORT     void ReadPersistentReference(Handle(Standard_Persistent)& sp,Storage_BaseDriver& s) ;
  
  Standard_EXPORT     Standard_Boolean AddPersistent(const Handle(Standard_Persistent)& sp,const Standard_CString tName) const;
  
  Standard_EXPORT     Standard_Boolean PersistentToAdd(const Handle(Standard_Persistent)& sp) const;




  DEFINE_STANDARD_RTTI(Storage_Schema)

protected:

  
  Standard_EXPORT     Standard_Boolean IsNested() const;
  
  Standard_EXPORT     Handle_Storage_CallBack ResolveUnknownType(const TCollection_AsciiString& aTypeName,const Handle(Standard_Persistent)& aPers,const Storage_SolveMode aMode) const;
  
        Standard_Boolean HasTypeBinding(const TCollection_AsciiString& aTypeName) const;
  
  Standard_EXPORT     void BindType(const TCollection_AsciiString& aTypeName,const Handle(Storage_CallBack)& aCallBack) const;
  
  Standard_EXPORT     Handle_Storage_CallBack TypeBinding(const TCollection_AsciiString& aTypeName) const;



private: 

  
  Standard_EXPORT     Standard_Boolean SetNested() ;
  
  Standard_EXPORT     Standard_Boolean UnsetNested() ;
  
  Standard_EXPORT     void Clear() const;
  
  Standard_EXPORT     Standard_Boolean IReadHeaderSection(Storage_BaseDriver& s,const Handle(Storage_HeaderData)& iData) const;
  
  Standard_EXPORT     Standard_Boolean IReadTypeSection(Storage_BaseDriver& s,const Handle(Storage_TypeData)& tData) const;
  
  Standard_EXPORT     Standard_Boolean IReadRootSection(Storage_BaseDriver& s,const Handle(Storage_RootData)& rData) const;
  
  Standard_EXPORT   static  void ISetCurrentData(const Handle(Storage_Data)& dData) ;
  
  Standard_EXPORT   static  Handle_Storage_Data& ICurrentData() ;

Storage_MapOfCallBack myCallBack;
Standard_Boolean myCallBackState;
Handle_Storage_CallBack myDefaultCallBack;
TCollection_AsciiString myName;
TCollection_AsciiString myVersion;
Handle_Storage_HArrayOfSchema myArrayOfSchema;
Standard_Boolean myNestedState;


};


#include <Storage_Schema.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
