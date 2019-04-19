#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "workshop6_functions.h"

// We assume the half-precision floating-point number conforms to the 
// IEEE 754-2008 standard. They have the following fields:
// sign: 1 bit
// exponent: 5 bits
const int n_expt = 5;
// fraction: 10 bits
const int n_frac = 10;

// Bias = 2^(n_expt-1) - 1 = 15.
#define bias ((1 << (n_expt-1)) -1)

void hp_float_to_fields(double f, hp_float_fields_TypeDef *field) {
    // f is a hp float, but we use a float type to keep the precision.

    // The maximum number for hp_float:
    // (1 + (1 - 2^(-n_expt))) * 2^(bias) = 
    // (1 + (1 - 2^(-5))) * 2^(15) = 2^16 - 2^10.
    const double hp_float_max = pow(2.0, bias+1) - pow(2.0, bias-n_expt);
    // The minimum normalized number for hp_float:
    // 1.0 * 2^(1-bias) = 1.0 * 2^(1 - 15) = 2^(-14).
    const double hp_float_min_norm = pow(2.0, (1-bias));
	
		float float_Val = (float) f;
	
    // Determine field->sign
	
    // Determine field->exponent
    
    // Determine field->fraction
 
    return;
}

float fields_to_hp_float(uint8_t sign, uint8_t expt, uint32_t frac) {
	float f = 0.0;

    return f;
}
