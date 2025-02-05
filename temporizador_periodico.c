#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

static volatile int estado = 0; // 0 = Vermelho, 1 = Amarelo, 2 = Verde

bool temporizador_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar o estado
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    // Alterna o estado do semáforo
    switch (estado) {
        case 0:
            gpio_put(LED_AMARELO, 1);
            estado = 1;
            break;
        case 1:
            gpio_put(LED_VERDE, 1);
            estado = 2;
            break;
        case 2:
            gpio_put(LED_VERMELHO, 1);
            estado = 0;
            break;
    }
    return true;
}

int main() {
    stdio_init_all();

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_put(LED_VERMELHO, 1); // Inicia no vermelho

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, temporizador_callback, NULL, &timer);

    while (true) {
        switch (estado) {
            case 0:
                printf("Semáforo: Vermelho\n");
                break;
            case 1:
                printf("Semáforo: Amarelo\n");
                break;
            case 2:
                printf("Semáforo: Verde\n");
                break;
        }
        sleep_ms(1000);
    }
    return 0;
}
