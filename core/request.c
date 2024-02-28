#include "request.h"


/* Installs a custom IRQ handler for the given IRQ */
void load_request(int irq, service handler)
{
	handle_interrupt[irq] = handler;
}


/* Clears the handler for a given IRQ */
void unload_request(int irq)
{
	handle_interrupt[irq] = 0;
}


void handle_core_request(registers regs)
{
	// Send an EOI (end of interrupt) signal to the PICs. If this interrupt involved the slave.
	if (regs.interrupt_index >= 40)
	{
		// Send reset signal to slave.
		outb(0xA0, 0x20);
	}
	// Send reset signal to master. (As well as slave, if necessary).
	outb(0x20, 0x20);

	if (handle_interrupt[regs.interrupt_index] != 0)
	{
		service handler = handle_interrupt[regs.interrupt_index];
		handler(regs);
	}

	asm("sti");
}
