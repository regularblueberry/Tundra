#define __GUML
#define USE_DEFAULTS
#define BUILTINS_
#include "std-libc.h"
#include "base-graphics.h"


void createbutton(){
	_Layout{
	    	_box(0)
		{

		}

	}
}
#define _Render()
render_status render_loop(display_id display){
	GUML_PAGE startpage = {0};

__START
	_SelectPage(&startpage,
	_Layout{
	    _box(
	    .bgcolor = 1.0
	    ){
		createbutton();
		createbutton();
		createbutton();
	    }
	}
	)
	_Render()

__END

return RENDER_CONTINUE;
}

bool RUN_GUML_TEST(){

	display_id test_display = GXsys_display_create(NULL);
	renderer_id test_renderer = GXsys_renderer_create(
		(renderer_blueprint){
			.type = RENDERER_CUSTOM,
			.custom_renderer_loader = GXsys_GUML_rendererloader, 
			.render_loop = render_loop}
	);
	
	GXsys_display_run(test_display, test_renderer, 0);

return true;
}
