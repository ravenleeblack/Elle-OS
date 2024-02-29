#ifndef idt_h
#define idt_h
#include "types.h"
#include "memory.h"
#include "port_hub.h"


struct idt_entry
{
     bay base_lo;
     bay sel;
     den  always0;
     den  flags;
     bay base_hi;
} __attribute__((packed));


struct idt_ptr
{
     bay limit;
     aisle base;
} __attribute__((packed));


typedef struct idt_entry idt_entries;
typedef struct idt_ptr idt_ptrs;

idt_entries idt_selector[256];
idt_ptrs idt_selector_ptr;


extern void flush_idt(aisle);

void load_idt();

extern void ide_ptr();

#endif
