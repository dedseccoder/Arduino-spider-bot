#include <Servo.h>

int val;
int LED = 13;
int servoPin1 = 9;
int servoPin2 = 7;
int servoPin3 = 11;

Servo servo1;
Servo servo2;
Servo servo3;

void setup()
{
  Serial.begin(9600);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    if (val == '0') //дефолтное положение для всего
    {
     servo3.write(90);
     delay (1000);
     servo1.write(90);
     servo2.write(90);
     delay (1000);
    }
    else if (val == '1') //поднятие правой ноги
    {
     servo3.write (65);
     delay (1000);
    }
    else if ( val == '2')//поднятие левой ноги
    {
     servo3.write (115);
     delay (1000);
    }
    else if (val == '3')  //правая нога вперед
    {
     servo1.write (130);
     delay (1000);
    }
    else if (val == '4') //левая нога впред
    {
     servo2.write (50);
     delay (1000);
    }
    else if (val == '5') // правая нога дефолт
    {
      servo1.write (90);
      delay (1000);
    }
    else if (val == '6') // левая нога дефолт
    {
      servo2.write (90);
      delay (1000);
    }
    else if (val == '8')
    {
     servo1.write (0);
     delay (1000);
     servo1.write (180);
     delay (1000);
    }
    else if ( val == '9')
    {
     servo2.write (0);
     delay (1000);
     servo2.write (180);
     delay (1000);
    }
   }
  }
