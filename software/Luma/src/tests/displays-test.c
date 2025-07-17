#include "display/renderer-data.h"
#include "std-libc.h"
#include "graphics.h"


render_status render_loop(display_id display){


return RENDER_CONTINUE;
}

bool RUN_DISPLAYS_TEST(){
	display_id test_display = GXsys_display_create(NULL);
	renderer_id test_renderer = GXsys_renderer_create(
		(renderer_blueprint){.type = RENDERER_OPENGL, .render_loop = render_loop});
	
	GXsys_display_run(test_display, test_renderer, 0);

return true;
}
