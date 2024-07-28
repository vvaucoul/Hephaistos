bits 32

global __nbrlen
__nbrlen:

    push ebp
    mov ebp, esp
    sub esp, 4

    push esi

    xor eax, eax
    xor ecx, ecx

    mov esi, [ebp + 8]    ; Retrieve the argument (the number)

    cmp esi, 0
    je _case_zero         ; If the number is zero, jump to _case_zero
    jl _negate            ; If the number is negative, jump to _negate

_loop:
    ; Loop to count the digits
    inc ecx               ; Increment the digit counter
    mov eax, esi
    cdq                   ; Sign-extend EAX into EDX
    mov ecx, 10
    idiv ecx              ; Divide EAX by 10
    mov esi, eax          ; Place the quotient in ESI
    cmp esi, 0            ; If the quotient is zero, exit the loop
    jne _loop

    jmp _end

_negate:
    ; If the number is negative, convert it to positive and count the digits
    neg esi               ; Convert to positive
    jmp _loop

_case_zero:
    ; Handling the case where the number is zero
    mov eax, 1
    jmp _cleanup

_end:
    ; Put the digit counter in EAX
    mov eax, ecx

_cleanup:
    ; Clean up the stack and return
    pop esi
    mov esp, ebp
    pop ebp
    ret