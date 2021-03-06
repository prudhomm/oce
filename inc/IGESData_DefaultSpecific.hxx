// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESData_DefaultSpecific_HeaderFile
#define _IGESData_DefaultSpecific_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESData_DefaultSpecific_HeaderFile
#include <Handle_IGESData_DefaultSpecific.hxx>
#endif

#ifndef _IGESData_SpecificModule_HeaderFile
#include <IGESData_SpecificModule.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_IGESData_IGESEntity_HeaderFile
#include <Handle_IGESData_IGESEntity.hxx>
#endif
#ifndef _Handle_Message_Messenger_HeaderFile
#include <Handle_Message_Messenger.hxx>
#endif
class IGESData_IGESEntity;
class IGESData_IGESDumper;
class Message_Messenger;


//! Specific IGES Services for UndefinedEntity, FreeFormatEntity <br>
class IGESData_DefaultSpecific : public IGESData_SpecificModule {

public:

  //! Creates a DefaultSpecific and puts it into SpecificLib <br>
  Standard_EXPORT   IGESData_DefaultSpecific();
  //! Specific Dump for UndefinedEntity : it concerns only <br>
//!           own parameters, the general data (Directory Part, Lists) are <br>
//!           taken into account by the IGESDumper <br>
  Standard_EXPORT     void OwnDump(const Standard_Integer CN,const Handle(IGESData_IGESEntity)& ent,const IGESData_IGESDumper& dumper,const Handle(Message_Messenger)& S,const Standard_Integer own) const;




  DEFINE_STANDARD_RTTI(IGESData_DefaultSpecific)

protected:




private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
