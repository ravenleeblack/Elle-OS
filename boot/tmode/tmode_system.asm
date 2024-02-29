%include "clear_screen.inc"
%include "move_cursor.inc"
%include "write.inc"


_set_tmode_system:
    pusha                ; push all general-purpose registers onto the stack

    mov ah, 00h          ; set the video mode to text mode
    mov al, 03h          ; vga text mode 80x50 - 4000 characters
    int 10h              ; call bios video services

    mov ax, 1112h    
    mov bh, 0
    mov bl, 32
    int 10h              ; call bios video services

    popa                 ; pop all general-purpose registers from the stack
    ret                  ; return to osload
