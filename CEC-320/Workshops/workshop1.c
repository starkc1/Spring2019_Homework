#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

char str_c[30];
char str_v[30];

void uint16_2_binary_str(uint16_t num, char *cPtr) {

}

void print_str_c(uint16_t num, char *cPtr) {

}

void print_str_v(uint16_t num, char *cPtr_c, char *cPtr_v) {

}

int main(void) {
    uint16_t test_num[] = {0x1234, 0x5678, 0x9ABC, 0xDEF0};
    int N = sizeof(test_num) / sizeof(test_num[0]);

    printf("Testing the printout of binary numbers:\n");
    for (int i = 0; i < N; i++) {
        printf("Compact display for 0x%x is ", test_num[i]);
        print_str_c(test_num[i], str_c);
        printf("\nVerbose display for 0x%x is ", test_num[i]);
        print_str_v(test_num[i], str_c, str_v);
        printf("\n");
    }

    while (1);
}