                AREA my_fancy_asm_code, CODE, READONLY  

                EXPORT task1i
                EXPORT task1u
                EXPORT task2
                EXPORT task3
                EXPORT task4
                EXPORT task5
                EXPORT task6
                EXPORT task7
                EXPORT task8
                EXPORT task9
                EXPORT task10
                EXPORT task11
                EXPORT task12
                EXPORT task13
                EXPORT task14
                    
                ALIGN                           

;int32_t task1i(int32_t a, int32_t x);
task1i          PROC
                CMP     r0, r1
                BLE     task1i_end
task1i_then     LSL     r0, #2
task1i_end      BX      lr
                ENDP

;uint32_t task1u(uint32_t a, uint32_t x);
task1u          PROC
                CMP     r0, r1
                BLS     task1u_end
task1u_then     LSL     r0, #2
task1u_end      BX      lr
                ENDP
            
;int32_t task2(int32_t a, int32_t x);
task2           PROC
                CMP     r1, #20
                BLE     task2_then
                CMP     r1, #25
                BLT     task2_end
task2_then      LSL     r0, #2
task2_end       BX      lr
                ENDP

;int32_t task3(int32_t a, int32_t x);
task3           PROC
                CMP     r0, r1
                BNE     task3_else
task3_then      ADD     r1, #3
                B       task3_end
task3_else      SUB     r1, #4
task3_end       MOV     r0, r1
                BX      lr
                ENDP

;int32_t task4(int32_t a, int32_t x);
task4           PROC
                CMP     r1, #20
                BLE     task4_then
                CMP     r1, #25
                BLT     task4_else
task4_then      LSL     r0, #3
                B       task4_end
task4_else      LSL     r0, #4
task4_end       BX      lr
                ENDP

;int32_t task5(int32_t n);
task5           PROC
                MOV     r1, #0             ; the sumation
                MOV     r2, #0             ; loop variable i
task5_loop      CMP     r2, r0
                BGE     task5_endloop
                ADD     r1, r2, LSL #2
                ADD     r2, #1
                B       task5_loop
task5_endloop   MOV     r0, r1
                BX      lr
                ENDP

;int32_t task6(int32_t *ptr, int32_t n);
task6           PROC
                PUSH    {r4, lr}
                MOV     r4, #0             ; the sumation
                MOV     r2, #0             ; loop variable i
task6_loop      CMP     r2, r1
                BGE     task6_endloop
                LDR     r3, [r0], #4
                ADD     r4, r3
                ADD     r2, #1
                B       task6_loop
task6_endloop   MOV     r0, r4
                POP     {r4, pc}
                ENDP

;int32_t task7(int32_t n);
task7           PROC
                MOV     r1, #0             ; the sumation
                MOV     r2, #0             ; loop variable i
task7_loop      CMP     r2, r0
                BGE     task7_endloop
                ADD     r1, r2, LSL #2
                ADD     r2, #1
                B       task7_loop
task7_endloop   MOV     r0, r1
                BX      lr
                ENDP

;int32_t task8(int32_t n);
task8           PROC
                MOV     r1, #0             ; the sumation
                MOV     r2, r0             ; loop variable i
task8_loop      CMP     r2, #0
                BLT     task8_endloop
                ADD     r1, r2, LSL #2
                SUB     r2, #1
                B       task8_loop
task8_endloop   MOV     r0, r1
                BX      lr
                ENDP

;int32_t task9(int32_t n);
task9           PROC
                MOV     r1, #0             ; the sumation
                MOV     r2, r0             ; loop variable i
task9_loop      ADD     r1, r2, LSL #2
                SUB     r2, #1
                CMP     r2, #0
                BGE     task9_loop
task9_endloop   MOV     r0, r1
                BX      lr
                ENDP

;int32_t task10(int32_t n);
task10          PROC
                MOV     r1, #0             ; the sumation
                MOV     r2, #0             ; loop variable i
task10_loop     ADD     r1, r2, LSL #2
                ADD     r2, #1
                CMP     r2, r0
                BLT     task10_loop
task10_endloop  MOV     r0, r1
                BX      lr
                ENDP 

;int32_t task11(int32_t a, int32_t x);
task11          PROC
                CMP     r1, #20
                BLE     task11_end 
                CMP     r1, #25
                BGE     task11_end
task11_else     LDR     r0, =11
task11_end      BX      lr
                ENDP

; void task12(int32_t *input_array, int32_t *outpt_array, int n);
task12          PROC
                PUSH    {r4, lr}
                MOV     r3, #0      ; the loop variable i
task12_loop     CMP     r3, r2
                BGE     task12_end
                CMP     r3, #3
                BEQ     task12_end
                LDR     r4, [r0], #4
                LSL     r4, #1
                STR     r4, [r1], #4
                ADD     r3, #1
                B       task12_loop
task12_end      POP     {r4, pc}
                ENDP

; void task13(int32_t *input_array, int32_t *outpt_array, int n);
task13          PROC
                PUSH    {r4, lr}
                MOV     r3, #0      ; the loop variable i
task13_loop     CMP     r3, r2
                BGE     task13_end
                CMP     r3, #3
                BEQ     task13_update_i
                LDR     r4, [r0], #4
                LSL     r4, #2
                STR     r4, [r1, r3, LSL #2]
task13_update_i ADD     r3, #1
                B       task13_loop
task13_end      POP     {r4, pc}
                ENDP

; void task14(int32_t n);
task14          PROC
                MOV     r1, r0
                MOV     r2, r0
                
                AND     r0, r0, r1
                ADD     r2, r2, #1
                MOV     r3, r2
                
                CMP     r0, #0
                ITTE    NE
                ANDNE   r0, r1, r2
                ADDNE   r2, r2, #1
                MOVEQ   r3, r2
                
                CMP     r0, #0
                ANDNE   r0, r1, r2
                ADDNE   r2, r2, #1
                MOVEQ   r3, r2
                BX      lr
                ENDP
    
                END     
