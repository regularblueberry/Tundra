#include "./device-tree.h"
#include "../internal_data.h"


errID initSYSDeviceTree(){

return ERRID_NOERR;
}

devID resolveDevicePath(const char* path){

	std_str path_str = str_cast((char*)path, 255); 

	if(path_str.txt[0] != '.' && !isalnum(path_str.txt[0]))
		return 0;

	loop(i, path_str.len){
		if(path_str.txt[i] == ':')
			break;
	}


}
