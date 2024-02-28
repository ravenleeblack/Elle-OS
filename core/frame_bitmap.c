#include "frame_bitmap.h"

struct bitmap_element *create_main_frame_bitmap(int width, int height)
{
	init_bitmap.width = width;
	init_bitmap.height = height;
	init_bitmap.color_format = rgb_format;
	init_bitmap.video_buffer = video_memory;
	return &init_bitmap;
}

struct bitmap_element *create_sub_frame_bitmap(int width, int height)
{
	init_bitmap.width = width;
	init_bitmap.height = height;
	init_bitmap.color_format = rgb_format;
	init_bitmap.video_buffer = video_memory; // Allocate memory for the video buffer
	return &init_bitmap;
}

struct bitmap_element *create_terminal_bitmap(int width, int height)
{
	init_bitmap.width = width;
	init_bitmap.height = height;
	init_bitmap.color_format = rgb_format;
	init_bitmap.video_buffer = video_memory; // Allocate memory for the video buffer
	return &init_bitmap;
}

struct bitmap_element *create_frame_bitmap(int width, int height)
{
	init_bitmap.width = width;
	init_bitmap.height = height;
	init_bitmap.color_format = rgb_format;
	init_bitmap.video_buffer = video_memory;
	return &init_bitmap;
}
