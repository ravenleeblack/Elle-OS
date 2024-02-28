#ifndef _port_hub_h_
#define _port_hub_h_


extern unsigned char in(unsigned short port);
extern void out(unsigned short port, unsigned char data);

#define inb(x)			in(x)
#define outb(x,y)		out(x,y)


#endif
