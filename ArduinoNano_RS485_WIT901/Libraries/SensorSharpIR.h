/* Author: Guilherme Orro- 62 981009520"
 * Date: 30/01/24
 * Sensor SharpIR - detecção de objetos que estejam a uma distância de 10 a 80cm.
 * Versao 1.0 
 */


//Modelo do sensor: 20150 para o GP2Y0A02YK0F, 1080 para o GP2Y0A21Y
#define model 1080  // sensor model GP2Y0A02Y 20150
SharpIR SharpIR(SensorDistanciaPin, model);

// Prototypes
void iniSharpIR();
void get_SensorSharpIR();
void serial_SensorSharpIR();

void iniSharpIR() {
  Serial.println("\nIni. sensor SharpIR\n");
}

void get_SensorSharpIR() {
  fSensorSharpIR = (10650.08 * pow(analogRead(SensorDistanciaPin),-0.935)) - 10;
  //Serial.print("\nSharpIR: "); Serial.println(analogRead(SensorDistanciaPin));
  //serial_SensorSharpIR();
}

void serial_SensorSharpIR() {
  //if (fSensorSharpIR != 0){
    Serial.print("\nSensor SharpIR | Distancia: "); Serial.println(fSensorSharpIR);
  //}
}
