#define ECHO 8
#define TRIG 9
#define MY_LED 2

#include <Ultrasonic.h>


Ultrasonic ultrasonic (TRIG, ECHO);
int distance;


void setup() 
{
  Serial.begin(9600);
  pinMode(MY_LED, OUTPUT);
}

void loop() 
{
  distance = ultrasonic.read();
  
  if(distance <= 20)
  {
    digitalWrite(MY_LED, HIGH);
  }
  else
  {
    digitalWrite(MY_LED, LOW);
  }
  
  Serial.print("CM: ");
  Serial.println(distance);
  delay(500);
}
