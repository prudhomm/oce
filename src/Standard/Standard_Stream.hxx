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

// Purpose:   Includes standard header files containing definition of streams;
//            defines macro USE_STL_STREAM if C++ standard STL streams are used
//            as opposed to obsolete non-standard streams.
//            Macro USE_OLD_STREAMS may be defined externally to command using 
//            old streams on WNT; otherwise new streams are used whenever available.
//            Macro NO_USING_STD may be defined externally to avoid "using"
//            declaratiions for types from std namespace.

#ifndef _Standard_Stream_HeaderFile
#define _Standard_Stream_HeaderFile

#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifdef USE_STL_STREAM
#undef USE_STL_STREAM
#endif

// Unix variant
#ifndef WNT

#ifdef OCE_HAVE_IOSTREAM
  #include <iostream>
  #define USE_STL_STREAM
#elif defined (OCE_HAVE_IOSTREAM_H)
  #include <iostream.h>
#else
  #error "check config.h file or compilation options: either OCE_HAVE_IOSTREAM or OCE_HAVE_IOSTREAM_H should be defined"
#endif

#ifdef OCE_HAVE_IOMANIP
  #include <iomanip>
#elif defined (OCE_HAVE_IOMANIP_H)
  #include <iomanip.h>
#endif

#ifdef OCE_HAVE_FSTREAM
  #include <fstream>
#elif defined (OCE_HAVE_FSTREAM_H)
  #include <fstream.h>
#endif

// Windows variant
#else /* WNT */

// Macro USE_OLD_STREAMS may be defined externally to command 
// using old streams on Windows NT; otherwise new streams are used
#ifndef USE_OLD_STREAMS
  #include <iostream>
  #include <iomanip>
  #include <fstream>
  #define USE_STL_STREAM
#else
  #include <iostream.h>
  #include <iomanip.h>
  #include <fstream.h>
#endif /* USE_OLD_STREAMS */

#endif /* WNT */

// "using" declaration for STL types is still necessary
// as OCCT code contains too much of this staff without std: prefix
#if defined(USE_STL_STREAM) && ! defined(NO_USING_STD)
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::filebuf;
using std::streambuf;
using std::streampos;
using std::ios;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ends;
using std::flush;
using std::setw;
using std::setprecision;
using std::hex;
using std::dec;
#endif

#endif /* _Standard_Stream_HeaderFile */
