bits 32

global __nbrlen_base
__nbrlen_base:
    push ebp
    mov ebp, esp
    sub esp, 4

    push esi
    push edi

    xor eax, eax
    xor ecx, ecx

    mov esi, [ebp + 8] ; esi = nbr
    mov edi, [ebp + 12] ; edi = base

    cmp esi, 0
    jz _case_zero

    cmp edi, 0
    jz _end

    cmp esi, 0
    jl _mul
    jmp _loop

_mul:
    push eax
    push ecx

    mov eax, -1
    mov ecx, 0
    mul esi

    mov esi, eax

    pop ecx
    pop eax
    jmp _loop

_inc:
    push eax
    push ecx

    mov eax, esi
    mov edx, 0
    mov ecx, edi
    div ecx
    mov esi, eax

    pop ecx
    pop eax

    inc ecx

_loop:
    cmp esi, 0
    jne _inc
    jmp _end

_case_zero:
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    mov eax, 1
    ret

_end:
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    mov eax, ecx
    ret