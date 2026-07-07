#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t DIR;
    uint8_t OUT;
    uint8_t IN;
} GPIO_Register;

uint8_t mask(uint8_t pin) {
    return (1u << pin);
}

int pin_isValid(uint8_t pin) {
    return pin <= 7;
}

void set_pin_output(GPIO_Register *gpio, uint8_t pin) {
    if (pin_isValid(pin))
        gpio->DIR |= mask(pin);
}
void set_pin_input(GPIO_Register *gpio, uint8_t pin) {
    if (pin_isValid(pin))
        gpio->DIR &= ~mask(pin);
}

void write_pin_high(GPIO_Register *gpio, uint8_t pin) {
    if (pin_isValid(pin))
        gpio->OUT |= mask(pin);
}
void write_pin_low(GPIO_Register *gpio, uint8_t pin) {
    if (pin_isValid(pin))
        gpio->OUT &= ~mask(pin);
}

void toggle_pin(GPIO_Register *gpio, uint8_t pin) {
    if (pin_isValid(pin))
        gpio->OUT ^= mask(pin);
}

int read_pin(GPIO_Register *gpio, uint8_t pin) {
    return pin_isValid(pin) ? ((gpio->IN & mask(pin)) != 0) : -1;
}

void print_register_binary(uint8_t reg) {
    for (int i = 7; i >= 0; i--) {
        ((1u << i) & reg) != 0 ? printf("1") : printf("0");
    }
    printf("\n");
}

int main(void) {
    GPIO_Register gpio = {0};
    GPIO_Register *GPIOA = &gpio;

    uint8_t ex = 4;
    print_register_binary(ex);

    return 0;
}
