/* Author: Guilherme Orro- 62 981009520"
 * ENCODER e30A
 */
// Prototypes
void doEncoder();
void OutputEncoder();
void iniEncoder();
void serial_encoder();

void doEncoder() {
  if (digitalRead(ENCODER0_PINA) == digitalRead(ENCODER0_PINB)) {
    ENCODER0_pos --;
  } else {
    ENCODER0_pos ++;
  }
}
void OutputEncoder(){
  pinMode(ENCODER0_PINA, INPUT);
  digitalWrite(ENCODER0_PINA, HIGH);     // Turn on pullup resistor
  pinMode(ENCODER0_PINB, INPUT);
  digitalWrite(ENCODER0_PINB, HIGH);     // Turn on pullup resistor
  pinMode(EnTxPin, OUTPUT);
}

void iniEncoder() {
  Serial.print("\nIniciando Encoder\n");
  Serial.println("Pino 2 | 3\n");
  attachInterrupt(digitalPinToInterrupt(ENCODER0_PINA), doEncoder, CHANGE);  // Encoder pin on interrupt 0 (pin 2) CHANGE codigo original
  //attachInterrupt(digitalPinToInterrupt(ENCODER0_PINA), doEncoder, RISING);  // Encoder pin on interrupt 0 (pin 2)
}

// the loop function runs over and over again forever
void serial_encoder() {
  if (ENCODER0_pos != ENCODER0_pos_ant){
    ENCODER0_pos_ant = ENCODER0_pos;
    Serial.print("Encoder: ");  Serial.print(ENCODER0_pos,DEC); // IMPRIME NO MONITOR SERIAL A POSIÇÃO ATUAL DO ENCODER
    Serial.println();
  }
}
