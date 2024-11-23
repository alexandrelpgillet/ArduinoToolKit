/* Author: Guilherme Orro- 62 981009520"
 * Date: 14/02/24
 * Settings / Configurações
 */
 /*1 Arduino Nano
  pino A1  -> RS485_RX (RO 0)
  pino A2  -> RS485_TX (DI 1)
  pino A3  -> RS485 | Transmissor ou Receptor
*/

void initSerial();
// Pinagem--------------------------------------------------
const int pinoLedonboard = 13;

const int RoboAvancarPin = 8;        //ROBO AVANCAR
const int RoboRetrocederPin = 9;     //ROBO RETROCEDER
const int RoboCabecaCimaPin = 4;     //ROBO CABEÇA CIMA
const int RoboCabecaBaixoPin = 5;    //ROBO CABEÇA BAIXO
const int RoboCabecaEsquerdaPin = 6; //ROBO CABEÇA ESQUERDA
const int RoboCabecaDireitaPin = 7;  //ROBO CABEÇA DIREITA
const int RoboCabecaPararPin = 10;   //ROBO CABEÇA PARAR

#define ENCODER0_PINA 2
#define ENCODER0_PINB 3
volatile long ENCODER0_pos,ENCODER0_pos_ant = 0;

// Pinos de comunicacao serial do modulo RS485
#define Pino_RS485_RX  A4  // RO 1 10 A2
#define Pino_RS485_TX  A2  // DI 0 11 A1
const int EnTxPin = A3;    // pino de habilitação da transmissao e recepcao de dados
byte estado1 = 0, cont1 = 0, estado2 = 0, cont2 = 0;
//SoftwareSerial RS485Serial(Pino_RS485_RX, Pino_RS485_TX); // Cria a serial por sofware para conexao com modulo RS485

// Serial
int incomingByte = 0;

// Sensores
float angleX;
float yaw;
float fSensorSharpIR;
String directCompass = "NULL";

void initSerial(){
  Serial.print(F("Autor:       ")); Serial.println(autor);
  Serial.print(F("Sistema:     ")); Serial.print(programa); Serial.println(versao);
  Serial.print(F("Data versao: ")); Serial.println(dataversao);
  Serial.print(F("Placa:       ")); Serial.println(placa);
}