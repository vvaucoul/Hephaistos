bits 32

global __strncmp
__strncmp:
    push ebp
    mov ebp, esp
    sub esp, 4

    push esi
    push edi
    push ebx   

    mov esi, [ebp + 8]  ; S1
    mov edi, [ebp + 12] ; S2
    mov ebx, [ebp + 16] ; count

    xor eax, eax ; eax = 0
    xor ecx, ecx ; ecx = 0

    ; If s1 == NULL || s2 == NULL || count == 0 -> return 0
    cmp esi, 0x0
    je _err
    cmp edi, 0x0
    je _err
    cmp ebx, 0
    je _err

    jmp _loop

_inc:
    mov al, byte [esi + ecx]
    mov dl, byte [edi + ecx]
    cmp al, 0
    je _end
    cmp dl, 0
    je _end

    push ebx
    sub ebx, 1
    cmp ebx, ecx
    jz _end_pop
    pop ebx

    inc ecx
    jmp _loop

_end_pop:
    pop ebx
    jmp _end

_loop:
    ; if i >= count -> jmp end
    cmp ecx, ebx
    jge _end

    ; if s1[i] == s2[i] -> jmp inc else jmp err
    mov al, byte [esi + ecx]
    mov dl, byte [edi + ecx]
    cmp al, dl
    je _inc
    jne _end

_err:
    pop ebx
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

_end:
    xor eax, eax
    xor edx, edx

    mov al, [esi + ecx]
    movsx eax, al
    mov dl , [edi + ecx]
    movsx edx, dl
    sub eax, edx

    pop ebx
    pop edi
    pop esi
    mov esp, ebp
    pop ebp

    ret