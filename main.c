#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t DIR;
    uint8_t OUT;
    uint8_t IN;
} GPIO_Register;

int main(void) {
    printf("Hello, World!\n");
    return 0;
}