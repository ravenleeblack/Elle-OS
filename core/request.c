#include "request.h"

void load_request(int irq, service handler)
{
    handle_interrupt[irq] = handler;
}

void unload_request(int irq)
{
     handle_interrupt[irq] = 0;
}


void handle_core_request(registers regs)
{
     if (regs.interrupt_index >= 40)
     {	
	outb(0xA0, 0x20);  // Send reset signal to slave.
     }
     outb(0x20, 0x20);   	// Send reset signal to master. (As well as slave, if necessary).

     if (handle_interrupt[regs.interrupt_index] != 0)
     {
	service handler = handle_interrupt[regs.interrupt_index];
	handler(regs);
     }
     asm("sti");
}
