#pragma once
#include "std-libc.h"

typedef u32 display_id;
typedef u32 renderer_id;


enum DISPLAY_VISIBILITY{VIS_HIDE, VIS_SHOW, VIS_MIN, VIS_MAX};
typedef struct display_blueprint{
	u32 height,width,x,y;
	enum DISPLAY_VISIBILITY visibility;
}display_blueprint;

typedef struct display_report{
	u32 height,width,x,y;
	enum DISPLAY_VISIBILITY visibility;
}display_report;

enum display_run_flags{
	RUN_NEWTHREAD = 0x01
};

display_id GXsys_display_create(display_blueprint* blueprint);
errvt GXsys_display_run(display_id display, renderer_id renderer, u8 flags);

