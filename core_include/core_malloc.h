#ifndef core_malloc_h
#define core_malloc_h
#include "types.h"


#define heap_size 100000                  // adjust the size as needed

char heap[heap_size];
static size heap_index = 0;

void *core_malloc(size size);
void core_free(void *ptr);

#endif
