#include "main_frame.h"


struct main_frame *create_main_frame(struct main_frame *parent, int x, int y, int width, int height)
{
    struct main_frame *main_frame = (struct main_frame *)core_malloc(sizeof(struct main_frame)); // Allocate memory for the main frame

    if (parent == NULL)
    {
	main_frame->element = create_main_element(NULL, x, y, width, height);

	return main_frame;
    }
    else
    {
	return NULL;               // Main frame cannot be a child
    }
}
