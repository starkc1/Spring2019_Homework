        AREA my_fancy_asm_code, CODE, READONLY   ; Define the program area
        
        ; Export functions defined in this file. These functions need to be declared 
        ; in the file calling them.
        EXPORT task5
        EXPORT task6
        EXPORT task7
        EXPORT task10
        EXPORT task11
        EXPORT task12
        EXPORT task13
        EXPORT task14
        EXPORT task15

        IMPORT gPtrArray1
        IMPORT gPtrArray2
        IMPORT gVar1
        IMPORT gVar2
            
        ALIGN                   ; Align the data in the boundary of 4 bytes. 

task5   PROC
        LDR  r0, =0x10          ; Pseudo code; see the disassembly for the true code
        LDR  r1, =0x12345678    ; Pseudo code; see the disassembly for the true code
        LDR  r2, =gVar1         ; Loading the address of the global variable gVar1
        LDR  r3, =gPtrArray1    ; Loading the address of the global variable gPtrArray1
        BX   lr         
        ENDP
            
task6   PROC
        LDR  r0, =0x10          ; Pseudo code; see the disassembly for the true code
        LDR  r1, =gVar1         ; Loading the address of the global variable gVar1
        LDR  r2, [r1]
        ADD  r0, r2
        STR  r0, [r1] 
        BX   lr        
        ENDP

task7   PROC
        LDR  r0, =0x12345678    ; Pseudo code; see the disassembly for the true code
        LDR  r1, =gVar1
        LDR  r1, [r1]
        ADD  r0, r1
        LDR  r2, =gVar2         ; Loading the address of the global variable gVar2
        STR  r0, [r2]        
        BX   lr 
        ENDP
            
task10  PROC
        LDR  r0, =gPtrArray1    ; Loading the address of the global variable gPtrArray1
        LDR  r0, [r0]           ; Loading the content of the global variable gPtrArray1
        LDR  r1, =gVar1         ; Loading the address of the global variable gVar1
        LDR  r1, [r1]           ; Loading the content of the global variable gVar1
        MOV  r2, #0             ; variable (int) i
task10_loop
        CMP  r2, r1                 ; test = r2 - r1
        BGE  task10_end              ; if test >= 0, then branch to task10_end    
        MOV  r3, r2, LSL #1         ; r3 <- 2 * r2
        ADD  r3, #1                 ; r3 <- r3 + 1
        STR  r3, [r0, r2, LSL #2]   ; r3 -> mem[r0 + 4*r2] or r3 -> mem[r0 + i]
        ADD  r2, #1                 ; r2 <- r2 + 1
        B    task10_loop             ; branch to task10_loop
task10_end
        BX   lr                     ; return
        ENDP

; If you need to use registers starting from r4, you need to PUSH them first to save the 
; run-time environment for the caller. You need to POP them up at the exit of the code.

task11  PROC
        LDR  r0, =gPtrArray2    
        LDR  r0, [r0]           
        LDR  r1, =gVar1
        LDR  r1, [r1]
        MOV  r2, #0            
task11_loop
        CMP  r2, r1
        BGE  task11_end  
        MOV  r3, r2, LSL #2
        ADD  r3, #1
        STR  r3, [r0, r2, LSL #2]
        ADD  r2, #1
        B    task11_loop
task11_end
        BX   lr     
        ENDP

task12  PROC
        PUSH {r4, lr}
        LDR  r0, =gPtrArray1    
        LDR  r0, [r0]           
        LDR  r4, =gPtrArray2    
        LDR  r4, [r4]               
        LDR  r1, =gVar1
        LDR  r1, [r1]
        MOV  r2, #0           
task12_loop
        CMP  r2, r1
        BGE  task12_end  
        LDR  r3, [r0, r2, LSL #2]
        STR  r3, [r4, r2, LSL #2]
        ADD  r3, #1
        STR  r3, [r0, r2, LSL #2]
        ADD  r2, #1
        B    task12_loop
task12_end
        POP  {r4, pc}       ; Pop lr to pc, which is the same as BX lr.
        ENDP
        
task13  PROC
        PUSH {r4-r5, lr}
        LDR  r0, =gPtrArray1   
        LDR  r0, [r0]          
        LDR  r4, =gPtrArray2   
        LDR  r4, [r4]          
        LDR  r1, =gVar1
        LDR  r1, [r1]
        SUB  r1, #1
        MOV  r2, #0         
task13_loop
        CMP  r2, r1
        BGE  task13_end  
        LDR  r3, [r0]
        LDR  r5, [r0, #4]
        ADD  r3, r5
        STR  r3, [r4, r2, LSL #2]
        ADD  r2, #1
        ADD  r0, #4
        B    task13_loop
task13_end
        POP  {r4-r5, pc}
        ENDP
    
task14  PROC
        PUSH {r4-r5, lr}
        LDR  r0, =gPtrArray1   
        LDR  r0, [r0]          
        LDR  r4, =gPtrArray2   
        LDR  r4, [r4]           
        LDR  r1, =gVar1
        LDR  r1, [r1]
        SUB  r1, #1
        MOV  r2, #0            
task14_loop
        CMP  r2, r1
        BGE  task14_end  
        LDR  r3, [r0]
        LDR  r5, [r0, #4]!
        ADD  r3, r5, LSL #1
        STR  r3, [r4, r2, LSL #2]
        ADD  r2, #1
        B    task14_loop
task14_end
        POP  {r4-r5, pc}
        ENDP

task15  PROC
        PUSH {r4-r5, lr}
        LDR  r0, =gPtrArray1   
        LDR  r0, [r0]          
        LDR  r4, =gPtrArray2   
        LDR  r4, [r4]         
        LDR  r1, =gVar1
        LDR  r1, [r1]
        SUB  r1, #1
        MOV  r2, #0        
task15_loop
        CMP  r2, r1
        BGE  task15_end  
        LDR  r3, [r0], #4
        LDR  r5, [r0]
        ADD  r3, r5, LSL #2
        STR  r3, [r4, r2, LSL #2]
        ADD  r2, #1
        B    task15_loop
task15_end
        POP  {r4-r5, pc}
        ENDP
    
        END                 ; End of the entire file
