	AREA asmcode, CODE, READONLY
	EXPORT read_port
	EXPORT set_port
	EXPORT clear_port
		
	ALIGN

read_port PROC
	LDR r2, [r0]
	AND r0, r1, r2
	BX lr
	ENDP

set_port PROC
	LDR r2, [r0]
	ORR r2, r1
	STR r2, [r0]
	BX lr
	ENDP
		
clear_port PROC
	LDR r2, [r0]
	BIC r2, r1
	STR r2, [r0]
	BX lr
	ENDP
		
	END