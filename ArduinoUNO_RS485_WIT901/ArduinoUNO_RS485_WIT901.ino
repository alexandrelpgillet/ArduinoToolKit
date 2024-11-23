/*********************************************************************/
  #define autor      "Alexandre Laureano"
  #define programa   "Robo inspercao "
  #define versao     "v5.1"
  #define dataversao "29/08/2024"
  #define placa      "Arduino Nano | Receptor"
/*********************************************************************/

// Libs import------------------------------------------------
#include "config.h"
#include "RS485_receptor.h"
#include "serialCallback.h"
#include "encoder_e30A.h"




void serial_sensores() {


    Serial.print(ENCODER0_pos,DEC); 
    Serial.print(";");
    Serial.print(fSensorSharpIR);
    Serial.print(";");
    Serial.print(angleX);
    Serial.print(";");
    Serial.print(yaw);
    Serial.print(";");
    Serial.print(directCompass);
    Serial.print("\n");
}

void setup() {
  
  angleX=0;
  yaw=0;
  fSensorSharpIR=0;

  // Definindo Status de Entrada/Saída do Encoder
  OutputEncoder();

  //Difindo Pinos de Saída do serialCallback.h
  pinMode(RoboAvancarPin, OUTPUT);
  pinMode(RoboRetrocederPin, OUTPUT);
  pinMode(13, OUTPUT);

  //Habilitando modos de recepção
  digitalWrite(EnTxPin, LOW); 
  
  Serial.begin(9600);
  Serial.print("\nIniciando Serial 9600...\n");
  
  //Dados do código
  initSerial();
  
  //Iniciando comunicação RS485
  initRS485();
  
  //Iniciando Encoder
  iniEncoder();
  
  Serial.println("\nEncoder | SensorSharpIR | Angulo | Bússola(yaw) | Direção da Bússola\n");
}

void loop() {

  
  //Verificando se o Serial tem dados disponíveis na porta
  if(Serial.available()>0)
  {
    //Leitura da entrada do Serial
    String input = Serial.readStringUntil('\n');
    
    //Retornar ao serial um sinal "RECEIVE" 

    if(input == "SEND")
    {
      
         
        Serial.println("RECEIVE");   
        delay(500);

    }
  }


  recebe_serial_rs485();

  serial_sensores();

  delay(500);
}

