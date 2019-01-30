#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

char str_c[30];
char str_v[30];
int c, k, count;

void uint16_2_binary_str(uint16_t num, char *cPtr)
{
    count = 0;

    for (c = 20; c >= 0; c--)
    {
        k = num >> c;
        
        if (k & 1)
            //str_c[count] = '1';                    
            //cPtr[count] = "1";
            *(cPtr + count) = '1';
            //printf("1");
        else
            //str_c[count] = '0';
            *(cPtr + count) = '0';
            //cPtr[count] = "0";
            //printf("0");
        
        count++;
    }
    
}

void print_str_c(uint16_t num, char *cPtr)
{
    uint16_2_binary_str(num, cPtr);
    printf("%s", cPtr);
}

void print_str_v(uint16_t num, char *cPtr_c, char *cPtr_v)
{
    int j = 1;
    count = 0;
        
    for (int i = 1; i < 30; i++) {
        j = i % 5;
        if (j == 0) {
            *(cPtr_v + count) = '_';
            *(cPtr_v + (count+1)) = *(cPtr_c + i);
            count++;
        } else {
            *(cPtr_v + count) = *(cPtr_c + i-1);
            count++;
        }
        
    }   
    printf("%s", cPtr_v);
}

int main(void)
{
    uint16_t test_num[] = {0x1234, 0x5678, 0x9ABC, 0xDEF0};
    int N = sizeof(test_num) / sizeof(test_num[0]); 
    printf("Testing the printout of binary numbers:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Compact display for 0x%x is ", test_num[i]);
        print_str_c(test_num[i], str_c);
        printf("\nVerbose display for 0x%x is ", test_num[i]);
        print_str_v(test_num[i], str_c, str_v);
        printf("\n");
    }
}