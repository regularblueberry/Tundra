#include "../../../include/tundra.h"
#include "../__common/virtual-drivers.h"
#include "internal_data.h"
#include "dlfcn.h"
#include <sys/mman.h>
#include "sys/device-tree.h"
#include <stdio.h>
#include <stdlib.h>


__tundra_driver* initTundraDrivers(u32 num_drivers, const char** drivers_names){

	std_list(__tundra_driver) active_drivers = 
		listInit(num_drivers, __tundra_driver);
	loop(i, num_drivers){
	    listForEach(tunData.avaliable_drivers, std_str, avaliable_driver){
	    	if(stringCompare(
		   str_cast((char*)drivers_names[i], 255), 
		   avaliable_driver)
		){
		}
	    }

	}
	
	 
return listFreeToPointer(active_drivers);
}

std_socket* initTundraServerConn(){

	std_socket* tundra_server = 
		socketInit((socket_settings){
		.domain = SOCKET_DOMAIN_LOCAL,
		.protocal = SOCKET_PROTOCAL_UDP,
		.blocking = false,
	});

	checkposterr(tundra_server == NULL, 
	      ERR_INITFAIL, "could not create tundra server socket", 
	      return NULL;)

	checkposterr(socketConnect(tundra_server, 
		(u8*)&(socklocal_target){
		  .target_type = SOCKET_DOMAIN_LOCAL,
		  .path = s("./__SOCKET") 
		}
	) != ERR_NONE,
	ERR_INITFAIL, "failed to bind to the tundra server socket",
	return NULL)
	
	// TODO: initialize server shared memory 

return tundra_server;
}

std_dir* initTundraEnvironment(){

	char* home_path = getenv("TUNDRA_HOME");

	checkposterr(home_path == NULL, 
	      ERR_INITFAIL, "TUNDRA_HOME environment variable not set",
	      return NULL;)

	std_dir* home_dir;
	checkposterr((home_dir = dirGet(home_path, DFL_READ)),
	      ERR_INITFAIL, "could not find directory pointed to by TUNDRA_HOME")
	
	dirSetCurrent(home_path);

return home_dir;
}

errID initTundra(u32 num_drivers, const char** drivers_names){
	
	checkposterr((tunData.home_dir = 
		initTundraEnvironment()) == NULL,
	      ERR_INITFAIL, "failed to establish tundra home environment",
	      return ERR_INITFAIL;)
	
	checkposterr((tunData.service_socket = 
		initTundraServerConn()) == NULL,
	      ERR_INITFAIL, "failed to connect to the tundra server",
	      return ERR_INITFAIL;)

	checkposterr((tunData.active_drivers = 
		initTundraDrivers(num_drivers, drivers_names)) == NULL,
	      ERR_INITFAIL, "failed to initialize drivers",
	      return ERR_INITFAIL;)

	checkposterr(initSYSDeviceTree() != ERRID_NOERR, 
	      ERR_INITFAIL, "failed to initialize system device tree",
	      return ERR_INITFAIL;)
		
return ERRID_NOERR;
}
errID exitTundra(){}
