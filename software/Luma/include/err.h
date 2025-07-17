#pragma once
#include "std-error.h"

#define SysGXErrorCodes		\
SGXERR_ENV_INITFAIL,		\
SGXERR_ENV_EXITFAIL,		\
SGXERR_ENV_DISPLAYEDIT,		\
SGXERR_ENV_DISPLAYALLOC		\

extern errvt SysGXErrorCodes;

errvt initSysGXErrorCodes();
