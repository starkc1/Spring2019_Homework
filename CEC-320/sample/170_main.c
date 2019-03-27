#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#define INITIALIZE_vals \
                ai = -4;\
                xi = 1;\
                au = -4;\
                xu = 1;

#define INITIALIZE_OUTPUT_ARRAY \
    po = outpt_array; \
    for (i = 0; i < 8; i++) { \
        *(po + i) = 0; \
    }\

// Functions defined in a .s file
extern int32_t task1i(int32_t a, int32_t x);
extern uint32_t task1u(uint32_t a, uint32_t x);
extern int32_t task2(int32_t a, int32_t x);
extern int32_t task3(int32_t a, int32_t x);
extern int32_t task4(int32_t a, int32_t x);
extern int32_t task5(int32_t n);
extern int32_t task6(int32_t *ptr, int32_t n);
extern int32_t task7(int32_t n);
extern int32_t task8(int32_t n);
extern int32_t task9(int32_t n);
extern int32_t task10(int32_t n);
extern int32_t task11(int32_t a, int32_t x);
extern void task12(int32_t *input_array, int32_t *outpt_array, int n);
extern void task13(int32_t *input_array, int32_t *outpt_array, int n);
extern void task14(int32_t n);
    
// Global variable

int32_t ai, xi;
uint32_t au, xu;

int32_t input_array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int32_t outpt_array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int32_t i, sum5, sum6, sum7, sum8, sum9, sum10;


int main(void) {
// Task 1. Simple if-then statement:
    INITIALIZE_vals
    printf("ai_1a = %d\n", ai);
    if (ai > xi) {
        ai <<= 2;
    }
    printf("ai_1b = %d\n", ai);
    INITIALIZE_vals
    ai = task1i(ai, xi);
    printf("ai_1c = %d\n", ai);

    INITIALIZE_vals
    printf("au_1a = %u\n", au);
    if (au > xu) {
        au <<= 2;
    }
    printf("au_1b = %u\n", au);
    INITIALIZE_vals
    au = task1u(au, xu);
    printf("au_1c = %u\n", au);

// Task 2. Simple if-then statement with compound logic OR expression:
    INITIALIZE_vals
    printf("ai_2a = %d\n", ai);
    if (xi <= 20 || xi >= 25) {
        ai *= 4;
    } 
    printf("ai_2b = %d\n", ai);
    INITIALIZE_vals
    ai = task2(ai, xi);
    printf("ai_2c = %d\n", ai);
    
// Task 3. Simple if-then-else statement:
    INITIALIZE_vals
    if (ai == xi) {
        xi += 3;
    } else {
        xi -= 4;
    }
    printf("xi_3a = %d\n", xi);
    INITIALIZE_vals
    xi = task3(ai, xi);
    printf("xi_3b = %d\n", xi);
    
// Task 4. If-then-else statement with compound logic OR expression:
    INITIALIZE_vals
    printf("ai_4a = %d\n", ai);
    if (xi <= 20 || xi >= 25) {
        ai *= 8;
    } else {
        ai *= 16;
    }
    printf("ai_4b = %d\n", ai);
    INITIALIZE_vals
    ai = task4(ai, xi);
    printf("ai_4c = %d\n", ai);


// Task 5. The for loop---a simple example
    sum5 = 0;
    for (int i = 0; i < 10; i++) {
        sum5 += i*4;
    }
    printf("sum5_a = %d\n", sum5);
    sum5 = 0;
    sum5 = task5(10);
    printf("sum5_b = %d\n", sum5);

// Task 6. The for loop---revisit the addressing problem
    int32_t *pArray = input_array;
    sum6 = 0;
    for (int i = 0; i < 8; i++) {
        sum6 += *pArray++;
    }
    printf("sum6_a = %d\n", sum6);
    sum6 = 0;
    pArray = input_array;
    sum6 = task6(pArray, 8);
    printf("sum6_b = %d\n", sum6);

// Task 7. The while loop doing the same thing as a for loop given in Task 5.
    i = 0;
    sum7 = 0;
    while (i < 10) {
        sum7 += i*4;
        i++;
    }
    printf("sum7_a = %d\n", sum7);
    sum7 = 0;
    sum7 = task7(10);
    printf("sum7_b = %d\n", sum7);

// Task 8. Another form of while loop doing the same thing as the above for loop
    i = 9;
    sum8 = 0;
    while (i >= 0) {
        sum8 += i*4;
        i--;
    }
    printf("sum8_a = %d\n", sum8);
    sum8 = 0;
    sum8 = task8(9);
    printf("sum8_b = %d\n", sum8);

// Task 9. The do-while loop doing the same thing as the above while loops
    i = 9;
    sum9 = 0;
    do {
        sum9 += i*4;
        i--;
    } while (i >= 0);
    printf("sum9_a = %d\n", sum9);
    sum9 = 0;
    sum9 = task9(9);
    printf("sum9_b = %d\n", sum9);

// Task 10. Another form of do-while loop doing the same thing as the above do-while loop
    i = 0;
    sum10 = 0;
    do {
        sum10 += i*4;
        i++;
    } while (i < 10);
    printf("sum10_a = %d\n", sum10);
    sum10 = 0;
    sum10 = task10(10);
    printf("sum10_b = %d\n", sum10);

// Task 11. Simple if-then statement with compound logic AND expression:
    // positive logic
    INITIALIZE_vals
    if (xi > 20 && xi < 25) {
        ai = 11;
    } 
    printf("ai_11a = %d\n", ai);

    // negative logic---transition to the Assembly code
    INITIALIZE_vals
    if (!(xi > 20 && xi < 25)) {
    } else {
        ai = 11;
    }
    printf("ai_11b = %d\n", ai);
    INITIALIZE_vals
    ai = task11(ai, xi);
    printf("ai_11c = %d\n", ai);
 
// Task 12. The break stastment in a for loop
    int32_t *pi = input_array;
    int32_t *po = outpt_array;
    for (i = 0; i < 6; i++) {
        if (i == 3) break;
        *(po++) = 2 * *(pi++);
    }
    pi = input_array; 
    INITIALIZE_OUTPUT_ARRAY
    task12(input_array, outpt_array, 6);

// Task 13. The continue statement in a for loop
    pi = input_array; 
    INITIALIZE_OUTPUT_ARRAY
    for (i = 0; i < 6; i++) {
        if (i == 3) continue;
        *(po+i) = 4 * *(pi++);
    }
    pi = input_array; 
    INITIALIZE_OUTPUT_ARRAY
    task13(input_array, outpt_array, 6);

// Task 14. The IT instruction
    task14(10);
    
    while (1);
}
