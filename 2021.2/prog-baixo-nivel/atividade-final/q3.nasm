; Atividade Final de Avaliação

; Alunos:
; Hugo Lima Romão
; Valeria Alexandra Guevara Parra

section .bss
    num resb 40

section .data
msg2 db' é par',0xa
len2 equ $-msg2
msg3 db'é impar',0xa
len3 equ $-msg3

section .text
global _start
_start:
    mov rax, 0
    mov rdi, 0
    mov rsi, num
    mov rdx, 32
    syscall

    lea rax, [num + 5]
    mov BYTE [rax], 0
    lea rdi, [num]
    call parse_uint

    and rax, 1

    jz par
    jmp impar
impar:
    mov edx,len3
    mov ecx,msg3
    mov ebx,1
    mov eax,4
    int 80h
    jmp exit

par:
    mov edx,len2
    mov ecx,msg2
    mov ebx,1
    mov eax,4
    int 80h
    jmp exit

exit:
    mov eax,1
    int 80h

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
