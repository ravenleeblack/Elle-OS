; tmode_system - This file handles all the text mode routines needed for the rootling bios.

%include "clear_screen.inc"
%include "move_cursor.inc"
%include "write.inc"


_set_tmode_system:
    pusha               ; Push all general-purpose registers onto the stack

    mov ah, 00h          ; Set the video mode to text mode
    mov al, 03h          ; VGA text mode 80x25 - 4000 characters
    int 10h              ; Call BIOS video services

	mov ax, 1112h    
    mov bh, 0
    mov bl, 32
    int 10h              ; Call BIOS video services

    popa                 ; Pop all general-purpose registers from the stack
    ret                  ; Return from the subroutine
