#include "port_hub.h"


unsigned char in(unsigned short port)
{
	/* "=a" (result) means: put AL register in variable result when finished */
	/* "d" (port) means: load EDX with port */
	unsigned char result;
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	return result;
}

void out(unsigned short port, unsigned char data)
{
	/* "a" (_data) means: load EAX with _data */
	/* "d" (_port) means: load EDX with _port */
	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}
