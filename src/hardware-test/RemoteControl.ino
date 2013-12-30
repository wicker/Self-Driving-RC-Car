// by wicker

#include "DualVNH5019MotorShield.h"
#include <ServoTimer2.h>
#include <SoftwareSerial.h>

#define MIN_PULSE  750
#define MAX_PULSE  2250

SoftwareSerial inSerial(0,1);

DualVNH5019MotorShield md;
ServoTimer2 servo;
int servoPin = 3;

int val0 = 0;
int val1 = 500;
int val2 = 1023;
int inByte = 0;

void setup()
{
  servo.attach(servoPin);
  
  inSerial.begin(9600);
  Serial.begin(9600);
  
  md.init();

  val0 = map(val0, 0, 1023, MIN_PULSE , MAX_PULSE );     // scale it to use it with the servo  
  val1 = map(val1, 0, 1023, MIN_PULSE , MAX_PULSE );     // scale it to use it with the servo  
  val2 = map(val2, 0, 1023, MIN_PULSE , MAX_PULSE );     // scale it to use it with the servo
 
}

void loop()
{
a  if (inSerial.available() > 0) {
    inByte = inSerial.read();
    
    if (inByte == 97)        // a
      servo.write(val0);
    else if (inByte == 115)  // s
      servo.write(val1);
    else if (inByte == 100)  // d
      servo.write(val2);
    else
      Serial.println(inByte);
  }
}
