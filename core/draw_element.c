#include "draw_element.h"
#include "frame_bitmap.h"
#include "terminal.h"

// I am still testing and trying to figure out the best way to create the drawing functions we will need for the frame manager.

struct draw_element *create_main_element(struct draw_element *parent, int x, int y, int width, int height)
{
    struct draw_element *element = (struct draw_element *)core_malloc(sizeof(struct draw_element));   // Allocate memory for the new main frame element

    if (parent == NULL)
    {
        //main_border(x, y, width, height, color_flat_black);
	fill_main(x, y, width, height, color_dark_plum);
	return element;
    }
    return NULL;
}

struct draw_element *create_sub_element(struct draw_element *parent, int x, int y, int width, int height)
{
    struct draw_element *element = (struct draw_element *)core_malloc(sizeof(struct draw_element));   // Allocate memory for the new sub frame element

    draw_frame(x, y, width, height, color_flat_black);
    fill_main(x, y, width, height, color_light_plum);
    return element;
}

struct draw_element *create_terminal_element(struct draw_element *parent, int x, int y, int width, int height)
{
    struct draw_element *element = (struct draw_element *)core_malloc(sizeof(struct draw_element));   // Allocate memory for the new terminal element

    element->cursor_x = 0;
    element->cursor_y = 0;

    draw_frame(x, y, width, height, color_flat_black);
    fill_main(x, y, width, height, color_dark_plum);

    return element;
}

void draw_horizontal_line(int pos_y, int start_x, int end_x, struct color_element color)
{
    for (int x = start_x; x <= end_x; x++)
    {
	putpixel(x, pos_y, color);
    }
}

void draw_vertical_line(int pos_x, int start_y, int end_y, struct color_element color)
{
    for (int y = start_y; y <= end_y; y++)
    {
	putpixel(pos_x, y, color);
    }
}

void main_border(int x, int y, int width, int height, struct color_element color)
{
    draw_horizontal_line(y, x, x + width - 1, color);                      // Top line
    draw_horizontal_line(y + height - 1, x, x + width - 1, color);         // Bottom line
    draw_vertical_line(x, y, y + height - 1, color);                       // Left line
    draw_vertical_line(x + width - 1, y, y + height - 1, color);           // Right line
}

void fill_main(int x, int y, int width, int height, struct color_element color)
{
    for (int row = y + 1; row < y + height - 1; row++)
    {
	draw_horizontal_line(row, x + 1, x + width - 2, color);
    }
}

void draw_frame(int x, int y, int width, int height, struct color_element color)
{
    draw_horizontal_line(y, x, x + width - 1, color);              // Top line
    draw_horizontal_line(y + height - 1, x, x + width - 1, color); // Bottom line
    draw_vertical_line(x, y, y + height - 1, color);               // Left line
    draw_vertical_line(x + width - 1, y, y + height - 1, color);   // Right line
}

void putpixel(int pos_x, int pos_y, struct color_element color)
{
    unsigned char* screen = (unsigned char*)video_memory;

    unsigned int offset = (pos_y * (screen_width * 4)) + (pos_x * 4);  // Calculate the linear memory offset for the pixel
    screen[offset] = color.blue;        // Blue component
    screen[offset + 1] = color.green;   // Green component
    screen[offset + 2] = color.red;     // Red component
    screen[offset + 3] = color.alpha;   // Alpha component
}


void draw_window(int x, int y, int width, int height, struct color_element color)
{
    draw_horizontal_line(y, x, x + width - 1, color);              // Top line
    draw_horizontal_line(y + height - 1, x, x + width - 1, color); // Bottom line
    draw_vertical_line(x, y, y + height - 1, color);               // Left line
    draw_vertical_line(x + width - 1, y, y + height - 1, color);   // Right line
}

