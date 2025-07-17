#include "./handling.h"

private(KLog,
	FILE* log_file;
)

errvt imethodimpl(KLog, Log,, inst(String) log){
	self(KLog);

	if(fwrite(log->txt, sizeof(char), log->len, priv->log_file) == -1)
		return ERR_FAIL;
return OK;
}

errvt imethodimpl(KLog, Close){
	self(KLog);

	if(fclose(priv->log_file) == -1)
		return ERR_FAIL;
return OK;
}


construct(KLog,
	.Loggable.log = KLog_Log,
	.__DESTROY = KLog_Close
){
	
}
