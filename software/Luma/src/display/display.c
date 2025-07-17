#include "./display.h"
#include "./display_envs/display-envs.h"

display_id GXsys_display_create(display_blueprint* blueprint){
	display_blueprint data = blueprint == NULL ? DEFAULT_DISPLAY : *blueprint;
	display_id res = __DISPLAY_ENVIRONMENT->display_alloc();
	__DISPLAY_ENVIRONMENT->display_edit(res, data);

	return res;
};
renderer_id GXsys_renderer_create(renderer_blueprint blueprint, ...){
	va_list args;
	va_start(args, blueprint);

	if(blueprint.type != RENDERER_CUSTOM){
		if(__DISPLAY_ENVIRONMENT->renderer_loaders[blueprint.type] != NULL)
			__DISPLAY_ENVIRONMENT->renderer_loaders[blueprint.type](args);
	}
	renderer_id res = __DISPLAY_ENVIRONMENT->add_renderer(blueprint.render_loop);	
		
	va_end(args);
return res;
}


errvt GXsys_display_run(display_id display, renderer_id renderer, u8 flags);
