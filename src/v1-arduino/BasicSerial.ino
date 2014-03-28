// From basic Arduino documentation

#include <SoftwareSerial.h>

int incomingByte = 0;   // for incoming serial data
SoftwareSerial inSerial(0,1);

void setup() {
  Serial.begin(9600);   // opens serial port, sets data rate
  inSerial.begin(9600);

}

void loop() {
    // send data only when you receive data:
    if (inSerial.available() > 0) {
        // read the incoming byte:
        incomingByte = inSerial.read();

        // say what you got:
        Serial.print("I received: ");
        Serial.println(incomingByte, DEC);
    }
}
