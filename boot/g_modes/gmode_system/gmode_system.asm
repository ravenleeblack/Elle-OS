[BITS 16]
section .text
global _set_gmode_system
global vbe_info
global _get_vbe_info

_set_gmode_system:
    mov ax, 4F02h   ; VESA BIOS call to set graphics mode
    mov bx, 980h    ; Mode 100h corresponds to 1440x900x32bpp
    int 10h         ; Call BIOS interrupt 10h to set the mode
    ret             ; Return

;need to add in the proper labels need to set multiple video modes instead of hard coding it and need to add the proper label to get infomation from vesa 
;so we can use that data in our core and c. We have some defines in c that we need to use to be able to get the mode size from here at some point.
