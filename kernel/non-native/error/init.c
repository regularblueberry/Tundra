#include "./handling.h"
#include <signal.h>

static data(KLog) 
	* INFO_Log  = NULL,
	* ERROR_Log = NULL
;


#define formatLogPath(logname, stringvar)				\
	StringBuilder.Insert(log_path_builder, env_root->len, NULL, 	\
		/*unix time year calc*/ 				\
		$((time->day / 365) + 1960), 				\
		"-",$(time->hour),					\
		":",$(time->minute),					\
		":",$(time->second),"_", logname 			\
	);								\
	inst(String) stringvar = StringBuilder.CreateStr(log_path_builder);


errvt initKernelErrHandling(inst(String) env_root, inst(Time) start_time){


    //Creating Logs
	inst(StringBuilder) log_path_builder = push(StringBuilder, env_root, 255);  
	
	inst(TimeShort) time = Time.ToTimeShort(start_time);

	formatLogPath("Tundra_Error.log", err_path);
	formatLogPath("Tundra_Info.log", info_path);

    	check(
	   kernel_log = new(Logger,
     		.name = "TundraKernel",
     		.errorlog = new(LogBook, 
		    .object = generic (ERROR_Log = new(KLog, err_path)),
		    .interface = &KLog.Loggable
		),
     		.infolog = new(LogBook, 
		    .object = generic (INFO_Log = new(KLog, info_path)),
		    .interface = &KLog.Loggable
		)
     	    )
    	){return err->errorcode;}
	
	Error.setLogger(kernel_log);

    //Setting up Signal Handler
	Error.setSignalHandler(SIG_ALL, KernelSignalHandler);

    //Freeing Allocations
	pop(log_path_builder);
	pop(time);

return OK;
}
