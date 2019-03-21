	AREA asm_code, CODE, READONLY   ; Define the program area

	; Export functions defined in this file. These functions need to be declared
	; in the file calling them.
	EXPORT task1
	
		
	ALIGN                   ; Align the data in the boundary of 4 bytes.


task1 PROC
	CMP r0, r1
	BGT task1_true
task1_true 
	LSR r0, #2
	ADD r0, #1
task1_end
	BX lr
	ENDP
		
	END