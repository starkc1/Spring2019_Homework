#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    while(1) {
        char name[20];
        printf("Enter your first and last name");
        fgets(name, 20, stdin);
        printf("Hello %s", name); 
    }

}