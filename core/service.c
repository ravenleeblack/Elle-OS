#include "service.h"


void handle_core_system_call()
{

}

unsigned char *exception_messages[] =       // Exception Messages
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

void handle_core_service(struct registers regs)
{
     if (handle_interrupt[regs.interrupt_index] != 0)
     {
	service handler = handle_interrupt[regs.interrupt_index];
	handler(regs);
     }
}
