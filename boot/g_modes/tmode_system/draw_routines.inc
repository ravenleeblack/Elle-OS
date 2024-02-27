; draw_block.inc - this file contains drawing functins for ui

draw_main_menu:        ; draw the main option window
    pusha
    mov ah, 02h        ; Set cursor position function
    mov bh, 0          ; Page number (0 for standard screen)
    mov dh, 3          ; Row (0-based) - Adjusted to a visible position
    mov dl, 1          ; Column (0-based) - Adjusted to a visible position
    int 10h 
.reloop_column:
    mov ah, 09h        ; Set AH register to 09h to write characters to the screen
    mov cx, 78         ; Set CX register to 1, indicating the number of characters to display
    mov al, ' '        ; Set AL register to the character ' ' (a space)
    mov bl, 01100110b  ; Set BL register to 00110000b for a white block on a black background
    int 10h 
.draw_block_loop:
    mov ah, 02h        ; Set cursor position function
    inc dh
    int 10h 
    cmp dh, 47
    jge .block_done
    jmp .reloop_column
.block_done:
    popa
    ret

draw_sub_menu:
    pusha
    mov ah, 02h         ; Set cursor position function
    mov bh, 0           ; Page number (0 for standard screen)
    mov dh, 4           ; Row (0-based) - Adjusted to a visible position
    mov dl, 2           ; Column (0-based) - Adjusted to a visible position
    int 10h 
.reloop_column:
    mov ah, 09h         ; Set AH register to 09h to write characters to the screen
    mov cx, 76          ; Set CX register to 1, indicating the number of characters to display
    mov al, ' '         ; Set AL register to the character ' ' (a space)
    mov bl, 01110111b   ; Set BL register to 00110000b for a white block on a black background
    int 10h 
.draw_block_loop:
    mov ah, 02h         ; Set cursor position function
    inc dh
    int 10h 
    cmp dh, 46
    jge .block_done
    jmp .reloop_column
.block_done:
    popa
    ret

draw_bar:               ; draws a single bar or row which consists of 80 coulumns
    pusha   
    mov ah, 09h         ; Set AH register to 09h to indicate we want to display a string
    mov bh, 0           ; Set BH register to 0, which is the display page number
    mov cx, 80          ; Set CX register to 80, indicating the number of characters to display
    mov bl, 00000010b   ; Set BL register to 01110000b, which represents the display attribute (foreground and background colors)
    mov al, ' '         ; Set AL register to the character ' ' (a space)
    int 10h             ; Trigger BIOS interrupt 10h to display the character
    popa
    ret
