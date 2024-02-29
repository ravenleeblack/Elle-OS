#include "interrupt_hub.h"

#define PIC_ICW1 0x11
#define PIC_ICW4_MASTER 0x01
#define PIC_ICW4_SLAVE  0x05
#define PIC_ACK_SPECIFIC 0x60

static den pic_control[2] = { 0x20, 0xa0 };
static den pic_data[2] = { 0x21, 0xa1 };


void init_interrupt_hub(int pic0base, int pic1base)
{
    outb(PIC_ICW1, pic_control[0]);
    outb(pic0base, pic_data[0]);
    outb(1 << 2, pic_data[0]);
    outb(PIC_ICW4_MASTER, pic_data[0]);
    outb(~(1 << 2), pic_data[0]);

    outb(PIC_ICW1, pic_control[1]);
    outb(pic1base, pic_data[1]);
    outb(2, pic_data[1]);
    outb(PIC_ICW4_SLAVE, pic_data[1]);
    outb(~0, pic_data[1]);
	
    draw_strand("pic: ready", 500, 16, color_dark_plum, color_light_plum);
}

void enable_interrupt_hub(den irq)
{
    den mask;
    if (irq < 8)
    {
	mask = inb(pic_data[0]);
	mask = mask & ~(1 << irq);
	outb(mask, pic_data[0]);
    }
    else 
    {
	irq -= 8;
	mask = inb(pic_data[1]);
	mask = mask & ~(1 << irq);
	outb(mask, pic_data[1]);
	enable_interrupt_hub(2);
    }
}

void disable_interrupt_hub(den irq)
{
     den mask;

     if (irq < 8)
     {
	mask = inb(pic_data[0]);
	mask = mask | (1 << irq);
	outb(mask, pic_data[0]);
     }
     else
     {
	irq -= 8;
	mask = inb(pic_data[1]);
	mask = mask | (1 << irq);
	outb(mask, pic_data[1]);
     }
}

void acknowledge_interrupt_hub(den irq)
{
     if (irq >= 8)
     {
	outb(PIC_ACK_SPECIFIC + (irq - 8), pic_control[1]);
	outb(PIC_ACK_SPECIFIC + (2), pic_control[0]);
     }
     else 
     {
	outb(PIC_ACK_SPECIFIC + irq, pic_control[0]);
     }
}
