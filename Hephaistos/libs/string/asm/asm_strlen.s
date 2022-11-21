bits 32

global __strlen
__strlen:
    push ebp
    mov ebp, esp
    sub esp, 4

    push esi

    xor eax, eax
    xor ecx, ecx

    mov esi, [ebp + 8]
    
    cmp esi, 0
    je _end

    jmp _loop

_inc:
    inc ecx
    jmp _loop

_loop:
    mov al, [esi + ecx]
    cmp al, 0
    jne _inc
    je _end

_end:
    mov eax, ecx
    pop esi
    mov esp, ebp
    pop ebp
    ret