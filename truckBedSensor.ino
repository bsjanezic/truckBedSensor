/*

Truck bed sensor
- Reads value of ultrasonic and looks for deviation
- if deviation is greater than 29com trigger output
- modified to use maxbotics sensor
*/
//#include <SPI.h>
//#include <NewPing.h>

#define sensorPin 3
#define ledPin 10

long pingDistance =000;
long newPingDistance =000;
int bedSensed = 0;


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
    // recognized truck bed or end of car
    bedSensed = 1;
    Serial.println("Truck bed");
    
    digitalWrite(ledPin, HIGH);
  }
  pingDistance = newPingDistance;
  delay(100);
}
long pingUltrasonic(){
  int readingCount = 15;
  long averageDistance =0;
  for (int i=0; i< readingCount; i++)
  {
    long uS = pulseIn(sensorPin, HIGH);
    long sensorDistance = uS/59; // round trip
   // valueArray[i] = sensorDistance;
    averageDistance = averageDistance+sensorDistance;  
}
  averageDistance = averageDistance/readingCount;
  Serial.println(averageDistance);
  return averageDistance;
  
}


