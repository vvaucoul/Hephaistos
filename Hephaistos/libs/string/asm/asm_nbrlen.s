bits 32

global __nbrlen
__nbrlen:



    push ebp
    mov ebp, esp
    sub esp, 4

    push esi

    xor eax, eax
    xor ecx, ecx

    mov esi, [ebp + 8]

    cmp esi, 0
    je _case_zero
    jl _mul
    jmp _loop

_mul:
    push eax
    push ecx

    mov eax, -1
    mov ecx, 0
    mul edx

    mov esi, eax

    pop ecx
    pop eax
    jmp _loop

_inc:
    push eax
    push ecx
    
    mov eax, esi
    mov edx, 0
    mov ecx, 10
    div ecx
    mov esi, eax

    pop ecx
    pop eax

    inc ecx

_loop:
    cmp esi, 10
    jge _inc
    jmp _end

_case_zero:
    pop esi
    mov esp, ebp
    pop ebp
    mov eax, 1
    ret

_end:
    mov eax, ecx
    inc eax
    pop esi
    mov esp, ebp
    pop ebp
    ret