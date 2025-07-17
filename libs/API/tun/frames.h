#include "types.h"

/*------------------------------|
	 <tun/frames.h>		|
       Ring Level 0-3 API	|
-------------------------------*/

enum frame_handle_type{
	FRAME_AUTO //  


};
typedef struct{
	u32 handle_type;
	void(*fail_handler)(__stream);
	void(*frame_handler)(__stream);
}frame_handling;


i32 frameCreate(__stream strm, size_t framesize, frame_handling handling);
//if framesize is 0 it returns the current frame size
size_t frameSize(__stream strm, size_t framesize);
i32 frameMod(__stream strm, frame_handling);
i32 framePull(__stream strm, void* framebuff);
i32 frameSend(__stream strm, void* framebuff);
i32 frameHandle(__stream strm);
i32 frameFail(__stream strm);
i32 frameDestroy(__stream strm);

