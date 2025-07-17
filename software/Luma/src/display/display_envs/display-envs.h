#pragma once
#include "../display.h"
#include "std-libc.h"



typedef const struct display_env {
	errvt(*init_func)();
	errvt(*exit_func)();
	display_id(*display_alloc)();	
	errvt(*display_edit)(display_id, display_blueprint);	
	errvt(*display_delete)(display_id);
	errvt(*status_display)(display_id, display_report*);	
	errvt(*renderer_loaders[RENDERER_CUSTOM])(va_list user_args);
	renderer_id(*add_renderer)(bool(*)(display_id));
	errvt(*remove_renderer)(renderer_id);
	errvt(*run_display_loop)();	
}display_env;	

/*--------------------------------------|
    Standard Display Enviroment Utils  	|
--------------------------------------*/

/*--------------|
     Loaders	|
--------------*/

errvt GXsys_loader_opengl(va_list userargs);
errvt GXsys_loader_vulkin(va_list userargs);
