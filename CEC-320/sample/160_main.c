#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define B 28

extern int32_t  x_cmp1_y_ab_i1_asm(int32_t x, int32_t y, int32_t a, int32_t b);
extern int32_t  x_cmp1_y_ab_i2_asm(int32_t x, int32_t y, int32_t a, int32_t b);
extern uint32_t x_cmp1_y_ab_u_asm(uint32_t x, uint32_t y, uint32_t a, uint32_t b);

extern int32_t  x_cmp1_y_ab_i_asm_cond_e(int32_t x, int32_t y, int32_t a, int32_t b);
extern uint32_t x_cmp1_y_ab_u_asm_cond_e(uint32_t x, uint32_t y, uint32_t a, uint32_t b);

extern int32_t abs_asm_cond_b(int32_t x);
extern int32_t abs_asm_cond_e(int32_t x);

int32_t  x_cmp1_y_ab_int(int32_t x, int32_t y, int32_t a, int32_t b);
uint32_t x_cmp1_y_ab_uint(uint32_t x, uint32_t y, uint32_t a, uint32_t b);

int main(void) {
    int32_t xs[] = {-6, 5, -5, 5};
    int32_t ys[] = {-5, 6, 6, -6};

    
// Expl 16-01
    for (int i = 0; i < 4; i++) {
        int32_t temp = x_cmp1_y_ab_int(xs[i]<<B, ys[i]<<B, xs[i]<<B, ys[i]<<B);
        printf("For int in C with shift, temp = %d\n", temp>>B);
    }
    printf("\n");
    
    for (int i = 0; i < 4; i++) {
        int32_t temp = x_cmp1_y_ab_int(xs[i], ys[i], xs[i], ys[i]);
        printf("For int in C w/o shift, temp = %d\n", temp);
    }
    printf("\n");

    for (int i = 0; i < 4; i++) {
        uint32_t temp = x_cmp1_y_ab_uint(xs[i], ys[i], xs[i], ys[i]);
        printf("For Uint in C, temp = %d\n", temp);
    }
    printf("\n");
    
    for (int i = 0; i < 4; i++) {
        int32_t temp = x_cmp1_y_ab_i1_asm(xs[i], ys[i], xs[i], ys[i]);
        printf("For int in asm 1, temp = %d\n", temp);
    }
    printf("\n");

    for (int i = 0; i < 4; i++) {
        int32_t temp = x_cmp1_y_ab_i2_asm(xs[i], ys[i], xs[i], ys[i]);
        printf("For int in asm 2, temp = %d\n", temp);
    }
    printf("\n");
    
    for (int i = 0; i < 4; i++) {
        uint32_t temp = x_cmp1_y_ab_u_asm(xs[i], ys[i], xs[i], ys[i]);
        printf("For Uint in asm, temp = %d\n", temp);
    }
    printf("\n");

    
// Expl 16-02
    for (int i = 0; i < 4; i++) {
        int32_t temp = x_cmp1_y_ab_i_asm_cond_e(xs[i], ys[i], xs[i], ys[i]);
        printf("For int in asm cond, temp = %d\n", temp);
    }
    printf("\n");
    
    for (int i = 0; i < 4; i++) {
        uint32_t temp = x_cmp1_y_ab_u_asm_cond_e(xs[i], ys[i], xs[i], ys[i]);
        printf("For Uint in asm cond, temp = %d\n", temp);
    }
    printf("\n");

        
// Expl 16-03
    for (int i = 0; i < 4; i++) {
        int32_t tempb = abs_asm_cond_b(xs[i]);
        int32_t tempe = abs_asm_cond_e(xs[i]);
        printf("The results from Cond B and Cond E are %d and %d, respectively\n", 
            tempb, tempe);
    }
    printf("\n");

    
    while (1);
}


int32_t x_cmp1_y_ab_int(int32_t x, int32_t y, int32_t a, int32_t b) {
    if (x > y) {
        return a;
    } else {
        return b;
    }
}

uint32_t x_cmp1_y_ab_uint(uint32_t x, uint32_t y, uint32_t a, uint32_t b) {
    if (x > y) {
        return a;
    } else {
        return b;
    }
}
