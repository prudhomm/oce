// Created by: NW,JPB,CAL
// Copyright (c) 1991-1999 Matra Datavision
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

//-Version  

//-Design Declaration of variables specific to groups
//    of primitives

//-Warning  A group is defined in a structure
// This is the smallest editable entity

//-References 

//-Language C++ 2.0

//-Declarations

// for the class
#include <Graphic3d_Group.jxx>
#include <Graphic3d_Group.pxx>

#include <Graphic3d_StructureManager.hxx>

// Structures are necessairy for interfacing with routines c
// Routines C should be declared externally
//-Methods, in order

Standard_Boolean Graphic3d_Group::IsDeleted () const {

  return ( (MyCGroup.ptrGroup == NULL) || (MyStructure->IsDeleted ()) );

}

Standard_Boolean Graphic3d_Group::ContainsFacet () const {

  return (MyContainsFacet);

}

Standard_Boolean Graphic3d_Group::IsEmpty () const {

  if (IsDeleted ()) return (Standard_True);

  Standard_ShortReal RL = ShortRealLast ();
  Standard_ShortReal RF = ShortRealFirst ();
  Standard_Boolean Result = ((MyBounds.XMin == RL) && (MyBounds.YMin == RL) &&
    (MyBounds.ZMin == RL) && (MyBounds.XMax == RF) &&
    (MyBounds.YMax == RF) && (MyBounds.ZMax == RF));

  if (Result != MyIsEmpty)
    cout << "MyIsEmpty != IsEmpty ()\n" << flush;

  return (Result);

}

void Graphic3d_Group::SetMinMaxValues (const Standard_Real XMin, const Standard_Real YMin, const Standard_Real ZMin, const Standard_Real XMax, const Standard_Real YMax, const Standard_Real ZMax) {

  MyBounds.XMin = Standard_ShortReal (XMin);
  MyBounds.YMin = Standard_ShortReal (YMin);
  MyBounds.ZMin = Standard_ShortReal (ZMin);
  MyBounds.XMax = Standard_ShortReal (XMax);
  MyBounds.YMax = Standard_ShortReal (YMax);
  MyBounds.ZMax = Standard_ShortReal (ZMax);

}

void Graphic3d_Group::MinMaxValues (Standard_Real& XMin, Standard_Real& YMin, Standard_Real& ZMin, Standard_Real& XMax, Standard_Real& YMax, Standard_Real& ZMax) const {

  MinMaxCoord (XMin, YMin, ZMin, XMax, YMax, ZMax);

}

Handle(Graphic3d_Structure) Graphic3d_Group::Structure () const {

  return MyStructure;

}

void Graphic3d_Group::MinMaxCoord (Standard_Real& XMin, Standard_Real& YMin, Standard_Real& ZMin, Standard_Real& XMax, Standard_Real& YMax, Standard_Real& ZMax) const {

  if (IsEmpty ()) {
    // Empty Group
    XMin  = YMin  = ZMin  = ShortRealFirst ();
    XMax  = YMax  = ZMax  = ShortRealLast ();
  }
  else {
    XMin  = Standard_Real (MyBounds.XMin);
    YMin  = Standard_Real (MyBounds.YMin);
    ZMin  = Standard_Real (MyBounds.ZMin);
    XMax  = Standard_Real (MyBounds.XMax);
    YMax  = Standard_Real (MyBounds.YMax);
    ZMax  = Standard_Real (MyBounds.ZMax);
  }

}

void Graphic3d_Group::Update () const {

  if (IsDeleted ()) return;

  if ( (MyStructure->StructureManager ())->UpdateMode () == Aspect_TOU_ASAP )
    (MyStructure->StructureManager ())->Update ();

}
