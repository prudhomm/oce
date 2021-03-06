// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepShape_VertexLoop_HeaderFile
#define _StepShape_VertexLoop_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepShape_VertexLoop_HeaderFile
#include <Handle_StepShape_VertexLoop.hxx>
#endif

#ifndef _Handle_StepShape_Vertex_HeaderFile
#include <Handle_StepShape_Vertex.hxx>
#endif
#ifndef _StepShape_Loop_HeaderFile
#include <StepShape_Loop.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
class StepShape_Vertex;
class TCollection_HAsciiString;



class StepShape_VertexLoop : public StepShape_Loop {

public:

  //! Returns a VertexLoop <br>
  Standard_EXPORT   StepShape_VertexLoop();
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Handle(StepShape_Vertex)& aLoopVertex) ;
  
  Standard_EXPORT     void SetLoopVertex(const Handle(StepShape_Vertex)& aLoopVertex) ;
  
  Standard_EXPORT     Handle_StepShape_Vertex LoopVertex() const;




  DEFINE_STANDARD_RTTI(StepShape_VertexLoop)

protected:




private: 


Handle_StepShape_Vertex loopVertex;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
