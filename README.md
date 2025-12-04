# Oasis_Planta_Feliz
Projeto de arduíno que monitora e alerta sobre condições ambientais que podem danificar plantas ao redor do sistema

O sistema lê sensores de temperatura/umidade (DHT11) e luz (LDR), compara com limites definidos e alerta o usuário caso algo esteja inadequado. Seu objetivo é facilitar o cuidado das plantas usando tecnologia acessível.

## Objetivos do Projeto

- Monitorar umidade, temperatura e luminosidade em tempo real.
- Promover o bem-estar da planta usando automação simples.
- Exibir mensagens claras no display LCD.
- Alertar sobre problemas usando LEDs piscando e som do buzzer.

Desenvolver habilidades de:
- Programação em Arduino C/C++
- Integração de hardware + software
- Trabalho em equipe
- Criação de soluções tecnológicas para saúde vegetal

## Componentes Utilizados

01 Sensor de umidade e temperatura DHT11
01 Sensor de luminosidade LDR
02 LEDs
01 Black Board Uno R3 (compatível com Arduino Uno)
01 Buzzer
01 Resistor de 1 kΩ
01 Potenciômetro de 10 kΩ
01 Resistor de 220 Ω
01 LCD Display (16x2)
23 Jumpers

## Lógica de Funcionamento

1 - O sensor DHT11 lê temperatura e umidade.
2 - O sensor LDR mede a luminosidade do ambiente.
3 - O sistema compara as leituras com valores-limite definidos no código.
4 - Se algo estiver fora do ideal:
    - O display LCD mostra o alerta correspondente.
    - LEDs começam a piscar.
    - O buzzer emite um som.

## 🐢 Protótipo

Uma tartaruga feita com Arduino que monitora o ambiente da planta e interage quando encontra algo errado. Ela se comunica por som, luz e mensagens no display.

## Equipe
Abraão Filipi dos Santos – afs6@cesar.school
Dilvanir Aline Alves Cabral de Melo – daacm@cesar.school
Emanoel Alessandro da Silva – eas3@cesar.school
Marcio Aureliano Pedro da Silva – maps@cesar.school
Maria Larysse Yasmin Lira Pereira – mlylp@cesar.school (LÍDER)
Pedro Pessôa De Albuquerque Neto – ppan@cesar.school
