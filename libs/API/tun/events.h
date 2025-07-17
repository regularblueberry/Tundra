#include "types.h"

/*------------------------------|
	 <tun/events.h>		|
       Ring Level 0-3 API	|
-------------------------------*/

enum event_types{
	EVNT_DESTROY,	// raised when the device has been destroyed
	EVNT_MODIFY,	// raised when the device has been modified
	EVNT_REQUEST,	// raised when data is being requested from the device
	EVNT_NEWDATA,	// raised when data is being sent through the device
	EVNT_USERALRT,	// raised when the user calls the evntAlert function on the device
};
typedef union {
    struct{
	u64 port : 32;
	u64 event_type : 32;
    };
	u64 id;
}evntID;


evntID evntCreate(__device device, u32 event_type, u32 port);

errvt evntDestory(__device device, evntID event);
//Returns the number of events queued up 
u64 evntCheck(__device device);
//Returns the evntID of this first event queued up 
evntID evntGet(__device device);

errvt evntAlert(__device device);

