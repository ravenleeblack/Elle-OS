#ifndef terminal_h
#define terminal_h
#include "sub_frame.h"


struct terminal
{
	struct kinship_element *kinship_tag;
	struct index_element *label_index_tag;
	struct draw_element *element;
};

struct terminal *create_terminal(struct sub_frame *parent, int x, int y, int width, int height);

#endif
