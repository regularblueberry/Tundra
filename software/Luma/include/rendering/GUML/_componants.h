#pragma once
#include "std-libc.h"
#include "_core.h"

#define COMPONANT_MACRO_LAYOUT(element_name,...) \
for( 				\
	errvt error = GXsys_GUML_pushnode( 	\
	    GXsys_GUML_newcomponant( 		\
	    (guml_element_data*) 		\
	    &NEW_ELEMENT(element_name,		\
		__VA_ARGS__))) 			\
	;					\
	runLoopOnce(&error)			\
	;					\
	GXsys_GUML_popnode()			\
)

#define _Layout 				\
for( 						\
	errvt error = 				\
	GXsys_GUML_treebuilder_layoutstart()	\
	;					\
	runLoopOnce(&error)			\
	;					\
	GXsys_GUML_treebuilder_layoutend()			\
)



#define _SelectPage(page, ...) 				\
	GXsys_GUML_treebuilder_selectpage(page);	\
	__VA_ARGS__ 					\
	GXsys_GUML_treebuilder_deselectpage();

#define __START GXsys_GUML_treebuilder_start();
#define __END GXsys_GUML_treebuilder_end();

typedef struct GUML_COMPONANT_NODE GUML_COMPONANT_NODE;

bool runLoopOnce(errvt* errorcode);
errvt GXsys_GUML_pushnode(GUML_COMPONANT_NODE* node);
errvt GXsys_GUML_popnode();
GUML_COMPONANT_NODE* GXsys_GUML_newcomponant(guml_element_data* element);

void GXsys_GUML_treebuilder_start();
void GXsys_GUML_treebuilder_end();
errvt GXsys_GUML_treebuilder_layoutstart();
errvt GXsys_GUML_treebuilder_layoutend();
errvt GXsys_GUML_treebuilder_selectpage(GUML_PAGE* page);
errvt GXsys_GUML_treebuilder_deselectpage();



