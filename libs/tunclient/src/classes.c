#include "../data-structs.h"




private(TundraDevice,
	devID parent, first_child, next_sibling;
	List(devID) implem_ids; 
	u32 name_hash;
	u32 name_offset;
	u8  name_size;
	u8 interface : 1;
	u8 send_only : 1;
	u8 highest_ring_lvl : 2;
)



private(TundraStream,
	__device device;
	u16 port_number;
	Queue(u8) data;
)

