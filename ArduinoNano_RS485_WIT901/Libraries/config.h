/* Author: Guilherme Orro- 62 981009520"
 * Settings / Configurações
 */
/*Arduino Mini Pro - ROBÔ 
  pino A1  -> RS485_RX (RO 0)
  pino A2  -> RS485_TX (DI 1)
  pino A3  -> RS485 | Transmissor ou Receptor
  pino A0 -> Sensor SharpIR
  Pino SDA A4 -> Sensor WT901
  Pino SCL A5 -> Sensor WT901
*/

// Pinos de comunicacao serial do modulo RS485
#define Pino_RS485_RX  A2  // RO 0 11
#define Pino_RS485_TX  A1  // DI 1 10

#include "SharpIR.h"
#include "SharpIR.cpp"
#include <Servo.h> 


void initSerial();
// Pinagem--------------------------------------------------
const int pinoLedonboard = 13;
const int EnTxPin =  A3;   // Pino de habilitação da transmissão e recepção de dados

byte estado1 = 0, cont1 = 0, estado2 = 0, cont2 = 0;

// Sensor SharpIR
const int SensorDistanciaPin = A0; //A2
float fSensorSharpIR = 0;

// Sensor WT901
float angleX,angleY,angleZ,angleW;
float magX,magY,magZ;
float accX , accY, accZ;
float gyrX, gyrY , gyrZ;
float yaw;

//Direção da Bussola
String directCompass = "NULL";

// Serial
int incomingByte = 0;

//Variaveis do Motor de Tração
int motorD1=6; // orig 6
int motorD2=7; // orig 7
int motorE3=8; // orig 8
int motorE4=9; // orig 9



//Variaveis da cabeça sonda
int m1=5;  // orig 3 | setado direto 10
int m2=4;  // orig 4 | setado direto 11
int com=5; // orig 5

//Variaveis da  camera 2
int i=90;
int j=60;

//Variaveis do servo motor
Servo motor_base_cabeca;
Servo motor_cabeca;



void initSerial(){
  Serial.print(F("Autor:       ")); Serial.println(autor);
  Serial.print(F("Sistema:     ")); Serial.print(programa); Serial.println(versao);
  Serial.print(F("Data versao: ")); Serial.println(dataversao);
  Serial.print(F("Placa:       ")); Serial.println(placa);

}
