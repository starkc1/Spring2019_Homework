#ifndef __FUNCTIONS_ASM_H
#define __FUNCTIONS_ASM_H

#ifdef __cplusplus
  extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

// Functions defined in the .s file
void swap_asm_1(uint32_t *x, uint32_t *y);
void swap_asm_2(uint32_t *x, uint32_t *y);
void swap_asm_3(uint32_t *x, uint32_t *y);
void rank_descending_asm(uint32_t *pArray, uint32_t n);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __FUNCTIONS_ASM_H */
