
_write:                 ; writes a strand to te screen without a new line will have to call _neli afterwards if needed.
    pusha
    mov ah, 0Eh         ; int 10h teletype function
.repeat:
    lodsb               ; get the next mark for the strand
    cmp al, 0
    je .done            ; if mark is zero  we have reached the end of the strand
    int 10h             ; display the character
    jmp .repeat         ; move on to the next char
.done:
    popa
    ret

_neli:
     pusha
     mov ah, 0Eh	; call bios to output char code
     mov al, 13
     int 10h
     mov al, 10
     int 10h
     popa
     ret
