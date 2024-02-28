#include "service.h"


void handle_core_system_call()
{

}

/* Exception Messages */
unsigned char *exception_messages[] =
{
	"service: arith error: division by zero",
	"service: debug service",
	"service: non maskable interrupt",
	"service: debug break point",
	"service: arith: detected overflow",
	"service: memory error: out of bounds",
	"service: asm error: invalid opcode",
	"service: cpu error: no coprocessor",
	"service: cpu error: double fault",
	"service: cpu error: coprocessor segment overrun",
	"service: bad tss",
	"service: memory error: segment not present",
	"service: stack fault",
	"service: cpu error: general protection fault",
	"service: memory error: page fault",
	"service: cpu error: unknown interrupt",
	"service: cpu error: coprocessor fault",
	"service: memory error: alignment check",
	"service: cpu error: machine check",
	"service: reserved 0",
	"service: reserved 1",
	"service: reserved 2",
	"service: reserved 3",
	"service: reserved 4",
	"service: reserved 5",
	"service: reserved 6",
	"service: reserved 7",
	"service: reserved 8",
	"service: reserved 9",
	"service: reserved 10",
	"service: reserved 11",
	"service: reserved 12"
};


// This gets called from our ASM interrupt handler stub.
void handle_core_service(struct registers regs)
{

	//draw_strand("recieved interrupt: ", 10, 48, 178, 188, 170, 255, 60, 60, 60, 255);
	//draw_integer(exception_messages[regs.interrupt_index], 10, 50, 178, 188, 170, 255, 98, 100, 95, 255);

	if (handle_interrupt[regs.interrupt_index] != 0)
	{
		service handler = handle_interrupt[regs.interrupt_index];
		handler(regs);
	}
}
