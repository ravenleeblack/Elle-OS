#include "core.h"


int init_core()
{
	struct main_frame *root = NULL;                                                                        	// Create the root main frame
	struct main_frame *main_frame = create_main_frame(root, 0, 0, screen_width, screen_height);
	fill_main(0, 870, 1440, 30, color_flat_black);                                                          //create the taskbar

	
	struct sub_frame *app = create_sub_frame(main_frame, 10, 10, 600, 700);                                 // Create the application window
	draw_strand("Terminal", 500, 16, color_dark_plum, color_light_plum);


	struct terminal *term_element = create_terminal(app, 12, 26, 596, 682);   	                            // Create terminal element within the application window


	//draw_hex(0xABCD1234, 200, 200, color_flat_black, color_white);                                        //write hex works just commented out


	core_free(main_frame);  	                                                                            // Free memory
	core_free(root);

	return 1; // Success
}


int _core(int argc, const char *argv[])
{
	struct registers regs;

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
