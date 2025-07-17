#include "./X11-displayenv.h"
#include "err.h"
#include "std-libc.h"
#include "std-data.h"
#include "std-error.h"
#include <X11/Xlib.h>
#include <stdbool.h>


x11_envdata _ENV_X11 = {0};


errvt INIT_FUNC(){
	checkreturnerr(_ENV_X11.init, 
		SGXERR_ENV_INITFAIL, "Display Environment already initialized")

	_ENV_X11.X11_display = XOpenDisplay(NULL);
	checkreturnerr(_ENV_X11.X11_display == NULL, 
		SGXERR_ENV_INITFAIL, "Failed to open display");
	
	_ENV_X11.X11_root = DefaultRootWindow(_ENV_X11.X11_display);
	checkreturnerr(_ENV_X11.X11_root == None, 
		SGXERR_ENV_INITFAIL, "No root window found", 
		XCloseDisplay(_ENV_X11.X11_display)
	)
	_ENV_X11.displays = listInit(5, sizeof(x11_displaydata));

	_ENV_X11.init = true;
return NOERROR;
}

errvt EXIT_FUNC(){
	checkreturnerr(!_ENV_X11.init, 
		SGXERR_ENV_EXITFAIL, "Display Environment cannot be exited without initialization")

	x11_displaydata* active_displays = listGetPointer(_ENV_X11.displays,0);
	loop(i, listSize(_ENV_X11.displays)){
		if(active_displays[i].alloced)
		XDestroyWindow(_ENV_X11.X11_display,active_displays[i].window);
	}
	listFree(_ENV_X11.displays);

	XCloseDisplay(_ENV_X11.X11_display);

	_ENV_X11.init = false;
return NOERROR;
}


display_id ALLOC_DISPLAY(){
	display_id res = listSize(_ENV_X11.displays);
	listAppend(_ENV_X11.displays, &(x11_displaydata){
		.window = XCreateSimpleWindow(
			_ENV_X11.X11_display,
			_ENV_X11.X11_root,
			DEFAULT_DISPLAY.x,
			DEFAULT_DISPLAY.y,
			DEFAULT_DISPLAY.width,
			DEFAULT_DISPLAY.height,
			0,0,0x00000000
		)
	});
return res;
}
errvt EDIT_DISPLAY(display_id id, display_blueprint blueprint){
	x11_displaydata* data = listGetPointer(_ENV_X11.displays, id);
	checkreturnerr(data == NULL, 
		SGXERR_ENV_DISPLAYEDIT, "display id out of range")
	data->data = blueprint; 
return NOERROR;
}





display_env GXsys_displayenv_X11 = {
	.init_func = INIT_FUNC,
	.display_alloc = ALLOC_DISPLAY,
	.display_edit = EDIT_DISPLAY,
	.renderer_loaders[RENDERER_OPENGL] = GXsys_loader_opengl,
	.renderer_loaders[RENDERER_VULKIN] = GXsys_loader_vulkin
};
