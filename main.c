#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t DIR;
    uint8_t OUT;
    uint8_t IN;
} GPIO_Register;

void set_pin_mode() {

}

void write_pin() {

}

void toggle_pin() {

}

uint8_t read_pin() {
    return 0;
}

void print_registers() {

}

int main(void) {
    GPIO_Register gpio = {0};
    GPIO_Register *GPIOA = &gpio;

    printf("%u\n", GPIOA->DIR);
    printf("%u\n", GPIOA->OUT);
    printf("%u\n", GPIOA->IN);

    return 0;
}
