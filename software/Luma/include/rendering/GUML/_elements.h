#pragma once
#include "std-libc.h"
#include "./_core.h"


typedef enum guml_shader_type{
	SHADERTYPE_GLSL
}guml_shader_type;

typedef struct guml_mesh{
	u32* attribs_sizes;
	float* data;
}guml_mesh;

typedef struct guml_shader{
	guml_shader_type type;	
	str shader;
}guml_shader;

typedef struct guml_element_data {
	guml_mesh* mesh;
	guml_shader* shader;
}guml_element_data;


//------------------------------------------------------|
//			ELEMENT MACROS			|
//------------------------------------------------------|
	
/*\------------------|
        MESHES       |
/------------------*/
	#define mesh(name, attribs, ...) 			\
		guml_mesh name##_MESH = { 			\
			.attribs_sizes = (u32[]){attribs},	\
			.data = (float[]){__VA_ARGS__}}; 	
	#define shader(name, _type, ...) 		\
		guml_shader name##_SHADER = {		\
			.type = SHADERTYPE_##_type,	\
			.shader = (str){		\
			.len = sizeof(#__VA_ARGS__), 	\
			.txt = #__VA_ARGS__}};
	#define __attribs(...) __VA_ARGS__
	#define attr_(type) sizeof(type)
	#define attr_vec(type, len) sizeof(type) * len

/*\------------------|
        ELEMENTS     |
/------------------*/
	/*FIRST*/                               #define elmnt(NAME,_data, ...) 		\
	/* Creates a traits struct def for*/    	typedef struct NAME##_TRAITS{	\
	/* new element*/                        		__VA_ARGS__		\
	                                        	}NAME##_TRAITS; 		\
	/*THEN*/                                					\
	/* Creates the actual element struct*/  	typedef struct NAME##_ELEMENT{  \
	/* which stores all of the data for the*/		guml_element_data data; \
	/* element instance*/                   		u64 traits_len; 	\
	                                        		NAME##_TRAITS traits; 	\
							}NAME##_ELEMENT; 		\
		                                					\
	/*FINALLY*/                             	static const 			\
	/* Creates a base struct which holds */ 	NAME##_ELEMENT NAME##_BASE = {	\
	/* constant data such as the mesh and*/ 		_data, 			\
	/* other element meta data*/				sizeof(NAME##_TRAITS), 	\
							(NAME##_TRAITS){0}};
	


	#define __data(...) (guml_element_data){__VA_ARGS__}
	
	#define NEW_ELEMENT(name, ...) 			\
		(name##_ELEMENT){ 			\
		.data = name##_BASE.data, 		\
		.traits_len = name##_BASE.traits_len, 	\
		.traits = {__VA_ARGS__}			\
	}






	






