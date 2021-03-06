// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _MoniTool_TypedValue_HeaderFile
#define _MoniTool_TypedValue_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_MoniTool_TypedValue_HeaderFile
#include <Handle_MoniTool_TypedValue.hxx>
#endif

#ifndef _TCollection_AsciiString_HeaderFile
#include <TCollection_AsciiString.hxx>
#endif
#ifndef _MoniTool_ValueType_HeaderFile
#include <MoniTool_ValueType.hxx>
#endif
#ifndef _Handle_Standard_Type_HeaderFile
#include <Handle_Standard_Type.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_TColStd_HArray1OfAsciiString_HeaderFile
#include <Handle_TColStd_HArray1OfAsciiString.hxx>
#endif
#ifndef _Handle_Dico_DictionaryOfInteger_HeaderFile
#include <Handle_Dico_DictionaryOfInteger.hxx>
#endif
#ifndef _MoniTool_ValueInterpret_HeaderFile
#include <MoniTool_ValueInterpret.hxx>
#endif
#ifndef _MoniTool_ValueSatisfies_HeaderFile
#include <MoniTool_ValueSatisfies.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Handle_Message_Messenger_HeaderFile
#include <Handle_Message_Messenger.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_TColStd_HSequenceOfAsciiString_HeaderFile
#include <Handle_TColStd_HSequenceOfAsciiString.hxx>
#endif
#ifndef _Handle_Dico_DictionaryOfTransient_HeaderFile
#include <Handle_Dico_DictionaryOfTransient.hxx>
#endif
class Standard_Type;
class TColStd_HArray1OfAsciiString;
class Dico_DictionaryOfInteger;
class TCollection_HAsciiString;
class Standard_Transient;
class Standard_ConstructionError;
class TCollection_AsciiString;
class Message_Messenger;
class TColStd_HSequenceOfAsciiString;
class Dico_DictionaryOfTransient;


//! This class allows to dynamically manage .. typed values, i.e. <br>
//!           values which have an alphanumeric expression, but with <br>
//!           controls. Such as "must be an Integer" or "Enumerative Text" <br>
//!           etc <br>
//! <br>
//!           Hence, a TypedValue brings a specification (type + constraints <br>
//!           if any) and a value. Its basic form is a string, it can be <br>
//!           specified as integer or real or enumerative string, then <br>
//!           queried as such. <br>
//!           Its string content, which is a Handle(HAsciiString) can be <br>
//!           shared by other data structures, hence gives a direct on line <br>
//!           access to its value. <br>
class MoniTool_TypedValue : public MMgt_TShared {

public:

