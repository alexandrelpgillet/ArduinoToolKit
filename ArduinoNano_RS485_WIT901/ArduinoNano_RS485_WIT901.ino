/*********************************************************************/
  #define autor      "Alexandre Laureano"
  #define programa   "Robo inspercao "
  #define versao     "v5.1"
  #define dataversao "23/11/2024"
  #define placa      "Arduino UNO | sensor WT901 lib: JY901 - conexão IIC"
/*********************************************************************/



// Import Libs ------------------------------------------------
#include "config.h"
#include  "SensorWT901_JY901_IIC.h"
#include "SensorSharpIR.h"
#include  "SensorWT901_JY901Serial.h"
#include "RS485_Transmissor.h"

void serial_sensores() {

  Serial.print(fSensorSharpIR); 
  Serial.print(";"); 
  Serial.print(angleX); 
  Serial.print(";"); 
  Serial.print(yaw);
  Serial.print(";");
  Serial.print(directCompass);
  Serial.print("\n");
  
}

void setup(){
  
  //Definindo portas de entrada e saída RS485
  OutputRS485();
 
  Serial.begin(9600);
	
  Serial.println("\nIniciando Serial 9600...");

  //Escrever no serial informações do código  
  initSerial();

  //Iniciar o sensorSharpIR
  iniSharpIR();

  //Iniciar a comunicação com o WIT901
  JY901.StartIIC();

  //Iniciar comunicação RS485
  initRS485();


  Serial.println("Encoder | Angulo | Bússola | Direção da Bussóla ");
} 


void loop(){
  
  //Atualizar dados sensor WIT901
  get_SensorWT901(); 
  
  //Atualizar dados do sensor SharpIR
  get_SensorSharpIR();
  
  //Escrever no serial os seguintes dados : Encoder | Angulo(Inclinação) | Bussola(yaw) | Direção da Bussola
  serial_sensores();
  
  //Envio de dados do Sensor SharpIR para o RS485
  RS485_SensorSharpIR();

  //Envio de dados de inclinação do Sensor WIT901 para o RS485
  RS485_SensorWT901Angle();

  //Envio de dados de Bussola(yaw) para o RS485
  RS485_SensorWT901Mag();

  delay(100);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
}


