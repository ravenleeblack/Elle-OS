; write.inc - write a string to the screen


_write:                 ; regular write without new line will have to call _neli afterwards if needed.
    pusha
    mov ah, 0Eh         ; int 10h teletype function

.repeat:
    lodsb               ; Get char from string
    cmp al, 0
    je .done            ; If char is zero, end of string

    int 10h             ; Display the character

    jmp .repeat         ; Move on to the next char

.done:
    popa
    ret

_neli:
	pusha

	mov ah, 0Eh			; BIOS output char code

	mov al, 13
	int 10h
	mov al, 10
	int 10h

	popa
	ret
