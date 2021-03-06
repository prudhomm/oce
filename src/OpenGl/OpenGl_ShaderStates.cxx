// Created on: 2013-10-02
// Created by: Denis BOGOLEPOV
// Copyright (c) 2013 OPEN CASCADE SAS
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

#include <NCollection_Mat4.hxx>

#include <OpenGl_ShaderStates.hxx>

// =======================================================================
// function : OpenGl_StateInterface
// purpose  : Creates new OCCT state
// =======================================================================
OpenGl_StateInterface::OpenGl_StateInterface()
: myIndex (0)
{
  //
}

// =======================================================================
// function : Index
// purpose  : Returns current state index
// =======================================================================
Standard_Size OpenGl_StateInterface::Index() const
{
  return myIndex;
}

// =======================================================================
// function : Update
// purpose  : Updates current state
// =======================================================================
void OpenGl_StateInterface::Update()
{
  ++myIndex;
}

// =======================================================================
// function : Revert
// purpose  : Reverts current state
// =======================================================================
void OpenGl_StateInterface::Revert()
{
  if (myIndex > 0)
  {
    --myIndex;
  }
}

// =======================================================================
// function : OpenGl_ProjectionState
// purpose  : Creates uninitialized projection state
// =======================================================================
OpenGl_ProjectionState::OpenGl_ProjectionState()
: myInverseNeedUpdate (false)
{
  //
}

// =======================================================================
// function : Set
// purpose  : Sets new OCCT projection state
// =======================================================================
void OpenGl_ProjectionState::Set (const Tmatrix3& theProjectionMatrix)
{
  memcpy (myProjectionMatrix, theProjectionMatrix, sizeof (Tmatrix3));
  myInverseNeedUpdate = true;
}

// =======================================================================
// function : ProjectionMatrix
// purpose  : Returns current projection matrix
// =======================================================================
const Tmatrix3& OpenGl_ProjectionState::ProjectionMatrix() const
{
  return myProjectionMatrix;
}

// =======================================================================
// function : ProjectionMatrixInverse
// purpose  : Returns inverse of current projection matrix
// =======================================================================
const Tmatrix3& OpenGl_ProjectionState::ProjectionMatrixInverse() const
{
  if (!myInverseNeedUpdate)
  {
    return myProjectionMatrixInverse;
  }

  reinterpret_cast<const NCollection_Mat4<float>*> (*myProjectionMatrix)->Inverted (
                *(reinterpret_cast<NCollection_Mat4<float>*> (*myProjectionMatrixInverse)));
  return myProjectionMatrixInverse;
}

// =======================================================================
// function : OpenGl_ModelWorldState
// purpose  : Creates uninitialized model-world state
// =======================================================================
OpenGl_ModelWorldState::OpenGl_ModelWorldState()
: myInverseNeedUpdate (false)
{
  //
}

// =======================================================================
// function : Set
// purpose  : Sets new model-world matrix
// =======================================================================
void OpenGl_ModelWorldState::Set (const Tmatrix3& theModelWorldMatrix)
{
  memcpy (myModelWorldMatrix, theModelWorldMatrix, sizeof (Tmatrix3));
  myInverseNeedUpdate = true;
}

// =======================================================================
// function : ModelWorldMatrix
// purpose  : Returns current model-world matrix
// =======================================================================
const Tmatrix3& OpenGl_ModelWorldState::ModelWorldMatrix() const
{
  return myModelWorldMatrix;
}

// =======================================================================
// function : ModelWorldMatrixInverse
// purpose  : Returns inverse of current model-world matrix
// =======================================================================
const Tmatrix3& OpenGl_ModelWorldState::ModelWorldMatrixInverse() const
{
  if (!myInverseNeedUpdate)
  {
    return myModelWorldMatrix;
  }

  reinterpret_cast<const NCollection_Mat4<float>*> (*myModelWorldMatrix)->Inverted (
                *(reinterpret_cast<NCollection_Mat4<float>*> (*myModelWorldMatrixInverse)));
  return myModelWorldMatrixInverse;
}

// =======================================================================
// function : OpenGl_WorldViewState
// purpose  : Creates uninitialized world-view state
// =======================================================================
OpenGl_WorldViewState::OpenGl_WorldViewState()
: myInverseNeedUpdate (false)
{
  //
}

// =======================================================================
// function : Set
// purpose  : Sets new world-view matrix
// =======================================================================
void OpenGl_WorldViewState::Set (const Tmatrix3& theWorldViewMatrix)
{
  memcpy (myWorldViewMatrix, theWorldViewMatrix, sizeof (Tmatrix3));
  myInverseNeedUpdate = true;
}

// =======================================================================
// function : WorldViewMatrix
// purpose  : Returns current world-view matrix
// =======================================================================
const Tmatrix3& OpenGl_WorldViewState::WorldViewMatrix() const
{
  return myWorldViewMatrix;
}

// =======================================================================
// function : WorldViewMatrixInverse
// purpose  : Returns inverse of current world-view matrix
// =======================================================================
const Tmatrix3& OpenGl_WorldViewState::WorldViewMatrixInverse() const
{
  if (!myInverseNeedUpdate)
  {
    return myWorldViewMatrix;
  }

  reinterpret_cast<const NCollection_Mat4<float>*> (*myWorldViewMatrix)->Inverted (
                *(reinterpret_cast<NCollection_Mat4<float>*> (*myWorldViewMatrixInverse)));
  return myWorldViewMatrixInverse;
}

// =======================================================================
// function : OpenGl_LightSourceState
// purpose  : Creates uninitialized state of light sources
// =======================================================================
OpenGl_LightSourceState::OpenGl_LightSourceState()
: myLightSources (NULL)
{
  //
}

// =======================================================================
// function : Set
// purpose  : Sets new light sources
// =======================================================================
void OpenGl_LightSourceState::Set (const OpenGl_ListOfLight* theLightSources)
{
  myLightSources = theLightSources;
}

// =======================================================================
// function : LightSources
// purpose  : Returns current list of light sources
// =======================================================================
const OpenGl_ListOfLight* OpenGl_LightSourceState::LightSources() const
{
  return myLightSources;
}

// =======================================================================
// function : OpenGl_MaterialState
// purpose  : Creates uninitialized material state
// =======================================================================
OpenGl_MaterialState::OpenGl_MaterialState (const OpenGl_Element* theAspect)
: myAspect (theAspect)
{
  //
}

// =======================================================================
// function : Set
// purpose  : Sets new material aspect
// =======================================================================
void OpenGl_MaterialState::Set (const OpenGl_Element* theAspect)
{
  myAspect = theAspect;
}

// =======================================================================
// function : Aspect
// purpose  : Returns material aspect
// =======================================================================
const OpenGl_Element* OpenGl_MaterialState::Aspect() const
{
  return myAspect;
}

// =======================================================================
// function : OpenGl_ClippingState
// purpose  : Creates new clipping state
// =======================================================================
OpenGl_ClippingState::OpenGl_ClippingState()
{
  //
}
