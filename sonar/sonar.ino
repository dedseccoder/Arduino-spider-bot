#define ECHO 8
#define TRIG 9
#define MY_LED 2

#include <Ultrasonic.h>
#include <GyverOLED.h>

GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
Ultrasonic ultrasonic (TRIG, ECHO);
int distance;


void setup() 
{
  Serial.begin(9600);
  oled.init();
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

  WriteOledDistance(distance);
  
  Serial.println(distance);
  delay(500);
}

void WriteOledDistance(int cm)
{
  oled.clear();  
  oled.setScale(3);
  oled.setCursorXY(10, 25);
  
  oled.print("CM: ");
  oled.println(distance);
  
  oled.update();
  delay(500);
}
