// Created on: 1999-02-11
// Created by: Pavel DURANDIN
// Copyright (c) 1999-1999 Matra Datavision
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

#include <STEPSelections_SelectFaces.ixx>
#include <StepShape_FaceSurface.hxx>
#include <StepGeom_Surface.hxx>
#include <StepShape_GeometricSet.hxx>
#include <StepGeom_Surface.hxx>


STEPSelections_SelectFaces::STEPSelections_SelectFaces():IFSelect_SelectExplore (-1){ }

Standard_Boolean STEPSelections_SelectFaces::Explore(const Standard_Integer /*level*/,
						    const Handle(Standard_Transient)& start,
						    const Interface_Graph& G,
						    Interface_EntityIterator& explored) const
{
  if(start.IsNull()) return Standard_False;
  
  if (start->IsKind(STANDARD_TYPE(StepShape_FaceSurface))) return Standard_True;
  
  Standard_Boolean isInFaceOfInSurface = Standard_False;
  if (start->IsKind(STANDARD_TYPE(StepGeom_Surface))) {
    Interface_EntityIterator subs = G.Sharings(start);
    for (subs.Start(); subs.More(); subs.Next()) {
      if(subs.Value()->IsKind(STANDARD_TYPE(StepShape_GeometricSet)))
	return Standard_True;
      if(subs.Value()->IsKind(STANDARD_TYPE(StepGeom_Surface)))
	isInFaceOfInSurface = Standard_True;
      if(subs.Value()->IsKind(STANDARD_TYPE(StepShape_FaceSurface)))
	isInFaceOfInSurface = Standard_True;
    }
    return !isInFaceOfInSurface;
  }
  Interface_EntityIterator subs = G.Shareds(start);
  subs.Start();
  Standard_Boolean isSome = subs.More();
  for (; subs.More(); subs.Next()) 
    explored.AddItem (subs.Value());
  
  return isSome;
}

TCollection_AsciiString STEPSelections_SelectFaces::ExploreLabel() const
{
  return TCollection_AsciiString ("Faces");
}
