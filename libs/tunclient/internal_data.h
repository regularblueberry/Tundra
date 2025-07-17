#pragma once
#include "./API.h"
#include "../__common/data-structs.h"
#include "../__common/virtual-drivers.h"
#include "../__common/device_tree-protocal.h"
#include "../../../../../../Berry-StdLibs/extra-c/include/std-all.h"


typedef struct{

	u32 root_number;
	u32 num_active_drivers;
	__tundra_driver* active_drivers;
	
	__tun_device_tree_header device_tree_header;

	std_list(__tun_device_interface) devices;
	u64 last_free_device;
	
	std_thread* mgmt_thread;
	std_socket* service_socket;
	std_dir* home_dir;
	std_list(std_str) avaliable_drivers;
}__tun_data;

static __tun_data tunData = {0};
