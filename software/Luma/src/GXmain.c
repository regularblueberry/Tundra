#include "GXinternal.h"

errvt SysGXErrorCodes;

errvt initSysGXErrorCodes(){
	SGXERR_ENV_INITFAIL = newerr();
	SGXERR_ENV_DISPLAYALLOC = newerr();
	SGXERR_ENV_EXITFAIL = newerr();
	SGXERR_ENV_DISPLAYEDIT = newerr();	

return NOERROR;
};
