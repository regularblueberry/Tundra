#pragma once
#include "./_elements.h"
#include "./_componants.h"

#define simplefrag 


	static const shader(SIMPLE_VERT, GLSL,
		//#insert "./_builtin-shaders/simple-vert.glsl"
	)
	static const shader(SIMPLE_FRAG, GLSL,
		//#insert "./_builtin-shaders/simple-frag.glsl"
	)

	static const mesh(SQUARE,
	__attribs(
		attr_vec(float, 2)
	),
		      1.0f, 0.0f,
		      0.0f, 1.0f,
		      0.0f, 0.0f,
		      1.0f, 1.0f
	)

	elmnt(BOX,
	__data(
		.mesh = (guml_mesh*)&SQUARE_MESH

       	),
		guml_color bgcolor;
	)

#define _box(...) COMPONANT_MACRO_LAYOUT(BOX, __VA_ARGS__)
