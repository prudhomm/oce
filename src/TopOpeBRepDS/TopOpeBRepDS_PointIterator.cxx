// Created on: 1993-06-17
// Created by: Jean Yves LEBEY
// Copyright (c) 1993-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and / or modify it
// under the terms of the GNU Lesser General Public version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <TopOpeBRepDS_PointIterator.ixx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_CurvePointInterference.hxx>
#include <TopOpeBRepDS_EdgeVertexInterference.hxx>
#include <Standard_ProgramError.hxx>

//=======================================================================
//function : TopOpeBRepDS_PointIterator
//purpose  : 
//=======================================================================

TopOpeBRepDS_PointIterator::TopOpeBRepDS_PointIterator
  (const TopOpeBRepDS_ListOfInterference& L) :
  TopOpeBRepDS_InterferenceIterator(L)
{
  Match();
}

//=======================================================================
//function : MatchInterference
//purpose  : 
//=======================================================================

Standard_Boolean TopOpeBRepDS_PointIterator::MatchInterference
   (const Handle(TopOpeBRepDS_Interference)& I) const
{
  TopOpeBRepDS_Kind GT = I->GeometryType();
  Standard_Boolean r = ( GT == TopOpeBRepDS_POINT) || ( GT == TopOpeBRepDS_VERTEX);
  return r;
}

//=======================================================================
//function : Current
//purpose  : 
//=======================================================================

Standard_Integer  TopOpeBRepDS_PointIterator::Current()const 
{
  return Value()->Geometry();
}


//=======================================================================
//function : Orientation
//purpose  : 
//=======================================================================

TopAbs_Orientation  TopOpeBRepDS_PointIterator::Orientation
  (const TopAbs_State S)const 
{
  Handle(TopOpeBRepDS_Interference) I = Value();
  const TopOpeBRepDS_Transition& T = I->Transition();
  TopAbs_Orientation o = T.Orientation(S);
  return o;
}


//=======================================================================
//function : Parameter
//purpose  : 
//=======================================================================

Standard_Real  TopOpeBRepDS_PointIterator::Parameter()const 
{

#ifdef DEB
//  cout<<"PointIterator : I = "; Value()->Dump(cout); cout<<endl;
#endif

  const Handle(TopOpeBRepDS_Interference)& I = Value();
  Handle(Standard_Type) T = I->DynamicType(); 
  if      ( T == STANDARD_TYPE(TopOpeBRepDS_CurvePointInterference) ) { 
    return (*((Handle(TopOpeBRepDS_CurvePointInterference)*)&I))->Parameter();
  }
  else if ( T == STANDARD_TYPE(TopOpeBRepDS_EdgeVertexInterference) ) {
    return (*((Handle(TopOpeBRepDS_EdgeVertexInterference)*)&I))->Parameter();
  }
  else {
    Standard_ProgramError::Raise("TopOpeBRepDS_PointIterator::Parameter()");
    return 0.;  // windowsNT
  }
//  return 0.;  // windowsNT
}

//=======================================================================
//function : IsVertex
//purpose  : 
//=======================================================================

Standard_Boolean TopOpeBRepDS_PointIterator::IsVertex() const 
{
  return (Value()->GeometryType() == TopOpeBRepDS_VERTEX);
}

//=======================================================================
//function : IsPoint
//purpose  : 
//=======================================================================

Standard_Boolean TopOpeBRepDS_PointIterator::IsPoint() const 
{
  return (Value()->GeometryType() == TopOpeBRepDS_POINT);
}

//=======================================================================
//function : DiffOriented
//purpose  : 
//=======================================================================

Standard_Boolean TopOpeBRepDS_PointIterator::DiffOriented() const 
{
  const Handle(TopOpeBRepDS_Interference)& I = Value();
  if ( I->DynamicType() == STANDARD_TYPE(TopOpeBRepDS_EdgeVertexInterference) ) {
    return (*((Handle(TopOpeBRepDS_EdgeVertexInterference)*)&I))
      ->Config() == TopOpeBRepDS_DIFFORIENTED;
  }
  else {
    Standard_ProgramError::Raise("TopOpeBRepDS_PointIterator::DiffOriented()");
    return Standard_False; // windowsNT
  }
//  return Standard_False; // windowsNT
}

//=======================================================================
//function : SameOriented
//purpose  : 
//=======================================================================

Standard_Boolean TopOpeBRepDS_PointIterator::SameOriented() const 
{
  const Handle(TopOpeBRepDS_Interference)& I = Value();
  if ( I->DynamicType() == STANDARD_TYPE(TopOpeBRepDS_EdgeVertexInterference) ) {
    return (*((Handle(TopOpeBRepDS_EdgeVertexInterference)*)&I))
      ->Config() == TopOpeBRepDS_SAMEORIENTED;
  }
  else {
    Standard_ProgramError::Raise("TopOpeBRepDS_PointIterator::SameOriented()");
    return Standard_False; // windowsNT
  }
}

//=======================================================================
//function : Support
//purpose  : 
//=======================================================================

Standard_Integer TopOpeBRepDS_PointIterator::Support() const 
{
  return (Value()->Support());
}
