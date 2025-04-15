//Inits LCD Displays and counts to 100 pretty fast.

// Digital 5 - Increment Ones Counter
// Digibal 8 - Reset Ones counter
// Digital 9 - Tens Reset counter
// Digital 10 - Tens increment counter

void startTone(){
  //mario kart start noise
  tone(2, 600);
  delay(25);
  noTone(2);
  delay(10);
  
  tone(2, 600);
  delay(25);
  noTone(2);
  delay(10);

  tone(2, 600);
  delay(25);
  noTone(2);
  delay(10);

  tone(2, 1000);
  delay(40);
  noTone(2);
  delay(100);
}

void loseTone(){
  //womp womp womp waa
  tone(2, 800);
  delay(25);
  noTone(2);
  delay(6);
  
  tone(2, 700);
  delay(25);
  noTone(2);
  delay(6);

  tone(2, 600);
  delay(25);
  noTone(2);
  delay(6);

  tone(2, 500);
  delay(40);
  noTone(2);
  delay(100);
}

void winTone(){
  //doot doot doot doo
  tone(2, 950);
  delay(15);
  noTone(2);
  delay(1);
  
  tone(2, 950);
  delay(15);
  noTone(2);
  delay(.25);

  tone(2, 950);
  delay(15);
  noTone(2);
  delay(1);

  tone(2, 1300);
  delay(30);
  noTone(2);
  delay(100);
}

void zoomTone(){
  //low high
  tone(2, 600);
  delay(25);
  noTone(2);
  delay(1);
  
  tone(2, 1200);
  delay(25);
  noTone(2);
  delay(100);
}

void panTone(){
  //one long beat
  tone(2, 600);
  delay(45);
  noTone(2);
  delay(100);
}

void snapTone(){
  //three quick beats
  tone(2, 1200);
  delay(5);
  noTone(2);
  delay(2);
  
  tone(2, 1200);
  delay(5);
  noTone(2);
  delay(2);

  tone(2, 1200);
  delay(5);
  noTone(2);
  delay(100);
}

void setup(){
    pinMode(2, OUTPUT);
}

void loop(){


}