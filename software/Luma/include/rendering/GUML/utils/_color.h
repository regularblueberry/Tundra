#pragma once
#include "std-libc.h"

typedef float guml_color[4];
#define RGBA(R,G,B,A)(guml_color){((float)R)/255.0,((float)G)/255.0,((float)B)/255.0,((float)A)/255.0}; 
