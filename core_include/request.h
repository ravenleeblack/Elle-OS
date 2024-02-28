#ifndef _request_h_
#define _request_h_
#include "types.h"
#include "service.h"

// irq = requests
extern void handle_core_request(registers regs);
extern void load_request(int irq, service handler);
extern void unload_request(int irq);


#endif
