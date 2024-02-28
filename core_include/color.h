#ifndef color_h
#define color_h
#include "types.h"


struct color_element
{
	den red;
	den green;
	den blue;
	den alpha;
};


extern struct color_element color_black;
extern struct color_element color_flat_black;

extern struct color_element color_dark_gray;
extern struct color_element color_light_gray;

extern struct color_element color_white;

extern struct color_element color_tea_green;

extern struct color_element color_french_gray;
extern struct color_element color_light_plum;
extern struct color_element color_med_plum;
extern struct color_element color_dark_plum;

extern struct color_element color_orange;

extern struct color_element color_teal;
extern struct color_element color_slate;

#endif
