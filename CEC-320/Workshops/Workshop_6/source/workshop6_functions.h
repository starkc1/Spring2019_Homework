#ifndef __WORKSHOP6_FUNCTIONS_H
#define __WORKSHOP6_FUNCTIONS_H

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#include <stdint.h>


typedef struct
{
    uint8_t  sign;        // Sign of a half-precision floating-point number
    uint8_t  exponent;    // Exponent of a half-precision floating-point number
    uint16_t fraction;    // Fraction of a half-precision floating-point number
} hp_float_fields_TypeDef;


void hp_float_to_fields(double f, hp_float_fields_TypeDef *field);
float fields_to_hp_float(uint8_t sign, uint8_t exp, uint32_t frac);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WORKSHOP6_FUNCTIONS_H */
