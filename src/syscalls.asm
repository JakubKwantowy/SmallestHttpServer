section .text
    global _exit
    global _read
    global _write
    global _close
    global _socket
    global _setsockopt
    global _bind
    global _listen
    global _accept

%macro syscall_func 1
    mov rax, %1
    syscall
    ret
%endmacro

%macro syscall_func2 1
    mov rax, %1
    mov r10, rcx
    syscall
    ret
%endmacro

_exit:
    syscall_func 60

_read:
    syscall_func 0

_write:
    syscall_func 1

_close:
    syscall_func 3

_socket:
    syscall_func 41

_setsockopt:
    syscall_func2 54

_bind:
    syscall_func 49

_listen:
    syscall_func 50

_accept:
    syscall_func 43
