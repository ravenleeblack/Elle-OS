
section .page_tables

sadule_dir_address equ 0x1000

setup_paging:                      ; Initialize page directory
    mov ebx, 4096          ; Move the address of page tables to ebx
    mov ecx, 1024                  ; Number of page tables
    mov esi, sadule_dir_address    ; Move the address of page directory to esi

sadule_directory:
    mov eax, ebx                   ; Store the address of page table in eax
    or eax, 0x03                   ; Set Present and Read/Write flags
    mov [esi], eax                 ; Store the page table address in the page directory entry
    add esi, 4                     ; Move to the next page directory entry
    add ebx, 4096                  ; Move to the next page table
    loop sadule_directory          ; Repeat for all page tables

    ; Initialize page tables
    mov eax, 0x00000002            ; Physical address of the first page table
    mov ebx, 4096           ; Move the address of page tables to ebx
    mov ecx, 1024                  ; Number of page tables

sadule_tables:
    mov edi, eax                   ; Store the physical address in edi
    mov esi, ebx                   ; Move the address of page table to esi
    mov eax, 1024

sadules:
    mov dword [esi], edi           ; Store the physical address in the page table entry
    add esi, 4                     ; Move to the next page table entry
    add edi, 4096                  ; Move to the next page
    loop sadules                   ; Repeat for all page table entries
    add ebx, 4096                  ; Move to the next page table
    loop sadule_tables             ; Repeat for all page tables

enable_paging:
    ; Enable paging by setting CR0 register
    mov eax, cr0
    or eax, 0x80000000             ; Set the paging bit
    mov cr0, eax
	ret
