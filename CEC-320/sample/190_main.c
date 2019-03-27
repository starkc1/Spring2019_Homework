#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

extern void aTask1_4(void);
extern void aTask1_3(void);
extern void aTask1_2(void);
extern uint32_t aTask2(uint32_t n);
extern uint32_t aTask3(int32_t *arr, uint32_t n);
extern uint32_t aTask4(uint32_t n);
extern uint32_t aTask5(uint32_t n, uint32_t parity_odd);
extern uint32_t aTask6(uint32_t n);

// Global variable
int32_t A = 0, B = -1, C = -2, D = 2;
int32_t array_e[8] = {-1, 5, 3, 8, 10, 23, 6, 5};
uint32_t rslt1, rslt2, rslt3, rslt4, rslt5, rslt6;

void cTask1(void) {
    A = B + C - D;
    return;
}

// Find the factorial of n
uint32_t cTask2(uint32_t n) {
    uint32_t prod = 1;
    for (int i = 1; i <= n; i++) {
        prod *= i;
    }
    return prod;
}

// Find the index of the max number in an array arr of size n
uint32_t cTask3(int32_t *arr, int32_t n) {
    uint32_t maxLoc = 0;
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxLoc = i;
        }
    }
    return maxLoc;
}

// Count the number of deimal digits of an uint32_t number
uint32_t cTask4(uint32_t n) {
    uint32_t count = 0;
    while (n) {
        n /= 10;
        count++;
    }
    return count;
}

// Set the parity bit (the return is the bit to append to the data)
    // parity_odd = 0 for even parity check and 1 for odd parity check.
uint32_t cTask5(uint32_t num,  uint32_t parity_odd) {
    while (num) {
        parity_odd = !parity_odd;
        num = num & (num-1);
    }
    return parity_odd;
}

// Count the number of binary 1's
uint32_t cTask6(uint32_t x) {
    uint32_t y, z;
    uint32_t count = x >> 31; 
    while (x) {
        y = x << 2;
        z = y >> 31;
        if (x<<1 > y)
            count += z + 1;
        else
            count += z;
        x = y;
    }
    return count;
}

int main(void) {
    cTask1();
    printf("C version of Task 1: A = %d \n", A);
    A = 0,  aTask1_4();
    printf("ASM4 version of Task 1: A = %d \n", A);
    A = 0,  aTask1_3();
    printf("ASM3 version of Task 1: A = %d \n", A);
    A = 0,  aTask1_2();
    printf("ASM2 version of Task 1: A = %d \n", A);

    rslt2 = cTask2(5);
    printf("C version of Task 2: rslt2 = %d \n", rslt2);
    rslt2 = 0;
    rslt2 = aTask2(5);
    printf("ASM version of Task 2: rslt2 = %d \n", rslt2);

    rslt3 = cTask3(array_e, 8);
    printf("C version of Task 3: rslt3 = %d \n", rslt3);
    rslt3 = 0;
    rslt3 = aTask3(array_e, 8);
    printf("ASM version of Task 3: rslt3 = %d \n", rslt3);

    uint32_t num = 123456;
    rslt4 = cTask4(num);
    printf("C version of Task 4: rslt4 = %d \n", rslt4);
    rslt4 = 0;
    rslt4 = aTask4(num);
    printf("ASM version of Task 4: rslt4 = %d \n", rslt4);

    num = 11;
    rslt5 = cTask5(num, 1);
    printf("C version of Task 5: rslt5 = %d \n", rslt5);
    rslt5 = 0;
    rslt5 = aTask5(num, 1);
    printf("ASM version of Task 5: rslt5 = %d \n", rslt5);

    num = 0xAAAAAAAA;
    rslt6 = cTask6(num);
    printf("C version of Task 6: rslt6 = %d \n", rslt6);
    rslt6 = 0;
    rslt6 = aTask6(num);
    printf("ASM version of Task 6: rslt6 = %d \n", rslt6);

    while (1);
}
