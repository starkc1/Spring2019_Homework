#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "workshop6_functions.h"

hp_float_fields_TypeDef real_fields[3];

int main(void){
    float a_too_big_num = pow(2.0, 18);
    float a_normal_num = -31.875;
    float a_tiny_num = pow(2.0, -18);

// Convert the value of a float number to its field expression 
    hp_float_to_fields(a_too_big_num, &real_fields[0]);
    hp_float_to_fields(a_normal_num, &real_fields[1]);
    hp_float_to_fields(a_tiny_num, &real_fields[2]);
    
    printf("Sign = %1d, Expt = %3d, Frac = 0x%06X\n", real_fields[0].sign,
        real_fields[0].exponent, real_fields[0].fraction);
    printf("Sign = %1d, Expt = %3d, Frac = 0x%06X\n", real_fields[1].sign,
        real_fields[1].exponent, real_fields[1].fraction);
    printf("Sign = %1d, Expt = %3d, Frac = 0x%06X\n", real_fields[2].sign,
        real_fields[2].exponent, real_fields[2].fraction);

// Convert the field expression of a number to its value 
    float reconstructed1 = fields_to_hp_float(real_fields[1].sign, \
        real_fields[1].exponent, real_fields[1].fraction);
    float reconstructed2 = fields_to_hp_float(real_fields[2].sign, \
        real_fields[2].exponent, real_fields[2].fraction);
   
    printf("Value = %f\n", reconstructed1); 
    printf("Value = %f\n", reconstructed2*pow(2.0, 18)); 

    while(1);
}