  //! Creates a TypedValue, with a name <br>
//! <br>
//!           type gives the type of the parameter, default is free text <br>
//!           Also available : Integer, Real, Enum, Entity (i.e. Object) <br>
//!           More precise specifications, titles, can be given to the <br>
//!           TypedValue once created <br>
//! <br>
//!           init gives an initial value. If it is not given, the <br>
//!           TypedValue begins as "not set", its value is empty <br>
  Standard_EXPORT   MoniTool_TypedValue(const Standard_CString name,const MoniTool_ValueType type = MoniTool_ValueText,const Standard_CString init = "");
  //! Creates a TypedValue from another one, by duplication <br>
  Standard_EXPORT   MoniTool_TypedValue(const Handle(MoniTool_TypedValue)& other);
  //! Access to internal data which have no other access <br>
  Standard_EXPORT     void Internals(MoniTool_ValueInterpret& interp,MoniTool_ValueSatisfies& satisf,Standard_CString& satisname,Handle(Dico_DictionaryOfInteger)& enums) const;
  //! Returns the name <br>
  Standard_EXPORT     Standard_CString Name() const;
  //! Returns the type of the value <br>
  Standard_EXPORT     MoniTool_ValueType ValueType() const;
  //! Returns the Definition <br>
//!           By priority, the enforced one, else an automatic one, computed <br>
//!           from the specification <br>
  Standard_EXPORT     TCollection_AsciiString Definition() const;
  //! Enforces a Definition <br>
  Standard_EXPORT     void SetDefinition(const Standard_CString deftext) ;
  //! Prints definition, specification, and actual status and value <br>
  Standard_EXPORT   virtual  void Print(const Handle(Message_Messenger)& S) const;
  //! Prints only the Value <br>
  Standard_EXPORT     void PrintValue(const Handle(Message_Messenger)& S) const;
  //! Completes the definition of a TypedValue by command <initext>, <br>
//!           once created with its type <br>
//!           Returns True if done, False if could not be interpreted <br>
//!           <initext> may be : <br>
//!           imin ival : minimum value for an integer <br>
//!           imax ival : maximum value for an integer <br>
//!           rmin rval : minimum value for a real <br>
//!           rmax rval : maximum value for a real <br>
//!           unit name : name of unit <br>
//!           ematch i  : enum from integer value i, match required <br>
//!           enum   i  : enum from integer value i, match not required <br>
//!           eval text : add an enumerative value (increments max by 1) <br>
//!           eval ??   : add a non-authorised enum value (to be skipped) <br>
//!           tmax   l  : maximum length for a text <br>
  Standard_EXPORT     Standard_Boolean AddDef(const Standard_CString initext) ;
  //! Sets a label, which can then be displayed <br>
  Standard_EXPORT     void SetLabel(const Standard_CString label) ;
  //! Returns the label, if set; else returns an empty string <br>
  Standard_EXPORT     Standard_CString Label() const;
  //! Sets a maximum length for a text (active only for a free text) <br>
  Standard_EXPORT     void SetMaxLength(const Standard_Integer max) ;
  //! Returns the maximum length, 0 if not set <br>
  Standard_EXPORT     Standard_Integer MaxLength() const;
  //! Sets an Integer limit (included) to <val>, the upper limit <br>
//!           if <max> is True, the lower limit if <max> is False <br>
  Standard_EXPORT     void SetIntegerLimit(const Standard_Boolean max,const Standard_Integer val) ;
  //! Gives an Integer Limit (upper if <max> True, lower if <max> <br>
//!           False). Returns True if this limit is defined, False else <br>
//!           (in that case, gives the natural limit for Integer) <br>
  Standard_EXPORT     Standard_Boolean IntegerLimit(const Standard_Boolean max,Standard_Integer& val) const;
  //! Sets a Real limit (included) to <val>, the upper limit <br>
//!           if <max> is True, the lower limit if <max> is False <br>
  Standard_EXPORT     void SetRealLimit(const Standard_Boolean max,const Standard_Real val) ;
  //! Gives an Real Limit (upper if <max> True, lower if <max> <br>
//!           False). Returns True if this limit is defined, False else <br>
//!           (in that case, gives the natural limit for Real) <br>
  Standard_EXPORT     Standard_Boolean RealLimit(const Standard_Boolean max,Standard_Real& val) const;
  //! Sets (Clears if <def> empty) a unit definition, as an equation <br>
//!           of dimensions. TypedValue just records this definition, does <br>
//!           not exploit it, to be done as required by user applications <br>
  Standard_EXPORT     void SetUnitDef(const Standard_CString def) ;
  //! Returns the recorded unit definition, empty if not set <br>
  Standard_EXPORT     Standard_CString UnitDef() const;
  //! For an enumeration, precises the starting value (default 0) <br>
//!           and the match condition : if True (D), the string value must <br>
//!           match the definition, else it may take another value : in that <br>
//!           case, the Integer Value will be  Start - 1. <br>
//!           (empty value remains allowed) <br>
  Standard_EXPORT     void StartEnum(const Standard_Integer start = 0,const Standard_Boolean match = Standard_True) ;
  //! Adds enumerative definitions. For more than 10, several calls <br>
  Standard_EXPORT     void AddEnum(const Standard_CString v1 = "",const Standard_CString v2 = "",const Standard_CString v3 = "",const Standard_CString v4 = "",const Standard_CString v5 = "",const Standard_CString v6 = "",const Standard_CString v7 = "",const Standard_CString v8 = "",const Standard_CString v9 = "",const Standard_CString v10 = "") ;
  //! Adds an enumeration definition, by its string and numeric <br>
//!           values. If it is the first setting for this value, it is <br>
//!           recorded as main value. Else, it is recognized as alternate <br>
//!           string for this numeric value <br>
  Standard_EXPORT     void AddEnumValue(const Standard_CString val,const Standard_Integer num) ;
  //! Gives the Enum definitions : start value, end value, match <br>
//!           status. Returns True for an Enum, False else. <br>
  Standard_EXPORT     Standard_Boolean EnumDef(Standard_Integer& startcase,Standard_Integer& endcase,Standard_Boolean& match) const;
  //! Returns the value of an enumerative definition, from its rank <br>
//!           Empty string if out of range or not an Enum <br>
  Standard_EXPORT     Standard_CString EnumVal(const Standard_Integer num) const;
  //! Returns the case number which cooresponds to a string value <br>
//!           Works with main and additionnal values <br>
//!           Returns (StartEnum - 1) if not OK, -1 if not an Enum <br>
  Standard_EXPORT     Standard_Integer EnumCase(const Standard_CString val) const;
  //! Sets type of which an Object TypedValue must be kind of <br>//!           Error for a TypedValue not an Object (Entity) <br>
  Standard_EXPORT     void SetObjectType(const Handle(Standard_Type)& typ) ;
  //! Returns the type of which an Object TypedValue must be kind of <br>
//!           Default is Standard_Transient <br>
//!           Null for a TypedValue not an Object <br>
  Standard_EXPORT     Handle_Standard_Type ObjectType() const;
  //! Sets a specific Interpret function <br>
  Standard_EXPORT     void SetInterpret(const MoniTool_ValueInterpret func) ;
  //! Tells if a TypedValue has an Interpret <br>
  Standard_EXPORT   virtual  Standard_Boolean HasInterpret() const;
  //! Sets a specific Satisfies function : it is added to the <br>
//!           already defined criteria <br>
//!           It must match the form : <br>
//!             statisfies (val : HAsciiString) returns Boolean <br>
  Standard_EXPORT     void SetSatisfies(const MoniTool_ValueSatisfies func,const Standard_CString name) ;
  //! Returns name of specific satisfy, empty string if none <br>
  Standard_EXPORT     Standard_CString SatisfiesName() const;
  //! Returns True if the value is set (not empty/not null object) <br>
  Standard_EXPORT     Standard_Boolean IsSetValue() const;
  //! Returns the value, as a cstring. Empty if not set. <br>
  Standard_EXPORT     Standard_CString CStringValue() const;
  //! Returns the value, as a Handle (can then be shared) <br>
//!           Null if not defined <br>
  Standard_EXPORT     Handle_TCollection_HAsciiString HStringValue() const;
  //! Interprets a value. <br>
//!           <native> True  : returns a native value <br>
//!           <native> False : returns a coded  value <br>
//!           If the Interpret function is set, calls it <br>
//!           Else, for an Enum, Native returns the Text, Coded returns <br>
//!             the number <br>
//!           STANDARD RETURNS : = hval means no specific interpretation <br>
//!            Null means senseless <br>
//!           Can also be redefined <br>
  Standard_EXPORT   virtual  Handle_TCollection_HAsciiString Interpret(const Handle(TCollection_HAsciiString)& hval,const Standard_Boolean native) const;
  //! Returns True if a value statifies the specification <br>
//!           (remark : does not apply to Entity : see ObjectType, for this <br>
//!           type, the string is just a comment) <br>
  Standard_EXPORT   virtual  Standard_Boolean Satisfies(const Handle(TCollection_HAsciiString)& hval) const;
  //! Clears the recorded Value : it is now unset <br>
  Standard_EXPORT     void ClearValue() ;
  //! Changes the value. The new one must satisfy the specification <br>//!           Returns False (and did not set) if the new value <br>
//!             does not satisfy the specification <br>
//!           Can be redefined to be managed (in a subclass) <br>
  Standard_EXPORT   virtual  Standard_Boolean SetCStringValue(const Standard_CString val) ;
  //! Forces a new Handle for the Value <br>
//!           It can be empty, else (if Type is not free Text), it must <br>
//!           satisfy the specification. <br>
//!           Not only the value is changed, but also the way it is shared <br>
//!           Remark : for Type=Object, this value is not controlled, it can <br>
//!           be set as a comment <br>//!           Returns False (and did not set) if the new value <br>
//!             does not satisfy the specification <br>
//!           Can be redefined to be managed (in a subclass) <br>
  Standard_EXPORT   virtual  Standard_Boolean SetHStringValue(const Handle(TCollection_HAsciiString)& hval) ;
  //! Returns the value as integer, i.e. : <br>
//!           For type = Integer, the integer itself; 0 if not set <br>
//!           For type = Enum, the designated rank (see Enum definition) <br>
//!             StartEnum - 1 if not set or not in the definition <br>
//!           Else, returns 0 <br>
  Standard_EXPORT     Standard_Integer IntegerValue() const;
  //! Changes the value as an integer, only for Integer or Enum <br>
  Standard_EXPORT   virtual  Standard_Boolean SetIntegerValue(const Standard_Integer ival) ;
  //! Returns the value as real,  for a Real type TypedValue <br>
//!           Else, returns 0. <br>
  Standard_EXPORT     Standard_Real RealValue() const;
  //! Changes the value as a real, only for Real <br>
  Standard_EXPORT   virtual  Standard_Boolean SetRealValue(const Standard_Real rval) ;
  //! Returns the value as Transient Object, only for Object/Entity <br>
//!           Remark that the "HString value" is IGNORED here <br>
//!           Null if not set; remains to be casted <br>
  Standard_EXPORT     Handle_Standard_Transient ObjectValue() const;
  //! Same as ObjectValue, but avoids DownCast : the receiving <br>
//!           variable is directly loaded. It is assumed that it complies <br>
//!           with the definition of ObjectType ! Otherwise, big trouble <br>
  Standard_EXPORT     void GetObjectValue(Handle(Standard_Transient)& val) const;
  //! Changes the value as Transient Object, only for Object/Entity <br>
//!           Returns False if DynamicType does not satisfy ObjectType <br>
//!           Can be redefined to be managed (in a subclass) <br>
  Standard_EXPORT   virtual  Standard_Boolean SetObjectValue(const Handle(Standard_Transient)& obj) ;
  //! Returns the type name of the ObjectValue, or an empty string <br>
//!           if not set <br>
  Standard_EXPORT     Standard_CString ObjectTypeName() const;
  //! Adds a TypedValue in the library. <br>
//!           It is recorded then will be accessed by its Name <br>
//!           Its Definition may be imposed, else it is computed as usual <br>
//!           By default it will be accessed by its Definition (string) <br>
//!           Returns True if done, False if tv is Null or brings no <br>
//!           Definition or <def> not defined <br>
//! <br>
//!           If a TypedValue was already recorded under this name, it is <br>
//!           replaced <br>
  Standard_EXPORT   static  Standard_Boolean AddLib(const Handle(MoniTool_TypedValue)& tv,const Standard_CString def = "") ;
  //! Returns the TypedValue bound with a given Name <br>
//!           Null Handle if none recorded <br>
//!           Warning : it is the original, not duplicated <br>
  Standard_EXPORT   static  Handle_MoniTool_TypedValue Lib(const Standard_CString def) ;
  //! Returns a COPY of the TypedValue bound with a given Name <br>
//!           Null Handle if none recorded <br>
  Standard_EXPORT   static  Handle_MoniTool_TypedValue FromLib(const Standard_CString def) ;
  //! Returns the list of names of items of the Library of Types <br>
//! --    Library of TypedValue as Valued Parameters,    -- -- <br>
//!       accessed by parameter name <br>
//!       for use by management of Static Parameters <br>
  Standard_EXPORT   static  Handle_TColStd_HSequenceOfAsciiString LibList() ;
  //! Returns a static value from its name, null if unknown <br>
  Standard_EXPORT   static  Handle_MoniTool_TypedValue StaticValue(const Standard_CString name) ;




  DEFINE_STANDARD_RTTI(MoniTool_TypedValue)

protected:

  //! Gives the internal library of static values <br>
  Standard_EXPORT   static  Handle_Dico_DictionaryOfTransient Stats() ;



private: 


TCollection_AsciiString thename;
TCollection_AsciiString thedef;
TCollection_AsciiString thelabel;
MoniTool_ValueType thetype;
Handle_Standard_Type theotyp;
Standard_Integer thelims;
Standard_Integer themaxlen;
Standard_Integer theintlow;
Standard_Integer theintup;
Standard_Real therealow;
Standard_Real therealup;
TCollection_AsciiString theunidef;
Handle_TColStd_HArray1OfAsciiString theenums;
Handle_Dico_DictionaryOfInteger theeadds;
MoniTool_ValueInterpret theinterp;
MoniTool_ValueSatisfies thesatisf;
TCollection_AsciiString thesatisn;
Standard_Integer theival;
Handle_TCollection_HAsciiString thehval;
Handle_Standard_Transient theoval;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
