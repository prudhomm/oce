// Created by: Kirill GAVRILOV
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

#include <OpenGl_PointSprite.hxx>

#include <Graphic3d_TextureParams.hxx>
#include <OpenGl_Context.hxx>
#include <Standard_Assert.hxx>
#include <Image_PixMap.hxx>

IMPLEMENT_STANDARD_HANDLE (OpenGl_PointSprite, OpenGl_Texture)
IMPLEMENT_STANDARD_RTTIEXT(OpenGl_PointSprite, OpenGl_Texture)

// =======================================================================
// function : OpenGl_PointSprite
// purpose  :
// =======================================================================
OpenGl_PointSprite::OpenGl_PointSprite()
: OpenGl_Texture (NULL),
  myBitmapList (0)
{
  //myParams->SetFilter (Graphic3d_TOTF_NEAREST);
  myParams->SetGenMode (Graphic3d_TOTM_SPRITE,
                        Graphic3d_Vec4 (0.0f, 0.0f, 0.0f, 0.0f),
                        Graphic3d_Vec4 (0.0f, 0.0f, 0.0f, 0.0f));
}

// =======================================================================
// function : ~OpenGl_PointSprite
// purpose  :
// =======================================================================
OpenGl_PointSprite::~OpenGl_PointSprite()
{
  Release (NULL);
}

// =======================================================================
// function : Release
// purpose  :
// =======================================================================
void OpenGl_PointSprite::Release (const OpenGl_Context* theGlCtx)
{
  if (myBitmapList != 0)
  {
    if (theGlCtx->IsValid())
    {
      glDeleteLists (myBitmapList, 1);
    }
    myBitmapList = 0;
  }

  OpenGl_Texture::Release (theGlCtx);
}

// =======================================================================
// function : SetDisplayList
// purpose  :
// =======================================================================
void OpenGl_PointSprite::SetDisplayList (const Handle(OpenGl_Context)& theCtx,
                                         const GLuint                  theBitmapList)
{
  Release (theCtx.operator->());
  myBitmapList = theBitmapList;
}


// =======================================================================
// function : DrawBitmap
// purpose  :
// =======================================================================
void OpenGl_PointSprite::DrawBitmap (const Handle(OpenGl_Context)& ) const
{
  if (myBitmapList != 0)
  {
    glCallList (myBitmapList);
  }
}
