#define pinoAnalog A0 // Define o pino A0 como "pinoAnalog"
#define pinoRele 8 // Define o pino 8 como "pinoRele"
#define pinoLEDVERDE 9 // Define o pino 9 como "pinoLEDVERDE"
#define pinoLEDAMARELO 10 // Define o pino 10 como "pinoLEDAMARELO"
#define pinoLEDVERMELHO 12 // Define o pino 12 como "pinoLEDVERMELHO"
#define pino5V 7 // Define o pino 7 como "pino5V"

int buzzer = 6; // pino no qual o buzzer está conectado
int ValAnalogIn; // Introduz o valor analógico ao código

void setup() {
  Serial.begin(9600); // Declara o BaundRate em 9600
  pinMode(pinoRele, OUTPUT); // Declara o pinoRele como Saída
  pinMode(pino5V, OUTPUT); // Declara o pino5V como Saída
  digitalWrite(pino5V, HIGH); // Põem o pino5V em estado Alto = 5V
  pinMode(pinoLEDVERDE, OUTPUT); // Declara o pinoLED como Saída
  pinMode(pinoLEDAMARELO, OUTPUT); // Declara o pinoLED como Saída
  pinMode(pinoLEDVERMELHO, OUTPUT); // Declara o pinoLED como Saída
  pinMode(buzzer, OUTPUT); // Declara o buzzer com Saída
}

void loop() {
  ValAnalogIn = analogRead(pinoAnalog); // Relaciona o valor analógico com o recebido do sensor
  int Porcento = map(ValAnalogIn, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem

  Serial.print(Porcento); // Imprime o valor em Porcento no monitor Serial
  Serial.println("%"); // Imprime o símbolo junto ao valor encontrado

  if (Porcento <= 45) { // Se a porcentagem for menor ou igual a 45
    Serial.println("Terreno com índice de umidade apropriado"); // Imprime a frase no monitor serial
    digitalWrite(pinoRele, LOW); // Altera o estado do pinoRele para nível baixo
    digitalWrite(pinoLEDVERDE, HIGH); // Acende o LED conectado ao pinoLEDVERDE
    digitalWrite(pinoLEDAMARELO, LOW); // Desliga o LED conectado ao pinoLEDAMARELO
    digitalWrite(pinoLEDVERMELHO, LOW); // Desliga o LED conectado ao pinoLEDVERMELHO
  } 
  else if (Porcento <= 60) { 
    Serial.println("Terreno com umidade média, tenha cuidado"); // Imprime a frase no monitor serial
    digitalWrite(pinoRele, LOW); // Altera o estado do pinoRele para nível Baixo
    digitalWrite(pinoLEDVERDE, LOW); // Desliga o LED conectado ao pinoLEDVERDE
    digitalWrite(pinoLEDAMARELO, HIGH); // Desliga o LED conectado ao pinoLEDAMARELO
    digitalWrite(pinoLEDVERMELHO, LOW); // Desliga o LED conectado ao pinoLEDVERMELHO
    tone (buzzer, 250,1000 ); // Define o pino e a frequência
    delay(300); // Aguarda 300 milissegundos
  }
  else {
    Serial.println("Terreno com nível máximo de umidade, fuja !");
    digitalWrite(pinoRele, HIGH); // Altera o estado do pinoRele para nível baixo
    digitalWrite(pinoLEDVERDE, LOW); // Desliga o LED conectado ao pinoLEDVERDE
    digitalWrite(pinoLEDAMARELO, LOW); // Desliga o LED conectado ao pinoLEDAMARELO
    digitalWrite(pinoLEDVERMELHO, HIGH); // Desliga o LED conectado ao pinoLEDVERMELHO
    tone (buzzer, 330,1000 ); // Define o pino e a frequência
  }

  delay(1000); // Estabelece o tempo de 1s para reinicializar a leitura
}