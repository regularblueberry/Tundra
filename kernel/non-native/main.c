#include "../external.h"
#include "./error/handling.h"
#include <stdlib.h>

Data(ServerOptions,
__INIT(int argc; cstr* argv),
	inst(String) env_root;
){

	getopts(args.argc, args.argv,
	case 'r':{
		self->env_root = new(String, OPTARG);
	break;}
	)
return self;
}


int main(int argc, cstr* argv){
	
	inst(TimeWatch) running_time = push(TimeWatch, .start = true);
	
	if(!isinit(running_time)){
		ERR(ERR_INITFAIL, "could not start running time watch");
		return -1;
	}
	
	//cannot fail must always return a valid result
	inst(ServerOptions) opts = push(ServerOptions, argc, argv); 
	
	if(initKernelErrHandling(
		opts->env_root, 
		TimeWatch.getStartTime(running_time)
	) != ERR_NONE){
		ERR(ERR_INITFAIL, 
      			"failed to initialize tundra "
      			"kernel error handler"
      		);
		return -1;
	}

	LOG(INFO, "error handler initialized");



ERR(ERR_ABORT, "unexpected program end");
return -1;
}
