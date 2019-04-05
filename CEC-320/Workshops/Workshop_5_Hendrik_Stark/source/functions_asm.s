	AREA functions_asm, CODE, READONLY
		
	EXPORT swap_asm_1;
	EXPORT swap_asm_2;
	EXPORT swap_asm_3;
	EXPORT rank_descending_asm
	
	ALIGN
		
swap_asm_1 PROC
	LDRB r2, [r0]
	LDRB r3, [r1]
	CMP r2, r3
	BEQ end_swap_asm_1
	STRB r2, [r1]
	STRB r3, [r0]
end_swap_asm_1
	BX lr
	ENDP
		
		
swap_asm_2 PROC
	CMP r0, r1
	BEQ end_swap_asm_2
	LDRB r2, [r0]
	LDRB r3, [r1]
	ADD r2, r3
	SUB r3, r2, r3
	SUB r2, r3
	STRB r2, [r0]
	STRB r3, [r1]
end_swap_asm_2
	BX lr
	ENDP
		

swap_asm_3 PROC
	CMP r0, r1
	BEQ end_swap_asm_3
	LDRB r2, [r0]
	LDRB r3, [r1]
	EOR r2, r3
	EOR r3, r2
	EOR r2, r3
	STRB r2, [r0]
	STRB r3, [r1]
end_swap_asm_3
	BX lr
	ENDP
		
		
rank_descending_asm PROC
	PUSH {r4-r10, lr}
	MOV r4, r0
	SUB r5, r1, #1
	MOV r6, #0
rank_des_loop_1
	CMP r6, r5
	BGE rank_des_loop_1_end
	SUB r7, r5, r6
	MOV r8, #0
rank_des_loop_2
	CMP r8, r7
	BGE rank_des_loop_2_end
	ADD r0, r4, r8
	ADD r1, r0, #1
	LDRB r9, [r0]
	LDRB r10, [r1]
	CMP r9, r10
	BGE else_label
	BL swap_asm_1
else_label
	ADD r8, #1
	B rank_des_loop_2
rank_des_loop_2_end
	ADD r6, #1
	B rank_des_loop_1
rank_des_loop_1_end
	POP {r4-r10,pc}
	ENDP
		
	END