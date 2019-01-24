//Lab 1 CEC 322 on 1/23/19

//Cameron Stark

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


void func1_fibo(uint32_t *fibo_array) {
    fibo_array[0] = 0;
    fibo_array[1] = 1;

    for (int i = 2; i <= 8; i++) {
        fibo_array[i] = fibo_array[i - 1] + fibo_array[i - 2];
    }
}

int32_t func2_norm(uint32_t *fibo_array) {
    int32_t norm = 0;

    for (int i = 1; i <= 8; i++) {
        int32_t newNorm = (pow(fibo_array[i], 2) + pow(fibo_array[i - 1], 2));
        norm = norm + newNorm;
    }

    norm = sqrt(norm);
    return norm;
}

void func3_print(uint32_t *fibo_array) {
    for (int i = 1; i <= 8; i++) {
        printf("Fibonacci Value %X: %d\n",i, fibo_array[i]);
    }
}



int main(void) {
    uint32_t fibo_array[8]; //stores finbonacci values
    uint32_t eucl_norm; //stores euclidan norm
    uint32_t max_unit32_t; //stores max value
    char my_team[] = "Cameron Stark & ";

    printf("Results of Lab1 from %s.\n", my_team);
    printf("fibo_array address: %p\n", (void*) &fibo_array);
    printf("eucl_norm address: %p\n", (void*) &eucl_norm);
    max_unit32_t = 0xFFFFFFFF;
    printf("max_unit32_t value is %u and address is %p\n", max_unit32_t, (void*) &max_unit32_t);
    
    func1_fibo(fibo_array);
    eucl_norm = func2_norm(fibo_array);
    func3_print(fibo_array);
}