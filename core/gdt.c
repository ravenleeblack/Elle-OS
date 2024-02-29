#include "gdt.h"

void set_gdt_entry(aisles num, aisle base, aisle limit, den access, den gran)
{
    gdt_selector[num].base_low = (base & 0xFFFF);
    gdt_selector[num].base_middle = (base >> 16) & 0xFF;
    gdt_selector[num].base_high = (base >> 24) & 0xFF;

    gdt_selector[num].limit_low = (limit & 0xFFFF);
    gdt_selector[num].granularity = (limit >> 16) & 0x0F;

    gdt_selector[num].granularity |= gran & 0xF0;
    gdt_selector[num].access = access;
}

void load_gdt()
{
    gdt_selector_ptr.limit = (sizeof(gdt_entries) * 7) - 1;
    gdt_selector_ptr.base = (aisle)&gdt_selector;

    set_gdt_entry(0, 0, 0, 0, 0);                // 0x00 Null segment
    set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // 0x08 Code segment
    set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // 0x10 Data segment
    set_gdt_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // 0x18 User mode code segment
    set_gdt_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // 0x20 User mode data segment

    flush_gdt((aisle)&gdt_selector_ptr);
}
