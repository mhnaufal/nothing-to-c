bits 64 ; tell nasm to run on 64-bit hardware
default rel ; tell nasm to compile the program with rip-relative addresing

; data segment
segment .data
        msg db "Hello, Assembly!", 0xd, 0xa, 0 ; define a variable called "msg", of type "define byte" or "byte" with the value of "Hello, Assembly!" followed by 'CR' and 'LF' as hexa and a null terminator

; text segment
segment .text
global main ; export symbol
extern ExitProcess ; import symbol
extern printf ; import symbol

main: ; program entry poin
        push rbp ; put the base pointer (rbp) to the bottom of the stack
        mov rbp, rsp ; move the stack pointer (rsp) to the current base pointer (rbp)
        sub rsp, 32 ; subtract rsp - 32 to give some shadow space for Microsoft x64. Help us to debug in an easier way

        lea rcx, [msg] ; move the pointer of [msg] to rcx (the function parameter stack)
        call printf ; print the first argument in the function parameter stack

        xor rax, rax ; zero-ing it out the rax register
        call ExitProcess
