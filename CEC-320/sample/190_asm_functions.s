                AREA my_fancy_asm_code, CODE, READONLY  

                EXPORT aTask1_4
                EXPORT aTask1_3
                EXPORT aTask1_2
                EXPORT aTask2
                EXPORT aTask3
                EXPORT aTask4
                EXPORT aTask5
                EXPORT aTask6

                IMPORT  A
                IMPORT  B 
                IMPORT  C
                IMPORT  D
                    
                ALIGN                           

; void aTask1_4(void)---Arithmetic with four registes
aTask1_4        PROC
                LDR     r0, =B
                LDR     r1, [r0]
                LDR     r0, =C
                LDR     r2, [r0]
                LDR     r0, =D
                LDR     r3, [r0]        
                ADD     r1, r2
                SUB     r1, r3
                LDR     r0, =A
                STR     r1, [r0]
                BX      lr
                ENDP

; void aTask1_3(void)---Arithmetic with three registes
aTask1_3        PROC
                LDR     r0, =B
                LDR     r1, [r0]
                LDR     r0, =C
                LDR     r2, [r0]
                LDR     r0, =D
                LDR     r0, [r0]        
                ADD     r1, r2
                SUB     r1, r0
                LDR     r0, =A
                STR     r1, [r0]
                BX      lr
                ENDP

; void aTask1_2(void)---Arithmetic with two registes
aTask1_2        PROC
                LDR     r0, =B
                LDR     r1, [r0]
                LDR     r0, =C
                LDR     r0, [r0]
                ADD     r1, r0
                LDR     r0, =D
                LDR     r0, [r0]        
                SUB     r1, r0
                LDR     r0, =A
                STR     r1, [r0]
                BX      lr
                ENDP

; uint32_t aTask2(uint32_t n)---Find the factorial of n
aTask2          PROC
                MOV     r1, #1      ; n!
                MOV     r2, #1      ; loop var i
aTask2_lpd      CMP     r2, r0      ; i <= n ?
                BGT     aTask2_end
                MUL     r1, r1, r2
                ADD     r2, #1
                B       aTask2_lpd
aTask2_end      MOV     r0, r1
                BX      lr
                ENDP

; Find the index of the max number in an array arr of size n
; uint32_t aTask3(int32_t *arr, int32_t n); 
aTask3          PROC
                PUSH    {r4, r5, lr}
                LDR     r4, [r0]           ; maxVal
                MOV     r3, #0             ; maxLoc
                MOV     r2, #1             ; loop index i
aTask3_lpe      CMP     r2, r1
                BGE     aTask3_end
                LDR     r5, [r0, r2, LSL #2]
                CMP     r5, r4
                MOVGT   r4, r5
                MOVGT   r3, r2
                ADD     r2, #1
                B       aTask3_lpe
aTask3_end      MOV     r0, r3
                POP     {r4, r5, pc}
                ENDP

; Count the number of deimal digits of an uint32_t number
; uint32_t aTask4(uint32_t n);
aTask4          PROC
                MOV     r1, #0     ; # of digits
                MOV     r2, #10
aTask4_lpf      CBZ     r0, aTask4_end
                UDIV    r0, r0, r2 ; signed division
                ADD     r1, #1
                B       aTask4_lpf 
aTask4_end      MOV     r0, r1
                BX      lr
                ENDP

; Set the parity bit 
    ; parity_odd = 0 for even parity check and 1 for odd parity check.
; uint32_t aTask4(uint32_t num,  uint32_t parity_odd); 
aTask5          PROC 
aTask5_lpg      CBZ     r0, aTask5_end 
                EOR     r1, #1
                SUB     r2, r0, #1
                AND     r0, r2
                B       aTask5_lpg
aTask5_end      MOV     r0, r1
                BX      LR
                ENDP

; Count the number of binary 1s
; uint32_t cTask6(uint32_t x);
aTask6          PROC 
                MOV     r1, r0, LSR #31
aTask6_lph      CBZ     r0, aTask6_end
                MOVS    r0, r0, LSL #2
                ADC     r1, r0, LSR #31
                B       aTask6_lph
aTask6_end      MOV     r0, r1
                BX      LR
                ENDP

                END     
