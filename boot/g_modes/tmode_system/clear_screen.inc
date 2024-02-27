; clear_screen.inc

clear_screen:                ; clear the screen
    pusha                    ; Push all general-purpose registers onto the stack
    mov ah, 09h              ; use a string to clear screen
    mov bh, 0                ; set page to zero
    mov cx, 4000             ; we have a total of 4000 chars pos 80x50
    mov bl, 00000000b        ; set bl to binary and make black background on black foreground. This just clears the screen so black.
    mov al, ' '              ; use the ' ' character to make each char black
    int 10h
    popa                     ; Pop all general-purpose registers from the stack
    ret                      ; Return from the subroutine
