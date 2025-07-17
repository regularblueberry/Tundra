#pragma once
#include "./utils/_pos.h"
#include "./utils/_color.h"


typedef struct guml_mesh guml_mesh;
typedef struct guml_element_data guml_element_data;


typedef struct guml_page_data guml_page_data;

typedef struct GUML_PAGE {
	guml_color background;
	guml_page_data* data;
}GUML_PAGE;
