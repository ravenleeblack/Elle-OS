#include "core.h"


int init_core()
{

	puts("Hello World\n\r");

	return 1; // Success
}


int _core(int argc, const char *argv[])
{
	struct registers regs;

	init_video();

	clear_screen();

	gdt_initialize();
	idt_initialize();

	int core_initialized = init_core();

	handle_core_request(regs);
	handle_core_service(regs);

	load_keyboard();
	load_timer();

	asm("sti");

	for (;;)
	{
		asm("hlt");
	}

	return 0;
}
