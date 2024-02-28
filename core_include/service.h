#ifndef service_h
#define service_h
#include "types.h"
#include "port_hub.h"

// isr = services
#define req_timer 32		    // Timer
#define req_keyboard 33		  // Keyboard
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

typedef struct registers
{
	aisle gs;
	aisle fs;
	aisle es;
	aisle ds;
	aisle edi, esi, ebp, esp, ebx, edx, ecx, eax;       //pushed by pusha
	aisle interrupt_index, errorCode;                   //if applicable
	aisle eip, cs, eflags, esp_user_mode, ss;           //pushed by the CPU
} registers;


void handle_core_service(struct registers regs);

typedef void(*service)(registers);
service handle_interrupt[256];

extern void handle_core_system_call();


#endif
