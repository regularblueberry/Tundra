#pragma once
#include "../../../include/tundra.h"





__device __tun_syscall_load_implem(const char* dev_path, devID DID, u32 dev_flags);
__stream __tun_syscall_query_implem(__device dev, void* query_data, size_t query_len, int query_opts);
__stream __tun_syscall_conn_implem(devID process_device, int stream_port, i32 stream_flags);
int __tun_syscall_pull_implem(__stream strm, void* buf, size_t len);
int __tun_syscall_send_implem(__stream strm, void* buf, size_t len);
int __tun_syscall_request_implem(__stream strm, void* send_buf, size_t send_len, void* pull_buf, size_t pull_len);
int __tun_syscall_close_implem(int resource);
devID __tun_syscall_devcreate_implem(devID root, size_t num, devName* children, devID* devIDS);
errID __tun_syscall_devhandle_implem(devID DID, size_t num, u32* device_ports, __stream* port_streams);
errID __tun_syscall_devdestroy_implem(devID DID);
errID __tun_syscall_devctrl_implem(devID DID, void* ctrl_data, size_t ctrl_len);
errID __tun_syscall_devinfo_implem(const char* path, dev_info* info_buf);
