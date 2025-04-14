#include <Wire.h>

/*
Registers:

X Acceleration
0x0E - MSB
0x0D - LSB

Y Acceleration
0x10 - MSB
0x0F - LSB

Z Acceleration
0x12 - MSB
0x11 - LSB

*/

//I2C Information
/*

7 Bit Device ID     0x4C    0x6C
8b Write Addr       0x98    0xD8
ob Read Addr        0x99    0xD9
Dout on Power Up    GND     VCC

*/

/*
Timing Characteristics
M. Device ID
M. Register & Restart
M. Device ID
S. Data

*/

int getXAccel(){
    Wire.beginTransmission(0x4C);
    Wire.write(0x0D);
    Wire.endTransmission();
    Wire.requestFrom(0x4C, 2);
    int xAccel = 0;
    if(Wire.available() == 2){
        byte xAccelMSB = Wire.read();
        byte xAccelLSB = Wire.read();
        xAccel = (xAccelMSB << 8) | xAccelLSB;
    }
    return xAccel;
}

int getYAccel(){
    Wire.beginTransmission(0x4C);
    Wire.write(0x0F);
    Wire.endTransmission();
    Wire.requestFrom(0x4C, 2);
    int yAccel = 0;
    if(Wire.available() == 2){
        byte yAccelMSB = Wire.read();
        byte yAccelLSB = Wire.read();
        yAccel = (yAccelMSB << 8) | yAccelLSB;
    }
    return yAccel;
}

int getZAccel(){
    Wire.beginTransmission(0x4C);
    Wire.write(0x11);
    Wire.endTransmission();
    Wire.requestFrom(0x4C, 2);
    int zAccel = 0;
    if(Wire.available() == 2){
        byte zAccelMSB = Wire.read();
        byte zAccelLSB = Wire.read();
        zAccel = (zAccelMSB << 8) | zAccelLSB;
    }
    return zAccel;
}