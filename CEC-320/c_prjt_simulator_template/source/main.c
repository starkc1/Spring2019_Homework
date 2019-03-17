//#include <stm32l476xx.h>  // Comment out this file while using simulator
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t my_id;
    uint32_t my_id2;
} MyType;

bool need_to_print = true;
MyType myid;
MyType *p_id = &myid;
  
int main(void) {
    myid.my_id = 1234;
    myid.my_id2 = myid.my_id * myid.my_id;
    if (need_to_print) {
        printf("The values of my_ids are %d and %d, respectively.\n", p_id->my_id, p_id->my_id2);
    }

    while (1);
}
