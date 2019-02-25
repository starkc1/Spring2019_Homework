        AREA strcopy, CODE
        
        IMPORT count
            
        ALIGN

strcpy_asm_in_s  PROC
        EXPORT  strcpy_asm_in_s
        LDR   r2, =count
        LDR   r2, [r2]
        SUB   r2, r2, #1
loop    CMP   r2, #0
        BEQ   end_loop
        LDRB  r3, [r0], #1
        STRB  r3, [r1], #1
        SUB   r2, #1
        B     loop
end_loop
        STRB  r2, [r1]
        BX    lr
        ENDP

        END  
