/*placa: Arduino UNO R3
  lib: JY901
  TX <---> 0(Rx)
*/

#include "Wire.h"
#include "JY901.h"
#include "JY901.cpp"


void serialEvent();
void get_SensorWT901_TX_RX();
void serial_Angle_TX_RX();
void serial_wt901_TX_RX();
void serial_wt901_original_TX_RX();


/* SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.

 SerialEvent ocorre sempre que novos dados chegam no RX serial do hardware. 
 Esta rotina é executada entre cada execução de loop(), 
 portanto, usar atraso dentro do loop pode atrasar a resposta. Vários bytes de dados podem estar disponíveis.
 */
void serialEvent(){
  while ( Serial.available() ){
    JY901.CopeSerialData(Serial.read()); // Call JY901 data cope function // Chame a função de gerenciamento de dados JY901
  }
}

void get_SensorWT901_TX_RX(){
  angleX = (float)JY901.stcAngle.Angle[0]/32768*180;
  angleY = (float)JY901.stcAngle.Angle[1]/32768*180;
  angleZ = (float)JY901.stcAngle.Angle[2]/32768*180;
  magX = JY901.stcMag.h[0];
  magY = JY901.stcMag.h[1];
  magZ = JY901.stcMag.h[2];
}

void serial_Angle_TX_RX(){
  Serial.print("Angle: "); Serial.println(angleX); //Serial.print(";"); Serial.print(angleY); Serial.print(";"); Serial.println(angleZ);
}

void serial_wt901_TX_RX(){
  //print received data. Data was received in serialEvent;
  angleX = (float)JY901.stcAngle.Angle[0]/32768*180;
  Serial.print("Angle:");Serial.print((float)JY901.stcAngle.Angle[0]/32768*180); Serial.print(";"); //Serial.print((float)JY901.stcAngle.Angle[1]/32768*180);Serial.print(" ");Serial.println((float)JY901.stcAngle.Angle[2]/32768*180);

  Serial.print("Mag:");Serial.print(JY901.stcMag.h[0]);Serial.print(" ");Serial.print(JY901.stcMag.h[1]);Serial.print(" ");Serial.println(JY901.stcMag.h[2]);
  
  Serial.println("");
}

void serial_wt901_original_TX_RX(){
  //print received data. Data was received in serialEvent;
  Serial.print("Time:20");
  Serial.print(JY901.stcTime.ucYear);
  Serial.print("-");Serial.print(JY901.stcTime.ucMonth);Serial.print("-");Serial.print(JY901.stcTime.ucDay);
  Serial.print(" ");Serial.print(JY901.stcTime.ucHour);Serial.print(":");Serial.print(JY901.stcTime.ucMinute);Serial.print(":");Serial.println((float)JY901.stcTime.ucSecond+(float)JY901.stcTime.usMiliSecond/1000);
              
  Serial.print("Acc:");Serial.print((float)JY901.stcAcc.a[0]/32768*16);Serial.print(" ");Serial.print((float)JY901.stcAcc.a[1]/32768*16);Serial.print(" ");Serial.println((float)JY901.stcAcc.a[2]/32768*16);
  Serial.print("Gyro:");Serial.print((float)JY901.stcGyro.w[0]/32768*2000);Serial.print(" ");Serial.print((float)JY901.stcGyro.w[1]/32768*2000);Serial.print(" ");Serial.println((float)JY901.stcGyro.w[2]/32768*2000);
  Serial.print("Angle:");Serial.print((float)JY901.stcAngle.Angle[0]/32768*180);Serial.print(" ");Serial.print((float)JY901.stcAngle.Angle[1]/32768*180);Serial.print(" ");Serial.println((float)JY901.stcAngle.Angle[2]/32768*180);
  Serial.print("Mag:");Serial.print(JY901.stcMag.h[0]);Serial.print(" ");Serial.print(JY901.stcMag.h[1]);Serial.print(" ");Serial.println(JY901.stcMag.h[2]);
  
  Serial.print("Pressure:");Serial.print(JY901.stcPress.lPressure);Serial.print(" ");Serial.println((float)JY901.stcPress.lAltitude/100);
  
  Serial.print("DStatus:");Serial.print(JY901.stcDStatus.sDStatus[0]);Serial.print(" ");Serial.print(JY901.stcDStatus.sDStatus[1]);Serial.print(" ");Serial.print(JY901.stcDStatus.sDStatus[2]);Serial.print(" ");Serial.println(JY901.stcDStatus.sDStatus[3]);
  
  Serial.print("Longitude:");Serial.print(JY901.stcLonLat.lLon/10000000);Serial.print("Deg");Serial.print((double)(JY901.stcLonLat.lLon % 10000000)/1e5);Serial.print("m Lattitude:");
  Serial.print(JY901.stcLonLat.lLat/10000000);Serial.print("Deg");Serial.print((double)(JY901.stcLonLat.lLat % 10000000)/1e5);Serial.println("m");
   
  Serial.print("GPSHeight:");Serial.print((float)JY901.stcGPSV.sGPSHeight/10);Serial.print("m GPSYaw:");Serial.print((float)JY901.stcGPSV.sGPSYaw/10);Serial.print("Deg GPSV:");Serial.print((float)JY901.stcGPSV.lGPSVelocity/1000);Serial.println("km/h");

  Serial.println("");
}

