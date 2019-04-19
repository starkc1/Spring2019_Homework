#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "workshop6_functions.h"
#include "unity.h"

void test_hp_float_to_fields(void) {
    hp_float_fields_TypeDef hp_float_fields[3];

    float a_too_big_num = pow(2.0, 18);
    uint16_t a_too_big_num_exptd[] = {0, 31, 0};
    float a_normal_num = -31.875;
    uint16_t a_normal_num_exptd[] = {1, 19, 0x3F8};
    float a_tiny_num = pow(2.0, -18);
    uint16_t a_tiny_num_exptd[] = {0, 0, 0x40};
 
    hp_float_to_fields(a_too_big_num, &hp_float_fields[0]);
    hp_float_to_fields(a_normal_num, &hp_float_fields[1]);
    hp_float_to_fields(a_tiny_num, &hp_float_fields[2]);
    
    uint16_t a_too_big_num_obtnd[3];
    uint16_t a_normal_num_obtnd[3];
    uint16_t a_tiny_num_obtnd[3];

    a_too_big_num_obtnd[0] = hp_float_fields[0].sign;
    a_too_big_num_obtnd[1] = hp_float_fields[0].exponent;
    a_too_big_num_obtnd[2] = hp_float_fields[0].fraction;

    a_normal_num_obtnd[0] = hp_float_fields[1].sign;
    a_normal_num_obtnd[1] = hp_float_fields[1].exponent;
    a_normal_num_obtnd[2] = hp_float_fields[1].fraction;

    a_tiny_num_obtnd[0] = hp_float_fields[2].sign;
    a_tiny_num_obtnd[1] = hp_float_fields[2].exponent;
    a_tiny_num_obtnd[2] = hp_float_fields[2].fraction;

    TEST_ASSERT_EQUAL_UINT16_ARRAY(a_too_big_num_exptd, a_too_big_num_obtnd, 3);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(a_normal_num_exptd, a_normal_num_obtnd, 3);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(a_tiny_num_exptd, a_tiny_num_obtnd, 3);
}
    
void test_fields_to_hp_float(void) {
    hp_float_fields_TypeDef hp_float_fields[2];
    float a_normal_num_exptd = -31.875;
    uint16_t a_normal_num_elements[] = {1, 19, 0x3F8};
    float a_tiny_num_exptd = pow(2.0, -18);
    uint16_t a_tiny_num_elements[] = {0, 0, 0x40};

    hp_float_fields[0].sign     = a_normal_num_elements[0];
    hp_float_fields[0].exponent = a_normal_num_elements[1];
    hp_float_fields[0].fraction = a_normal_num_elements[2];

    hp_float_fields[1].sign     = a_tiny_num_elements[0];
    hp_float_fields[1].exponent = a_tiny_num_elements[1];
    hp_float_fields[1].fraction = a_tiny_num_elements[2];

    float a_normal_num_obtnd = fields_to_hp_float(hp_float_fields[0].sign, \
        hp_float_fields[0].exponent, hp_float_fields[0].fraction);
    float a_tiny_num_obtnd = fields_to_hp_float(hp_float_fields[1].sign, \
        hp_float_fields[1].exponent, hp_float_fields[1].fraction);

    TEST_ASSERT_EQUAL_FLOAT(a_normal_num_exptd, a_normal_num_obtnd);
    TEST_ASSERT_EQUAL_FLOAT(a_tiny_num_exptd, a_tiny_num_obtnd);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_hp_float_to_fields);
    RUN_TEST(test_fields_to_hp_float);
    UNITY_END();

    while(1);
}
