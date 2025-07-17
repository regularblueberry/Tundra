#pragma once
#include "types.h"
#include <stddef.h>

/*------------------------------|
	 <tun/device.h>		|
       Ring Level 0-3 API	|
-------------------------------*/

// standard device api for the tundra system utils

#define	TUNDEV_SCHEDULER (__device)1
#define	TUNDEV_TERMINAL  (__device)2
#define	TUNDEV_MEMALLOC  (__device)3
#define	TUNDEV_NETWORK   (__device)4
#define	TUNDEV_DISK	 (__device)5
#define	TUNDEV_FILESYS	 (__device)6
#define	TUNDEV_USERINPUT (__device)7
#define TUNDEV_DISPLAY	 (__device)8
#define TUNDEV_AUDIO 	 (__device)9

#define RES_INVALID -1

/*------------------------------|
      Device Acquisition	|	
-------------------------------*/
/** load syscall
 * ----------------
 * const char* path = 
 *	path in the device tree to the device interface
 *	you want to load
 * 
 * devID DID =
 * 	if !D_IMPLEMENT
 *	    specific implementation id that you want to load 
 *	    if 0 then it will use the default implementation
 *	andif D_CREATE
 *	    default implementation for this interface 
 *	    if 0 then empty interface is created and default 
 *	    is first implementation
 *	else
 *	    implementation you want to link to the interface
 *	    if 0 then error will be returned
 *
 * RETURN_VALUE = 
 *	an i32 representing the an open device descriptor
 *	if the value returned is RES_INVALID (-1) then an 
 *	error has occured and errno has been set
*/
 
#define D_DONTBLOCK 	0x01 // asyncronous device queries
#define D_IMPLEMENT 	0x02 // links DID implementation to interface
#define D_CREATE 	0x04 // creates interface if doesnt exist
#define D_NORETURN 	0x08 // does not return a __device

//loads a device interface into the active device table (ADT) / 
//creates a device interface
__device load(const char* path, devID DID, u32 dev_flags);



/** query syscall
 * ----------------
 * __device dev = 
 *	loaded device resource
 * 
 *  u32 device_port = 
 *  	device port you want to query
 *
 *  void* query_data =
 *  	your query data, this is entirely dependent on
 *  	the specific device implementation you have opened
 *	
 *  size_t query_len =
 *  	your query data len, again this is entirely dependent on
 *  	the specific device implementation you have opened and 
 *  	may or may not refer to the actual length of the data
 *
 * RETURN_VALUE = 
 *	an i32 representing the an open stream descriptor
 *	if the value returned is RES_INVALID (-1) then an 
 *	error has occured and errno has been set
*/

//QUERY OPTIONS

//query a device for a particular stream
__stream query(__device dev, u32 port, void* query_data, size_t query_len, i32 stream_opts);

/** conn syscall
 * ----------------
 * procID PID = 
 *	proccess you want to connect to,
 *	if this is the same as the current process 
 *	then the stream will be created for this proccess'
 *	stream port
 * 
 *  u32 stream_port = 
 *  	device port you want to connect the stream to
 *
 * RETURN_VALUE = 
 *	an i32 representing the an open stream descriptor
 *	if the value returned is RES_INVALID (-1) then an 
 *	error has occured and errno has been set
*/

//STREAM OPTIONS
#define S_DONTBLOCK 0x01
#define S_PULL 0x02
#define S_SEND 0x04
//create a new stream connected to a specific processes stream port
__stream conn(devID device, u32 port, i32 stream_opts);


/*------------------------------|
      Stream Communication	|
-------------------------------*/

/** pull syscall
 * ----------------
 * __stream strm = 
 *	connected stream resource
 *
 *  void* buf = 
 *  	buffer for pulled data
 *
 *  size_t len = 
 *  	number of bytes you want to pull from the stream
 *
 * RETURN_VALUE = 
 *	an size_t representing the number of bytes pulled 
 *	from the stream if the value returned is 0 
 *	then an error has occured and errno has been set
*/
//pull some data from a stream
size_t pull(__stream strm, void* buf, size_t len);

/** pull syscall
 * ----------------
 * __stream strm = 
 *	connected stream resource
 *
 *  void* buf = 
 *  	buffer for sent data
 *
 *  size_t len = 
 *  	number of bytes you want to send to the stream
 *
 * RETURN_VALUE = 
 *	an size_t representing the number of bytes sent
 *	to the stream if the value returned is 0 
 *	then an error has occured and errno has been set
*/
//send some data through a stream
size_t send(__stream strm, void* buf, size_t len);

/** request syscall
 * ----------------
 * __stream strm = 
 *	connected stream resource
 *
 *  void* send_buf = 
 *  	buffer for sent data
 *
 *  size_t send_len = 
 *  	number of bytes you want to send to the stream
 *
 *  void* pull_buf = 
 *  	buffer for pulled data
 *
 *  size_t pull_len = 
 *  	number of bytes you want to pull from the stream
 *
 * RETURN_VALUE = 
 *	a size_t representing the number of bytes pulled 
 *	from the stream if the value returned is 0 
 *	then an error has occured and errno has been set
*/
//short hand for a send call and a pull call in one syscall
size_t request(__stream strm, void* send_buf, size_t send_len, void* pull_buf, size_t pull_len);

/** close syscall
 * ----------------
 * i32 resource = 
 *	resource to close
 *
 * RETURN_VALUE = 
 *	-1 on error and errno has been set,
 *	0 upon no error
 */

//close any loaded resources
i32 close(i32 resource);

/*------------------------------|
	Device Management	|
-------------------------------*/
typedef struct {
	u32 implem_num; 	// number of device implementations
	devID* implem_ids; 	// ids for each implementation
	devName* implem_names;
}dev_info;


devID devGetRoot();

//create a new device implementation
devID devCreate(devID parent, devName name);

//create a new device implementation
size_t devCreateMany(devID root, size_t num, devName* children, devID* devIDS);

//destroy a created device implementation
__stream devHandle(devID dev, u32 port);

//destroy a created device implementation
size_t devHandleMany(devID dev, size_t num, u32* device_ports, __stream* port_streams);

//destroy a created device implementation
errvt devDestroy(devID dev);

//control a device implementation's settings
errvt devCtrl(devID DID, void* ctrl_data, size_t ctrl_len);

//list a device interface's implementations
errvt devInfo(const char* path, dev_info* info_buf);




