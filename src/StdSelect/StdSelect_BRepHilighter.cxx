// Created on: 1995-03-22
// Created by: Robert COUBLANC
// Copyright (c) 1995-1999 Matra Datavision
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

#include <StdSelect_BRepHilighter.ixx>
#include <StdSelect_BRepOwner.hxx>
#include <StdSelect_Prs.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_Structure.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Prs3d_PointAspect.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <Prs3d_Presentation.hxx>
#include <StdPrs_WFShape.hxx>
#include <OSD_Chronometer.hxx>
#include <Visual3d_TransientManager.hxx>
static TColStd_MapIteratorOfMapOfInteger it;
static Standard_Boolean ImmediateIsEnable;
static  Standard_Boolean ImmediateIsEnableIsDef= Standard_False;
//==================================================
// Function: 
// Purpose :
//==================================================

StdSelect_BRepHilighter::
StdSelect_BRepHilighter():mylastindex(0)
,myManager(new Visual3d_TransientManager){}

//==================================================
// Function: 
// Purpose :
//==================================================

StdSelect_BRepHilighter::
StdSelect_BRepHilighter(const Handle(StdSelect_ViewerSelector3d)& aSelector,
			const Handle(V3d_Viewer)& aViewer,
			const Quantity_NameOfColor aColor,
			const StdSelect_TypeOfResult aTOR):
myselector(aSelector),
myviewer(aViewer),
mycolor(aColor),
mydrwr(new Prs3d_Drawer()),
mytype(aTOR),
mylastindex(0),
myManager(new Visual3d_TransientManager)

{
  Handle(Prs3d_PointAspect) PA = new Prs3d_PointAspect(Aspect_TOM_O,Quantity_NOC_INDIANRED3,3.);
  mydrwr->SetPointAspect(PA);
}
//==================================================
// Function: 
// Purpose :
//==================================================

void StdSelect_BRepHilighter::
Set(const Handle(StdSelect_ViewerSelector3d)& aSelector)
{myselector=aSelector;}
//==================================================
// Function: 
// Purpose :
//==================================================

void StdSelect_BRepHilighter::
Set(const StdSelect_TypeOfResult aTOR)
{mytype =aTOR;}

//==================================================
// Function: Set
// Purpose :
//==================================================

void StdSelect_BRepHilighter::
Set(const Handle(V3d_Viewer)& aViewer)
{myviewer=aViewer;}
//==================================================
// Function: 
// Purpose :
//==================================================

void StdSelect_BRepHilighter::
Set(const Quantity_NameOfColor aColor)
{mycolor=aColor;} 
//==================================================
// Function: 
// Purpose :
//==================================================
void StdSelect_BRepHilighter::
Process()
{
  Update();
  myviewer->Update();
}
//==================================================
// Function: 
// Purpose :
//==================================================
void StdSelect_BRepHilighter::
Process(const Handle(V3d_View)& aViou,const Standard_Boolean DoubleBuffer)
{
  if(aViou->Viewer() == myviewer){
    Update(aViou,DoubleBuffer);
//    aViou->Update();
  }
}

//==================================================
// Function: 
// Purpose :
//==================================================

void StdSelect_BRepHilighter::
Update()
{
  myselector->Init();
  
  switch(mytype){
  case StdSelect_TOR_MULTIPLE:{
    TColStd_MapIteratorOfMapOfInteger aIt;
    if(!myselector->More())
      {
	for(aIt.Initialize(myold);aIt.More();aIt.Next())
	  {myhimap.FindFromIndex(aIt.Key())->UnHighlight();
	   myhimap.FindFromIndex(aIt.Key())->SetVisible(Standard_False);
	 }
	myold.Clear();
	mynew.Clear();
      }
    else{

      for (;myselector->More();myselector->Next())
	{
	  const Handle(SelectBasics_EntityOwner)& OO = myselector->Picked();
	  if (!myhimap.Contains(OO))
	    {
	      if(!Handle(StdSelect_BRepOwner)::DownCast(OO).IsNull()){
		Handle(StdSelect_Prs) NiouPrs = new StdSelect_Prs
		  (myviewer->Viewer());
		
		StdPrs_WFShape::Add(NiouPrs,
				    Handle(StdSelect_BRepOwner)::DownCast(OO)->Shape(),
				    mydrwr);
		NiouPrs->Display();
		myhimap.Add(OO,NiouPrs);
	      mynew.Add(myhimap.FindIndex(OO));
	      if(myold.Contains(myhimap.FindIndex(OO))) 
		myold.Remove(myhimap.FindIndex(OO));
	      }
	    }
	}
      for(aIt.Initialize(myold);aIt.More();aIt.Next()){
	myhimap.FindFromIndex(aIt.Key())->UnHighlight();
	myhimap.FindFromIndex(aIt.Key())->SetVisible(Standard_False);
      }
      
      myold = mynew;
      mynew.Clear();
      for(aIt.Initialize(myold);aIt.More();aIt.Next()){
	myhimap.FindFromIndex(aIt.Key())->SetVisible(Standard_True);
	myhimap.FindFromIndex(aIt.Key())->SetDisplayPriority(10);
	myhimap.FindFromIndex(aIt.Key())->Color(mycolor);
      }
    }
    break;
  }
    
  case StdSelect_TOR_SIMPLE:
    {
      if(myselector->More()){
	const Handle(SelectBasics_EntityOwner)& OO = myselector->OnePicked();    
	if(!Handle(StdSelect_BRepOwner)::DownCast(OO).IsNull()){
	  if (!myhimap.Contains(OO)){    
	    Handle(StdSelect_Prs) NiouPrs = new StdSelect_Prs
	      (myviewer->Viewer());
	    StdPrs_WFShape::Add(NiouPrs,
				Handle(StdSelect_BRepOwner)::DownCast(OO)->Shape(),
				mydrwr);
	    NiouPrs->Display();
	    myhimap.Add(OO,NiouPrs);
	  } 
	}
	if(mylastindex!=myhimap.FindIndex(OO))
	  {
	    if(mylastindex!=0) 
	      {
		myhimap.FindFromIndex(mylastindex)->UnHighlight();
		myhimap.FindFromIndex(mylastindex)->SetVisible(Standard_False);
	      }
	    mylastindex = myhimap.FindIndex(OO);
	    myhimap.FindFromIndex(mylastindex)->SetVisible(Standard_True);
	    myhimap.FindFromIndex(mylastindex)->SetDisplayPriority(10);
	    myhimap.FindFromIndex(mylastindex)->Color(mycolor);
	  }
      }
      else {   
	if(mylastindex!=0) 
	      {
		myhimap.FindFromIndex(mylastindex)->UnHighlight();
		myhimap.FindFromIndex(mylastindex)->SetVisible(Standard_False);
		mylastindex=0;
	      }
	for (it.Initialize(myold);it.More();it.Next()){
	  myhimap.FindFromIndex(it.Key())->UnHighlight();
	  myhimap.FindFromIndex(it.Key())->SetVisible(Standard_False);}
	myold.Clear();
      }
    }
  }
}

