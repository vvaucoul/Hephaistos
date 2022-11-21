bits 32

global __strlen
__strlen:
    push ebp
    mov ebp, esp
    sub esp, 4
    
    xor ecx, ecx
    mov edx, [ebp + 8]

    cmp edx, 0
    je _end

_loop:
    cmp byte [edx + ecx], 0
    je _end
    inc ecx
    jmp _loop

_end:
    mov esp, ebp
    pop ebp
    mov eax, ecx
    ret