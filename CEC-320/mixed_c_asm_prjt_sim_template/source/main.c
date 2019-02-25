#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int32_t accumulate_inline(int32_t y, int32_t x, int32_t h) {
    int32_t t;
    __asm {
        MLA t, x, h, y  // t = x * h + y
    }
    return t;
}

// Note that you may see errors in the editor for the following code. This is 
// issue of the system. Ignore them and rely on the compiler.
__asm int32_t accumulate_asm_in_c(int32_t x1, int32_t x2, int32_t h1, int32_t h2) 
{
    ; r0 = x1, r1 = x2, r2 = h1, r3 = h2
    PUSH {r4, lr}        ; preserve the environment in stack
    MUL  r4, r0, r2      ; r4 = r0 * r2 = x1 * h1
    MLA  r0, r1, r3, r4  ; r0 = r1 * r3 + r4
    POP  {r4, pc}        ; recover the environment and return to caller
} 


extern void strcpy_asm_in_s(const char *src, char *dst);

uint8_t count = 20;

int main(void) {
    int32_t y = 10, x = 3, h = 4;
    const char a[] = "Copy me if you can---this is a long string.";
    char b[count];

// Calling a function with inline assembly code
    y = accumulate_inline(y, x, h);
    printf("The result of x * h + y is %d\n", y);

// Calling an assembly function saved in the C source file 
    y = accumulate_asm_in_c(x, x, h, h);
    printf("The result of x * h + x * h is %d\n", y);

// Caling an assembly function saved in a .s file
    strcpy_asm_in_s(a, b);
    printf("Original string: '%s'\n", a);
    printf("Copied   string: '%s'\n", b);
    while (1);
}
