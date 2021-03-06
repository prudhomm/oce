// Created on: 2003-05-04
// Created by: Alexander Grigoriev (a-grigoriev@opencascade.com)
// Copyright (c) 2003-2014 OPEN CASCADE SAS
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

#ifndef _AIS_NDataMapOfTransientIteratorOfListTransient_HeaderFile
#define _AIS_NDataMapOfTransientIteratorOfListTransient_HeaderFile

#include <AIS_NListIteratorOfListTransient.hxx>
#include <NCollection_DefineDataMap.hxx>

DEFINE_BASECOLLECTION(AIS_BaseCollItListTransient,
                      AIS_NListIteratorOfListTransient)
DEFINE_DATAMAP       (AIS_NDataMapOfTransientIteratorOfListTransient,
                      AIS_BaseCollItListTransient,
                      Handle(Standard_Transient),
                      AIS_NListIteratorOfListTransient)

#endif
