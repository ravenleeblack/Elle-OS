#ifndef _core_h_
#define _core_h_
#include "types.h"
#include "port_hub.h"
#include "gdt.h"
#include "idt.h"
#include "keyboard.h"
#include "service.h"
#include "clock.h"
#include "main_frame.h"
#include "sub_frame.h"
#include "terminal.h"
#include "memory.h"
#include "screen.h"

int init_core();
int _core(int argc, const char *argv[]);


#endif
