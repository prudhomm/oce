// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepAP214_ApprovalItem_HeaderFile
#define _StepAP214_ApprovalItem_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _StepData_SelectType_HeaderFile
#include <StepData_SelectType.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_StepRepr_AssemblyComponentUsageSubstitute_HeaderFile
#include <Handle_StepRepr_AssemblyComponentUsageSubstitute.hxx>
#endif
#ifndef _Handle_StepBasic_DocumentFile_HeaderFile
#include <Handle_StepBasic_DocumentFile.hxx>
#endif
#ifndef _Handle_StepRepr_MaterialDesignation_HeaderFile
#include <Handle_StepRepr_MaterialDesignation.hxx>
#endif
#ifndef _Handle_StepVisual_MechanicalDesignGeometricPresentationRepresentation_HeaderFile
#include <Handle_StepVisual_MechanicalDesignGeometricPresentationRepresentation.hxx>
#endif
#ifndef _Handle_StepVisual_PresentationArea_HeaderFile
#include <Handle_StepVisual_PresentationArea.hxx>
#endif
#ifndef _Handle_StepBasic_Product_HeaderFile
#include <Handle_StepBasic_Product.hxx>
#endif
#ifndef _Handle_StepBasic_ProductDefinition_HeaderFile
#include <Handle_StepBasic_ProductDefinition.hxx>
#endif
#ifndef _Handle_StepBasic_ProductDefinitionFormation_HeaderFile
#include <Handle_StepBasic_ProductDefinitionFormation.hxx>
#endif
#ifndef _Handle_StepBasic_ProductDefinitionRelationship_HeaderFile
#include <Handle_StepBasic_ProductDefinitionRelationship.hxx>
#endif
#ifndef _Handle_StepRepr_PropertyDefinition_HeaderFile
#include <Handle_StepRepr_PropertyDefinition.hxx>
#endif
#ifndef _Handle_StepShape_ShapeRepresentation_HeaderFile
#include <Handle_StepShape_ShapeRepresentation.hxx>
#endif
#ifndef _Handle_StepBasic_SecurityClassification_HeaderFile
#include <Handle_StepBasic_SecurityClassification.hxx>
#endif
class Standard_Transient;
class StepRepr_AssemblyComponentUsageSubstitute;
class StepBasic_DocumentFile;
class StepRepr_MaterialDesignation;
class StepVisual_MechanicalDesignGeometricPresentationRepresentation;
class StepVisual_PresentationArea;
class StepBasic_Product;
class StepBasic_ProductDefinition;
class StepBasic_ProductDefinitionFormation;
class StepBasic_ProductDefinitionRelationship;
class StepRepr_PropertyDefinition;
class StepShape_ShapeRepresentation;
class StepBasic_SecurityClassification;



class StepAP214_ApprovalItem  : public StepData_SelectType {
public:

  DEFINE_STANDARD_ALLOC

  //! Returns a ApprovalItem SelectType <br>
  Standard_EXPORT   StepAP214_ApprovalItem();
  //! Recognizes a ApprovalItem Kind Entity that is : <br>
//!        1 -> AssemblyComponentUsageSubstitute <br>
//!        2 -> DocumentFile <br>
//!        3 -> MaterialDesignation <br>
//!        4 -> MechanicalDesignGeometricPresentationRepresentation <br>
//!        5 -> PresentationArea <br>
//!        6 -> Product <br>
//!        7 -> ProductDefinition <br>
//!        8 -> ProductDefinitionFormation <br>
//!        9 -> ProductDefinitionRelationship <br>
//!        10 -> PropertyDefinition <br>
//!        11 -> ShapeRepresentation <br>
//!        12 -> SecurityClassification <br>
//!        0 else <br>
  Standard_EXPORT   virtual  Standard_Integer CaseNum(const Handle(Standard_Transient)& ent) const;
  //! returns Value as a AssemblyComponentUsageSubstitute (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepRepr_AssemblyComponentUsageSubstitute AssemblyComponentUsageSubstitute() const;
  //! returns Value as a DocumentFile (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepBasic_DocumentFile DocumentFile() const;
  //! returns Value as a MaterialDesignation (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepRepr_MaterialDesignation MaterialDesignation() const;
  //! returns Value as a MechanicalDesignGeometricPresentationRepresentation (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepVisual_MechanicalDesignGeometricPresentationRepresentation MechanicalDesignGeometricPresentationRepresentation() const;
  //! returns Value as a PresentationArea (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepVisual_PresentationArea PresentationArea() const;
  //! returns Value as a Product (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepBasic_Product Product() const;
  //! returns Value as a ProductDefinition (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepBasic_ProductDefinition ProductDefinition() const;
  //! returns Value as a ProductDefinitionFormation (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepBasic_ProductDefinitionFormation ProductDefinitionFormation() const;
  //! returns Value as aProductDefinitionRelationship (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepBasic_ProductDefinitionRelationship ProductDefinitionRelationship() const;
  //! returns Value as a PropertyDefinition (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepRepr_PropertyDefinition PropertyDefinition() const;
  //! returns Value as a ShapeRepresentation  (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepShape_ShapeRepresentation ShapeRepresentation() const;
  //! returns Value as a SecurityClassification (Null if another type) <br>
  Standard_EXPORT   virtual  Handle_StepBasic_SecurityClassification SecurityClassification() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
