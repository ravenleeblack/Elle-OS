#ifndef _clock_h_
#define _clock_h_
#include "types.h"
#include "service.h"

#define clicks_per_second 20   // minimum pit frequency is 18.2Hz.

#define timer_0		0x40
#define timer_mode	0x43
#define square_wave     0x36
#define timer_freq	1193182
#define timer_count	(((unsigned)timer_freq)/clicks_per_second)


extern void load_request(int irq, service handler);
void load_timer();



#endif
