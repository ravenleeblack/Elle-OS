#include "clock.h"


static aisle click = 0;


void system_clock_interrupt(struct registers regs)
{
	click++;
}

void load_timer()
{

	// Send the command byte.
	outb(timer_mode, square_wave);

	// Send the frequency divisor.
	outb((timer_count & 0xff), timer_0);
	outb((timer_count >> 8) & 0xff, timer_0);

	// Firstly, register our timer callback.
	load_request(req_timer, &system_clock_interrupt);

}
