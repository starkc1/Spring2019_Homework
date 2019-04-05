#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions.h"
#include "functions_asm.h"

#define N 8

uint32_t breakPointHere = 0;

int main(void) {
    uint32_t myID = 1234;   // The last 4 digit of your ERAU ID
    uint32_t  array1[N], array2[N];
    srand(myID);            // Seed the random number generator
    for (int i = 0; i < N; i++) {
        array1[i] = 2*rand();
        array2[i] = array1[i];
    }
    
    printf("Random array:\n");
    for (int i = 0; i < N; i++) {
        printf(" 0x%X,", array1[i]);
    }
    printf("\n");
    
    // rank descending in c
    printf("Results after rank_descending_c:\n");
    breakPointHere++;
    rank_descending_c(array1, N);
    breakPointHere++;
    for (int i = 0; i < N; i++) {
        printf(" 0x%X,", array1[i]);
    }
    printf("\n");
    
    // rank descending in asm
    printf("Results after rank_descending_asm:\n");
    breakPointHere++;
    rank_descending_asm(array2, N);
    // rank_descending_asm(arr1, N);
    breakPointHere++;
    for (int i = 0; i < N; i++) {
        printf(" 0x%X,", array2[i]);
    }
    printf("\n");

    
    while(1);
}
