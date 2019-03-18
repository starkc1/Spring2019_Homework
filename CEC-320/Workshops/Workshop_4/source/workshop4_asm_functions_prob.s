	AREA workshop4_asm_functions_prob, CODE, READONLY  
	
	EXPORT aTask1
	EXPORT aTask2
	EXPORT aTask3
	EXPORT aTask4
		
	ALIGN                           


; extern void aTask1(int32_t *arr1, int32_t *arr2, int32_t *arr3, uint32_t M);
;r0 = arr1
;r1 = arr2
;r2 = arr3
;r3 = M
aTask1	PROC
	PUSH {r4-r6, lr}
	MOV r4, #0 ;i
	MOV r5, #0 ;r0 temp
	MOV r6, #0 ;r1 temp
aTask1_loop
	CMP r4, r3
	BGE aTask1_end
	LDR r5, [r0], #4
	LDR r6, [r1], #4
	ADD r5, r6
	MOV [r2, r4, LSL #2], r5
	ADD r4, #1
	B aTask1_loop
aTask1_end	
	MOV r0, r2
	POP	{r4-r6, pc}
	BX lr
	ENDP

; extern void aTask2(int32_t *arr1, int32_t *arr2, int32_t *arr3, uint32_t M_n);
; M_n = M & (n << 16)
aTask2	PROC
	PUSH {r4-r7, lr}

aTask2_end	
	POP {r4-r7, pc}
	ENDP

; extern void aTask3(int32_t *arr1, int32_t *arr2, int32_t *arr3, uint32_t M_n);
; M_n = M & (n << 16)
aTask3 PROC
	PUSH {r5-r7, lr}
 
aTask3_end      
	POP {r5-r7, pc}
    ENDP

; extern void aTask3(int32_t *arr1, int32_t *arr2, int32_t *arr3, uint32_t M_n);
; M_n = M & (n << 16)
aTask4	PROC
	PUSH {r4-r7, lr}

aTask4_end      
	POP {r4-r7, pc}
    ENDP

	END
                    