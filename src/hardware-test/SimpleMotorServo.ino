#include "DualVNH5019MotorShield.h"
#include <ServoTimer2.h>

#define MIN_PULSE  750
#define MAX_PULSE  2250

DualVNH5019MotorShield md;
ServoTimer2 servo;
int servoPin = 3;

  int val0 = 0;
  int val1 = 500;
  int val2 = 1023;

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
}

void setup()
{
  servo.attach(servoPin);
  Serial.begin(115200);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();

  val0 = map(val0, 0, 1023, MIN_PULSE , MAX_PULSE );     // scale it to use it with the servo  
  val1 = map(val1, 0, 1023, MIN_PULSE , MAX_PULSE );     // scale it to use it with the servo  
  val2 = map(val2, 0, 1023, MIN_PULSE , MAX_PULSE );     // scale it to use it with the servo
 
}

void loop()
{

  servo.write(val0);
  delay(100);
  Serial.println("Sent 0 to servo.");
  md.setM1Speed(80);
  stopIfFault();
  delay(2000);
  
  md.setM1Speed(0);
  delay(3000);
  
  servo.write(val2);
  delay(100);
  Serial.println("Sent 180 to servo.");
  md.setM1Speed(-80);
  stopIfFault();
  delay(2000);
  
  md.setM1Speed(0);
  delay(3000);
  
return;

  for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }
  
//  for (int i = 400; i >= -400; i--)
  for (int i = 100; i >= -100; i--)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }

//  for (int i = 0; i <= 400; i++)
  for (int i = 0; i <= 100; i++)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }
  
  
//  for (int i = 400; i >= -400; i--)
    for (int i = 100; i >= -100; i--)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }
  
 // for (int i = -400; i <= 0; i++)
  for (int i = -100; i <= 0; i++)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }
}
