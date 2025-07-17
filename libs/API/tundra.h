/*---------------------------------------------------------------------------
MIT License

Copyright (c) 2025 CitronLabs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
---------------------------------------------------------------------------*/
#pragma once
#include "config.h"
#include "./tun/types.h"
#include "./tun/device.h"
#include "./tun/frames.h"
#include "./tun/events.h"

/*----------------------------------\
	`   *	~	* , .+	     \	
 	( TUNDRA STANDARD LIBARARY )  \	
 	` ~	* +- ` ~ ~..	       \	
	/\_ _/|     + ` . -.  + ~	\
       /   , ,)_ 	  *.~ 	*	 \	   
       ( ~     7 	    *` .~	  \
   _   /     )   	 *`  '	,	   \
  )  \/_(    |	 	   *  .~  -	    \
  u*  .*	 	  . , `		     \
 (       |   |	 	 ` ~ ,		      \
  \ _ ) )|_) |_) 	  .		       \
----------------------------------------------*/

#define V_ALPHA 		3
#define V_BETA 			2
#define V_RELEASECANDIATE 	1
#define V_RELEASE 		0

static const int __tundra_version[5] = {
	0, V_RELEASE,
	1, V_RELEASE,
	0
};

#if NON_NATIVE
errvt initTundra(u32 num_drivers, const char** driver_names);
errvt exitTundra();
#endif



