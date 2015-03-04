#include <Servo.h> 
 
//servos
Servo leftservo; 
const int leftservopin = 9;// connect to pin D9
Servo rightservo;  // connect to pin D10
const int rightservopin = 10;// connect to pin D9


void setup() 
{ 
  
} 

void readsensors()
{
  rightlight = analogRead(1);
  leftlight = analogRead(0);
  bumperleft = digitalRead(3);
  bumperright = digitalRead(2);
}

void forward()
{
  //check if the motors are off
  if (!rightservo.attached() || !leftservo.attached())
  {
    leftservo.attach(9);
    rightservo.attach(10);
  }
  rightservo.write(0);
  leftservo.write(180);
}

void back()
{
  //check if the motors are off
  if (!rightservo.attached() || !leftservo.attached())
  {
    leftservo.attach(9);
    rightservo.attach(10);
  }
  rightservo.write(180);
  leftservo.write(0);
}

void left()
{
  //check if the motors are off
  if (!rightservo.attached() || !leftservo.attached())
  {
    leftservo.attach(9);
    rightservo.attach(10);
  }
  rightservo.write(0);
  leftservo.write(0);
}

void right()
{
  //check if the motors are off
  if (!rightservo.attached() || !leftservo.attached())
  {
    leftservo.attach(9);
    rightservo.attach(10);
  }
  rightservo.write(180);
  leftservo.write(180);
}

void halt()
{
  rightservo.detach();
  leftservo.detach();
}

