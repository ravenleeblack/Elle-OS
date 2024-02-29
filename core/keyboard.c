#include "keyboard.h"


unsigned char keyboard_map[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8',
    '9', '0', '-', '=', '\0',
    '\t',
    'q', 'w', 'e', 'r',
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
     0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n',
    'm', ',', '.', '/', 0,
    '*',
    0,
    ' ',
    0,
	0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0,
	0,
	0,
	0,
	0,
	0,
	'-',
	0,
	0,
	0,
	'+',
	0,
	0,
	0,
	0,
	0,
	0, 0, 0,
	0,
	0,
	0 };

void request_keyboard(int i, int intr_code)
{
    unsigned char scancode;

    scancode = inb(0x60);

    while (scancode & 1 && (scancode & 0x20) == 0)
    {
	den keycode = inb(0x60);
	den scan_code = keycode & 0x7f;
	den key_state = !(keycode & 0x80);

	if (key_state)
	{
	    puts(keyboard_map[(unsigned char)scan_code]);
	}

	scancode = inb(0x64);
     }
    outb(0x20, 0x20);
}

void load_keyboard()
{
    load_request(req_keyboard, request_keyboard);    // request interrupt for keyboard
}
