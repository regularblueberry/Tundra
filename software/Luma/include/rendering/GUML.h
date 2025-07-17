#pragma once
#include "std-libc.h"

/*\<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\
                                          .         .				 |
     ,o888888o.    8 8888      88        ,8.       ,8.          8 8888           |
    8888     `88.  8 8888      88       ,888.     ,888.         8 8888           |
 ,8 8888       `8. 8 8888      88      .`8888.   .`8888.        8 8888           |
 88 8888           8 8888      88     ,8.`8888. ,8.`8888.       8 8888           |
 88 8888           8 8888      88    ,8'8.`8888,8^8.`8888.      8 8888           |
 88 8888           8 8888      88   ,8' `8.`8888' `8.`8888.     8 8888           |
 88 8888   8888888 8 8888      88  ,8'   `8.`88'   `8.`8888.    8 8888           |
 `8 8888       .8' ` 8888     ,8P ,8'     `8.`'     `8.`8888.   8 8888           |
    8888     ,88'    8888   ,d8P ,8'       `8        `8.`8888.  8 8888           |
     `8888888P'       `Y88888P' ,8'         `         `8.`8888. 8 888888888888   |
										 |
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/


/*\------------------|
    INIT FUNCTIONS   |
/------------------*/

errvt GXsys_GUML_rendererloader(va_list user_args);

/*\------------------|
         GUML        |
/------------------*/
#define __GUML
#ifdef __GUML


#define	_CUSTOM_ 0x00
#define	_SIMPLE_ 0x01
#define	_INVOVLED_ 0x02


#define	_OPENGL_ 0x01
#ifdef USE_DEFAULTS
	#define __PROFILE _SIMPLE_
	#define __GFXAPI _OPENGL_
#endif

#if defined(__PROFILE) && defined(__GFXAPI)
#if __PROFILE == _SIMPLE_
	#include "GUML/_componants.h"
	#include "GUML/_render.h"

#elif __PROFILE == _INVOLVED_
	#include "GUML/_elements.h"
	#include "GUML/_componants.h"
	#include "GUML/_render.h"
#elif __PROFILE == _CUSTOM_
#endif

#ifdef DEBUG_
#include "GUML/_debug.h"
#endif

#ifdef BUILTINS_
#include "GUML/_builtins.h"
#endif

#endif
#endif









