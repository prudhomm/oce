// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepRepr_AssemblyComponentUsageSubstitute_HeaderFile
#define _StepRepr_AssemblyComponentUsageSubstitute_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepRepr_AssemblyComponentUsageSubstitute_HeaderFile
#include <Handle_StepRepr_AssemblyComponentUsageSubstitute.hxx>
#endif

#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Handle_StepRepr_AssemblyComponentUsage_HeaderFile
#include <Handle_StepRepr_AssemblyComponentUsage.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
class TCollection_HAsciiString;
class StepRepr_AssemblyComponentUsage;



class StepRepr_AssemblyComponentUsageSubstitute : public MMgt_TShared {

public:

  
  Standard_EXPORT   StepRepr_AssemblyComponentUsageSubstitute();
  
  Standard_EXPORT     void Init(const Handle(TCollection_HAsciiString)& aName,const Handle(TCollection_HAsciiString)& aDef,const Handle(StepRepr_AssemblyComponentUsage)& aBase,const Handle(StepRepr_AssemblyComponentUsage)& aSubs) ;
  
  Standard_EXPORT     Handle_TCollection_HAsciiString Name() const;
  
  Standard_EXPORT     void SetName(const Handle(TCollection_HAsciiString)& aName) ;
  
  Standard_EXPORT     Handle_TCollection_HAsciiString Definition() const;
  
  Standard_EXPORT     void SetDefinition(const Handle(TCollection_HAsciiString)& aDef) ;
  
  Standard_EXPORT     Handle_StepRepr_AssemblyComponentUsage Base() const;
  
  Standard_EXPORT     void SetBase(const Handle(StepRepr_AssemblyComponentUsage)& aBase) ;
  
  Standard_EXPORT     Handle_StepRepr_AssemblyComponentUsage Substitute() const;
  
  Standard_EXPORT     void SetSubstitute(const Handle(StepRepr_AssemblyComponentUsage)& aSubstitute) ;




  DEFINE_STANDARD_RTTI(StepRepr_AssemblyComponentUsageSubstitute)

protected:




private: 


Handle_TCollection_HAsciiString theName;
Handle_TCollection_HAsciiString theDef;
Handle_StepRepr_AssemblyComponentUsage theBase;
Handle_StepRepr_AssemblyComponentUsage theSubs;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
