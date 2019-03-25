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
aTask1_loop
	CMP r4, r3
	BGE aTask1_end
	LDR r5, [r0], #4
	LDR r6, [r1], #4
	ADD r5, r5, r6
	STR r5, [r2], #4
	ADD r4, r4, #1
	B aTask1_loop
aTask1_end	
	MOV r0, r2
	POP	{r4-r6, pc}
	ENDP

; extern void aTask2(int32_t *arr1, int32_t *arr2, int32_t *arr3, uint32_t M_n);
; M_n = M & (n << 16)
aTask2	PROC
	PUSH {r4-r7, lr}
	;r0 -> array1
	;r1 -> array2
	;r2 -> array3
	;r3 -> 0xnnnnMMMM -> M
	;r4 -> i
	;r7 -> n
	MOV r4, #0
	MOV r7, r3, ASR #16
	LSL r3, #16
	ASR r3, #16
aTask2_loop
	CMP r4, r7
	BGE aTask2_end
	LDR r5, [r0], #4
	LDR r6, [r1], #4
	ASR r5, r7
	MUL r5, r5, r6
	STR r5, [r2], #4
	ADD r4, #1
	B aTask2_loop
aTask2_end	
	POP {r4-r7, pc}
	ENDP

; extern void aTask3(int32_t *arr1, int32_t *arr2, int32_t *arr3, uint32_t M_n);
; M_n = M & (n << 16)
aTask3 PROC
	PUSH {r4-r7, lr}
	; r0 -> array1
	; r1 -> array2
	; r2 -> array3
	; r3 -> 0xnnnnMMMM -> M
	; r4 -> i
	; r7 -> n
	MOV r4, r3 
	MOV r7, r3, ASR #16
	LSL r4, #16
	ASR r4, #16
aTask3_loop                                
	LDR r5, [r0], #4
	LDR r6, [r1], #4
	LSL r5, r7
	SDIV r5, r5, r6
	STR r5, [r2], #4
	SUB r4, #1
	CBZ r4, aTask3_end
	B aTask3_loop
aTask3_end      
	POP {r4-r7, pc}
	ENDP


; extern void aTask3(int32_t *arr1, int32_t *arr2, int32_t *arr3, uint32_t M_n);
; M_n = M & (n << 16)
aTask4	PROC
	PUSH {r4-r7, lr}
	; r0 -> array1
	; r1 -> array2
	; r2 -> array3
	; r3 -> 0xnnnnMMMM -> M
	; r4 -> i
	; r7 -> n
	LSL r3, #16
	ASR r3, #16
aTask4_loop	
	LDR r5, [r0], #4
	LDR r6, [r1], #4
	SDIV r4, r5, r6
	MLS r7, r5, r4, r6
	STR r4, [r2], #4
	SUB r3, #1
	CBZ r3, aTask4_end
	B aTask4_loop
aTask4_end     
	POP {r4-r7, pc}
    ENDP

	END
                    