#include "screen.h"

// screen.c functions are for text mode support and testing. Elle is currently using graphics mode so refer to draw_element.c for its functions
// and vesa video buffer. I left this here so we could continue testing from text mode if needed.

unsigned short *textptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void scroll(void)
{
    unsigned short blank, temp;
    blank = 0x20 | (attrib << 8);

    if (csr_y >= 50)
    {
	temp = csr_y - 50 + 1;
	memcpyw(textptr, textptr + temp * 80, (50 - temp) * 80);
	memsetw(textptr + (50 - temp) * 80, blank, 80);
	csr_y = 50 - 1;
    }
}


void move_csr(void)
{
    unsigned temp;
    temp = csr_y * 80 + csr_x;

    out(0x3D4, 14);
    out(0x3D5, temp >> 8);
    out(0x3D4, 15);
    out(0x3D5, temp);
}

void clear_screen(void)
{
     unsigned blank;
     int i;
     blank = 0x20 | (attrib << 8);

     for (i = 0; i < 50; i++)
     {
	memsetw(textptr + i * 80, blank, 80);
     }	
     csr_x = 0;
     csr_y = 0;
     move_csr();
}

void putch(unsigned char c)
{
     unsigned short *where;
     unsigned att = attrib << 8;
	
     if (c == 0x08)
     {
	if (csr_x != 0) csr_x--;
     }
     else if (c == 0x09)
     {
	csr_x = (csr_x + 8) & ~(8 - 1);
     }
     else if (c == '\r')
     {
	csr_x = 0;
     }
     else if (c == '\n')
     {
	csr_x = 0;
	csr_y++;
     }
     else if (c >= ' ')
     {
	where = textptr + (csr_y * 80 + csr_x);
	*where = c | att;	/* Character AND attributes: color */
	csr_x++;
     }
     if (csr_x >= 80)
     {
        csr_x = 0;
	csr_y++;
     }
     scroll();
     move_csr();
}


void puts(unsigned char *text)
{
    int i;

    for (i = 0; i < strlen(text); i++)
    {
	putch(text[i]);
    }
}

void init_video(void)
{
     int temp;

     textptr = (unsigned short *)0xB8000;
     attrib = 0x20;  

     out(0x3D4, 14);
     temp = in(0x3D5) << 8;
     out(0x3D4, 15);
     temp |= in(0x3D5);

     csr_y = temp / 80;
     csr_x = csr_x * 80 * 2;
}
