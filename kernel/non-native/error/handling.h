#include "../../external.h"


Class(KLog,
__INIT(inst(String) name),
__FIELD(),
      	#define LOG(TYPE, ...) Logger.logWithFormat(kernel_log, LOG_##TYPE, __VA_ARGS__)
	interface(Loggable);
)
static inst(Logger) kernel_log = NULL;

errvt initKernelErrHandling(inst(String) env_root, inst(Time) start_time);
void KernelSignalHandler(ErrorSignal signal);
