#include "screen.h"

// screen.c functions are for text mode support and testing. Elle is currently using graphics mode so refer to draw_element.c for its functions
// and vesa video buffer. I left this here so we could continue testing from text mode if needed.

unsigned short *textptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void scroll(void)
{
	unsigned short blank, temp;

	/* A blank is defined as a space... we need to give it
	*  backcolor too */
	blank = 0x20 | (attrib << 8);

	/* Row 25 is the end, this means we need to scroll up */
	if (csr_y >= 50)
	{
		/* Move the current text chunk that makes up the screen
		*  back in the buffer by a line */
		temp = csr_y - 50 + 1;
		memcpyw(textptr, textptr + temp * 80, (50 - temp) * 80);

		/* Finally, we set the chunk of memory that occupies
		*  the last line of text to our 'blank' character */
		memsetw(textptr + (50 - temp) * 80, blank, 80);
		csr_y = 50 - 1;
	}
}


void move_csr(void)
{
	unsigned temp;
	/* The equation for finding the index in a linear
	 *  chunk of memory can be represented by:
	 *  Index = [(y * width) + x] */
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

	/* Again, we need the 'short' that will be used to
	*  represent a space with color */
	blank = 0x20 | (attrib << 8);

	/* Sets the entire screen to spaces in our current
	*  color */
	for (i = 0; i < 50; i++)
		memsetw(textptr + i * 80, blank, 80);

	/* Update out virtual cursor, and then move the
	*  hardware cursor */
	csr_x = 0;
	csr_y = 0;
	move_csr();
}

/* Puts a single character on the screen */
void putch(unsigned char c)
{
	unsigned short *where;
	unsigned att = attrib << 8;

	/* Handle a backspace, by moving the cursor back one space */
	if (c == 0x08)
	{
		if (csr_x != 0) csr_x--;
	}
	/* Handles a tab by incrementing the cursor's x, but only
	*  to a point that will make it divisible by 8 */
	else if (c == 0x09)
	{
		csr_x = (csr_x + 8) & ~(8 - 1);
	}
	/* Handles a 'Carriage Return', which simply brings the
	*  cursor back to the margin */
	else if (c == '\r')
	{
		csr_x = 0;
	}
	/* We handle our newlines the way DOS and the BIOS do: we
	*  treat it as if a 'CR' was also there, so we bring the
	*  cursor to the margin and we increment the 'y' value */
	else if (c == '\n')
	{
		csr_x = 0;
		csr_y++;
	}
	/* Any character greater than and including a space, is a
	*  printable character. The equation for finding the index
	*  in a linear chunk of memory can be represented by:
	*  Index = [(y * width) + x] */
	else if (c >= ' ')
	{
		where = textptr + (csr_y * 80 + csr_x);
		*where = c | att;	/* Character AND attributes: color */
		csr_x++;
	}

	/* If the cursor has reached the edge of the screen's width, we
	*  insert a new line in there */
	if (csr_x >= 80)
	{
		csr_x = 0;
		csr_y++;
	}

	/* Scroll the screen if needed, and finally move the cursor */
	scroll();
	move_csr();
}

/* Uses the above routine to output a string... */
void puts(unsigned char *text)
{
	int i;

	for (i = 0; i < strlen(text); i++)
	{
		putch(text[i]);
	}
}

/* Sets the forecolor and backcolor that we will use */
void settextcolor(unsigned char forecolor, unsigned char backcolor)
{
	/* Top 4 bytes are the background, bottom 4 bytes
	*  are the foreground color */
	attrib = (backcolor << 4) | (forecolor & 0x0F);
}

void init_video(void)
{
	int temp;

	textptr = (unsigned short *)0xB8000;
	attrib = 0x20; /* Yellow on Blue */

	/* read cursor position */
	out(0x3D4, 14);
	temp = in(0x3D5) << 8;
	out(0x3D4, 15);
	temp |= in(0x3D5);

	csr_y = temp / 80;
	csr_x = csr_x * 80 * 2;
}
