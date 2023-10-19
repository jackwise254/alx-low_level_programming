section .data
    hello db 'Hello, Holberton',10 ; 10 is the ASCII value for newline
    hello_len equ $ - hello         ; Compute the length of the string

section .text
    global main
    extern printf

main:
    ; Prepare arguments for printf
    mov rdi, hello     ; rdi gets the address of the format string
    xor rax, rax       ; Clear rax (printf's way of counting floating point arguments, none here)

    ; Call printf
    call printf

    ; Return
    mov rax, 0         ; Return 0 status
    ret
