; Atividade Final de Avaliação

; Alunos:
; Hugo Lima Romão
; Valeria Alexandra Guevara Parra

section .text
global _start

_start:
    call    mul                     ;multiply the values
    jmp     safe_exit               ;use jmp as opposed to call since it technically doesn't 'ret'

mul:
    ; Inputs
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

    mul     rbx                     ;multiply eax*edx, result in edx:eax

    call _printUINT

    ret

safe_exit:
    mov     eax,1                   ;initiate 'exit' syscall
    mov     ebx,0                   ;exit with error code 0
    int     0x80                    ;invoke kernel to do its bidding

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

_printUINT:
  mov rcx, digitSpace
  mov rbx, 10
  mov [rcx], rbx
  inc rcx
  mov [digitSpacePosition], rcx

_printUINTLoop:
  mov rdx, 0
  mov rbx, 10
  div rbx
  push rax
  add rdx, 48

  mov rcx, [digitSpacePosition]
  mov [rcx], dl
  inc rcx
  mov [digitSpacePosition], rcx

  pop rax
  cmp rax, 0
  jne _printUINTLoop

_printUINTLoop2:
  mov rcx, [digitSpacePosition]

  mov rax, 1
  mov rdi, 1
  mov rsi, rcx
  mov rdx, 1
  syscall

  mov rcx, [digitSpacePosition]
  dec rcx
  mov [digitSpacePosition], rcx

  cmp rcx, digitSpace
  jge _printUINTLoop2

  ret

section .bss
    n1 resb 40  
    n2 resb 40
    digitSpace resb 100
    digitSpacePosition resb 8
    ; this section is not allocated, just reserved.
    ; Automatically set to zero when program starts
    ;
    ; alloc 4 bytes of data in 'valueToPrint'
valueToPrint:
    resd    1               ; 1 resd=4 resb (Dword/Byte)