# Temporizador Periódico - Raspberry Pi Pico W

Este projeto implementa um **semáforo com temporização periódica** utilizando o **Raspberry Pi Pico W** e a função `add_repeating_timer_ms()` do **Pico SDK**. A simulação pode ser executada na ferramenta **Wokwi**.

## 📌 Requisitos

- **Placa**: Raspberry Pi Pico W
- **Linguagem**: C
- **Ambiente de Desenvolvimento**: VS Code com a extensão **Raspberry Pi Pico SDK** e **Wokwi**
- **Componentes**:
  - 3 LEDs (Vermelho, Amarelo e Verde)
  - 3 Resistores de **330Ω**
  - Raspberry Pi Pico W

## 📜 Estrutura do Código

- **`temporizador_periodico.c`**: Implementação do código principal com o temporizador periódico.
- **`CMakeLists.txt`**: Configuração para compilar o código com o Pico SDK.
- **`diagram.json`**: Diagrama da simulação para Wokwi.

#### 🖥️ Como Executar o Projeto

**Passo 1**: Clone o repositório do projeto para o seu ambiente local e abra-o no VS Code.

**Passo 2**: Antes de compilar o código, é necessário garantir que todas as extensões e ferramentas estão devidamente instaladas.

Instalar o Pico SDK e extensão Raspberry Pi Pico: Siga as instruções do Pico SDK para configurar o ambiente de desenvolvimento no VS Code e instale a extensão Raspberry Pi Pico.

**Passo 3**: Com o ambiente devidamente configurado, abra o código no VS Code e compile o projeto a partir do menu de compilação da extensão Raspberry Pi Pico.

4. **Simulação no Wokwi**:
   - Abra o arquivo `diagram.json` no Wokwi.
   - Execute a simulação para testar o funcionamento do semáforo.

## 🚦 Funcionamento do Semáforo

- O semáforo inicia com o **LED Vermelho aceso**.
- A cada **3 segundos**, muda de cor seguindo a ordem:
  - **Vermelho → Amarelo → Verde → Vermelho**
- A cada **1 segundo**, uma mensagem é impressa na saída serial informando o estado atual do semáforo.

## 🎯 Objetivos Atendidos

✔ Uso da função `add_repeating_timer_ms()` para controle do semáforo.

✔ Mensagem serial impressa a cada 1 segundo.

✔ Simulação compatível com Wokwi e execução no Raspberry Pi Pico W.

🚀 **Desenvolvido por Gabriel Menezes**
