#ifndef gdt_h
#define gdt_h
#include "types.h"
#include "service.h"
#include "memory.h"
#include "port_hub.h"


struct gdt_entry
{
    bay limit_low;
    bay base_low;
    den  base_middle;
    den  access;
    den  granularity;
    den  base_high;
} __attribute__((packed));


struct gdt_ptr
{
    bay limit;
    aisle base;
} __attribute__((packed));


typedef struct gdt_entry gdt_entries;
typedef struct gdt_ptr gdt_ptrs;

gdt_entries gdt_selector[6];
gdt_ptrs gdt_selector_ptr;


extern void flush_gdt(aisle);
extern void flush_tss();

void load_gdt();


#endif
