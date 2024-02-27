[BITS 16]
section .text
global _set_gmode_system
global vbe_info
global _get_vbe_info

_set_gmode_system:
    mov ax, 4F02h   ; VESA BIOS call to set graphics mode
    mov bx, 980h    ; Mode 100h corresponds to 1440x900x32bpp
    int 10h         ; Call BIOS interrupt 10h to set the mode


    ; Return
    ret