void StdSelect_BRepHilighter::
Update(const Handle(V3d_View)& aView,const Standard_Boolean DoubleBuffer)
{
  if(!ImmediateIsEnableIsDef) {
    ImmediateIsEnable = aView->TransientManagerBeginDraw();
    ImmediateIsEnableIsDef = Standard_True;
    Visual3d_TransientManager::EndDraw();
  }
  if(!ImmediateIsEnable) {
    Update();
  }
  else {
    myselector->Init();
    mynew.Clear();
  
    switch(mytype){
    case StdSelect_TOR_MULTIPLE:{
      
      for (;myselector->More();myselector->Next()) {
	const Handle(SelectBasics_EntityOwner)& OO = myselector->Picked();
	if(!Handle(StdSelect_BRepOwner)::DownCast(OO).IsNull()){
	  if (!myhimap.Contains(OO)) {
	    Handle(StdSelect_Prs) NiouPrs = new StdSelect_Prs(myviewer->Viewer());
	    
	    StdPrs_WFShape::Add(NiouPrs,Handle(StdSelect_BRepOwner)::DownCast(OO)->Shape(),mydrwr);
	    NiouPrs->Color(mycolor);
	    myhimap.Add(OO,NiouPrs);
	  }
	  mynew.Add(myhimap.FindIndex(OO));
	}
      }
      break;
    }
      
    case StdSelect_TOR_SIMPLE: {
      
      if(myselector->More()){
	const Handle(SelectBasics_EntityOwner)& OO = myselector->OnePicked();    
	if(!Handle(StdSelect_BRepOwner)::DownCast(OO).IsNull()){
	  if (!myhimap.Contains(OO)){    
	    Handle(StdSelect_Prs) NiouPrs = new StdSelect_Prs(myviewer->Viewer());
	    StdPrs_WFShape::Add(NiouPrs,Handle(StdSelect_BRepOwner)::DownCast(OO)->Shape(),mydrwr);
	    NiouPrs->Color(mycolor);
	    myhimap.Add(OO,NiouPrs);
	  }
	  mynew.Add(myhimap.FindIndex(OO));
	}
      }
    }
      break;
    } 
    Standard_Boolean First = Standard_True; // to avoid begindraw if there is nothing (expensive)
    
    for(it.Initialize(mynew);it.More();it.Next()){
      
      if(First) {
	aView->TransientManagerBeginDraw(DoubleBuffer);
	First = Standard_False;
      }
      
      Visual3d_TransientManager::DrawStructure(myhimap.FindFromIndex(it.Key()));
    }
    
    if(!First) 
      Visual3d_TransientManager::EndDraw();
  }
}

void StdSelect_BRepHilighter::Clear()
{
  if(!myhimap.IsEmpty()){
    for (Standard_Integer i=1;i<=myhimap.Extent();i++){
      myhimap.FindFromIndex(i)->UnHighlight();
      myhimap.FindFromIndex(i)->Erase();
      myhimap.FindFromIndex(i)->Clear();
    }
    myold.Clear();
    mynew.Clear();
    mylastindex=0;   
  }
  myhimap.Clear();
}

const Handle(Prs3d_Drawer)& StdSelect_BRepHilighter::Drawer() const 
{
  return mydrwr;
}

