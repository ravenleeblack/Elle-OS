#ifndef interrupt_h
#define interrupt_h
#include "types.h"
#include "port_hub.h"
#include "draw_element.h"


void init_interrupt_hub(int base0, int base1);
void enable_interrupt_hub(den irq);
void disable_interrupt_hub(den irq);
void acknowledge_interrupt_hub(den irq);

#endif
