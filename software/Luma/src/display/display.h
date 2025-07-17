#pragma once
#include "../GXinternal.h"
#include "std-libc.h"

typedef const struct display_env display_env;	

/*--------------|
  Display Envs	|
--------------*/
extern display_env GXsys_displayenv_X11;
static const display_env* __DISPLAY_ENVIRONMENT = NULL;













