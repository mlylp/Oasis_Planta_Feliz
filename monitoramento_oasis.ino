// Inclui a biblioteca para o sensor de Umidade e Temperatura DHT
#include <DHT.h>
// Inclui a biblioteca para controlar o display LCD
#include <LiquidCrystal.h>

// Define o pino digital onde o sensor DHT está conectado (pino 13)
#define DHTPIN 13

// Define o tipo de sensor DHT que está sendo usado (DHT11 neste caso)
#define DHTTYPE DHT11

// Cria um objeto 'dht' para interagir com o sensor, usando o pino e o tipo definidos
DHT dht(DHTPIN, DHTTYPE);
// Define o pino analógico onde o LDR (sensor de luz) está conectado (A0)
int ldr = A0;
// Variável para armazenar o valor lido do sensor LDR
int valorldr = 0;

// Cria um objeto 'lcd_1' para controlar o display LCD. 
// Os números são os pinos do Arduino conectados ao LCD (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd_1(7,6,5,4,3,2);

// Variáveis booleanas (verdadeiro/falso) para sinalizar se a temperatura, umidade ou luz está acima/abaixo dos limites
bool templus = false; // Indica se a Temperatura está alta
bool temminus = false; // Indica se a Temperatura está baixa
bool humiplus = false; // Indica se a Umidade está alta
bool humiminus = false; // Indica se a Umidade está baixa
bool luzplus = false; // Indica se a Luz está alta/ambiente claro (valor do LDR baixo)
bool luzminus = false; // Indica se a Luz está baixa/ambiente escuro (valor do LDR alto)

// Define o pino digital para o buzzer (saída de som)
const int buzzerPin =9;
// Define a frequência da nota (Lá = 440 Hz)
const int NOTA_LA = 440;
// Define o pino digital para o LED
int led = 11;

void setup() {
  
   // Inicia a comunicação com o sensor DHT
  dht.begin(); 
  // Inicializa a comunicação serial a 9600 bits por segundo (para enviar dados ao computador)
  Serial.begin(9600); 
    // Inicializa o display LCD, definindo que ele tem 16 colunas e 2 linhas
  lcd_1.begin(16, 2);

  // Envia uma mensagem inicial para o monitor serial
  Serial.println("sensor iniciando");
  // Define o pino do LDR como entrada (para ler o valor do sensor)
  pinMode(ldr,INPUT);

 
// Define o pino do buzzer como saída (para emitir som)
pinMode(buzzerPin,OUTPUT);
// Define o pino do LED como saída (para acender/apagar)
pinMode(led, OUTPUT);
}
void loop() {

  // Pausa por 2 segundos (2000 milissegundos) antes de fazer uma nova leitura
  delay(2000);

  // Lê o valor analógico do sensor LDR (vai de 0 a 1023)
  valorldr=analogRead(ldr);

  // Lê a umidade do sensor DHT
  float h = dht.readHumidity();

  // Lê a temperatura do sensor DHT
  float t = dht.readTemperature();

  // Verifica se a leitura do sensor DHT falhou (se houver erro ou valor inválido)
  if (isnan(h) || isnan(t)) {
    // Se falhar, imprime uma mensagem de erro no monitor serial e sai do loop (retorna)
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  // --- Imprime os valores no monitor Serial ---
  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println("°C");
  Serial.print("luminosidade: ");
  Serial.println(valorldr);
  // ---------------------------------------------
  
  // --- Bloco de Verificação de Limites e Sinalização ---

  // Verifica se a umidade está acima de 70%
  if (h>70){ 
    humiplus = true; // Se sim, ativa a flag de umidade alta
  }
  // Verifica se a umidade está abaixo de 40%
  if (h<40){
    humiminus = true; // Se sim, ativa a flag de umidade baixa
  }
  // Verifica se a temperatura está acima de 30°C
  if (t>30){
    templus = true; // Se sim, ativa a flag de temperatura alta
  }
  // Verifica se a temperatura está abaixo de 18°C
  if (t<18){
    temminus = true; // Se sim, ativa a flag de temperatura baixa
  }
  // Verifica se a luminosidade (LDR) está acima de 700 (geralmente indica ESCURO)
  if (valorldr>700){
    luzminus = true; // Se sim, ativa a flag de luz baixa/escuro
  }
  // Verifica se a luminosidade (LDR) está abaixo de 90 (geralmente indica CLARO)
  if (valorldr<90){
    luzplus = true; // Se sim, ativa a flag de luz alta/claro
  }

  // --- Bloco de Ações (LCD e Buzzer) Baseado nas Flags ---

  // Se a umidade estiver alta
  if (humiplus == true){
    lcd_1.print("umido!!"); // Imprime "umido!!" no LCD
    tone(buzzerPin, 440, 1000); // Toca o buzzer na frequência 440 Hz por 1 segundo
  }

  // Se a umidade estiver baixa
  if (humiminus == true){
    lcd_1.print("seco!!"); // Imprime "seco!!" no LCD
    tone(buzzerPin, 440, 1000); // Toca o buzzer
  }

  // Se a temperatura estiver alta
  if (templus == true){ 
    lcd_1.print("quente!!"); // Imprime "quente!!" no LCD
    tone(buzzerPin, 440, 1000); // Toca o buzzer
  }

  // Se a temperatura estiver baixa
  if (temminus == true){
    lcd_1.print("frio!!"); // Imprime "frio!!" no LCD
    tone(buzzerPin, 440, 1000); // Toca o buzzer
  }

  // Se a luz estiver alta/claro
  if (luzplus == true){
    lcd_1.setCursor(0,1); // Move o cursor para o início da segunda linha (coluna 0, linha 1)
    lcd_1.print("claro!!"); // Imprime "claro!!"
    tone(buzzerPin, 440, 1000); // Toca o buzzer
  }
    
  // Se a luz estiver baixa/escuro
  if (luzminus == true){
    lcd_1.setCursor(0,1); // Move o cursor para o início da segunda linha
    lcd_1.print("escuro!!"); // Imprime "escuro!!"
    tone(buzzerPin, 440, 1000); // Toca o buzzer
  }
  
  // Se nenhuma das condições acima for verdadeira (tudo está dentro dos limites)
  if(templus == false && temminus == false && humiplus == false && humiminus == false && luzplus == false && luzminus == false){
    lcd_1.print("tudo otimo :)"); // Imprime "tudo otimo :)" no LCD
  } 
  
  // --- Piscando o LED ---
  digitalWrite(led, HIGH);  // Acende o LED (coloca a tensão em nível ALTO)
  delay(1000);              // Espera 1 segundo (LED aceso) 
  digitalWrite(led, LOW);   // Apaga o LED (coloca a tensão em nível BAIXO)
  delay(1000);              // Espera 1 segundo (LED apagado)
  // -----------------------

  // Limpa todo o conteúdo do display LCD antes da próxima repetição do loop
  lcd_1.clear();

}
