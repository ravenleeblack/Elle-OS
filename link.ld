ENTRY(_core)
OUTPUT_FORMAT(elf32-i386)

SECTIONS
{
    . = 0x7C00;                  /* osboot.asm starts at 0x7C00*/
    .osboot : AT(0x7C00) SUBALIGN(4)
    {
        osboot.o(.text)
        osboot.o(.*)
    }

    . = 0x7DFE;
    .bootsig : {
        SHORT(0xaa55);
    }

    . = 0x7E00;                 /* osload.asm starts at 0x7E00. We need a place to jmp to from osboot */
    .osload : AT(0x7E00) SUBALIGN(4)
    {
        osload.o(.text)
        osload.o(.*)
    }

    . = 0x819e;                /* core.c started at 0x8000. As the os grows so will this address. This is the address where the core _core starts */
    ._core : SUBALIGN(4)
    {
        *(.text*)
        *(.rodata*)
        *(.data*)
    }

    .bss : SUBALIGN(4) {
        __bss_start = .;
        *(COMMON);
        *(.bss*);
    }
    . = ALIGN(4);              /* Round BSS up to 4 byte boundary */
    __bss_end = .;

    kernel_sectors = (SIZEOF(._core) + 511) / 512;

    /DISCARD/ : {
        *(.eh_frame)
        *(.comment)
    }
}
