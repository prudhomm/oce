// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XSControl_Controller_HeaderFile
#define _XSControl_Controller_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_XSControl_Controller_HeaderFile
#include <Handle_XSControl_Controller.hxx>
#endif

#ifndef _IFSelect_Profile_HeaderFile
#include <IFSelect_Profile.hxx>
#endif
#ifndef _TCollection_AsciiString_HeaderFile
#include <TCollection_AsciiString.hxx>
#endif
#ifndef _Handle_IFSelect_WorkLibrary_HeaderFile
#include <Handle_IFSelect_WorkLibrary.hxx>
#endif
#ifndef _Handle_Interface_Protocol_HeaderFile
#include <Handle_Interface_Protocol.hxx>
#endif
#ifndef _Handle_IFSelect_Signature_HeaderFile
#include <Handle_IFSelect_Signature.hxx>
#endif
#ifndef _Handle_Transfer_ActorOfTransientProcess_HeaderFile
#include <Handle_Transfer_ActorOfTransientProcess.hxx>
#endif
#ifndef _Handle_Transfer_ActorOfFinderProcess_HeaderFile
#include <Handle_Transfer_ActorOfFinderProcess.hxx>
#endif
#ifndef _Handle_Dico_DictionaryOfTransient_HeaderFile
#include <Handle_Dico_DictionaryOfTransient.hxx>
#endif
#ifndef _TColStd_SequenceOfTransient_HeaderFile
#include <TColStd_SequenceOfTransient.hxx>
#endif
#ifndef _Handle_TColStd_HSequenceOfHAsciiString_HeaderFile
#include <Handle_TColStd_HSequenceOfHAsciiString.hxx>
#endif
#ifndef _TColStd_SequenceOfInteger_HeaderFile
#include <TColStd_SequenceOfInteger.hxx>
#endif
#ifndef _Handle_Interface_HArray1OfHAsciiString_HeaderFile
#include <Handle_Interface_HArray1OfHAsciiString.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_XSControl_WorkSession_HeaderFile
#include <Handle_XSControl_WorkSession.hxx>
#endif
#ifndef _Handle_Interface_InterfaceModel_HeaderFile
#include <Handle_Interface_InterfaceModel.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _IFSelect_ReturnStatus_HeaderFile
#include <IFSelect_ReturnStatus.hxx>
#endif
#ifndef _Handle_Transfer_FinderProcess_HeaderFile
#include <Handle_Transfer_FinderProcess.hxx>
#endif
class IFSelect_WorkLibrary;
class Interface_Protocol;
class IFSelect_Signature;
class Transfer_ActorOfTransientProcess;
class Transfer_ActorOfFinderProcess;
class Dico_DictionaryOfTransient;
class TColStd_HSequenceOfHAsciiString;
class Interface_HArray1OfHAsciiString;
class Standard_DomainError;
class XSControl_WorkSession;
class Interface_InterfaceModel;
class Standard_Transient;
class Transfer_FinderProcess;
class TopoDS_Shape;
class Interface_CheckIterator;


//! This class allows a general X-STEP engine to run generic <br>
//!           functions on any interface norm, in the same way. It includes <br>
//!           the transfer operations. I.e. it gathers the already available <br>
//!           general modules, the engine has just to know it <br>
//! <br>
//!           The important point is that a given X-STEP Controller is <br>
//!           attached to a given couple made of an Interface Norm (such as <br>
//!           IGES-5.1) and an application data model (CasCade Shapes for <br>
//!           instance). <br>
//! <br>
//!           A Controller brings a Profile, this allows to have several <br>
//!           variants on the same basic definition, for instance keep the <br>
//!           norm definition but give several transfer actors, etc <br>
//! <br>
//!           Finally, Controller can be gathered in a general dictionary then <br>
//!           retreived later by a general call (method Recorded) <br>
//! <br>
//!           It does not manage the produced data, but the Actors make the <br>
//!           link between the norm and the application <br>
class XSControl_Controller : public MMgt_TShared {

public:

