#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t DIR;
    uint8_t OUT;
    uint8_t IN;
} GPIO_Register;

void set_pin_output(GPIO_Register *gpio, uint8_t pin) {
    gpio->DIR |= (1 << pin);
}
void set_pin_input(GPIO_Register *gpio, uint8_t pin) {
    gpio->DIR &= ~(1 << pin);
}

void write_pin_high(GPIO_Register *gpio, uint8_t pin) {
    gpio->OUT |= (1 << pin);
}
void write_pin_low(GPIO_Register *gpio, uint8_t pin) {
    gpio->OUT &= ~(1 << pin);
}

void toggle_pin(GPIO_Register *gpio, uint8_t pin) {
    gpio->OUT ^= (1 << pin);
}

int read_pin(GPIO_Register *gpio, uint8_t pin) {
    return (gpio->IN & (1 << pin)) != 0;
}

int main(void) {
    GPIO_Register gpio = {0};
    GPIO_Register *GPIOA = &gpio;

    printf("%u\n", GPIOA->DIR);
    printf("%u\n", GPIOA->OUT);
    printf("%u\n", GPIOA->IN);

    return 0;
}
