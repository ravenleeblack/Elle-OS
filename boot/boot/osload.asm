[BITS 16]
section .osload
global osload

osload:  jmp switch_pmode

%include "gmode_system.asm"
%include "tmode_system.asm"

switch_pmode:
    call enable_gate                 ; enable a20 gate for additional memory
    call _set_gmode_system           ; set vesa graphics mode so we can use it frame buffer
    ;call _set_tmode_system	         ; set text mode. Left here so I can return to build a proper bootloader menu later

    cli
    lgdt [selector_ptr]              ; load the gdt table

    mov eax, cr0                     ; get the status word
    or eax, 1                        ; turn on the protected mode bit
    mov cr0, eax                     ; store the status word

    jmp core_mode_code_seg:pmode     ; jmp to pmode

[BITS 32]
pmode:
    mov ax, core_mode_hold_seg
    mov ds, ax
    mov ss, ax
    mov es, ax

    mov ax, 0
    mov fs, ax
    mov gs, ax

    mov ebp, 0xfff0
    mov esp, ebp

    [EXTERN _core]
    call _core                      ; call the core. Yea boy!! Os loaded up without relying on a file system.

halt:                          
    cli
    hlt

%include "setup_gdt.inc"
%include "setup_isr.inc"
%include "enable_gate.inc"
