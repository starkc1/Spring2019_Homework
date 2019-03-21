//#include <stm32l476xx.h>  // Comment out this file while using simulator
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


uint32_t test(uint32_t x) {
	uint32_t y, z;
	uint32_t count = x >> 31;
	printf("initial count %d\n", count);
	while (x) {
		y = x << 2;
		z = y >> 31;
		if (x<<1 >y)
			count += z + 1;
		else 
			count += z;
		
		x=y;
		
		printf("x = %d\n", x);
		printf("y = %d\n", y);
		printf("z = %d\n", z);
		printf("count = %d\n\n", count);
	}
	
	return count;
}

void test2(uint32_t x) {
	uint32_t count = x >> 31;
	uint32_t z;
	printf("initial r1 %d\n", count);
	
	while(x) {
		printf("r0 = %d\n", x);
		x = x << 2;
		z = x >> 31;
		count = count + z;
		
		printf("r0 = %d\n", x);
		printf("r1 = %d\n\n", count);
	}
	printf("r0 = %d\n", x);
}


int main(void) {
		
	
	test2(0x9D000000);
}


