#include <tun/types.h>

/*------------------------------|
    TUNDRA DEVICE FILE UTILS	|
-------------------------------*/


typedef u32 block_addr;
typedef	u64 module_tokn;
#define blk_addr(to) block_addr
#define mod_addr(to) module_tokn

typedef struct{
	u64 group : 32;
	u64 module : 32;
}module_token;

enum dev_type {
	DEV_NULL,	// invalid device type
	DEV_BLOCK, 	// storage devices
	DEV_COMMS, 	// networking, IPC, ports, etc
	DEV_IN,  	// generic input device
	DEV_OUT, 	// generic output device 
	DEV_CTRL,	// devices that control other devices
	DEV_OTHER	// miscellaneous devices 
};

/** 
 	TUNDRA DEVICE DESCRIPTOR
 * this is the header to every .dev file 

 * it outlines basic compatibility and versioning which
 can be use to determine the rest of the file format,

 * for example if the boot flag is set then the file is intended
 to run at boot time so instead of the regular file layout header 
 a boot layout header is defined in its place 

*/
typedef struct{
	u8  magic   [8]    	;  // must be defined as ".TUN_DEV"	
	u8  arch    [8]  	;  // intended system architecture	
	u8  version [2]		;  // currently only 1 is allowed here padded with spaces	
	
	// Device Identification
	u8  device_type : 3	;  // used purely for id reasons has no effect the content or usage of device
	u8  boot 	: 1	;  // for devices intent on running at boot time nullifies read_only flag since always read only
	u8  read_only   : 1	;  // locks the file so no more modifications can be made after creation

	// File Layout
	u16 block_size		;  // size in bytes of 1 block on the file
	u32 total_block_num	;
	u32 blocks_per_group	;
		
	blk_addr(dev_group[]) groups_start; 	// the starting block of dev_groups
	blk_addr(dev_group) last_empty;		// the last emptied group slot
	
	/** using this layout we can calculate these fields
	//
	// - num_dev_groups = (total_block_num - groups_start) / blocks_per_group
	// - desired_group_start =  groups_start + (index * blocks_per_group)
	*/ 

}__attribute__((packed)) 
dev_descriptor;

typedef struct{
	struct


}__attribute__((packed))
dev_module;

/**
 	TUNDRA DEVICE GROUP
 * this is what added on whenever more space is required
 * it includes :
 	- meta-data (1 block)
	    --> for managing the allocation of componants within the group
	
	- module descriptor table ((blk_per_group - sizeof(data blocks) - 1) blocks)
	   --> describes all of the features and protections of the module 
	      as well as what registers belong to the module and thier locations

	- data blocks ((blk_per_group - sizeof(module descriptor table) - 1) blocks)
	   --> where all of the data required to be stored for the module belongs
*/
typedef struct{
	u32 MDT_num_entries;
	u32 MDT_last_free;
	blk_addr(dev_group) next_free_group;
	//data_blocks_start = blk_per_group - ((MDT_num_entries * sizeof(dev_module)) / blk_size)
	
}__attribute__((packed))
dev_group_metadata;

typedef struct{
	dev_group_metadata meta_data;
	dev_node_module* module_descriptor_table;
    	void* data_blocks;
}dev_group

typedef struct dev_file dev_file;
/*
	.dev File Format
Header:
    -struct dev_descriptor 
Groups:
    dev_group:
    	- struct dev_group_metadata

	module_descriptor_table:
	    - struct dev_module ...
	
	data_blocks:
	    - 
    	

*/

dev_file* tdutils_createDevFile(dev_descriptor header, dev_group_metadata** layout); 

