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

double time_per_instruction = 5000;  //ms

int Score;

void setup() {
  //rot inputs
  pinMode(OutA, INPUT);
  pinMode(OutB, INPUT);
  //Shoot
  pinMode(Shoot, INPUT);
  //Start
  pinMode(START_BUTTON, INPUT);

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

void loop() {
  //Wait for start button
  while (!digitalRead(START_BUTTON)) {
  }
  
  startTone();
  //Game init
  Wire.beginTransmission(0x08);  // Match slave address
  Wire.write(Score);             // Send number
  Wire.endTransmission();

  for (int i = 0; i < 99; i++) {     //instruction count
    int instruction = random(0, 2);  //random number between 0 and 2
    delay(0.05 * time_per_instruction);
    if (instruction == 1) {
      panTone();
      readAccelerometer();

      int dx = abs(ax - last_ax);
      int dy = abs(ay - last_ay);
      int dz = abs(az - last_az);
      if (!Shake && millis() - startTime <= time_per_instruction) {
        if (dx > threshold || dy > threshold || dz > threshold) {
          Score++;
          time_per_instruction = time_per_instruction * .99;

          delay(0.9*time_per_instruction);
          Wire.beginTransmission(0x08);  // Match slave address
          Wire.write(Score);             // Send number
          Wire.endTransmission();

          // Update last values
          last_ax = ax;
          last_ay = ay;
          last_az = az;

          //delay(100);
          Shake = true;
        }
      }
      if (millis() - startTime > time_per_instruction && !Shake) {
        loseTone();
        break;
      }
      Shake = false;
    } else if (instruction == 2) {
      zoomTone();
      int state1 = digitalRead(OutA);
      int state2 = digitalRead(OutB);

      if (!Turn && millis() - startTime <= time_per_instruction) {
        if (state1 == LOW || state2 == LOW) {
          Score++;
          time_per_instruction = time_per_instruction * .99;

          delay(0.9*time_per_instruction);
          Wire.beginTransmission(0x08);  // Match slave address
          Wire.write(Score);             // Send number
          Wire.endTransmission();

          Turn = true;
        }
      }
      // Game Over
      if (millis() - startTime > time_per_instruction && !Turn) {
        loseTone();
        break;
      }
      Turn = false;
    } else if (instruction == 0) {
      snapTone();
      if (!ShootPressed && millis() - startTime <= time_per_instruction) {
        if (digitalRead(Shoot) == HIGH) {
          Score++;
          time_per_instruction = time_per_instruction * .99;

          delay(0.9*time_per_instruction);
          Wire.beginTransmission(0x08);  // Match slave address
          Wire.write(Score);             // Send number
          Wire.endTransmission();

          ShootPressed = true;
        }
      }

      // Game Over
      if (millis() - startTime > time_per_instruction && !ShootPressed) {
        loseTone();
        break;
      }

      ShootPressed = false;
    }
  }
}
