const int OutA = 6;
const int OutB = 7;
const int LedPIN = 8;

void setup() {
  pinMode(OutA, INPUT);
  pinMode(OutB, INPUT);
  pinMode(LedPIN, OUTPUT);
}

void loop() {
  int state1 = digitalRead(OutA);
  int state2 = digitalRead(OutB);

  if(state1 == LOW || state2 == LOW)
  {
    digitalWrite(LedPIN, HIGH);
  } 
  else 
  {
    digitalWrite(LedPIN, LOW);
  }
}
