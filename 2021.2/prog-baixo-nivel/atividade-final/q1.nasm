segment .data
    msg db "A soma é: "
    len equ $-msg
    lf db 0x0A

segment .bss
    n1 resb 40      
    n2 resb 40
    sum resb 40
    sum_len resd 1

section .text
    global _start

_start:
    ; Input
    mov rax, 0
    mov rdi, 0
    mov rsi, n1
    mov rdx, 32
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, n2
    mov rdx, 32
    syscall

    lea rax, [n1 + 5];
    mov BYTE [rax], 0
    lea rdi, [n1]
    call parse_uint

    mov rbx, rax

    lea rax, [n2 + 5];
    mov BYTE [rax], 0
    lea rdi, [n2]
    call parse_uint

    add rax, rbx

    ; Number para string
    mov edi, sum
    call int2str
    sub edi, sum
    mov [sum_len], edi

    ; Output "A soma é: "
    mov ecx, msg
    mov edx, len
    mov ebx, 1
    mov eax, 4
    int 0x80

    ; Output soma valor
    mov eax, 4
    mov ebx, 1
    mov ecx, sum
    mov edx, [sum_len]
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, lf
    mov edx, 1
    int 0x80

    ; Exit code
    mov eax, 1
    mov ebx, 0
    int 0x80

int2str:    ; Converte um inteiro positivo em EAX em uma string apontada por EDI
    xor ecx, ecx
    mov ebx, 10
    .LL1:                   ; First loop: Save the remainders
    xor edx, edx            ; Clear EDX for div
    div ebx                 ; EDX:EAX/EBX -> EAX Remainder EDX
    push dx                 ; Save remainder
    inc ecx                 ; Increment push counter
    test eax, eax           ; Anything left to divide?
    jnz .LL1                ; Yes: loop once more

    .LL2:                   ; Second loop: Retrieve the remainders
    pop dx                  ; In DL is the value
    or dl, '0'              ; To ASCII
    mov [edi], dl           ; Save it to the string
    inc edi                 ; Increment the pointer to the string
    loop .LL2               ; Loop ECX times

    mov byte [edi], 0       ; Termination character
    ret                     ; RET: EDI points to the terminating NULL

parse_uint:
    mov r8, 10
    xor rax, rax
    xor rcx, rcx
.loop:
    movzx r9, byte [rdi + rcx] 
    cmp r9b, '0'
    jb .end
    cmp r9b, '9'
    ja .end
    xor rdx, rdx 
    mul r8
    and r9b, 0x0f
    add rax, r9
    inc rcx 
    jmp .loop 
    .end:
    mov rdx, rcx
    ret