void draw_menu(int x, int y, int width, int height, struct color_element color)
{
    draw_horizontal_line(y, x, x + width - 1, color);              // Top line
    draw_horizontal_line(y + height - 1, x, x + width - 1, color); // Bottom line
    draw_vertical_line(x, y, y + height - 1, color);               // Left line
    draw_vertical_line(x + width - 1, y, y + height - 1, color);   // Right line
}

void draw_taskbar(int x, int y, int width, int height, struct color_element color)
{
    draw_horizontal_line(y, x, x + width - 1, color);              // Top line
    draw_horizontal_line(y + height - 1, x, x + width - 1, color); // Bottom line
}

void set_main_rect(struct color_element color)
{
    for (int y = 0; y < screen_height; y++)
    {
	for (int x = 0; x < screen_width; x++)
	{
	    putpixel(x, y, color);
	}
    }
}

void fill_frame(int x, int y, int width, int height, struct color_element color)
{
    for (int row = y + 1; row < y + height - 1; row++)
    {
	draw_horizontal_line(row, x + 1, x + width - 2, color);
    }
}
void fill_frame2(int x, int y, int width, int height, struct color_element color)
{
    for (int row = y + 1; row < y + height - 1; row++)
    {
	draw_horizontal_line(row, x, x + width - 1, color);
    }
}

void draw_integer(int value, int start_x, int start_y, struct color_element forecolor, struct color_element backcolor)
{
    char buffer[12];                                              // Maximum digits for a 32-bit integer is 11 plus a null terminator
    int x = start_x;
    int y = start_y;

     itoa(value, buffer, 10);                                     // Convert integer to string
     draw_strand(buffer, x, y, forecolor, backcolor);             // Call draw_strand to print the integer as a string
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end) 
    {
	char temp = str[start];
	str[start] = str[end];
	str[end] = temp;
	start++;
	end--;
    }
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    int is_negative = 0;

    if (num == 0)                 // Handle 0 explicitly, otherwise empty string is printed
    {
	str[i++] = '0';
	str[i] = '\0';
	return str;
    }
    if (num < 0 && base != 10)     // Handle negative numbers for bases other than 10
    {
	is_negative = 1;
	num = -num;
     }
    while (num != 0)              // Convert integer to string, handling each digit
    {
	int rem = num % base;
	str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
	num = num / base;
    }
    if (is_negative)  // Append negative sign if necessary
    {
	str[i++] = '-';
    }
    str[i] = '\0';         // Null terminate the string

    reverse(str, i);   // Reverse the string

    return str;
}

void draw_hex(unsigned int value, int start_x, int start_y, struct color_element forecolor, struct color_element backcolor)
{
    char buffer[11];                          // Maximum characters for "0x" + 8-digit hexadecimal value + null terminator
    int x = start_x;
    int y = start_y;

    hex_to_string(value, buffer + 2);        // Start writing from buffer[2] to leave space for "0x"
    buffer[0] = '0'; // Add "0x" prefix
    buffer[1] = 'x';

    draw_strand(buffer, x, y, forecolor, backcolor);   // Call draw_strand to print the hexadecimal value as a string
}

void hex_to_string(aisle value, char* buffer)
{
    char hex[] = "0123456789ABCDEF";    	  // Hexadecimal characters

    for (int i = 7; i >= 0; i--)                  // Loop through each nibble (4 bits) of the value
    {	
	int nibble = (value >> (i * 4)) & 0xF;    // Extract the current nibble
	buffer[7 - i] = hex[nibble];              // Convert nibble to its corresponding hexadecimal character
    }
    buffer[8] = '\0';                             // Null-terminate the string
}

void draw_strand(const char *str, int start_x, int start_y, struct color_element forecolor, struct color_element backcolor)
{
    int x = start_x;
    int y = start_y;
    while (*str != '\0')
    {
	draw_mark(*str, x, y, forecolor, backcolor);
	x += font_width;       // Move to the next character position
	str++;                 // Move to the next character in the string
    }
}


