#include "terminal.h"


struct terminal *create_terminal(struct sub_frame *parent, int x, int y, int width, int height)
{
    struct terminal *term_element = (struct terminal *)core_malloc(sizeof(struct terminal));
    term_element->element = create_terminal_element(parent->element, x, y, width, height);
    return term_element;
}
