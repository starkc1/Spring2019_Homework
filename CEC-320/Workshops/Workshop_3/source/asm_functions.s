        AREA my_fancy_asm_code, CODE, READONLY   ; Define the program area
        
        ; Export functions defined in this file. These functions need to be declared 
        ; in the file calling them.
        EXPORT task10
        EXPORT task11
        EXPORT task12
        EXPORT task13
        EXPORT task14
        EXPORT task15

        IMPORT gPtrArray10a
        IMPORT gPtrArray11a
        IMPORT gPtrArray12a
        IMPORT gPtrArray13a
        IMPORT gPtrArray14a
        IMPORT gPtrArray15a
        IMPORT gVar1
            
        ALIGN                   ; Align the data in the boundary of 4 bytes. 
           
task10  PROC
        LDR  r0, =gPtrArray10a  ; Loading the address of the global variable gPtrArray10a
        LDR  r0, [r0]           ; Loading the content of the global variable gPtrArray10a
        LDR  r1, =gVar1         ; Loading the address of the global variable gVar1
        LDR  r1, [r1]           ; Loading the content of the global variable gVar1
        MOV  r2, #0             ; variable (int) i
task10_loop
        CMP  r2, r1                 ; test = r2 - r1
        BGE  task10_end             ; if test >= 0, then branch to task10_end    
        MOV  r3, r2, LSL #2         ; r3 <- r2 * 4
        SUB  r3, #15                ; r3 <- r3 - 15
        STRB r3, [r0, r2]           ; r3 -> mem[r0 + r2] or r3 -> mem[r0 + i]
        ADD  r2, #1                 ; r2 <- r2 + 1
        B    task10_loop            ; branch to task10_loop
task10_end
        BX   lr                     ; return
        ENDP

; If you need to use registers starting from r4, you need to PUSH them first to save the 
; run-time environment for the caller. You need to POP them up at the exit of the code.

task11  PROC
		
        BX   lr     
        ENDP

task12  PROC
        PUSH {r4-r5, lr}
        LDR  r0, =gPtrArray10a    
        LDR  r0, [r0]           
        LDR  r4, =gPtrArray12a    
        LDR  r4, [r4]               
        LDR  r1, =gVar1
        LDR  r1, [r1]
        MOV  r2, #0           
task12_loop
        CMP  r2, r1
        BGE  task12_end  
        LDRSB  r3, [r0, r2]
        LDR  r5, =10
        SUB  r5, r3
        STRH r5, [r4, r2, LSL #1]
        ADD  r3, #1
        STRB r3, [r0, r2]
        ADD  r2, #1
        B    task12_loop
task12_end
        POP  {r4-r5, pc}       ; Pop lr to pc, which is the same as BX lr.
        ENDP
        
task13  PROC
        PUSH {r4-r5, lr}
        POP  {r4-r5, pc}
        ENDP
    
task14  PROC
        PUSH {r4-r5, lr}
        LDR  r0, =gPtrArray12a   
        LDR  r0, [r0]          
        LDR  r4, =gPtrArray14a   
        LDR  r4, [r4]           
        LDR  r1, =gVar1
        LDR  r1, [r1]
        SUB  r1, #1
        MOV  r2, #0            
task14_loop
        CMP  r2, r1
        BGE  task14_end  
        LDRSH  r3, [r0]
        LDRSH  r5, [r0, #2]!
        ADD  r3, r5, LSL #3
        STR  r3, [r4, r2, LSL #2]
        ADD  r2, #1
        B    task14_loop
task14_end
        POP  {r4-r5, pc}
        ENDP

task15  PROC
        PUSH {r4-r5, lr}
        POP  {r4-r5, pc}
        ENDP
    
        END     