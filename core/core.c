#include "core.h"


int init_core()
{
	struct main_frame *root = NULL;                                                                        	// Create the root main frame
	struct main_frame *main_frame = create_main_frame(root, 0, 0, screen_width, screen_height);
	fill_main(0, 870, 1440, 30, color_flat_black);                                                          //create the taskbar

	struct sub_frame *app = create_sub_frame(main_frame, 10, 10, 600, 700);                                 // Create the application window
	draw_strand("Terminal", 500, 16, color_dark_plum, color_light_plum);                                    // Create the appliction title

	struct terminal *term_element = create_terminal(app, 12, 26, 596, 682);   	                            // Create terminal element within the application window

	//draw_hex(0xABCD1234, 200, 200, color_flat_black, color_white);                                        //write hex works just commented out

	core_free(main_frame);  	                                                                            // free the main frame
	core_free(root);                                                                                        // free the main root

	return 1; 
}


int _core(int argc, const char *argv[])
{
	struct registers regs;                      // I dont suppose this is right. Only here because core_request and core_service require an argument.

	load_gdt();                          
	load_idt();

	int core_initialized = init_core();        // needs to be called before interrrupt handling otherwise its a black screen in bochs.

	handle_core_request(regs);
	handle_core_service(regs);

	load_keyboard();
	load_timer();

	asm("sti");                               // enable interrupts

	for (;;)                                  // loop required 
	{
		asm("hlt");
	}
	return 0;
}
