
int sensorState = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  tone(3, 38000);
}

// the loop function runs over and over again forever
void loop() {
  sensorState = digitalRead(2);
  if (sensorState == LOW){
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);  
  }
}
