section .data
	msg db "Hello, World", 10
	len equ $ - msg

section .text
	global main

main:
	; write(1, msg, len)
	mov rax, 1          ; syscall: write
	mov rdi, 1          ; fd: stdout
	mov rsi, msg        ; buf
	mov rdx, len        ; count
	syscall

	; exit(0)
	mov rax, 60         ; syscall: exit
	xor rdi, rdi        ; status 0
	syscall
