#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MY_ARRAY_BASE (0x20010000)

// Functions defined in a .s file
extern void task5(void);
extern void task6(void);
extern void task7(void);
extern void task10(void);
extern void task11(void);
extern void task12(void);
extern void task13(void);
extern void task14(void);
extern void task15(void);


// Global variable
uint32_t *gPtrArray1, *gPtrArray2;
uint32_t gVar1 = 6, gVar2;

volatile uint32_t gTemp1;
volatile uint32_t gTemp2;

int main(void) {
    // We configure the RAM into the following two blocks in "Options for Target..." ->
    // "Target" -> "IRAM1 and IRAM2", with the first being default:
    // 1) Starting: 0x20000000; size: 0x10000 (2^16 B = 2^6 kB)
    // 2) Starting: 0x20010000; size: 0x10000 (2^16 B = 2^6 kB)
    // As a result, we can put our own data starting at 0x20010000.

    // Initialize the global pointers
    gPtrArray1 = (uint32_t *)(MY_ARRAY_BASE + 0x00);
    gPtrArray2 = (uint32_t *)(MY_ARRAY_BASE + 0x40);
    
    // Task 1. Load, modify, and store of a global var---example 1
    gTemp1 = 0x10;
    gTemp1 += 1;
    
    // Task 2. Load, modify, and store of a global var---example 2
    gTemp2 = 0x20;
    gTemp2 += (gTemp1<<8); 
    
    printf("gTemp1 = 0x%X, gTemp2 = 0x%X\n", gTemp1, gTemp2);
    
    // Task 3. Load, modify, and store of a local var---example 1
    volatile uint32_t lTemp1 = 0x1000;
    lTemp1 += 1;
    
    // Task 4. Load, modify, and store of a local var---example 2
    volatile uint32_t lTemp2 = 0x2000;
    lTemp2 += (lTemp1<<16); 
    
    printf("lTemp1 = 0x%X, lTemp2 = 0x%X\n", lTemp1, lTemp2);
    
    // Task 5. LDR pseudo instruction.
    task5();
    
    // Task 6. Load/Modify/Store using offset addressing.
    gVar1 += 0x10;
    task6();    // Task6: perform the above task using assembly
    
    // Task 7. Load/Modify/Store using pseudo instruction.  
    gVar2 = 0x12345678;    
    gVar2 += gVar1;
    task7();    // Task7: perform the above task using assembly
    
    
    gVar1 = 6;
    // Task 10. Register offset-based addressing---a simple example.
    // Note that this is especially useful for pointer arithmetic here. 
    for (int i = 0; i < gVar1; i++) {
        *(gPtrArray1 + i) = (uint32_t)(i*2 + 1); // i is register offset based         
    }
    // clear the memory for task10 in assembly
    for (int i = 0; i < gVar1; i++) { *(gPtrArray1 + i) = 0; }
    task10();    // task10: perform the above task using assembly

    // Task 11. Register offset-based addressing---another simple example.
    // Note that this is especially useful for pointer arithmetic here. 
    for (int i = 0; i < gVar1; i++) {      
        *(gPtrArray2 + i) = (uint32_t)(i*4 + 1); 
    }
    // clear the memory for task11 in assembly
    for (int i = 0; i < gVar1; i++) { *(gPtrArray2 + i) = 0; }
    task11();    // task11: perform the above task using assembly
    
    // Task 12. Register offset-based addressing---more complicated case.
    for (int i = 0; i < gVar1; i++) {            
        *(gPtrArray2 + i) = (*(gPtrArray1 + i))++;  // Note that the input data is changed as well
    }
    // clear the memory for task12 in assembly
    for (int i = 0; i < gVar1; i++) { *(gPtrArray2 + i) = 0; }
    task12();    // task12: perform the above task using assembly
    printf("Task 2 is done.\n");
    
    // Task 13. Immediate offset addressing. 
    for (int i = 0; i < gVar1-1; i++) {            
        // We use immediate offset addressing twice in the righthand side of the following
        *(gPtrArray2 + i) = *(gPtrArray1) + *(gPtrArray1+1);   
        gPtrArray1++;
    }
    // clear the memory for task13 in assembly
    gPtrArray1 = (uint32_t *)(MY_ARRAY_BASE + 0x00); // Restore the pointer 
    for (int i = 0; i < gVar1-1; i++) { *(gPtrArray2 + i) = 0; }
    task13();    // task13: perform the above task using assembly
    
    gPtrArray1 = (uint32_t *)(MY_ARRAY_BASE + 0x00); // Restore the pointer
    // Task 14. Immediate offset addressing and pre-index addressing.    
    for (int i = 0; i < gVar1-1; i++) {            
        //*(gPtrArray2 + i) = *(gPtrArray1) + 2 * (*(++gPtrArray1)); 
        // The above statement can be implemented below to force the ''sequencing'':
        // See: https://en.wikipedia.org/wiki/Sequence_point
        uint32_t temp = *(gPtrArray1);
        *(gPtrArray2 + i) = temp + 2 * (*(++gPtrArray1));
    }
    gPtrArray1 = (uint32_t *)(MY_ARRAY_BASE + 0x00); // Restore the pointer 
    for (int i = 0; i < gVar1-1; i++) { *(gPtrArray2 + i) = 0; }
    task14();    // task14: perform the above task using assembly
    
    gPtrArray1 = (uint32_t *)(MY_ARRAY_BASE + 0x00); // Restore the pointer
    // Task 15. Post-index addressing and immediate offset addressing.     
    for (int i = 0; i < gVar1-1; i++) {            
        //*(gPtrArray2 + i) = *(gPtrArray1++) + 4 * (*gPtrArray1); 
        uint32_t temp = *(gPtrArray1++);
        *(gPtrArray2 + i) = temp + 4 * (*gPtrArray1); 
    }
    gPtrArray1 = (uint32_t *)(MY_ARRAY_BASE + 0x00); // Restore the pointer
    for (int i = 0; i < gVar1-1; i++) { *(gPtrArray2 + i) = 0; }
    task15();    // task15: perform the above task using assembly
    

    
    while (1);
}
