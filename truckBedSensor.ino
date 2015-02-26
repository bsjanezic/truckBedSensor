/*

Truck bed sensor
- Reads value of ultrasonic and looks for deviation
- if deviation is greater than 60cm trigger output
*/
//#include <SPI.h>
#include <NewPing.h>

#define PING_ONE 3
#define ledPin 10

int pingDistance =000;
int newPingDistance =000;
int bedSensed = 0;
NewPing pingOne(PING_ONE, PING_ONE, 300);

void setup(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pingDistance = pingUltrasonic();
  Serial.begin(9600);
}
void loop()
{
  newPingDistance = pingUltrasonic();
  if(((newPingDistance - pingDistance) > 59) && bedSensed != 1)
  {
    // recognized truck bed now turn off wax
    bedSensed = 1;
    Serial.println("Truck bed");
    
    digitalWrite(ledPin, HIGH);
  }
  pingDistance = newPingDistance;
  delay(1000);
}
int pingUltrasonic(){
  unsigned int uS = pingOne.ping_median(15);
  int sensorDistance = (uS/US_ROUNDTRIP_CM);
  Serial.println(sensorDistance);
  return sensorDistance;
  
}