  //! Changes names <br>
//!           if a name is empty, the formerly set one remains <br>
//!           Remark : Does not call Record or AutoRecord <br>
  Standard_EXPORT     void SetNames(const Standard_CString longname,const Standard_CString shortname) ;
  //! Records <me> is a general dictionary under Short and Long <br>
//!           Names (see method Name) <br>
  Standard_EXPORT     void AutoRecord() const;
  //! Records <me> in a general dictionary under a name <br>
//!           Error if <name> already used for another one <br>
  Standard_EXPORT     void Record(const Standard_CString name) const;
  //! Returns the Controller attached to a given name <br>
//!           Returns a Null Handle if <name> is unknown <br>
  Standard_EXPORT   static  Handle_XSControl_Controller Recorded(const Standard_CString name) ;
  //! Returns the list of names of recorded norms, according to mode <br>
//!           = 0 (D) : all the recorded names <br>
//!           < 0 : for each distinct norm, its resource (short) name <br>
//!           > 0 : for each distinct norm, its complete (long)  name <br>
  Standard_EXPORT   static  Handle_TColStd_HSequenceOfHAsciiString ListRecorded(const Standard_Integer mode = 0) ;
  //! Returns a name, as given when initializing : <br>
//!           rsc = False (D) : True Name attached to the Norm (long name) <br>
//!           rsc = True : Name of the ressource set (i.e. short name) <br>
  Standard_EXPORT     Standard_CString Name(const Standard_Boolean rsc = Standard_False) const;
  //! Returns the Profile <br>
//!           It starts with a first configuration Base (empty) and the <br>
//!           following options : <br>
//!           protocol    for the Protocol <br>
//!           sign-type   for the SignType (Default Signature for Type) <br>
//!           access      for the WorkLibrary <br>
//!           tr-read  for ActorRead  (import processor) <br>
//!           tr-write for ActorWrite (export processor) <br>
  Standard_EXPORT     Handle_IFSelect_Profile Profile() const;
  //! Considers the current state of the Controller as defining a <br>
//!           configuration, newly created or already existing <br>
  Standard_EXPORT     void DefineProfile(const Standard_CString confname) ;
  //! Sets the Controller in a given Configuration of its Profile <br>
//!           Calls SettingProfile (which can be redefined) <br>
//! <br>
//!           Returns True if done, False if <confname> unknown <br>
  Standard_EXPORT     Standard_Boolean SetProfile(const Standard_CString confname) ;
  //! This method is called by SetProfile, it can be redefined <br>
//!           for specific sub-class of Controller <br>
//!           The default does nothing <br>
  Standard_EXPORT   virtual  Standard_Boolean SettingProfile(const Standard_CString confname) ;
  //! Applies a Configuration of the Profile to the WorkSession <br>
//!           I.E. calls SetProfile then fills WorkSession with definitions <br>
  Standard_EXPORT     Standard_Boolean ApplyProfile(const Handle(XSControl_WorkSession)& WS,const Standard_CString confname) ;
  //! Called by ApplyProfile, can be redefined for specific <br>
//!           sub-class of Controller <br>
//!           The default does nothing <br>
  Standard_EXPORT   virtual  Standard_Boolean ApplyingProfile(const Handle(XSControl_WorkSession)& WS,const Standard_CString confname) ;
  //! Returns the Protocol attached to the Norm (from field) <br>
  Standard_EXPORT     Handle_Interface_Protocol Protocol() const;
  //! Returns the SignType attached to the norm (from field) <br>
  Standard_EXPORT     Handle_IFSelect_Signature SignType() const;
  //! Returns the WorkLibrary attached to the Norm. Remark that it <br>
//!           has to be in phase with the Protocol  (read from field) <br>
  Standard_EXPORT     Handle_IFSelect_WorkLibrary WorkLibrary() const;
  //! Creates a new empty Model ready to receive data of the Norm <br>
//!           Used to write data from Imagine to an interface file <br>
  Standard_EXPORT   virtual  Handle_Interface_InterfaceModel NewModel() const = 0;
  //! Returns the Actor for Read attached to the pair (norm,appli) <br>
//!           It can be adapted for data of the input Model, as required <br>
//!           Can be read from field then adapted with Model as required <br>
  Standard_EXPORT   virtual  Handle_Transfer_ActorOfTransientProcess ActorRead(const Handle(Interface_InterfaceModel)& model) const = 0;
  //! Returns the Actor for Write attached to the pair (norm,appli) <br>
//!           Read from field. Can be redefined <br>
  Standard_EXPORT   virtual  Handle_Transfer_ActorOfFinderProcess ActorWrite() const;
  //! Updates static values <br>
//!           <mode> precises the kind of updating : (see Items from Static) <br>
//!           -1 : a precise static item : criter = its name <br>
//!           0  : all items of a family : criter = the family name <br>
//!           1  : all items which match regexp name : criter = regexp name <br>
//!           By default (criter empty) should consider all relevant statics <br>
//!           If <name> is defined, can consider only this static item <br>
//!           The provided default method does nothing, to be redefined <br>
  Standard_EXPORT   virtual  void UpdateStatics(const Standard_Integer mode,const Standard_CString criter = "") const;
  //! Sets mininum and maximum values for modetrans (write) <br>
//!           Erases formerly recorded bounds and values <br>
//!           Actually only for shape <br>
//!           Then, for each value a little help can be attached <br>
  Standard_EXPORT     void SetModeWrite(const Standard_Integer modemin,const Standard_Integer modemax,const Standard_Boolean shape = Standard_True) ;
  //! Attaches a short line of help to a value of modetrans (write) <br>
  Standard_EXPORT     void SetModeWriteHelp(const Standard_Integer modetrans,const Standard_CString help,const Standard_Boolean shape = Standard_True) ;
  //! Returns recorded min and max values for modetrans (write) <br>
//!           Actually only for shapes <br>
//!           Returns True if bounds are set, False else (then, free value) <br>
  Standard_EXPORT     Standard_Boolean ModeWriteBounds(Standard_Integer& modemin,Standard_Integer& modemax,const Standard_Boolean shape = Standard_True) const;
  //! Tells if a value of <modetrans> is a good value(within bounds) <br>
//!           Actually only for shapes <br>
  Standard_EXPORT     Standard_Boolean IsModeWrite(const Standard_Integer modetrans,const Standard_Boolean shape = Standard_True) const;
  //! Returns the help line recorded for a value of modetrans <br>
//!           empty if help not defined or not within bounds or if values are free <br>
  Standard_EXPORT     Standard_CString ModeWriteHelp(const Standard_Integer modetrans,const Standard_Boolean shape = Standard_True) const;
  //! Tells if <obj> (an application object) is a valid candidate <br>
//!           for a transfer to a Model. <br>
//!           By default, asks the ActorWrite if known (through a <br>
//!           TransientMapper). Can be redefined <br>
  Standard_EXPORT   virtual  Standard_Boolean RecognizeWriteTransient(const Handle(Standard_Transient)& obj,const Standard_Integer modetrans = 0) const;
  //! Takes one Transient Object and transfers it to an <br>
//!             InterfaceModel (already created, e.g. by NewModel) <br>
//!           (result is recorded in the model by AddWithRefs) <br>
//!           FP records produced results and checks <br>
//! <br>
//!           Default uses ActorWrite; can be redefined as necessary <br>
//!           Returned value is a status, as follows : <br>
//!             0  OK ,  1 No Result ,  2 Fail (e.g. exception raised) <br>
//!             -1 bad conditions ,  -2 bad model or null model <br>
//!           For type of object not recognized : should return 1 <br>
  Standard_EXPORT   virtual  IFSelect_ReturnStatus TransferWriteTransient(const Handle(Standard_Transient)& obj,const Handle(Transfer_FinderProcess)& FP,const Handle(Interface_InterfaceModel)& model,const Standard_Integer modetrans = 0) const;
  //! Tells if a shape is valid for a transfer to a model <br>
//!           Asks the ActorWrite (through a ShapeMapper) <br>
  Standard_EXPORT   virtual  Standard_Boolean RecognizeWriteShape(const TopoDS_Shape& shape,const Standard_Integer modetrans = 0) const;
  //! Takes one Shape and transfers it to an <br>
//!             InterfaceModel (already created, e.g. by NewModel) <br>
//!           Default uses ActorWrite; can be redefined as necessary <br>
//!           Returned value is a status, as follows : <br>
//!             Done  OK ,  Void : No Result ,  Fail : Fail (e.g. exception) <br>
//!             Error : bad conditions , bad model or null model <br>
//!  Resolution of file clusters <br>
//!  According to each norm, there can (or not) be files of which <br>
//!  definition is not complete but refers to other files : this defines <br>
//!  a file cluster. <br>
//!  It can then be resolved by two calls : <br>
//!  - ClusterContext prepares the resolution, specific of each case <br>
//!  - ResolveCluster performs the resolution, its result consists in <br>
//!    having all data gathered in one final model <br>
  Standard_EXPORT   virtual  IFSelect_ReturnStatus TransferWriteShape(const TopoDS_Shape& shape,const Handle(Transfer_FinderProcess)& FP,const Handle(Interface_InterfaceModel)& model,const Standard_Integer modetrans = 0) const;
  //! Prepares and returns a context to resolve a cluster <br>
//!           All data to be used are detained by the WorkSession <br>
//!           The definition of this context is free and proper to each case <br>
//!           remark that it is aimed to be used in ResolveCluster <br>
//! <br>
//!           The context must be prepared, but resolution must not have <br>
//!           began <br>
//! <br>
//!           If no cluster has to be resolved, should return a null handle <br>
//!           This is the default case, which can be redefined <br>
  Standard_EXPORT   virtual  Handle_Standard_Transient ClusterContext(const Handle(XSControl_WorkSession)& WS) const;
  //! Performs the resolution itself, from the starting data and <br>
//!           the cluster context <br>
//! <br>
//!           Can fill a CheckList as necessary (especially when one or <br>
//!           more references remain unresolved) <br>
//! <br>
//!           Default does nothing and returns an empty CheckList <br>
  Standard_EXPORT   virtual  Interface_CheckIterator ResolveCluster(const Handle(XSControl_WorkSession)& WS,const Handle(Standard_Transient)& context) const;
  //! Adds an item in the control list <br>
//!           A control item of a controller is accessed by its name which <br>
//!           is specific of a kind of item (i.e. a kind of functionnality) <br>
//!           Adds or replaces if <name> is already recorded <br>
  Standard_EXPORT     void AddControlItem(const Handle(Standard_Transient)& item,const Standard_CString name) ;
  //! Returns a control item from its name, Null if <name> unknown <br>
//!           To be used then, it just remains to be down-casted <br>
  Standard_EXPORT     Handle_Standard_Transient ControlItem(const Standard_CString name) const;
  //! Records the name of a Static to be traced for a given use <br>
  Standard_EXPORT     void TraceStatic(const Standard_CString name,const Standard_Integer use) ;
  //! Records a Session Item, to be added for customisation of the <br>
//!           Work Session. It must have a specific name. <br>
//!           <setapplied> is used if <item> is a GeneralModifier, to decide <br>
//!           to which hook list it will be applied, if not empty (else, <br>
//!           not applied to any hook list) <br>
//!           ACTUAL : only one hook list is managed : "send" <br>
//!           Remark : this method is to be called at Create time, the <br>
//!           recorded items will be used by Customise <br>
//!  Warning : if <name> conflicts, the last recorded item is kept <br>
  Standard_EXPORT     void AddSessionItem(const Handle(Standard_Transient)& item,const Standard_CString name,const Standard_CString setapplied = "") ;
  //! Returns an item given its name to record in a Session <br>
//!           If <name> is unknown, returns a Null Handle <br>
  Standard_EXPORT     Handle_Standard_Transient SessionItem(const Standard_CString name) const;
  //! Returns True if <item> is recorded as <setapplied = True> <br>
  Standard_EXPORT     Standard_Boolean IsApplied(const Handle(Standard_Transient)& item) const;
  //! Customises a WorkSession, by adding to it the recorded items <br>
//!           (by AddSessionItem), then by calling a specific method <br>
//!           Customising, set by default to do nothing <br>
  Standard_EXPORT   virtual  void Customise(Handle(XSControl_WorkSession)& WS) ;
  //! Specific customisation method, which can be redefined <br>
//!           Default does nothing <br>
  Standard_EXPORT     void Customising(Handle(XSControl_WorkSession)& WS) ;
  
