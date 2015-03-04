//sensors
int rightlight;    // variable to read the value from light sensor on A1 (value between 0 and 1023)
int leftlight;     // variable to read the value from light sensor on A0 (value between 0 and 1023)
int bumperleft;    // variable to read the value from switch on D3
int bumperright;   // variable to read the value from switch on D2


void loop()
{
  readsensors();
  if (bumperleft)
  {
    back();
    delay(1000);
    right();
    delay(400);
  }
else if (bumperright)
{
  back();
  delay(1000);
  left();
delay(400);
}
if (leftlight > rightlight + 100)
  {
    left();
    delay(50);
  }
  else if (rightlight > leftlight + 100)
  {
    right();
    delay(50);
  }
  else
  {
    forward();
    delay(500);
  }
  forward();
}

