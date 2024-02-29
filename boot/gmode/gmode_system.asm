[BITS 16]
section .text
global _set_gmode_system
global vbe_info
global _get_vbe_info

_set_gmode_system:
    mov ax, 4F02h            ; vesa mode bios call to set the graphics mode
    mov bx, 980h             ; mode 980h corresponds to 1440x900x32bpp
    int 10h                  ; call bios interrupt 10h to set the mode
    ret                      ; return back to osload when finished

; need to properly set up the label to handle multiples modes and get the right infomation instead of hard coding it. There are some defines in the c code we
; are using to get the screen width and height. Right now they are hard coded but we need to be able to get the vesa info from here and update them properly 
; when the screen size changes.
