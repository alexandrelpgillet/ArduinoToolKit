 /* Author: Guilherme Orro- 62 981009520"
 * Date: 30/01/24
 * Receptor
 * Versao 1.0 
 */
/* Comunicação RS485 com Arduino
 * Comunicação 2 fios
 * Comunicação a longas distâncias (até 1.200 m)
 * Possibilidade de ter até 32 nós/estações na rede RS485 em um mesmo barramento
 * Velocidade de até 35 Mbps
 * detecção de objetos que estejam a uma distância de 10 a 80cm.
 */
 
#include <SoftwareSerial.h>

SoftwareSerial RS485Serial(Pino_RS485_RX, Pino_RS485_TX); //Cria a serial por sofware para conexao com modulo RS485

void initRS485() {
  Serial.print("\nIniciando RS485\n");
  Serial.setTimeout(100);
  Serial.println("Pino A3  -> RS485 | Transmissor ou Receptor");
  Serial.println("Pino A2  -> RS485_RX (RO 0)");
  Serial.println("Pino A4  -> RS485_TX (DI 1)\n");
  RS485Serial.begin(9600);
}

// Armazena os dados que chegam pela serial
String inputString = "";
// Variavel de string completa
boolean stringComplete = false;

char c_mns_recebida;
String s_mns_recebida;
int i_mns = 0;
int i_sensor = 0;
// Recebe os dados do RS485 via porta serial
void recebe_serial_rs485() {
  digitalWrite(EnTxPin, 0);  // Habilita o modulo para transmissao 1 | recepcao 0

  if(RS485Serial.available()) {
    while (RS485Serial.available()) {

      // Recebe os dados e monta a string
      char inChar = RS485Serial.read();
      

      if ((inChar != 'z') and (inChar != 'a') and (inChar != 'b') and (inChar != 'c') and (inChar != 'd') and (inChar != 'e') and (inChar != 'f')) {
        inputString += inChar;
      }

      if (inChar == 'a') {
        i_sensor = 1;
      }
      if (inChar == 'b') {
        i_sensor = 2;
      }
      if (inChar == 'c') {
        i_sensor = 3;
      }
      if (inChar == 'd') {
        i_sensor = 4;
      }
      if (inChar == 'e') {
        i_sensor = 5;
      }
      if (inChar == 'f') {
        i_sensor = 6;
      }

      if (inChar == 'z') {
        // Mostra no Serial Monitor a string recebida
       

          if (i_sensor == 1) {
            fSensorSharpIR =  inputString.toFloat();
          }
          if (i_sensor == 2) {
            angleX = inputString.toFloat();
          }
          if (i_sensor == 3) {
            yaw = inputString.toFloat();
          }
          if (i_sensor == 4) {
            directCompass = inputString;
            directCompass.trim();
          }
          if (i_sensor == 5) {
          }
          if (i_sensor == 6) {
          }

        //stringComplete = true;
        inputString = "";
      }
    }
    //Serial.println();
  }else {
    //Serial.println("falha recebendo os dados do RS485 via porta serial");
  }
}
