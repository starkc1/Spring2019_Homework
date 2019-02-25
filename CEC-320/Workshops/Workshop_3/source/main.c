#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MY_ARRAY_BASE (0x20010000)

// Functions defined in a .s file
extern void task10(void);
extern void task11(void);
extern void task12(void);
extern void task13(void);
extern void task14(void);
extern void task15(void);

// Pointers for the C version.
int8_t      *gPtrArray10c = (int8_t *)   (MY_ARRAY_BASE + 0x00);
uint8_t     *gPtrArray11c = (uint8_t *)  (MY_ARRAY_BASE + 0x40);
int16_t     *gPtrArray12c = (int16_t *)  (MY_ARRAY_BASE + 0x80);
uint16_t    *gPtrArray13c = (uint16_t *) (MY_ARRAY_BASE + 0xC0);
int32_t     *gPtrArray14c = (int32_t *)  (MY_ARRAY_BASE + 0x100);
uint32_t    *gPtrArray15c = (uint32_t *) (MY_ARRAY_BASE + 0x140);
// Pointers for the asm version.
int8_t      *gPtrArray10a = (int8_t *)   (MY_ARRAY_BASE + 0x20);
uint8_t     *gPtrArray11a = (uint8_t *)  (MY_ARRAY_BASE + 0x60);
int16_t     *gPtrArray12a = (int16_t *)  (MY_ARRAY_BASE + 0xA0);
uint16_t    *gPtrArray13a = (uint16_t *) (MY_ARRAY_BASE + 0xE0);
int32_t     *gPtrArray14a = (int32_t *)  (MY_ARRAY_BASE + 0x120);
uint32_t    *gPtrArray15a = (uint32_t *) (MY_ARRAY_BASE + 0x160);

int8_t gVar1 = 8;

int main(void) {   
    // Task 10. Register offset-based addressing---a simple example.
//    for (int i = 0; i < gVar1; i++) {
//        *(gPtrArray10c + i) = (int8_t)(i*4 - 15); // i is saved in a register         
//    }
    task10();       // task10: perform the above task using assembly 

    // Task 11. Register offset-based addressing---another simple example.
    for (int i = 0; i < gVar1; i++) {      
        *(gPtrArray11c + i) = (uint8_t)(i*32 + 2); 
    }
    task11();       // task11: perform the above task using assembly
    
    // Task 12. Register offset-based addressing---more complicated case.
    for (int i = 0; i < gVar1; i++) {            
        *(gPtrArray12c + i) = 10 - (*(gPtrArray10c + i))++;  
    }               // Note that the input data is changed as well in the above line
    task12();       // task12: perform the above task using assembly
    
    // Task 13. Immediate offset addressing. 
    for (int i = 0; i < gVar1-1; i++) {            
        // We use immediate offset addressing twice below (righthand side)
        *(gPtrArray13c + i) = *(gPtrArray11c) + *(gPtrArray11c+1);   
        gPtrArray11c++;
    }
    task13();    // task13: perform the above task using assembly
    
    // Task 14. Immediate offset addressing and pre-index addressing.    
    for (int i = 0; i < gVar1-1; i++) {            
        uint32_t temp = *(gPtrArray12c);
        *(gPtrArray14c + i) = temp + 8 * (*(++gPtrArray12c));
    }
    task14();    // task14: perform the above task using assembly
    
    // Task 15. Post-index addressing and immediate offset addressing.     
    for (int i = 0; i < gVar1-1; i++) {             
        uint32_t temp = *(gPtrArray13c++);
        *(gPtrArray15c + i) = temp + 16 * (*gPtrArray13c); 
    }
    task15();    // task15: perform the above task using assembly
    
    //while (1);
}