void draw_mark(unsigned char c, int start_x, int start_y, struct color_element forecolor, struct color_element backcolor)
{
    int mask[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

    unsigned char *glyph = fontdata + (int)c * font_height;

    for (int cy = 0; cy < font_height; cy++)
    {
	for (int cx = 0; cx < font_width; cx++)
	{
	    if (glyph[cy] & mask[7 - cx]) // Reversed mask to preserve original order
	    {
		putpixel(start_x + cx, start_y + cy, forecolor); // Set foreground color
	    }
	    else
	    {
		putpixel(start_x + cx, start_y + cy, backcolor); // Set background color
	    }
	}
    }
}


aisle set_element_width(struct draw_element * element)
{
    return element->clip.w_clip_pos;
}

aisle set_element_height(struct draw_element * element)
{
    return element->clip.h_clip_pos;
}

void set_foreground_color(struct draw_element *element, struct color_element color)
{
    element->element_fore_color = color;
}

void set_background_color(struct draw_element *element, struct color_element color)
{
    element->element_back_color = color;
}

void plot_pixel(struct bitmap_element *bitmap_element, int x, int y, struct color_element color)
{
    den *element_buffer = bitmap_element->video_buffer + (bitmap_element->width * y + x) * 4;

    if (color.alpha == 0) 
    {
	element_buffer[2] = color.red;
	element_buffer[1] = color.green;
	element_buffer[0] = color.blue;
    }
    else
    {
	bay alpha_byte = color.alpha;
	bay color_byte = 256 - alpha_byte;
	element_buffer[0] = (color.red * color_byte + element_buffer[0] * alpha_byte) >> 8;
	element_buffer[1] = (color.green * color_byte + element_buffer[1] * alpha_byte) >> 8;
	element_buffer[2] = (color.blue * color_byte + element_buffer[2] * alpha_byte) >> 8;
    }
}

void bitmap_element(struct draw_element *element, int x, int y, int width, int height, den *font_array, struct color_element color)
{
     x += element->clip.x_clip_pos;
     y += element->clip.y_clip_pos;

     if (x < 0) { width += x; x = 0; }
     if (y < 0) { height += y; y = 0; }

     if (x + width > element->clip.w_clip_pos) { width = element->clip.w_clip_pos - x; }
     if (y + height > element->clip.h_clip_pos) { height = element->clip.h_clip_pos - y; }

     int width_pass, height_pass, bitmap_pass;
     int mark_value;

     bitmap_pass = 0;

	for (height_pass = 0; height_pass < height; height_pass++)
	{
	   for (width_pass = 0; width_pass < width; width_pass++)
	   {
	    mark_value = ((*font_array) << bitmap_pass) & 0x80;

	   if (mark_value)
	   {
		plot_pixel(element->bitmap, x + width_pass, y + height_pass, color);
	   }
	   else
	   {
		plot_pixel(element->bitmap, x + width_pass, y + height_pass, element->element_back_color);
	    }
	    bitmap_pass++;
	    if (bitmap_pass == 8)
	    {
		font_array++;
		bitmap_pass = 0;
	    }
	}
    }
}

void scroll_element(struct draw_element *element, int x, int y, int w, int h, int delta_y)
{
   int j;

   if (element->clip.w_clip_pos - x < w)   // Adjust width and height based on clipping boundaries
   {
	w = element->clip.w_clip_pos - x;
   }
   if (element->clip.h_clip_pos - y < h)
   {
	h = element->clip.h_clip_pos - y;
   }

   x += element->clip.x_clip_pos;
   y += element->clip.y_clip_pos;

   if (delta_y > h)
   {
	delta_y = h;
   }

   for (j = 0; j < (h - delta_y); j++)
   {
	memcpy(&element->bitmap->video_buffer[((y + j) * element->bitmap->width + x) * 3], &element->bitmap->video_buffer[((y + j + delta_y) * element->bitmap->width + x) * 3], w * 3);
   }
   //clear_element(element, x, y + h - delta_y, w, delta_y);
}






