#include <Wire.h>

//Rot
const int OutA = 6;

const int OutB = 7;
//Push Button
const int Shoot = 5;
//I2C Stuff
const int threshold = 0;
const int MPU_ADDR = 0x68;  // MPU6050 I2C address
int16_t ax, ay, az;
int16_t last_ax = 0, last_ay = 0, last_az = 0;
//Start Button
const int START_BUTTON = 4;
//speaker
const int Speaker = 2;

unsigned long startTime;

bool ShootPressed = false;
bool Turn = false;
bool Shake = false;

double time_per_instruction = 1000;  //ms

int Score;

void setup() {
  randomSeed(analogRead(0));
  //rot inputs
  pinMode(OutA, INPUT);
  pinMode(OutB, INPUT);
  //Shoot
  pinMode(Shoot, INPUT);
  //Start
  pinMode(START_BUTTON, INPUT_PULLUP);

  //start timer
  startTime = millis();

  //I2C
  Wire.begin();  // I2C as master

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void readAccelerometer() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);  // Starting register for accelerometer readings
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);  // Request 6 bytes

  ax = (Wire.read() << 8 | Wire.read()) / 16384.0;  // X-axis
  ay = (Wire.read() << 8 | Wire.read()) / 16384.0;  // Y-axis
  az = (Wire.read() << 8 | Wire.read()) / 16384.0;  // Z-axis
}

void startTone(){
  //mario kart start noise
  tone(2, 600);
  delay(250);
  noTone(2);
  delay(10);
  
  tone(2, 600);
  delay(250);
  noTone(2);
  delay(100);

  tone(2, 600);
  delay(250);
  noTone(2);
  delay(100);

  tone(2, 1000);
  delay(400);
  noTone(2);
  delay(1000);
}

void loseTone(){
  //womp womp womp waa
  tone(2, 800);
  delay(250);
  noTone(2);
  delay(60);
  
  tone(2, 700);
  delay(250);
  noTone(2);
  delay(60);

  tone(2, 600);
  delay(250);
  noTone(2);
  delay(60);

  tone(2, 500);
  delay(400);
  noTone(2);
  delay(1000);
}

void winTone(){
  //doot doot doot doo
  tone(2, 950);
  delay(150);
  noTone(2);
  delay(10);
  
  tone(2, 950);
  delay(150);
  noTone(2);
  delay(2.5);

  tone(2, 950);
  delay(150);
  noTone(2);
  delay(10);

  tone(2, 1300);
  delay(300);
  noTone(2);
  delay(1000);
}

void zoomTone(){
  //low high
  tone(2, 600);
  delay(250);
  noTone(2);
  delay(10);
  
  tone(2, 1200);
  delay(250);
  noTone(2);
  delay(1000);
}

void panTone(){
  //one long beat
  tone(2, 600);
  delay(450);
  noTone(2);
  delay(1000);
}

void snapTone(){
  //three quick beats
  tone(2, 1200);
  delay(50);
  noTone(2);
  delay(20);
  
  tone(2, 1200);
  delay(50);
  noTone(2);
  delay(20);

  tone(2, 1200);
  delay(50);
  noTone(2);
  delay(100);
}

void loop() {
  //Wait for start button
  if(digitalRead(START_BUTTON)){
    startTone();
   //Game init
  //  Wire.beginTransmission(0x08);  // Match slave address
  // Wire.write(Score);             // Send number
  // Wire.endTransmission();

   for (int i = 0; i < 99; i++) {     //instruction count
    int instruction = random(0, 2);  //random number between 0 and 1
    delay(time_per_instruction);
    if (instruction == 1) {
      panTone();
      unsigned long instructionStart = millis();
      while (!Shake && millis() - instructionStart <= time_per_instruction) {
        readAccelerometer();
        int dx = abs(ax - last_ax);
        int dy = abs(ay - last_ay);
        int dz = abs(az - last_az);
        if (dx > threshold || dy > threshold || dz > threshold) {
          Score++;
          digitalWrite(12, HIGH);
          delay(100);
          digitalWrite(12, LOW);
          time_per_instruction = time_per_instruction * .99;

          //delay(0.9*time_per_instruction);
          //Wire.beginTransmission(0x08);  // Match slave address
          //Wire.write(Score);             // Send number
          //Wire.endTransmission();

          // Update last values
          last_ax = ax;
          last_ay = ay;
          last_az = az;

          //delay(100);
          Shake = true;
        }
      }
      if (millis() - instructionStart > time_per_instruction && !Shake) {
        loseTone();
        break;
      }
      Shake = false;
    } else if (instruction == 2) {
      zoomTone();
      unsigned long instructionStart = millis();
      int state1 = digitalRead(OutA);
      int state2 = digitalRead(OutB);

      while (!Turn && millis() - startTime <= time_per_instruction) {
        if (state1 == LOW || state2 == LOW) {
          Score++;
          time_per_instruction = time_per_instruction * .99;

         // delay(0.9*time_per_instruction);
         // Wire.beginTransmission(0x08);  // Match slave address
         // Wire.write(Score);             // Send number
         // Wire.endTransmission();

          Turn = true;
        }
      }
      // Game Over
      if (millis() - instructionStart > time_per_instruction && !Turn) {
        loseTone();
        break;
      }
      Turn = false;
    } else if (instruction == 0) {
      snapTone();
      
      unsigned long instructionStart = millis();


      while(!ShootPressed && millis() - instructionStart < time_per_instruction) {
        if (digitalRead(Shoot)) {
          Score++;
          time_per_instruction = time_per_instruction * .99;
          digitalWrite(12, HIGH);
          delay(1000);
          digitalWrite(12, LOW);
         // delay(0.9*time_per_instruction);
          //Wire.beginTransmission(0x08);  // Match slave address
         // Wire.write(Score);             // Send number
         // Wire.endTransmission();

          ShootPressed = true;
        }
        
      }

      // Game Over
      if (millis() - instructionStart > time_per_instruction && !ShootPressed) {
        loseTone();
        break;
      }

      ShootPressed = false;
    }
  }
  }
}