/* Author: Alexandre Laureano"
 * Date: 23/11/2024
 * Sensor WT901
 * lib: JY901
 * comunicação IIC
 * SDA <---> SDA
 * SCL <---> SCL
 * pino SCL SDA -> Sensor WT901 Arduino UNO
 * pino A4 A5   -> Sensor WT901 Arduino Mini Pro
 * placa: Arduino UNO / Arduino Mini Pro
 */

#include "Wire.h"
#include "JY901.h"

void get_SensorWT901();


void get_SensorWT901(){

  JY901.GetAngle();

  angleX = (float)JY901.stcAngle.Angle[0]/32768*180;
  angleY = (float)JY901.stcAngle.Angle[1]/32768*180;
  angleZ = (float)JY901.stcAngle.Angle[2]/32768*180;

  JY901.GetMag();

  magX = JY901.stcMag.h[0];
  magY = JY901.stcMag.h[1];
  magZ = JY901.stcMag.h[2];

  JY901.GetAcc();

  accX=(float)JY901.stcAcc.a[0]/32768*16;
  accY=(float)JY901.stcAcc.a[1]/32768*16;
  accZ=(float)JY901.stcAcc.a[2]/32768*16;

  JY901.GetGyro();

  gyrX=(float)JY901.stcGyro.w[0]/32768*2000;
  gyrY=(float)JY901.stcGyro.w[1]/32768*2000;
  gyrZ=(float)JY901.stcGyro.w[2]/32768*2000;

  yaw = atan2(magY,magX);

  yaw = yaw * (180/PI);

  if(yaw<0)
  {
    yaw+=360;
  }

  if(yaw>=350 && yaw<=360)
  {
    directCompass = "N";
  }
  else if(yaw>=0 && yaw<=9)
  {
    directCompass = "N";
  }
  else if(yaw>=10 && yaw <=79)
  {
    directCompass = "NE";
  
  }
  else if(yaw>=80 && yaw<=99)
  {
    directCompass = "E";
  }
  else if(yaw>=100 && yaw<169)
  {
    directCompass = "SE";
  }
  else if(yaw>=170 && yaw<=189)
  {
    directCompass = "S";
  }
  else if(yaw>=190 && yaw <=259)
  {
    directCompass = "SW";
  }
  else if(yaw>=260 && yaw <=279)
  {
    directCompass = "W";
  }
  else if (yaw>=280 && yaw <=349)
  {
    directCompass = "NW";
  }



}





