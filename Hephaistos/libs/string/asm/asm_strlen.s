bits 32

global __strlen
__strlen:
    push ebp
    push edi

    xor eax, eax
    xor edi, edi
    xor ecx, ecx

    mov edi, [ebp + 8]
    jmp __loop

__inc:
    inc ecx
    jmp __loop

__loop:
    mov al, [edi + ecx]
    test al, al
    jnz __inc
    jz __end

__end:
    mov eax, ecx
    pop edi
    pop ebp
    ret