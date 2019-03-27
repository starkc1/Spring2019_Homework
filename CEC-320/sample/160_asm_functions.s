        AREA my_fancy_asm_code, CODE, READONLY   
            
; Expl 16-01
        EXPORT x_cmp1_y_ab_i1_asm
        EXPORT x_cmp1_y_ab_i2_asm
        EXPORT x_cmp1_y_ab_u_asm

; Expl 16-02
        EXPORT x_cmp1_y_ab_i_asm_cond_e
        EXPORT x_cmp1_y_ab_u_asm_cond_e

; Expl 16-03
        EXPORT abs_asm_cond_b
        EXPORT abs_asm_cond_e
            
        ALIGN      

; int32_t  x_cmp1_y_ab_i1_asm(int32_t x, int32_t y, int32_t a, int32_t b);
x_cmp1_y_ab_i1_asm PROC
                CMP     r0, r1
                BGT     cmp1_i1_then
cmp1_i1_slse    MOV     r0, r3
                B       cmp1_i1_end
cmp1_i1_then    MOV     r0, r2
cmp1_i1_end     BX      lr
                ENDP

; int32_t  x_cmp1_y_ab_i2_asm(int32_t x, int32_t y, int32_t a, int32_t b);
x_cmp1_y_ab_i2_asm PROC
                CMP     r0, r1
                BLE     cmp1_i2_else ; Note the negative logic here!
cmp1_i2_then    MOV     r0, r2
                B       cmp1_i2_end
cmp1_i2_else    MOV     r0, r3
cmp1_i2_end     BX      lr
                ENDP
                    
; uint32_t x_cmp1_y_ab_u_asm(uint32_t x, uint32_t y, uint32_t a, uint32_t b);
x_cmp1_y_ab_u_asm PROC
                CMP     r0, r1
                BLS     cmp1_u_else
cmp1_u_then     MOV     r0, r2
                B       cmp1_u_end
cmp1_u_else     MOV     r0, r3
cmp1_u_end      BX      lr
                ENDP

; int32_t  x_cmp1_y_ab_i_asm_cond_e(int32_t x, int32_t y, int32_t a, int32_t b);
x_cmp1_y_ab_i_asm_cond_e PROC
                CMP     r0, r1
                MOVGT   r0, r2
                MOVLE   r0, r3
                BX      lr
                ENDP

; uint32_t x_cmp1_y_ab_u_asm_cond_e(uint32_t x, uint32_t y, uint32_t a, uint32_t b);
x_cmp1_y_ab_u_asm_cond_e PROC
                CMP     r0, r1
                MOVHI   r0, r2
                MOVLS   r0, r3
                BX      lr
                ENDP
                    
; int32_t abs_asm_cond_b(int32_t x);
abs_asm_cond_b  PROC
                CMP     r0, #0
                BGE     abs_asm_cond_b_then
                MOV     r1, #0          ; this instruction and the next can be 
                SUB     r0, r1, r0      ; combined as RSB r0, r0, #0
abs_asm_cond_b_then
                BX      lr
                ENDP

; int32_t abs_asm_cond_e(int32_t x);
abs_asm_cond_e  PROC
                CMP     r0, #0
                MOVLT   r1, #0          ; this instruction and the next can be 
                SUBLT   r0, r1, r0      ; combined as RSBLT r0, r0, #0
                BX      lr
                ENDP
            
                END   
