; move_cursor.inc

show_cursor:
	pusha
	mov ch, 6
	mov cl, 7
	mov ah, 1
	mov al, 3
	int 10h
	popa
	ret

hide_cursor:
	pusha
	mov ch, 32
	mov ah, 1
	mov al, 3			
	int 10h
	popa
	ret

move_cursor:
    pusha                ; Push all general-purpose registers onto the stack

    mov ah, 02h          ; Set cursor position function
    mov bh, 0            ; Page number (0 for standard screen)
    mov dh, 0            ; Row (0-based)
    mov dl, 0            ; Column (0-based)
    int 10h              ; Call BIOS video services

    popa                 ; Pop all general-purpose registers from the stack
    ret                  ; Return from the subroutine

set_text_pos_01:         ; currently sets the main title string
    pusha                ; Push all general-purpose registers onto the stack

    mov ah, 02h          ; Set cursor position function
    mov bh, 0            ; Page number (0 for standard screen)
    mov dh, 1            ; Row (0-based) - Adjusted to a visible position
    mov dl, 0            ; Column (0-based) - Adjusted to a visible position
    int 10h              ; Call BIOS video services

    popa                 ; Pop all general-purpose registers from the stack
    ret                  ; Return from the subroutine

set_text_pos_02:         ; currently sets the version title string
    pusha                ; Push all general-purpose registers onto the stack

    mov ah, 02h          ; Set cursor position function
    mov bh, 0            ; Page number (0 for standard screen)
    mov dh, 48           ; Row (0-based) - Adjusted to a visible position
    mov dl, 0            ; Column (0-based) - Adjusted to a visible position
    int 10h              ; Call BIOS video services

    popa                 ; Pop all general-purpose registers from the stack
    ret                  ; Return from the subroutine

set_text_pos_03:         ; currently sets the information display string
    pusha                ; Push all general-purpose registers onto the stack

    mov ah, 02h          ; Set cursor position function
    mov bh, 0            ; Page number (0 for standard screen)
    mov dh, 48           ; Row (0-based) - Adjusted to a visible position
    mov dl, 49           ; Column (0-based) - Adjusted to a visible position
    int 10h              ; Call BIOS video services

    popa                 ; Pop all general-purpose registers from the stack
    ret                  ; Return from the subroutine


set_text_pos_04:        ; currently sets the information display string
    pusha               ; Push all general-purpose registers onto the stack

    mov ah, 02h         ; Set cursor position function
    mov bh, 0           ; Page number (0 for standard screen)
    mov dh, 5           ; Row (0-based) - Adjusted to a visible position
    mov dl, 3           ; Column (0-based) - Adjusted to a visible position
    int 10h             ; Call BIOS video services

    popa                ; Pop all general-purpose registers from the stack
    ret                 ; Return from the subroutine

set_progress_pos_01:    ; currently sets the information display string
    pusha               ; Push all general-purpose registers onto the stack

    mov ah, 02h         ; Set cursor position function
    mov bh, 0           ; Page number (0 for standard screen)
    mov dh, 42          ; Row (0-based) - Adjusted to a visible position
    mov dl, 1           ; Column (0-based) - Adjusted to a visible position
    int 10h             ; Call BIOS video services

    popa                ; Pop all general-purpose registers from the stack
    ret                 ; Return from the subroutine
