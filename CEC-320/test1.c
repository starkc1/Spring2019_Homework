// Test 1 of CEC 320 on 1/23/19

// Section:      ; Name:

// See your score at the bottom of the next page.


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void) {
    uint16_t A[4] = {0x3333, 0x5555, 0x7777, 0x9999};
    uint16_t B[4] = {0x6666, 0x8888, 0xAAAA, 0xCCCC};
    uint16_t C[20];
    uint16_t Mask = 0x7;      // a mask 
    uint16_t N_shift = 8;
    uint16_t to_assign = 5; 
    uint16_t *pInt = B;

    printf("Determine the values of the elements of C in Hexadecimal\n");
    printf("after each of the following 15 operations: \n");
    // 6 points each for the following 15 questions: 

    C[0] = A[0] & A[0];
    // (1) C[0] = ?
    
    C[1] = !A[1];
    // (2) C[1] = ?
    
    C[2] = ~A[2];
    // (3) C[2] = ?

    C[3] = 0x000F ^ A[3];
    // (4) C[3] = ?

    C[4] = 32 / 6;
    // (5) C[4] = ?

    C[5] = 15 - ((15>>2)<<2);
    // (6) C[5] = ?

    C[6] = ~(Mask << N_shift);
    // (7) C[6] = ?

    C[7] = B[0] & ~(Mask << N_shift);
    // (8) C[7] = ?

    C[8] = C[7] | (to_assign << N_shift);
    // (9) C[8] = ?

    C[9] = ~C[7] | ~(to_assign << N_shift);
    // (10) C[9] = ?

    C[10] = *(pInt + 1);
    // (11) C[10] = ?

    C[11] = *pInt++;
    // (12) C[11] = ?

    pInt = &B[2];
    C[12] = (*pInt)++;
    // (13) C[12] = ?

    C[13] = ++(*pInt);
    // (14) C[13] = ?

    C[14] = 35 % 8;
    // (15) C[14] = ?

    printf("Determine the values of the elements of C in Decimal\n");
    printf("after each of the following 2 operations: \n");
    // 5 points each for the following 2 questions: 
    
    C[15] = 0x32;
    // (16) C[15] = ?
    
    C[16] = 0x32 << 2;
    // (17) C[16] = ?
    
    
    for (int i = 0; i < 15; i++) {
        printf("C[%d] = 0x%X \n", i, C[i]);
    }

    for (int i = 15; i < 17; i++) {
        printf("C[%d] = %d \n", i, C[i]);
    }
    
    //while (1);
}



//
// Score: 
//
