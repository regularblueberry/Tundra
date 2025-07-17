#pragma once
#include "std-libc.h"

typedef u32 display_id;
typedef u32 renderer_id;


typedef enum renderer_type{ RENDERER_OPENGL, RENDERER_VULKIN, RENDERER_CUSTOM }renderer_type;

typedef bool render_status;
#define RENDER_STOP false
#define RENDER_CONTINUE true

typedef struct renderer_blueprint{
	renderer_type type;
	render_status(*render_loop)(display_id);
	errvt(*custom_renderer_loader)(va_list user_args);
}renderer_blueprint;





renderer_id GXsys_renderer_create(renderer_blueprint blueprint, ...);
