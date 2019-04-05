#include "functions.h"

void swap_c_1(uint32_t *x, uint32_t *y) {
    if (*x != *y) {
        uint32_t temp = *x;
        *x = *y;
        *y = temp;
    }
}

void swap_c_2(uint32_t *x, uint32_t *y) {  
    if (x != y) {    // Note that we compare x and y, not *x and *y
        *x = *x + *y;  
        *y = *x - *y;  
        *x = *x - *y;  
    }  
}

void swap_c_3(uint32_t *x, uint32_t *y) {  
    if (x != y) {  
        *x ^= *y;  
        *y ^= *x;  
        *x ^= *y;  
    }  
}

void rank_ascending_c(uint32_t *pArray, uint32_t n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (*(pArray + j) > *(pArray + j+1)) {
                swap_c_1((pArray + j), (pArray + j+1));
            }
        }
    }
}

void rank_descending_c(uint32_t *pArray, uint32_t n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (*(pArray + j) < *(pArray + j+1)) {
                swap_c_1((pArray + j), (pArray + j+1));
            }
        }
    }
}
