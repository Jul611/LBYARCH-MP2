section .data



section .text
    global asm_dot_product

; double asm_dot_product(double *A, double *B, int n)
asm_dot_product:
    ; A in rcx, B in rdx, n in r8
    LEA rsi, [rcx]         
    LEA rdi, [rdx]         
    MOV RCX, r8            
    XORPD xmm0, xmm0       

dot_loop:
    CMP RCX, 0       
    je dot_done            

    movsd xmm1, [rsi]      
    movsd xmm2, [rdi]      
    mulsd xmm1, xmm2       
    addsd xmm0, xmm1       
    ;MOVSD xmm0, [sdot]

    add rsi, 8             
    add rdi, 8             
    dec RCX               
    jmp dot_loop           

dot_done:
    
    ret                    ; Return result in xmm0
