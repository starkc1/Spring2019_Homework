#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "functions.h"
#include "functions_asm.h"
#include "unity.h"

void test_swap_c_1(void) {
    uint32_t a1[] = {0xFFFFFFFE, 3};
    uint32_t a2[] = {3, 0xFFFFFFFE};
    swap_c_1(&a2[0], &a2[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a1, a2, 2);
    uint32_t a3[] = {0xFFFFFFF0, 3};
    uint32_t a4[] = {3, 0xFFFFFFF0};
    swap_c_1(&a4[0], &a4[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a3, a4, 2);
}

void test_swap_c_2(void) {
    uint32_t a1[] = {0xFFFFFFFE, 3};
    uint32_t a2[] = {3, 0xFFFFFFFE};
    swap_c_2(&a2[0], &a2[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a1, a2, 2);
    uint32_t a3[] = {0xFFFFFFF0, 3};
    uint32_t a4[] = {3, 0xFFFFFFF0};
    swap_c_2(&a4[0], &a4[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a3, a4, 2);
}

void test_swap_c_3(void) {
    uint32_t a1[] = {0xFFFFFFFE, 3};
    uint32_t a2[] = {3, 0xFFFFFFFE};
    swap_c_3(&a2[0], &a2[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a1, a2, 2);
    uint32_t a3[] = {0xFFFFFFF0, 3};
    uint32_t a4[] = {3, 0xFFFFFFF0};
    swap_c_3(&a4[0], &a4[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a3, a4, 2);
}

void test_rank_ascending_c(void) {
    uint32_t arr1[] = {0xDDDDDDDD, 0x12345678, 0, 0xFFFFFFFF, 0x88888888};
    uint32_t arr1asc[] = {0, 0x12345678, 0x88888888, 0xDDDDDDDD, 0xFFFFFFFF};
    rank_ascending_c(arr1, 5);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(arr1asc, arr1, 5);
}

void test_rank_desending_c(void) {
    uint32_t arr1[] = {0xDDDDDDDD, 0x12345678, 0, 0xFFFFFFFF, 0x88888888};
    uint32_t arr1des[] = {0xFFFFFFFF, 0xDDDDDDDD, 0x88888888, 0x12345678, 0};
    rank_descending_c(arr1, 5);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(arr1des, arr1, 5);
}

void test_swap_asm_1(void) {
	uint32_t a1[] = {0xFFFFFFFE, 3};
	uint32_t a2[] = {3, 0xFFFFFFFE};
	swap_asm_1((a1), (a1+1));
	//printf("0x%X", *(a1+1));
	TEST_ASSERT_EQUAL_UINT32_ARRAY(a2, a1, 2);
  uint32_t a3[] = {0xFFFFFFF0, 3};
	uint32_t a4[] = {3, 0xFFFFFFF0};
	swap_asm_1((a3), (a3+1));
	TEST_ASSERT_EQUAL_UINT32_ARRAY(a4, a3, 2);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_swap_c_1);
    RUN_TEST(test_swap_c_2);
    RUN_TEST(test_swap_c_3);
    RUN_TEST(test_rank_ascending_c);
    RUN_TEST(test_rank_desending_c);
		RUN_TEST(test_swap_asm_1);
    UNITY_END();

    while(1);
}

