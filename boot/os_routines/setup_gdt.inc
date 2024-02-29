
global selector_ptr
[GLOBAL flush_gdt]

gdt_start:
gdt_null:
    dw 0
    dw 0
    db 0
    db 0
    db 0
    db 0

core_mode_code:                ; core mode code segment descriptor
    dw 0xffff
    dw 0
    db 0
    db 10011010b               
    db 11001111b
    db 0

core_mode_hold:                ; core mode data segment descriptor
    dw 0xffff
    dw 0
    db 0
    db 10010010b              
    db 11001111b
    db 0
core_mode_stack:               ; core mode stack segment descriptor
    dw 0xffff      
    dw 0           
    db 0           
    db 10010001b  
    db 10000000b   
user_mode_code:                ; User mode code segment descriptor
    dw 0xffff
    dw 0
    db 0
    db 11111010b               
    db 11001111b
    db 0

user_mode_hold:                ; User mode data segment descriptor
    dw 0xffff
    dw 0
    db 0
    db 11110010b               
    db 11001111b
    db 0
user_mode_stack:               ; User mode stack segment descriptor
    dw 0xffff  
    dw 0        
    db 0       
    db 10010001b
    db 10000000b                
	db 0
gdt_end:
selector_ptr:
    dw gdt_end - gdt_start - 1
    dd gdt_start                

core_mode_code_seg equ core_mode_code - gdt_start                ; Offset for core mode code segment
core_mode_hold_seg equ core_mode_hold - gdt_start                ; Offset for core mode data segment
core_mode_stack_seg equ core_mode_stack - gdt_start              ; Offset for core mode stack segment

user_mode_code_seg equ user_mode_code - gdt_start                ; Offset for user mode code segment
user_mode_hold_seg equ user_mode_hold - gdt_start                ; Offset for user mode data segment
user_mode_stack_seg equ user_mode_stack - gdt_start              ; Offset for user mode stack segment

; There are two modes: 
; core mode (ring 0)
; user mode (ring 3)

; may need to create a tss segment descriptor in order to set it up for the min. Still not sure yet on that??

flush_gdt:
    mov eax, [esp+4]           ;[esp+4] is the parametered passed
    lgdt [eax]

    mov ax, 0x10               ;0x10 is the core mode data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush            ;0x08 is the core mode code segment
.flush:
    ret
