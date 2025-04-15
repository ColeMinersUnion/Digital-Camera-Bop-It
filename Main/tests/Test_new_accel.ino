#include <Wire.h>

#define MODE 1

const byte a1 = 0;
const byte b1 = 1;
const byte c1 = 2;
const byte d1 = 3;
const byte e1 = 4;
const byte f1 = 5;
const byte g1 = 6;
const byte a2 = 7;
const byte b2 = 8;
const byte c2 = 9;
const byte d2 = 10;
const byte e2 = 11;
const byte f2 = 12;
const byte g2 = 13;

float AccX, AccY, AccZ;
const int MPU = 0x68; // MPU6050 I2C address


void outputOnes(unsigned n){
  //isolate for ones
  unsigned x = n % 10;
  switch(x){
    case 1:
    //bc
    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, HIGH);
    digitalWrite(e1, HIGH);
    digitalWrite(f1, HIGH);
    digitalWrite(g1, HIGH);

    break;

    case 2:
    //abdeg
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(c1, HIGH);
    digitalWrite(d1, LOW);
    digitalWrite(e1, LOW);
    digitalWrite(f1, HIGH);
    digitalWrite(g1, LOW);

    break;

    case 3:
    //abcdg
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(e1, HIGH);
    digitalWrite(f1, HIGH);
    digitalWrite(g1, LOW);

    break;

    case 4:
    //bcfg
    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, HIGH);
    digitalWrite(e1, HIGH);
    digitalWrite(f1, LOW);
    digitalWrite(g1, LOW);

    break;

    case 5:
    //acdfg
    digitalWrite(a1, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(c1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(e1, HIGH);
    digitalWrite(f1, LOW);
    digitalWrite(g1, LOW);

    break;

    case 6:
    //acdefg
    digitalWrite(a1, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(c1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(e1, LOW);
    digitalWrite(f1, LOW);
    digitalWrite(g1, LOW);

    break;

    case 7:
    //abc
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, HIGH);
    digitalWrite(e1, HIGH);
    digitalWrite(f1, HIGH);
    digitalWrite(g1, HIGH);

    break;

    case 8:
    //abcdefg
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(e1, LOW);
    digitalWrite(f1, LOW);
    digitalWrite(g1, LOW);

    break;

    case 9:
    //abcdfg
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(e1, HIGH);
    digitalWrite(f1, LOW);
    digitalWrite(g1, LOW);

    break;

    case 0:
    //abcdef
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(e1, LOW);
    digitalWrite(f1, LOW);
    digitalWrite(g1, HIGH);

    break;

  }
}

void outputTens(unsigned n){
  //isolate for tens
  unsigned x = (n/10U) % 10;
  switch(x){
    case 1:
    //bc
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(c2, LOW);
    digitalWrite(d2, HIGH);
    digitalWrite(e2, HIGH);
    digitalWrite(f2, HIGH);
    digitalWrite(g2, HIGH);

    break;

    case 2:
    //abdeg
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(c2, HIGH);
    digitalWrite(d2, LOW);
    digitalWrite(e2, LOW);
    digitalWrite(f2, HIGH);
    digitalWrite(g2, LOW);

    break;

    case 3:
    //abcdg
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(c2, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(e2, HIGH);
    digitalWrite(f2, HIGH);
    digitalWrite(g2, LOW);

    break;

    case 4:
    //bcfg
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(c2, LOW);
    digitalWrite(d2, HIGH);
    digitalWrite(e2, HIGH);
    digitalWrite(f2, LOW);
    digitalWrite(g2, LOW);

    break;

    case 5:
    //acdfg
    digitalWrite(a2, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(c2, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(e2, HIGH);
    digitalWrite(f2, LOW);
    digitalWrite(g2, LOW);

    break;

    case 6:
    //acdefg
    digitalWrite(a2, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(c2, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(e2, LOW);
    digitalWrite(f2, LOW);
    digitalWrite(g2, LOW);

    break;

    case 7:
    //abc
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(c2, LOW);
    digitalWrite(d2, HIGH);
    digitalWrite(e2, HIGH);
    digitalWrite(f2, HIGH);
    digitalWrite(g2, HIGH);

    break;

    case 8:
    //abcdefg
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(c2, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(e2, LOW);
    digitalWrite(f2, LOW);
    digitalWrite(g2, LOW);

    break;

    case 9:
    //abcdfg
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(c2, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(e2, HIGH);
    digitalWrite(f2, LOW);
    digitalWrite(g2, LOW);

    break;

    case 0:
    //abcdef
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(c2, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(e2, LOW);
    digitalWrite(f2, LOW);
    digitalWrite(g2, HIGH);

    break;

  }
}


void update_Acceleration(){
    Wire.beginTransmission(MPU);
    Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
    //For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet
    AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
    AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
    AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value
}

void setup() {
  Serial.begin(19200);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission
  delay(20);
}

void loop(){
  update_Acceleration();
  unsigned int one;
  unsigned int ten;
  if(MODE==1){
    //Print AccX to driver boards
    one = int(AccX) % 10;
    ten = int(AccX/10) % 10;
  }else if(MODE == 2){
    one = int(AccX) % 10;
    ten = int(AccX/10) % 10;
  }else if(MODE == 3){
    one = int(AccX) % 10;
    ten = int(AccX/10) % 10;
  }else{
    one = 9;
    ten = 9;
  }
  outputOnes(one);
  outputTens(ten);
  //delay(100);

}