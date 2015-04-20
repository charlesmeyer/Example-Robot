#include <Servo.h> //Code to run the servos
//Set up names for numbers we want to store (variables)
Servo leftservo;
Servo rightservo;
int rightIR;
int leftIR;
int edgeSensor;

void setup() { 
  pinMode(2, INPUT); //Set IR sensors pins
  pinMode(4, INPUT);
  leftservo.attach(9); //Set servo pins
  rightservo.attach(10);
  tone(3, 38000); //Start IR signal
} 

void loop() {
  //Read sensors
  leftIR = digitalRead(2);
  rightIR = digitalRead(4);
  if (rightIR == HIGH && leftIR == LOW) {
    //Robot to the left, so turn
    leftservo.write(0);
    rightservo.write(0);
  }
  else if (rightIR == LOW && leftIR == HIGH) {
    //Robot to the right, so turn
    leftservo.write(180);
    rightservo.write(180);
  }
  else if (rightIR == LOW && leftIR == LOW) {
    //Robot ahead, so push it
    leftservo.write(180);
    rightservo.write(0);
  }
  else {
    //No robot detected, so check edge sensor
    edgeSensor = analogRead(A0);
    if (edgeSensor > 90) {
      //White line, backup and turn
      leftservo.write(0);
      rightservo.write(180);
      delay(100);
      leftservo.write(0);
      rightservo.write(0);
      delay(200);
    }
    else {
      //Nothing detected, so just go forward
      leftservo.write(180);
      rightservo.write(0);
    }
  }
}

