section .bss
num resb 1

section .data
msg1 db'enter a number',0xa
len1 equ $-msg1
msg2 db' is even',0xa
len2 equ $-msg2
msg3 db'is odd',0xa
len3 equ $-msg3

section .text
global _start
_start:
mov edx,len1
mov ecx,msg1
mov ebx,1
mov eax,4
int 80h

mov ecx,num
mov ebx,0
mov eax,3
int 80h


mov al,[num]
add al,30h
and al,1
jz iseven
jmp isodd
isodd:
mov edx,len3
mov ecx,msg3
mov ebx,1
mov eax,4
int 80h
jmp exit

iseven:
mov edx,len2
mov ecx,msg2
mov ebx,1
mov eax,4
int 80h
jmp exit

exit:
mov eax,1
int 80h