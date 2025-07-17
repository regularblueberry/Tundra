#include "./display-envs.h"
#include "X11/Xlib.h"
#include "std-data.h"
#include <X11/X.h>



typedef struct x11_envdata{
	u8 running : 1;
	u8 init : 1;
	Display* X11_display;
	Window X11_root;
	std_list(x11_displaydata) displays;
}x11_envdata;


typedef struct x11_displaydata{
	u8 active : 1;
	u8 alloced : 1;
	display_blueprint data;
	Window window;
}x11_displaydata;
