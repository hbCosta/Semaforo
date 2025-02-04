# Controle de Semáforo com Raspberry Pi Pico

Este projeto implementa um sistema de controle de semáforo utilizando o Raspberry Pi Pico W. O funcionamento segue um ciclo de cores (vermelho, amarelo e verde) com um intervalo de 3 segundos entre as transições, utilizando um temporizador de hardware.

## Requisitos Atendidos

1. **Acionamento inicial**: O semáforo inicia com o LED vermelho aceso, seguindo a sequência vermelho -> amarelo -> verde.
2. **Temporização**: O temporizador é configurado para um atraso de 3 segundos (3000 ms), garantindo a troca de estados no tempo correto.
3. **Call-back do temporizador**: A mudança de estado dos LEDs é implementada na função `repeating_timer_callback()`, chamada automaticamente a cada 3 segundos.
4. **Saída serial**: No loop principal (`while`), uma mensagem é impressa na porta serial a cada 1 segundo (1000 ms).

## Componentes Utilizados
- **Raspberry Pi Pico**
- **LEDs** (Vermelho, Amarelo e Verde)
- **Resistores de 330Ω**
- **BitDogLab** (para simulação e testes)
- **OBSERVAÇÃO:** FEITO TUDO NO SIMULADOR WOKWI ONLINE E NA EXTENSÃO WOKWI NO VSCODE

## Instalação e Execução

1. Conecte os LEDs aos pinos GPIO do Raspberry Pi Pico:
   - LED Vermelho -> GPIO 11
   - LED Amarelo -> GPIO 12
   - LED Verde -> GPIO 13
2. Configure o ambiente de desenvolvimento com o SDK do Raspberry Pi Pico.
3. Compile e envie o código para o Raspberry Pi Pico.

## Estrutura do Código

- **`iniciar_leds()`**: Configura os GPIOs e define o LED vermelho como inicial.
- **`repeating_timer_callback()`**: Alterna os LEDs a cada 3 segundos.
- **`main()`**: Inicializa a comunicação serial e configura o temporizador.


## Teste com BitDogLab

Para testar no BitDogLab:
1. Configure os GPIOs 11, 12 e 13 como saída.
2. Suba o código para o Raspberry Pi Pico.
3. Observe a mudança dos LEDs conforme esperado.
-**OBS:** O LED AZUL SERIA O LED AMARELO USANDO A PLACA BitDogLab E TUDO SERIA NO LED RGB

## Conclusão
Este projeto demonstra a utilização de temporizadores e manipulação de GPIOs no Raspberry Pi Pico para criar um sistema de semáforo funcional.

