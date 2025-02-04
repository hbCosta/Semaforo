#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.


#define led_vermelho 11
#define led_amarelo 12
#define led_verde 13


int estado = 0;


void iniciar_leds(){
  gpio_init(led_vermelho);
  gpio_init(led_amarelo);
  gpio_init(led_verde);

  gpio_set_dir(led_vermelho, true);
  gpio_set_dir(led_amarelo, true);
  gpio_set_dir(led_verde, true);

  gpio_put(led_vermelho, 1);
  gpio_put(led_amarelo, 0);
  gpio_put(led_verde, 0);

}

bool repeating_timer_callback(struct repeating_timer *t) {
    // Imprime uma mensagem na saída serial indicando que 3 segundo se passou.
    printf("3 segundos passou\n");
    if(estado == 0){
      gpio_put(led_vermelho, 0);
      gpio_put(led_amarelo, 1);
      estado = 1;
    }else if(estado == 1){
      gpio_put(led_amarelo, 0);
      gpio_put(led_verde, 1);
      estado = 2;
    }else{
      gpio_put(led_verde, 0);
      gpio_put(led_vermelho, 1);
      estado = 0;
    }

    return true;
}

int main() {
     // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializar os pinos
    iniciar_leds();

    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução.
    while (true) {
        sleep_ms(10000);
        printf("rotina de repetição\n");
    }
    return 0;
}
