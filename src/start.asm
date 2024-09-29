section .text
    global _start
    extern main
    extern _exit

_start:
    call main

    mov rdi, rax
    call _exit
