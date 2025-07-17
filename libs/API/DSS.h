#pragma once
#include "../../../../../../ExtraC/core/include/std-all.h"
#include "../../../include/tundra.h"
#include "data-structs.h"
#include "virtual-drivers.h"

/*----------------------------------------------|
     DEVICE SYSTEM SYNCHRONIZATION PROTOCAL	|
----------------------------------------------*/
/*
 * This protocal is built on top of a NACK-Oriented Reliable Multicast (NORM)
 * implementation for IP socket connections. Although this implementation mostly
 * follows the standard specified by (RFC 5740), there are going to be some 
 * differences mainly in order to limit scope and complexity
 *
 * -blueberry
 */

typedef struct {
	u32 root_num;
}DSS_Address;

typedef struct {

}DSS_ServerInfo;

typedef struct {

}DSS_SystemInfo;

typedef struct {

}DSS_DeviceQuery;

Class(DSSClient,
__INIT(u8 remote : 1; inst(Connection) connection),
__FIELD(
	inst(Connection) connection;
      	DSS_Address address;
	u8 remote : 1; 
),
	#define DSS_REMOTE true
      	#define DSS_LOCAL false
	errvt method(DSSClient, RegisterProcess);
	errvt method(DSSClient, MountTree);
	errvt method(DSSClient, GetSysInfo,, DSS_SystemInfo* result);
	errvt method(DSSClient, GetSrvInfo,, DSS_ServerInfo* result);
	errvt method(DSSClient, QueryDevice,, DSS_DeviceQuery* result);
)

inst(Connection) DSSClient_ConnectLocal();
inst(Connection) DSSClient_ConnectRemote(u8 domain, void* address);
void test(){

	inst(DSSClient) tundra_server = new(DSSClient, DSS_LOCAL , DSSClient_ConnectLocal());
	
	check(NULL) tundra_server ){
		exitTundra();
	}

	DSSClient.GetSrvInfo(tundra_server)
}
