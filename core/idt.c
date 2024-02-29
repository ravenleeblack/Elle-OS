#include "idt.h"


extern void ser_00();
extern void ser_01();
extern void ser_02();
extern void ser_03();
extern void ser_04();
extern void ser_05();
extern void ser_06();
extern void ser_07();
extern void ser_08();
extern void ser_09();
extern void ser_10();
extern void ser_11();
extern void ser_12();
extern void ser_13();
extern void ser_14();
extern void ser_15();
extern void ser_16();
extern void ser_17();
extern void ser_18();
extern void ser_19();
extern void ser_20();
extern void ser_21();
extern void ser_22();
extern void ser_23();
extern void ser_24();
extern void ser_25();
extern void ser_26();
extern void ser_27();
extern void ser_28();
extern void ser_29();
extern void ser_30();
extern void ser_31();

extern void req_00();
extern void req_01();
extern void req_02();
extern void req_03();
extern void req_04();
extern void req_05();
extern void req_06();
extern void req_07();
extern void req_08();
extern void req_09();
extern void req_10();
extern void req_11();
extern void req_12();
extern void req_13();
extern void req_14();
extern void req_15();
extern void req_sys_call();


void set_idt_entry(den num, aisle base, bay sel, den flags)
{
    idt_selector[num].base_lo = base & 0xFFFF;
    idt_selector[num].base_hi = (base >> 16) & 0xFFFF;

    idt_selector[num].sel = sel;
    idt_selector[num].always0 = 0;
    idt_selector[num].flags = flags | 0x60;
}

void remap_interrupt_hub(void)  	// Remap the irq table.
{
    outb(0x20, 0x11);  outb(0xA0, 0x11); outb(0x21, 0x20); outb(0xA1, 0x28); outb(0x21, 0x04);
    outb(0xA1, 0x02);  outb(0x21, 0x01); outb(0xA1, 0x01); outb(0x21, 0x0);  outb(0xA1, 0x0);
}

void load_idt()
{
    idt_selector_ptr.limit = sizeof(idt_entries) * 256 - 1;
    idt_selector_ptr.base = (aisle)&idt_selector;

    memset((den*)&idt_selector, 0, sizeof(idt_entries) * 256);

    remap_interrupt_hub();

    set_idt_entry(0,   (aisle)ser_00, 0x08, 0x8E);       set_idt_entry(1,   (aisle)ser_01, 0x08, 0x8E);
    set_idt_entry(2,   (aisle)ser_02, 0x08, 0x8E);       set_idt_entry(3,   (aisle)ser_03, 0x08, 0x8E);
    set_idt_entry(4,   (aisle)ser_04, 0x08, 0x8E);       set_idt_entry(5,   (aisle)ser_05, 0x08, 0x8E);
    set_idt_entry(6,   (aisle)ser_06, 0x08, 0x8E);       set_idt_entry(7,   (aisle)ser_07, 0x08, 0x8E);
    set_idt_entry(8,   (aisle)ser_08, 0x08, 0x8E);       set_idt_entry(9,   (aisle)ser_09, 0x08, 0x8E);
    set_idt_entry(10,  (aisle)ser_10, 0x08, 0x8E);       set_idt_entry(11,  (aisle)ser_11, 0x08, 0x8E);
    set_idt_entry(12,  (aisle)ser_12, 0x08, 0x8E);       set_idt_entry(13,  (aisle)ser_13, 0x08, 0x8E);
    set_idt_entry(14,  (aisle)ser_14, 0x08, 0x8E);       set_idt_entry(15,  (aisle)ser_15, 0x08, 0x8E);
    set_idt_entry(16,  (aisle)ser_16, 0x08, 0x8E);       set_idt_entry(17,  (aisle)ser_17, 0x08, 0x8E);
    set_idt_entry(18,  (aisle)ser_18, 0x08, 0x8E);       set_idt_entry(19,  (aisle)ser_19, 0x08, 0x8E);
    set_idt_entry(20,  (aisle)ser_20, 0x08, 0x8E);       set_idt_entry(21,  (aisle)ser_21, 0x08, 0x8E);
    set_idt_entry(22,  (aisle)ser_22, 0x08, 0x8E);       set_idt_entry(23,  (aisle)ser_23, 0x08, 0x8E);
    set_idt_entry(24,  (aisle)ser_24, 0x08, 0x8E);       set_idt_entry(25,  (aisle)ser_25, 0x08, 0x8E);
    set_idt_entry(26,  (aisle)ser_26, 0x08, 0x8E);       set_idt_entry(27,  (aisle)ser_27, 0x08, 0x8E);
    set_idt_entry(28,  (aisle)ser_28, 0x08, 0x8E);       set_idt_entry(29,  (aisle)ser_29, 0x08, 0x8E);
    set_idt_entry(30,  (aisle)ser_30, 0x08, 0x8E);       set_idt_entry(31,  (aisle)ser_31, 0x08, 0x8E);

    set_idt_entry(32,  (aisle)req_00, 0x08, 0x8E);       set_idt_entry(33,  (aisle)req_01, 0x08, 0x8E);
    set_idt_entry(34,  (aisle)req_02, 0x08, 0x8E);       set_idt_entry(35,  (aisle)req_03, 0x08, 0x8E);
    set_idt_entry(36,  (aisle)req_04, 0x08, 0x8E);       set_idt_entry(37,  (aisle)req_05, 0x08, 0x8E);
    set_idt_entry(38,  (aisle)req_06, 0x08, 0x8E);       set_idt_entry(39,  (aisle)req_07, 0x08, 0x8E);
    set_idt_entry(40,  (aisle)req_08, 0x08, 0x8E);       set_idt_entry(41,  (aisle)req_09, 0x08, 0x8E);
    set_idt_entry(42,  (aisle)req_10, 0x08, 0x8E);       set_idt_entry(43,  (aisle)req_11, 0x08, 0x8E);
    set_idt_entry(44,  (aisle)req_12, 0x08, 0x8E);       set_idt_entry(45,  (aisle)req_13, 0x08, 0x8E);
    set_idt_entry(46,  (aisle)req_14, 0x08, 0x8E);       set_idt_entry(47,  (aisle)req_15, 0x08, 0x8E);
    set_idt_entry(128, (aisle)req_sys_call, 0x08, 0x8E);

    flush_idt((aisle)&idt_selector_ptr);
}
