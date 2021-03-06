// Created on: 2005-03-15
// Created by: Peter KURNEV
// Copyright (c) 1998-1999 Matra Datavision
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

#include <Standard.ixx>

#include <stdlib.h>

#include <Standard_MMgrOpt.hxx>
#include <Standard_MMgrRaw.hxx>
#include <Standard_MMgrTBBalloc.hxx>

#if(defined(_WIN32) || defined(__WIN32__))
  #include <windows.h>
  #include <malloc.h>
  #include <locale.h>
#endif

#ifndef OCCT_MMGT_OPT_DEFAULT
#define OCCT_MMGT_OPT_DEFAULT 0
#endif

#ifndef MMGT_OPT_DEFAULT
# define MMGT_OPT_DEFAULT           0
#endif
#ifndef MMGT_CLEAR_DEFAULT
# define MMGT_CLEAR_DEFAULT         1
#endif
#ifndef MMGT_MMAP_DEFAULT
# define MMGT_MMAP_DEFAULT          1
#endif
#ifndef MMGT_CELLSIZE_DEFAULT
# define MMGT_CELLSIZE_DEFAULT    200
#endif
#ifndef MMGT_NBPAGES_DEFAULT
# define MMGT_NBPAGES_DEFAULT    1000
#endif
#ifndef MMGT_THRESHOLD_DEFAULT
# define MMGT_THRESHOLD_DEFAULT 40000
#endif
#ifndef MMGT_REENTRANT_DEFAULT
# define MMGT_REENTRANT_DEFAULT     0
#endif

//=======================================================================
//class    : Standard_MMgrFactory 
//purpose  : Container for pointer to memory manager;
//           used to construct appropriate memory manager according
//           to environment settings, and to ensure destruction upon exit
//=======================================================================

static Standard_MMgrRoot* GetMMgr();

class Standard_MMgrFactory {
 public:
  Standard_MMgrFactory();
  ~Standard_MMgrFactory();
 private:
  Standard_MMgrRoot* myFMMgr;
  friend Standard_MMgrRoot* GetMMgr();
};

//=======================================================================
//function : Standard_MMgrFactory
//purpose  : Check environment variables and create appropriate memory manager
//=======================================================================

Standard_MMgrFactory::Standard_MMgrFactory()
: myFMMgr (NULL)
{
/*#if defined(_MSC_VER) && (_MSC_VER > 1400)
  // Turn ON thread-safe C locale globally to avoid side effects by setlocale() calls between threads.
  // After this call all following _configthreadlocale() will be ignored assuming
  // Notice that this is MSVCRT feature - on POSIX systems xlocale API (uselocale instead of setlocale)
  // should be used explicitly to ensure thread-safety!

  // This is not well documented call because _ENABLE_PER_THREAD_LOCALE_GLOBAL flag is defined but not implemented for some reason.
  // -1 will set global locale flag to force _ENABLE_PER_THREAD_LOCALE_GLOBAL + _ENABLE_PER_THREAD_LOCALE_NEW behaviour
  // although there NO way to turn it off again and following calls will have no effect (locale will be changed only for current thread).
  _configthreadlocale (-1);
#endif*/

  char* aVar;
  aVar = getenv ("MMGT_OPT");
  Standard_Integer anAllocId   = (aVar != NULL ?  atoi (aVar): MMGT_OPT_DEFAULT);
  aVar = getenv ("MMGT_CLEAR");
  Standard_Boolean toClear     = (aVar != NULL ? (atoi (aVar) != 0) : (MMGT_CLEAR_DEFAULT != 0));

  // on Windows (actual for XP and 2000) activate low fragmentation heap
  // for CRT heap in order to get best performance.
  // Environment variable MMGT_LFH can be used to switch off this action (if set to 0)
#if defined(_MSC_VER)
  aVar = getenv ("MMGT_LFH");
  if ( aVar == NULL || atoi (aVar) != 0 )
  {
    ULONG aHeapInfo = 2;
    HANDLE aCRTHeap = (HANDLE)_get_heap_handle();
    HeapSetInformation (aCRTHeap, HeapCompatibilityInformation, &aHeapInfo, sizeof(aHeapInfo));
  }
#endif

  switch (anAllocId)
  {
    case 1:  // OCCT optimized memory allocator
    {
      aVar = getenv ("MMGT_MMAP");
      Standard_Boolean bMMap       = (aVar != NULL ? (atoi (aVar) != 0) : (MMGT_MMAP_DEFAULT != 0));
      aVar = getenv ("MMGT_CELLSIZE");
      Standard_Integer aCellSize   = (aVar != NULL ?  atoi (aVar) : MMGT_CELLSIZE_DEFAULT);
      aVar = getenv ("MMGT_NBPAGES");
      Standard_Integer aNbPages    = (aVar != NULL ?  atoi (aVar) : MMGT_NBPAGES_DEFAULT);
      aVar = getenv ("MMGT_THRESHOLD");
      Standard_Integer aThreshold  = (aVar != NULL ?  atoi (aVar) : MMGT_THRESHOLD_DEFAULT);
      myFMMgr = new Standard_MMgrOpt (toClear, bMMap, aCellSize, aNbPages, aThreshold);
      break;
    }
    case 2:  // TBB memory allocator
      myFMMgr = new Standard_MMgrTBBalloc (toClear);
      break;
    case 0:
    default: // system default memory allocator
      myFMMgr = new Standard_MMgrRaw (toClear);
  }
}

