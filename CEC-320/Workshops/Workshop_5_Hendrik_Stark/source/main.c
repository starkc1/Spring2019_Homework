#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// C functions
void swap_c_1(uint8_t *x, uint8_t *y);
void swap_c_2(uint8_t *x, uint8_t *y);
void swap_c_3(uint8_t *x, uint8_t *y);
void rank_ascending_c(uint8_t *pArray, uint32_t n);
void rank_descending_c(uint8_t *pArray, uint32_t n);

// Functions defined in a .s file
extern void swap_asm_1(uint8_t *x, uint8_t *y);
extern void swap_asm_2(uint8_t *x, uint8_t *y);
extern void swap_asm_3(uint8_t *x, uint8_t *y);
extern void rank_descending_asm(uint8_t *pArray, uint32_t n);

// Global variable


int main(void){

// Problem 1. 
    // a. the C function.
    //uint8_t A[] = {3, 129, 255, 122};
    //uint8_t B[] = {254, 128, 2, 234};
    uint8_t x = 10, y = 20;
    swap_c_1(&x, &y);
    printf("Results after swap_c_1: x = %d, y = %d, \n", x, y);
  
    // b. the asm function.
    swap_asm_1(&x, &y);
    printf("Results after swap_asm_1: x = %d, y = %d, \n", x, y);
  
// Problem 2. 
    // a. swap_c_2
    uint8_t A2a[] = {3, 129, 255, 122};
    uint8_t B2a[] = {254, 128, 2, 234};
    printf("Results after swap_c_2:\n");
    for (int i = 0; i < 4; i++) {
        swap_c_2(&A2a[i], &B2a[i]);
        printf(" A2a[%d] = %3d, B2a[%d] = %3d\n", i, A2a[i], i, B2a[i]);
    }

    // a. swap_c_3
    uint8_t A2b[] = {3, 129, 255, 122};
    uint8_t B2b[] = {254, 128, 2, 234};
    printf("Results after swap_c_2:\n");
    for (int i = 0; i < 4; i++) {
        swap_c_3(&A2b[i], &B2b[i]);
        printf(" A2b[%d] = %3d, B2b[%d] = %3d\n", i, A2b[i], i, B2b[i]);
    }
    
// Problem 4. 
    // a. rank ascending in c
    uint8_t A4a[] = {3, 129, 255, 122};
    uint8_t B4a[] = {254, 128, 2, 234};
    printf("Results after rank_ascending_c:\n");
    rank_ascending_c(A4a, 4);
    rank_ascending_c(B4a, 4);
    for (int i = 0; i < 4; i++) {
        printf(" %d,", A4a[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf(" %d,", B4a[i]);
    }
    printf("\n");
    
    // b. rank descending in c
    uint8_t A4b[] = {3, 129, 255, 122};
    uint8_t B4b[] = {254, 128, 2, 234};
    printf("Results after rank_descending_c:\n");
    rank_descending_c(A4b, 4);
    rank_descending_c(B4b, 4);
    for (int i = 0; i < 4; i++) {
        printf(" %d,", A4b[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf(" %d,", B4b[i]);
    }
    printf("\n");
    
    // c. rank descending in asm
    uint8_t A4c[] = {3, 129, 255, 122};
    uint8_t B4c[] = {254, 128, 2, 234};
    printf("Results after rank_descending_asm:\n");
    rank_descending_asm(A4c, 4);
    rank_descending_asm(B4c, 4);
    for (int i = 0; i < 4; i++) {
        printf(" %d,", A4c[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf(" %d,", B4c[i]);
    }
    printf("\n");
    
    while(1);
}


void swap_c_1(uint8_t *x, uint8_t *y) {
    if (*x != *y) {
        uint8_t temp = *x;
        *x = *y;
        *y = temp;
    }
}

void swap_c_2(uint8_t *x, uint8_t *y) {  
    if (x != y) {  
        *x = *x + *y;  
        *y = *x - *y;  
        *x = *x - *y;  
    }  
}

void swap_c_3(uint8_t *x, uint8_t *y) {  
    if (x != y) {  
        *x ^= *y;  
        *y ^= *x;  
        *x ^= *y;  
    }  
}

void rank_ascending_c(uint8_t *pArray, uint32_t n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (*(pArray + j) > *(pArray + j+1)) {
                swap_c_1((pArray + j), (pArray + j+1));
            }
        }
    }
}

void rank_descending_c(uint8_t *pArray, uint32_t n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (*(pArray + j) < *(pArray + j+1)) {
                swap_c_1((pArray + j), (pArray + j+1));
            }
        }
    }
}
