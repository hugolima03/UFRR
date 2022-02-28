section .bss
    n1 resb 6   
    n2 resb 6
    digitSpace resb 100
    digitSpacePosition resb 8
valueToPrint:
    resd    1

section .text
global _start
_start:
    call    mul                    
    call    convert_values        
    jmp     safe_exit              
mul:
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

    mul rbx

    call _printUINT

    ret
convert_values:
    mov     edx,0                   ;value actually edx:eax, zero edx
    mov     ecx,0x0A                ;divide edx:eax by 10
    idiv    ecx                     ;result in eax, remainder in edx
    push    rax                     ;save value on stack
    mov     eax,edx                 ;put remainder (0-9) in eax
    add     eax,'0'                 ;convert value to ascii character
    ; call    print_char              ;print the latest character
    pop     rax                     ;restore value
    or      eax,eax                 ;set flags based on eax value
    jnz     convert_values          ;while eax != 0 continue process
endl:
    mov     eax, 10                 ;store newline character in eax to be printed
    ; call    print_char              ;print value
    ret
print_char:
    mov     [valueToPrint], eax     ;store contents of 'eax' in [valueToPrint]
    mov     eax, 4                  ;syswrite
    mov     ebx, 1                  ;stdout
    mov     ecx, valueToPrint       ;machine will take whatever value exists in [ecx] and print
    mov     edx, 1                  ;print only a single byte's worth of data
    int     0x80                    ;invoke kernel to perfrom instruction
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
