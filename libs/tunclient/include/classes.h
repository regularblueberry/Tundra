#pragma once
#include "../../../../../../ExtraC/core/include/std-all.h"
#include "../../../include/tundra.h"



typedef struct{
	u64 root : 32;
	u64 self : 32;
}devID_def; 


typedef struct TundraDevice_Instance TundraDevice_Instance;

Class(TundraStream,
__INIT(inst(TundraDevice) device; u32 port_number),
__FIELD(
	u8 non_block : 1;
	u8 sendable : 1;
	u8 pullable : 1;
),

)

Class(TundraDevice,
__INIT(inst(String) name; inst(TundraDevice) parent;),
__FIELD(
	devID device;
	Pool(__stream) streams;
	u8 non_block : 1;
),
	__stream method(TundraDevice, OpenStream,, u32 port_number);	
	errvt method(TundraDevice, CloseStream,, __stream stream);	
)


Class(DeviceTree,
__INIT(),
__FIELD(
	u16 deepest_nest;
	Map(devName,devID) labels;
	List(u8) names;
),
	

)
