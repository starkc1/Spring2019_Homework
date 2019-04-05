#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#ifdef __cplusplus
  extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

// Functions defined in the .c file
void swap_c_1(uint32_t *x, uint32_t *y);
void swap_c_2(uint32_t *x, uint32_t *y);
void swap_c_3(uint32_t *x, uint32_t *y);
void rank_ascending_c(uint32_t *pArray, uint32_t n);
void rank_descending_c(uint32_t *pArray, uint32_t n);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __FUNCTIONS_H */
