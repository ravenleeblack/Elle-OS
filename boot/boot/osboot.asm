[BITS 16]
extern osload

osboot:
     cli
     xor ax, ax                      ; Initialize seg regsisters to 0 since linker script will be placing bootloader at org 0x7c00             
     mov ds, ax
     mov es, ax
     mov fs, ax
     mov gs, ax

     mov ss, ax
     mov sp, 0x7c00                  ; Place stack just below bootloader at 0x0000:0x7c00
     sti

     call read_osload                ; read enough sectors

     jmp 0:osload                    ; jmp to second stage osload

%include "read_osload.inc"
