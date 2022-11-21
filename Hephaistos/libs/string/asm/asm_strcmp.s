bits 32

global __strcmp
__strcmp:
    push ebp
    mov ebp, esp
    sub esp, 4

    push esi
    push edi

    mov esi, [ebp + 8]
    mov edi, [ebp + 12]

    xor eax, eax
    xor ecx, ecx

    cmp esi, 0
    je _err

    cmp edi, 0
    je _err

    jmp _loop

_inc:
    inc ecx

_loop:
    mov al, byte [esi + ecx]
    mov dl, byte [edi + ecx]
    cmp al, 0
    je _end
    cmp dl, 0
    je _end
    cmp al, dl
    je _inc
    jne _end

_err:
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    mov eax, -1
    ret

_end:
    mov al, [esi + ecx]
    mov dl, [edi + ecx]
    sub al, dl

    pop edi
    pop esi
    mov esp, ebp
    pop ebp

    cmp al, 0
    jl _end_neg
    jg _end_pos
    jmp _end_zero

_end_neg:
    mov eax, -1
    ret

_end_zero:
    mov eax, 0
    ret

_end_pos:
    mov eax, 1
    ret