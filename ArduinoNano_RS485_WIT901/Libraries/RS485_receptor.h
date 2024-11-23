/* Author: Guilherme Orro- 62 981009520"
 * Receptor
 */
/* Comunicação RS485 com Arduino
 * Comunicação 2 fios
 * Comunicação a longas distâncias (até 1.200 m)
 * Possibilidade de ter até 32 nós/estações na rede RS485 em um mesmo barramento
 * Velocidade de até 35 Mbps
 * detecção de objetos que estejam a uma distância de 10 a 80cm.
 */

// Prototypes RS485
void recebe_serial_rs485();

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
  int i_stop = 0;
  
  digitalWrite(EnTxPin, 0);  // Habilita o modulo para transmissao 1 | recepcao 0

  //Serial.println("\nRS485-------------------------------");
  if(RS485Serial.available()) {
    
    while (RS485Serial.available()) {


      // Recebe os dados e monta a string
      char inChar = RS485Serial.read();
      
      //char inChar = (char)RS485Serial.read();
      
      //Serial.print("inChar: "); Serial.println(inChar);

      // comandos: motores - p f t e d | camera 1 - i k j l | camera 2 - h n b m

      
      if (inChar == 'f') {
        
        i_stop = 1;
        
        Serial.println("motores para frente");
        digitalWrite(motorD1,LOW);
        digitalWrite(motorD2,HIGH);
        digitalWrite(motorE3,LOW);
        digitalWrite(motorE4,HIGH);            
        
        // org delay(150);
        delay(150);
      }
      if (inChar == 't') {
        
        i_stop = 1;
        
        Serial.println("motores para tras");
        digitalWrite(motorD1,HIGH);
        digitalWrite(motorD2,LOW);
        digitalWrite(motorE3,HIGH);
        digitalWrite(motorE4,LOW);
        
        delay(150);
      }
      if (inChar == 'e') {
        
        i_stop = 1;
        
        Serial.println("motores para esquerda");
        digitalWrite(motorD1,HIGH);
        digitalWrite(motorD2,LOW);
        digitalWrite(motorE3,LOW);
        digitalWrite(motorE4,HIGH);
        
        delay(150);
      }
      if (inChar == 'd') {
        i_stop = 1;
        
        Serial.println("motores para direita");
        digitalWrite(motorD1,LOW);
        digitalWrite(motorD2,HIGH);
        digitalWrite(motorE3,HIGH);
        digitalWrite(motorE4,LOW);
        
        delay(150);
      }

      if (inChar == 'k') {
        
        Serial.println("camera 1 sonda - desce");
        digitalWrite(m1,HIGH);
        digitalWrite(m2,LOW);
        digitalWrite(com,LOW);
        
        delay(200);
      }
      if (inChar == 'i') {
        
        Serial.println("camera 1 sonda - sobe");
        digitalWrite(m1,LOW);
        digitalWrite(m2,HIGH);
        digitalWrite(com,HIGH);
        
        delay(200);
      
      }

      if (inChar == 'l') {
        
        Serial.println("camera 1 sonda - esquerda");
        digitalWrite(m1,HIGH);
        digitalWrite(m2,LOW);
        digitalWrite(com,HIGH);
        delay(200);
      
      }
      if (inChar == 'j') {
        
        Serial.println("camera 1 sonda - direita");
        digitalWrite(com,LOW);
        digitalWrite(m1,LOW);
        digitalWrite(m2,HIGH);
        delay(200);
      
      }


      if (inChar == 'h') {
        
        Serial.println("camera 2 - sobe ");
        motor_cabeca.write(0);
        delay(150);

      }
      if (inChar == 'n') {
        
        Serial.println("camera 2 - desce ");
        motor_cabeca.write(90);

      }

      if (inChar == 'b') {
        
        Serial.println("camera 2 - esquerda ");
                    
      }
      if (inChar == 'm') {
        
        Serial.println("camera 2 - direita ");
       
      }

    }
  }else {
    //Serial.println("\nfalha recebendo os dados do RS485 via porta serial");
  }
  if (i_stop != 0){
    
    Serial.println("\nmotores parado - estado de espera");
    digitalWrite(motorD1,LOW);
    digitalWrite(motorD2,LOW);
    digitalWrite(motorE3,LOW);
    digitalWrite(motorE4,LOW);
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(com,LOW);//*/
  
  }
  //Serial.println("\n------------------------------------");
}
