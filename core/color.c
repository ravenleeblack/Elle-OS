#include "color.h"

// Eventually this will be a lib file. These are color functions that we can use for testing ui so that we are not putting a bunch of foreground and background 
// args into functions. you can now write color_black, color_white as args for color. Will need to spend more time adding colors at some point.

struct color_element color_black = { 0, 0, 0, 0 };
struct color_element color_flat_black = { 20, 20, 20, 0 };

struct color_element color_dark_gray = { 80, 80, 80, 0 };
struct color_element color_light_gray = { 110, 110, 110, 0 };

struct color_element color_white = { 255, 255, 255, 0 };

struct color_element color_tea_green = { 204, 102, 0, 0 };

struct color_element color_french_gray = { 213, 197, 200, 0 };
struct color_element color_light_plum = { 112, 92, 103, 0 };
struct color_element color_med_plum = { 48, 33, 42, 0 };
struct color_element color_dark_plum = { 45, 36, 41, 0 };

struct color_element color_orange = { 204, 102, 0, 0 };

struct color_element color_teal = { 0, 128, 128, 0 };

struct color_element color_slate = { 113, 143, 148, 0 };
