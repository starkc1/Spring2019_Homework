//Lab 1 CEC 322 on 1/23/19

//Cameron Stark

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>



void func1_fibo(uint32_t *fibo_array) {
    fibo_array[0] = 0;
    fibo_array[1] = 1;

    for (int i = 2; i <= 8; i++) {
        fibo_array[i] = fibo_array[i - 1] + fibo_array[i - 2];
    }
}

int32_t func2_norm(uint32_t *fibo_array) {
    int32_t norm = 0;

    for (int i = 1; i <= 7; i++) {
        norm = norm + (fibo_array[i] * fibo_array[i]) + (fibo_array[i-1] * fibo_array[i-1]);
    }

    norm = sqrt(norm);

    return norm;
}




int main(void) {
    uint32_t fibo_array[8]; //stores finbonacci values
    uint32_t eucl_norm; //stores euclidan norm
    uint32_t max_unit32_t; //stores max value


    func1_fibo(fibo_array);
    func2_norm(fibo_array);

    for (int i = 0; i <= 7; i++) {
        printf("Fibonacci Value %X: %X\n",i, fibo_array[i]);
    }

    printf("Euclidian Norm: %X", eucl_norm);
}