// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TDF_AttributeDataMap_HeaderFile
#define _TDF_AttributeDataMap_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMap_HeaderFile
#include <TCollection_BasicMap.hxx>
#endif
#ifndef _Handle_TDF_Attribute_HeaderFile
#include <Handle_TDF_Attribute.hxx>
#endif
#ifndef _Handle_TDF_DataMapNodeOfAttributeDataMap_HeaderFile
#include <Handle_TDF_DataMapNodeOfAttributeDataMap.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
class Standard_DomainError;
class Standard_NoSuchObject;
class TDF_Attribute;
class TColStd_MapTransientHasher;
class TDF_DataMapNodeOfAttributeDataMap;
class TDF_DataMapIteratorOfAttributeDataMap;



class TDF_AttributeDataMap  : public TCollection_BasicMap {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   TDF_AttributeDataMap(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT     TDF_AttributeDataMap& Assign(const TDF_AttributeDataMap& Other) ;
    TDF_AttributeDataMap& operator =(const TDF_AttributeDataMap& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void ReSize(const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT     void Clear() ;
~TDF_AttributeDataMap()
{
  Clear();
}
  
  Standard_EXPORT     Standard_Boolean Bind(const Handle(TDF_Attribute)& K,const Handle(TDF_Attribute)& I) ;
  
  Standard_EXPORT     Standard_Boolean IsBound(const Handle(TDF_Attribute)& K) const;
  
  Standard_EXPORT     Standard_Boolean UnBind(const Handle(TDF_Attribute)& K) ;
  
  Standard_EXPORT    const Handle_TDF_Attribute& Find(const Handle(TDF_Attribute)& K) const;
   const Handle_TDF_Attribute& operator()(const Handle(TDF_Attribute)& K) const
{
  return Find(K);
}
  
  Standard_EXPORT     Handle_TDF_Attribute& ChangeFind(const Handle(TDF_Attribute)& K) ;
    Handle_TDF_Attribute& operator()(const Handle(TDF_Attribute)& K) 
{
  return ChangeFind(K);
}
  
  Standard_EXPORT     Standard_Address Find1(const Handle(TDF_Attribute)& K) const;
  
  Standard_EXPORT     Standard_Address ChangeFind1(const Handle(TDF_Attribute)& K) ;





protected:





private:

  
  Standard_EXPORT   TDF_AttributeDataMap(const TDF_AttributeDataMap& Other);




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
