global idt_load
extern idt_selector_ptr
idt_load:
    lidt [idt_selector_ptr]              ; load the interrupt table
    ret                                  ; return back to our c code


global handle_asm_request
global handle_asm_system_call

global syscall
global interrupt_stack_pointer
global ser_00
global ser_01
global ser_02
global ser_03
global ser_04
global ser_05
global ser_06
global ser_07 
global ser_08
global ser_09
global ser_10
global ser_11
global ser_12
global ser_13
global ser_14
global ser_15
global ser_16
global ser_17
global ser_18
global ser_19
global ser_20
global ser_21
global ser_22
global ser_23
global ser_24
global ser_25
global ser_26
global ser_27
global ser_28
global ser_29
global ser_30
global ser_31
global ser_32,

global req_00
global req_01
global req_02
global req_03
global req_04
global req_05
global req_06
global req_07
global req_08
global req_09
global req_10
global req_11
global req_12
global req_13
global req_14
global req_15
global req_sys_call

[extern handle_core_service]
[extern handle_core_request]
[extern handle_core_system_call]
global flush_idt
global flush_tss


ser_00:
    push dword 0
    push dword 0
    jmp handle_asm_service	

ser_01:
    push dword 0
    push dword 1
    jmp handle_asm_service

ser_02:
    push dword 0
    push dword 2
    jmp handle_asm_service

ser_03:
    push dword 0
    push dword 3
    jmp handle_asm_service

ser_04:
    push dword 0
    push dword 4
    jmp handle_asm_service

ser_05:
    push dword 0
    push dword 5
    jmp handle_asm_service

ser_06:
    push dword 0
    push dword 6
    jmp handle_asm_service

ser_07:
    push dword 0
    push dword 7
    jmp handle_asm_service

ser_08:
    push dword 8
    jmp handle_asm_service

ser_09:
    push dword 0
    push dword 9
    jmp handle_asm_service

ser_10:
    push dword 10
    jmp handle_asm_service

ser_11:
    push dword 11
    jmp handle_asm_service

ser_12:
    push dword 12
    jmp handle_asm_service

ser_13:
    push dword 13
    jmp handle_asm_service

ser_14:
    push dword 14
    jmp handle_asm_service

ser_15:
    push dword 0
    push dword 15
    jmp handle_asm_service

ser_16:
    push dword 0
    push dword 16
    jmp handle_asm_service

ser_17:
    push dword 17
    jmp handle_asm_service

ser_18:
    push dword 0
    push dword 18
    jmp handle_asm_service

ser_19:
    push dword 0
    push dword 19
    jmp handle_asm_service

ser_20:
    push dword 0
    push dword 20
    jmp handle_asm_service

ser_21:
    push dword 0
    push dword 21
    jmp handle_asm_service

ser_22:
    push dword 0
    push dword 22
    jmp handle_asm_service

ser_23:
    push dword 0
    push dword 23
    jmp handle_asm_service

ser_24:
    push dword 0
    push dword 24
    jmp handle_asm_service

ser_25:
    push dword 0
    push dword 25
    jmp handle_asm_service

ser_26:
    push dword 0
    push dword 26
    jmp handle_asm_service

ser_27:
    push dword 0
    push dword 27
    jmp handle_asm_service

ser_28:
    push dword 0
    push dword 28
    jmp handle_asm_service

ser_29:
    push dword 0
    push dword 29
    jmp handle_asm_service

ser_30:
    push dword 0
    push dword 30
    jmp handle_asm_service

ser_31:
    push dword 0
    push dword 31
    jmp handle_asm_service



req_00:
    push dword 0
    push dword 32
    jmp handle_asm_request

req_01:
    push dword 0
    push dword 33
    jmp handle_asm_request

req_02:
    push dword 0
    push dword 34
    jmp handle_asm_request

req_03:
    push dword 0
    push dword 35
    jmp handle_asm_request

req_04:
    push dword 0
    push dword 36
    jmp handle_asm_request

req_05:
    push dword 0
    push dword 37
    jmp handle_asm_request

req_06:
    push dword 0
    push dword 38
    jmp handle_asm_request

req_07:
    push dword 0
    push dword 39
    jmp handle_asm_request

req_08:
    push dword 0
    push dword 40
    jmp handle_asm_request

req_09:
    push dword 0
    push dword 41
    jmp handle_asm_request

req_10:
    push dword 0
    push dword 42
    jmp handle_asm_request

req_11:
    push dword 0
    push dword 43
    jmp handle_asm_request

req_12:
    push dword 0
    push dword 44
    jmp handle_asm_request

req_13:
    push dword 0
    push dword 45
    jmp handle_asm_request

req_14:
    push dword 0
    push dword 46
    jmp handle_asm_request

req_15:
    push dword 0
    push dword 47
    jmp handle_asm_request

req_sys_call:
    push dword 0
    push dword 128
    jmp handle_asm_system_call



handle_asm_service:                                            
    pusha
    push  ds
    push  es
    push  fs
    push  gs
    mov   ax, 0x10   					
    mov   ds, ax
    mov   es, ax
    mov   fs, ax
    mov   gs, ax
    mov   eax, esp   					
    push  eax
    mov   eax, handle_core_service
    call  eax       					
    pop   eax
    pop   gs
    pop   fs
    pop   es
    pop   ds
    popa
    add   esp, 8     					
    iret           						

handle_asm_request:
    pusha
    push  ds
    push  es
    push  fs
    push  gs
    mov   ax, 0x10
    mov   ds, ax
    mov   es, ax
    mov   fs, ax
    mov   gs, ax
    mov   eax, esp
    push  eax
    mov   eax, handle_core_request
    call  eax
    pop   eax
    pop   gs
    pop   fs
    pop   es
    pop   ds
    popa
    add   esp, 8
    iret


handle_asm_system_call:
    pushad                       
    push ds                       
    push es
    push fs
    push gs
    mov ax, 0x10                  
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, handle_core_system_call
    call eax
    pop eax
    pop gs                       
    pop fs
    pop es
    pop ds
    popad                         
    add esp, 8                   
    pop ebx
    pop ecx
    pop edx
    pop esi
    pop edi
    pop ebp
    pop gs
    pop fs
    pop es
    pop ds
    add esp, 4   
    add esp, 4    
    iret         

syscall:
    push ebp
    mov ebp, esp
    push eax
    push ebx
    push ecx
    push edx
    push esi
    push edi
    mov eax, [ebp + 8]
    mov ebx, [ebp + 12]
    mov ecx, [ebp + 16]
    mov edx, [ebp + 20]
    mov esi, [ebp + 24]
    mov edi, [ebp + 28]
    int 48
    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    add esp, 4
    leave
    ret

flush_idt:
    mov eax, [esp+4]       ;[esp+4] is the parametered passed
    lidt [eax]
    ret
