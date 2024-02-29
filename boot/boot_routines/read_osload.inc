[BITS 16]

read_osload:
    mov ah, 0         ; reset the drive function
    int 0x13          ; call the BIOS interrupt to reset drive

    xor ax, ax
    mov es, ax
    mov bx, 0x7E00    ; read address 0x7E00 so we can jmp to the second stage

    mov ah, 0x02      ; read sector function
    mov al, 36        ; read 15 sectors - this will need to be redone when the kernel gets larger
    mov ch, 0         ; 0 = track 1  (18 sectors per track) no need to move from track 0
    mov cl, 2         ; read sector 2
    mov dh, 0         ; head number
    int 0x13          ; call the BIOS interrupt to read drive
    ret
