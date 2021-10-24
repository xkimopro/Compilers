; void writeReal (double d);
; --------------------------
; This function prints a real number to the standard output.


            ;section .code
            global  _writeReal
            extern  _formatReal
            extern  _writeString
            extern printf
_writeReal:

    sub rsp, 8
    ;movq xmm0, qword [rs]
    mov rdi, string
    mov rax, 1
    call printf
    add rsp, 8

    ret

section .data
    string db `%f`, 0