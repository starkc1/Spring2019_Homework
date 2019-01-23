// Test 1 of CEC 320 on 9/21/18

// Name:

// See the score in the last page.


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Part 2 solution for the functions
int32_t func1_accumulate(int32_t *x, int32_t *h, int32_t N, int32_t y) {
    for (int i = 0; i < N; i++) {
        y += *x++ * *(h+i);
    }
    return y;
}
    
float func2_polynomial(float *p, uint8_t N, float x) {
    float y = 0.0;
    float x_n = 1.0;    // x_n = x^n

    for (int i = 0; i <= N; i += 2) {
        y += (*p++) * x_n;
        x_n *= x * x;
    }
    return y;
}
   
int main(void) {
    uint16_t A[4] = {0x3333, 0x6666, 0xAAAA, 0x9999};
    uint16_t B[4] = {0x6666, 0x9999, 0xCCCC, 0xBBBB};
    uint16_t C[20];
    uint16_t Mask = 0xF;      // a mask 
    uint16_t N_shift = 8;
    uint16_t to_assign = 9; 
    uint16_t *pInt;
    pInt = B;

    //printf("The address of array C: %x\n", C);
    printf("Please determine the values in Hexadecimal of C:\n");
    // 4 points each: 
    if (*(pInt + 2) == B[2]) {
        C[0] = A[0];
    } else {
        C[0] = A[1];
    }
    // C[0] = 0x3333
    // (1) C[0] = ?
    
    C[1] = !A[1];
    //C[1] = 0x0
    // (2) C[1] = ?
    
    C[2] = ~A[2];
    //C[2] = 1010 1010 1010 1010 -> 0101 0101 0101 0101 -> 0x5555
    // (3) C[2] = ?

    C[3] = 0x000F ^ A[3];
    //0x000F -> 0000 0000 0000 1111
    //0x9999 -> 1001 1001 1001 1001
    //C[3] = 1001 1001 1001 0110 -> 0x9996
    // (4) C[3] = ?

    C[4] = 23 / 6;
    //10111 / 00110
    //10001 -> 0001 0001 -> 0x0011
    // (5) C[4] = ?

    C[5] = 15 - ((15>>2)<<2);
    // 1111 >> 2 -> 0011 << 2 -> 1100 -> 1111 - 1100 -> 0011 -> 0x3 
    // (6) C[5] = ?

    C[6] = ~(Mask << N_shift);
    //0xF -> 1111
    //8
    //1111 << 8 -> 1111 0000 0000 -> 1111 0000 1111 1111 -> 0xF0FF
    // (7) C[6] = ?

    C[7] = B[0] & ~(Mask << N_shift);
    //0x6666 -> 0110 0110 0110 0110
    //0xF -> 1111
    //8
    //0110 0110 0110 0110 & 1111 0000 1111 1111 -> 0110 0000 0110 0110 -> 0x6066
    // (8) C[7] = ?

    C[8] = to_assign << N_shift;
    //9 -> 1001
    //8
    //1001 << 8 -> 1001 0000 0000 -> 0x900
    // (9) C[8] = ?

    C[9] = C[7] | (to_assign << N_shift);
    //0x6006 -> 0110 0000 0110 0110
    //9 -> 1001
    //8
    //1001 << 8 -> 1001 0000 0000 -> 0110 0000 0110 0110 | 0000 1001 0000 000 -> 0110 1001 0110 0110 -> 0x6966
    // (10) C[9] = ?

    C[10] = *(pInt + 1);
    //pInt -> B[0]
    //pInt 1 -> B[1] -> 0x9999
    // (11) C[10] = ?

    C[11] = *(++pInt);
    // (12) C[11] = ?

    C[12] = ++(*pInt);
    // (13) C[12] = ?

    C[13] = *pInt;
    // (14) C[13] = ?

    C[14] = 25 % 9;
    // (15) C[14] = ?

    C[15] = A[0] == 0x3334;
    // (16) C[15] = ?


    //printf("Please determine the followign values in decimal:\n");   
    int32_t xx[4] = {4, 3, 2, 1};
    int32_t y = func1_accumulate(xx, xx, 3, 0);
    //printf("The new result for accumulation is %d\n", y);
    // (17) (10 points) y = ?
   
    
    
    float p[10];
    for (int i = 0; i < 10; i++) {
        p[i] = 2*i;
    }
    float x = 2.0;
    float z = func2_polynomial(p, 6, x);
    // printf("The result for the polynomial is %f\n", z);
    // (18) (10 points) z = ?
 
    
    // You can check your results by runing the code and see the values in a 
    // Watch window or using the printf function. 
   printf("The values of Cs are as follows:\n");
   for (int i=0; i<18; i++) {
       printf("C[%d] = 0x%X\n", i, C[i]);
   }
    int temp = 234;
    //printf("0x%X\n", temp);
    
    while (1);
}






// (19) (6 points) Convert the following decimal number to binary and then to hexadecimal:
//      234

// Soln: 234_10 = 0b 1110 1010 = 0xEA





// (20) (5 points each) Consider a 4-bit Cortex-M system. Determine the results and 
// C flag of the following additions and subtractions of unsigned numbers:
//     (a) 12 + 13
//     (b) 12 - 13

// Soln: 
// (a) result = 9, C = 1

// (b) result = 15, C = 0     







//
// Score: 
//