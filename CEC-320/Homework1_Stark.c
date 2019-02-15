#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char str_c[30];
char str_v[30];
int c, k, count;

void uint16_2_binary_str(uint8_t num) {
    count = 0;

    for (c = 5; c >= 0; c--) {
        k = num >> c;

        if (k & 1) {
            str_c[count] = '1';
        } else {
            str_c[count] = '0';
        }
        count++;
    }
    printf("%s", str_c);
}

void add_int8(int8_t num1, int8_t num2) {
    
}

int main(void) {

    uint16_2_binary_str(10);
}