#ifndef main_frame_h
#define main_frame_h
#include "frame_bitmap.h"

struct kinship_element
{
	struct main_frame *parent;
	struct sub_frame *child;
	struct sub_frame *sibling;
};

struct index_element
{
	int card_index_tag;
	int card_instance;
};

struct main_frame 
{
	struct kinship_element *kinship_tag;
	struct index_element *label_index_tag;
	struct draw_element * element;

};


struct main_frame * create_main_frame(struct main_frame *parent, int x, int y, int width, int height);


#endif
