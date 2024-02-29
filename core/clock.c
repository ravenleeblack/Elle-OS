#include "clock.h"

static aisle click = 0;

void system_clock_interrupt(struct registers regs)
{
   click++;
}

void load_timer()
{
    outb(timer_mode, square_wave);                          // Send the command byte.

	outb((timer_count & 0xff), timer_0);              	    // Send the frequency divisor.
	outb((timer_count >> 8) & 0xff, timer_0);
	
	load_request(req_timer, &system_clock_interrupt);  	    // request an interrupt for the system timer
}
