[BITS 16]
section .osload
global osload


osload:  jmp switch_pmode

%include "rootling.inc"
%include "gmode_system.asm"
%include "tmode_system.asm"

switch_pmode:
    call enable_gate
    call _set_gmode_system
    ;call _set_tmode_system	

    cli
	lgdt [selector_ptr]

    mov eax, cr0             ; get the status word
    or eax, 1                ; turn on the P bit
    mov cr0, eax             ; store the status word
	
	jmp core_mode_code_seg:pmode

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
    call _core

halt:
    cli
	hlt

%include "setup_gdt.inc"
%include "setup_isr.inc"
%include "enable_gate.inc"
