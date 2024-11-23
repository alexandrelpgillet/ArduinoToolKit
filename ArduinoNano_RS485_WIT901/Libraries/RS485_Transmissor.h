/* Author: Guilherme Orro- 62 981009520"
 * Transmissor
 */
/* Comunicação RS485 com Arduino
 * Comunicação 2 fios
 * Comunicação a longas distâncias (até 1.200 m)
 * Possibilidade de ter até 32 nós/estações na rede RS485 em um mesmo barramento
 * Velocidade de até 35 Mbps
 * detecção de objetos que estejam a uma distância de 10 a 80cm.
 */
#include <SoftwareSerial.h>
 
// Prototypes RS485
void initRS485();
void RS485_SensorWT901Angle();
void RS485_SensorWT901Mag();
void RS485_SensorSharpIR();

void OutputRS485() { // Define a porta status de saida e entrada
  //pinMode(Pino_RS485_RX, OUTPUT);
  //pinMode(Pino_RS485_TX, OUTPUT);
  pinMode(EnTxPin, OUTPUT);
  digitalWrite(EnTxPin, 0);  // Habilita o modulo para transmissao 1 | recepcao 0
}

// Cria a serial por sofware para conexao com modulo RS485
SoftwareSerial RS485Serial(Pino_RS485_RX, Pino_RS485_TX);

void initRS485() { 
  Serial.print("\nIniciando RS485 Transmissor\n");
  Serial.setTimeout(100);
  Serial.println("Pino A3  -> RS485 | Transmissor ou Receptor");
  Serial.println("Pino A1  -> RS485_RX (RO 0)");                    
  Serial.println("Pino A2  -> RS485_TX (DI 1)\n");
  RS485Serial.begin(9600);  // Inicializa a serial do modulo RS485
  digitalWrite(EnTxPin, 0);  // Habilita o modulo para transmissao 1 | recepcao 0
}

void RS485_SensorSharpIR() {
  //Serial.println("\nRS485 Transmissor | Sensores.");
  // Habilita o modulo para transmissao ou recepcao
  digitalWrite(EnTxPin, 1);   // Habilita o modulo para transmissao 1 | recepcao 0
  RS485Serial.print("a");     // Inicio do pacote de transmissão do sensor
  RS485Serial.print(fSensorSharpIR);    // Valor do sensor
  RS485Serial.println("z");   // Fim do pacote de transmissão
  RS485Serial.flush();
}

void RS485_SensorWT901Angle() {
  //Serial.println("\nRS485 Transmissor | Sensores.");
  digitalWrite(EnTxPin, 1);    // Habilita o modulo para transmissao 1 | recepcao 0
  RS485Serial.print("b");      // Inicio do pacote de transmissão do sensor
  RS485Serial.print(angleX);   // Valor do sensor
  RS485Serial.println("z");    // Fim do pacote de transmissão
  RS485Serial.flush();
}
void RS485_SensorWT901Mag() {
  //Serial.println("\nRS485 Transmissor | Sensores.");
  digitalWrite(EnTxPin, 1);   // Habilita o modulo para transmissao 1 | recepcao 0
  RS485Serial.print("c");     // Inicio do pacote de transmissão do sensor
  RS485Serial.print(yaw);    // Valor do sensor
  RS485Serial.println("z");   // Fim do pacote de transmissão
  RS485Serial.print("d");      // Inicio do pacote de transmissão do sensor
  RS485Serial.print(directCompass);   // Valor do sensor
  RS485Serial.println("z");    // Fim do pacote de transmissão
  RS485Serial.flush();
}

void RS485_SensorWT901Angle3eixos() {
  //Serial.println("\nRS485 Transmissor | Sensores.");
  digitalWrite(EnTxPin, 1);    // Habilita o modulo para transmissao 1 | recepcao 0
  RS485Serial.print("a");      // Inicio do pacote de transmissão do sensor
  RS485Serial.print(angleX);   // Valor do sensor
  RS485Serial.println("z");    // Fim do pacote de transmissão
  RS485Serial.print("b");      // Inicio do pacote de transmissão do sensor
  RS485Serial.print(angleY);   // Valor do sensor
  RS485Serial.println("z");    // Fim do pacote de transmissão
  RS485Serial.print("c");      // Inicio do pacote de transmissão do sensor
  RS485Serial.print(angleZ);   // Valor do sensor
  RS485Serial.println("z");    // Fim do pacote de transmissão
  RS485Serial.flush();
}
void RS485_SensorWT901Mag3eixos() {
  //Serial.println("\nRS485 Transmissor | Sensores.");
  digitalWrite(EnTxPin, 1);   // Habilita o modulo para transmissao 1 | recepcao 0
  RS485Serial.print("d");     // Inicio do pacote de transmissão do sensor
  RS485Serial.print(magX);    // Valor do sensor
  RS485Serial.println("z");   // Fim do pacote de transmissão
  RS485Serial.print("e");     // Inicio do pacote de transmissão do sensor
  RS485Serial.print(magY);    // Valor do sensor
  RS485Serial.println("z");   // Fim do pacote de transmissão
  RS485Serial.print("f");     // Inicio do pacote de transmissão do sensor
  RS485Serial.print(magZ);    // Valor do sensor
  RS485Serial.println("z");   // Fim do pacote de transmissão
  RS485Serial.flush();
}

