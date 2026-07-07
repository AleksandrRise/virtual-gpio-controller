#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t DIR;
    uint8_t OUT;
    uint8_t IN;
} GPIO_Register;

int main(void) {
    GPIO_Register gpio = {0};
    GPIO_Register *GPIOA = &gpio;

    printf("%u\n", GPIOA->DIR);
    printf("%u\n", GPIOA->OUT);
    printf("%u\n", GPIOA->IN);

    return 0;
}
