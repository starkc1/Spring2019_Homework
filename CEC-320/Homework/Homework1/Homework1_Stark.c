#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define N 5
#define MIN_U 0    // minimum value of unsigned N-bit number
#define MAX_U ((1 << N) - 1)   // maximum value of unsigned N-bit number
#define MIN_I (-(1 << (N - 1)))
#define MAX_I ((1 << (N - 1)) -1)

char str_c[30];
char str_v[30];
int c, k, count;
bool v_flag, c_flag;

void uint8_2_binary_str(uint8_t num) {
    count = 0;

    for (c = 9; c >= 0; c--) {
        k = num >> c;

        if (k & 1) {
            str_c[count] = '1';
        } else {
            str_c[count] = '0';
        }
        count++;
    }
    //printf("%s", str_c);

    for (int i = 0, j = 0, k = 0; i < 9; i++) {
        if (j == 4)  {
            str_v[i] = '_';
            j = 0;
        } else if (j != 4) {
            str_v[i] = str_c[k];
            k++;
            j++;
        }
    }


    printf("%i and %s\n\n", num, str_v);
}

void add_int8(int8_t num1, int8_t num2) {
    int8_t result = num1 + num2;
    
    if (result < MIN_I) {
        v_flag = 1;
    } else if (result > MAX_I) {
        v_flag = 1;
    } else {
        v_flag = 0;
    }
    printf("%i\n", v_flag);
    uint8_2_binary_str(result);
}

int8_t  sub_int8(int8_t x0, int8_t x1) {
	
	int8_t result = x0 - x1;
	
	if(x0 < 0 && x1 > 0 && result > 0){
		 v_flag = 1;
	} else if(x0 > 0 && x1 < 0 && result < 0) {
		 v_flag = 1;
	} else {
		 v_flag = 0;
	}
		
	printf("%i\n", v_flag);
    uint8_2_binary_str(result);
}

uint8_t  sub_uint8(uint8_t x0, uint8_t x1) {
	
		uint8_t result = x0 - x1;	
	
		if(result > x0){
			c_flag = 0;//0
		} else {
			c_flag = 1;//0
		}
		
	printf("%i\n", c_flag);
    uint8_2_binary_str(result);
}

int main(void) {
    add_int8(-16, -16);
    sub_int8(14, -16);
    sub_uint8(14, 16);
    sub_int8(15, -6);
    add_int8(15, -6);
    add_int8(14, -16);
}