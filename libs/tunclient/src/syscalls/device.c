#include "../../include/tundra.h"
#include <stddef.h>
#include <errno.h>


__device load(const char* path, devID DID, u32 dev_flags){}
__stream query(__device dev, u32 port, void* query_data, size_t query_len, i32 query_opts){}
__stream conn(devID proc_dev, u32 stream_port, i32 stream_flags){}
size_t pull(__stream strm, void* buf, size_t len){}
size_t send(__stream strm, void* buf, size_t len){}
size_t request(__stream strm, void* send_buf, size_t send_len, void* pull_buf, size_t pull_len){}
i32 close(i32 resource){}
size_t devCreate(devID root, size_t num, devName* children, devID* devIDS){}
size_t devHandle(devID dev, size_t num, u32* device_ports, __stream* port_streams){}
errID devDestroy(devID dev){}
errID devCtrl(devID DID, void* ctrl_data, size_t ctrl_len){}
errID devInfo(const char* path, dev_info* info_buf){}