  Standard_EXPORT     Handle_Dico_DictionaryOfTransient AdaptorSession() const;




  DEFINE_STANDARD_RTTI(XSControl_Controller)

protected:

  //! Initializing with names <br>
//!           <longname>  is for the complete, official, long  name <br>
//!           <shortname> is for the short name used for resources <br>
  Standard_EXPORT   XSControl_Controller(const Standard_CString longname,const Standard_CString shortname);

TCollection_AsciiString theShortName;
TCollection_AsciiString theLongName;
Handle_IFSelect_WorkLibrary theAdaptorLibrary;
Handle_Interface_Protocol theAdaptorProtocol;
Handle_IFSelect_Signature theSignType;
Handle_Transfer_ActorOfTransientProcess theAdaptorRead;
Handle_Transfer_ActorOfFinderProcess theAdaptorWrite;
Handle_Dico_DictionaryOfTransient theAdaptorSession;


private: 


Handle_IFSelect_Profile theProfile;
Handle_Dico_DictionaryOfTransient theItems;
TColStd_SequenceOfTransient theAdaptorApplied;
Handle_TColStd_HSequenceOfHAsciiString theAdaptorHooks;
TColStd_SequenceOfTransient theParams;
TColStd_SequenceOfInteger theParamUses;
Handle_Interface_HArray1OfHAsciiString theModeWriteShapeN;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
