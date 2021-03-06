// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESGraph_DefinitionLevel_HeaderFile
#define _IGESGraph_DefinitionLevel_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESGraph_DefinitionLevel_HeaderFile
#include <Handle_IGESGraph_DefinitionLevel.hxx>
#endif

#ifndef _Handle_TColStd_HArray1OfInteger_HeaderFile
#include <Handle_TColStd_HArray1OfInteger.hxx>
#endif
#ifndef _IGESData_LevelListEntity_HeaderFile
#include <IGESData_LevelListEntity.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class TColStd_HArray1OfInteger;
class Standard_OutOfRange;


//! defines IGESDefinitionLevel, Type <406> Form <1> <br>
//!          in package IGESGraph <br>
//! <br>
//!          Indicates the no. of levels on which an entity is <br>
//!          defined <br>
class IGESGraph_DefinitionLevel : public IGESData_LevelListEntity {

public:

  
  Standard_EXPORT   IGESGraph_DefinitionLevel();
  //! This method is used to set the fields of the class <br>
//!           DefinitionLevel <br>
//!       - allLevelNumbers : Values of Level Numbers <br>
  Standard_EXPORT     void Init(const Handle(TColStd_HArray1OfInteger)& allLevelNumbers) ;
  //! returns the number of property values in <me> <br>
  Standard_EXPORT     Standard_Integer NbPropertyValues() const;
  //! Must return the count of levels (== NbPropertyValues) <br>
  Standard_EXPORT     Standard_Integer NbLevelNumbers() const;
  //! returns the Level Number of <me> indicated by <LevelIndex> <br>
//! raises an exception if LevelIndex is <= 0 or <br>
//! LevelIndex > NbPropertyValues <br>
  Standard_EXPORT     Standard_Integer LevelNumber(const Standard_Integer LevelIndex) const;




  DEFINE_STANDARD_RTTI(IGESGraph_DefinitionLevel)

protected:




private: 


Handle_TColStd_HArray1OfInteger theLevelNumbers;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