//=======================================================================
//function : ~Standard_MMgrFactory
//purpose  : 
//=======================================================================

Standard_MMgrFactory::~Standard_MMgrFactory()
{
  if (  myFMMgr ) {
    myFMMgr->Purge(Standard_True);
//  delete myFMMgr;
//  myFMMgr = 0;  
  }
}

//=======================================================================
// function: GetMMgr
//
// This static function has a purpose to wrap static holder for memory 
// manager instance. 
//
// Wrapping holder inside a function is needed to ensure that it will
// be initialized not later than the first call to memory manager (that
// would be impossible to guarantee if holder was static variable on 
// global or file scope, because memory manager may be called from 
// constructors of other static objects).
//
// Note that at the same time we could not guarantee that the holder 
// object is destroyed after last call to memory manager, since that 
// last call may be from static Handle() object which has been initialized
// dynamically during program execution rather than in its constructor.
//
// Therefore holder currently does not call destructor of the memory manager 
// but only its method Purge() with Standard_True.
//
// To free the memory completely, we probably could use compiler-specific 
// pragmas (such as '#pragma fini' on SUN Solaris and '#pragma init_seg' on 
// WNT MSVC++) to put destructing function in code segment that is called
// after destructors of other (even static) objects. However, this is not 
// done by the moment since it is compiler-dependent and there is no guarantee 
// thatsome other object calling memory manager is not placed also in that segment...
//
// Note that C runtime function atexit() could not help in this problem 
// since its behaviour is the same as for destructors of static objects 
// (see ISO 14882:1998 "Programming languages -- C++" 3.6.3)
//
// The correct approach to deal with the problem would be to have memory manager 
// to properly control its memory allocation and caching free blocks so 
// as to release all memory as soon as it is returned to it, and probably
// even delete itself if all memory it manages has been released and 
// last call to method Purge() was with True.
//
// Note that one possible method to control memory allocations could
// be counting calls to Allocate() and Free()...
//
//=======================================================================

static Standard_MMgrRoot* GetMMgr()
{
  static Standard_MMgrFactory aFactory;
  return aFactory.myFMMgr;
}

//=======================================================================
//function : Allocate
//purpose  : 
//=======================================================================

Standard_Address Standard::Allocate(const Standard_Size size)
{
  return GetMMgr()->Allocate(size);
}

//=======================================================================
//function : Free
//purpose  : 
//=======================================================================

void Standard::Free(Standard_Address& aStorage)
{
  GetMMgr()->Free(aStorage);
}

//=======================================================================
//function : Reallocate
//purpose  : 
//=======================================================================

Standard_Address Standard::Reallocate(Standard_Address& aStorage,
				      const Standard_Size newSize)
{
  return GetMMgr()->Reallocate(aStorage, newSize);
}

//=======================================================================
//function : Purge
//purpose  : 
//=======================================================================

Standard_Integer Standard::Purge()
{
  return GetMMgr()->Purge();
}
