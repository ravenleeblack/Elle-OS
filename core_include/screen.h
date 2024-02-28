#ifndef _screen_h_
#define _screen_h_
#include "memory.h"

extern void clear_screen(void);
extern void putch(unsigned char c);
extern void puts(unsigned char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video(void);

#endif
