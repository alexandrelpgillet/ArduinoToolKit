/* Author: Guilherme Orro- 62 981009520"
 * Serial_Callback
 */
// Prototypes  
void f_Serial_Callback();

void f_Serial_Callback() {
  if (Serial.available() > 0) {
    // lê do buffer o dado recebido:
    incomingByte = Serial.read();
    // responde com o dado recebido:
    // zera contador
    if (incomingByte==52) {
      ENCODER0_pos=0;
      incomingByte=0;
      digitalWrite(RoboAvancarPin, LOW);
      digitalWrite(RoboRetrocederPin, LOW);
    }
    //robo avanca
    if (incomingByte==49) {
      digitalWrite(RoboRetrocederPin, LOW);
      digitalWrite(RoboAvancarPin, HIGH);
    }
    //robo parar
    if (incomingByte==50) {
      digitalWrite(RoboAvancarPin, LOW);
      digitalWrite(RoboRetrocederPin, LOW);
    }
    //robo recua
    if (incomingByte==51) {
      digitalWrite(RoboAvancarPin, LOW);
      digitalWrite(RoboRetrocederPin, HIGH);
    }
    //robo cabeca acima
    if (incomingByte==53) {
      digitalWrite(RoboCabecaCimaPin, HIGH);
      digitalWrite(RoboCabecaBaixoPin, LOW);
      digitalWrite(RoboCabecaEsquerdaPin, LOW);
      digitalWrite(RoboCabecaDireitaPin, LOW);
    }
    //robo cabeca baixo
    if (incomingByte==54) {
      digitalWrite(RoboCabecaCimaPin, LOW);
      digitalWrite(RoboCabecaBaixoPin, HIGH);
      digitalWrite(RoboCabecaEsquerdaPin, LOW);
      digitalWrite(RoboCabecaDireitaPin, LOW);
    }
    //robo cabeca esquerda
    if (incomingByte==55) {
      digitalWrite(RoboCabecaCimaPin, LOW);
      digitalWrite(RoboCabecaBaixoPin, LOW);
      digitalWrite(RoboCabecaEsquerdaPin, HIGH);
      digitalWrite(RoboCabecaDireitaPin, LOW);
    }
    //robo cabeca direita
    if (incomingByte==56) {
      digitalWrite(RoboCabecaCimaPin, LOW);
      digitalWrite(RoboCabecaBaixoPin, LOW);
      digitalWrite(RoboCabecaEsquerdaPin, LOW);
      digitalWrite(RoboCabecaDireitaPin, HIGH);
    }
    //robo cabeca parar
    if (incomingByte==57) {
      digitalWrite(RoboCabecaCimaPin, LOW);
      digitalWrite(RoboCabecaBaixoPin, LOW);
      digitalWrite(RoboCabecaEsquerdaPin, LOW);
      digitalWrite(RoboCabecaDireitaPin, LOW);
    }
  }
}