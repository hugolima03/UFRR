 section .bss
  digitSpace resb 100
  digitSpacePosition resb 8
 
 section .text
  global _start

_start:
  mov rax, -123
  call _printUINT

  mov rax, 60
  mov rdi, 0
  syscall

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