section .data

sdot dq 5.9

section .text
    global asm_dot_product

; double asm_dot_product(double *A, double *B, int n)
asm_dot_product:
    ; A in rcx, B in rdx, n in r8
    LEA rsi, [rcx]         ; Vector A pointer
    LEA rdi, [rdx]         ; Vector B pointer
    MOV RCX, r8            ; n (counter)
    XORPD xmm0, xmm0       ; Initialize accumulator xmm0 = 0.0

dot_loop:
    CMP RCX, 0       ; Check if n == 0
    je dot_done            ; Exit if no more elements

    movsd xmm1, [rsi]      ; Load A[i] into XMM1
    movsd xmm2, [rdi]      ; Load B[i] into XMM2
    mulsd xmm1, xmm2       ; Multiply XMM1 = A[i] * B[i]
    addsd xmm0, xmm1       ; Add result to accumulator
    ;MOVSD xmm0, [sdot]

    add rsi, 8             ; Increment A pointer (sizeof(double) = 8 bytes)
    add rdi, 8             ; Increment B pointer
    dec RCX                ; Decrement n
    jmp dot_loop           ; Repeat loop

dot_done:
    ;MOVSD xmm0, [sdot]
    ret                    ; Return result in xmm0
