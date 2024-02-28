#include "sub_frame.h"


struct sub_frame *create_sub_frame(struct main_frame *parent, int x, int y, int width, int height)
{
	struct sub_frame *sub_frame = NULL;

	sub_frame->element = create_sub_element(parent->element, x, y, width, height);

	return sub_frame;
}
