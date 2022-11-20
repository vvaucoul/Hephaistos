bits 32

global __nbrlen
__nbrlen:
    push ebp
    push edi

    xor eax, eax
    xor edi, edi
    xor ecx, ecx

    mov edi, [ebp + 8]
    jmp __loop

__inc:
    inc edi
    ; div edi  / 10
    div dword [10]

__loop:
    mov cl, [edi]
    cmp cl, 0
    je __end
    jne __inc

__end:
    mov eax, ecx
    pop edi
    pop ebp
    ret