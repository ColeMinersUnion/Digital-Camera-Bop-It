//Testing acceleration

#define AXIS = 0 //0 for x, 1 for y, 2 for z

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

#define Ones 5
#define Tens 10
#define ResetOnes 8
#define ResetTens 9



int OnesVal = 0;
int TensVal = 0;
int TotalVal = 0;

void incrementCount(){
    if(OnesVal != 9){
        digitalWrite(Ones, HIGH);
        delay(10);
        digitalWrite(Ones, LOW);
        OnesVal++;
    } else {
        digitalWrite(ResetOnes, HIGH);
        delay(10);
        digitalWrite(ResetOnes, LOW);
        OnesVal = 0;
        if(TensVal != 9){
            digitalWrite(Tens, HIGH);
            delay(10);
            digitalWrite(Tens, LOW);
            TensVal++;
        } else {
            digitalWrite(ResetTens, HIGH);
            delay(10);
            digitalWrite(ResetTens, LOW);
            TensVal = 0;
        }
    }
}

void setup(){

}

void loop(){
    int Accel;
    if(AXIS == 0){
        Accel = getXAccel();
    } else if(AXIS == 1){
        Accel = getYAccel();
    } else if(AXIS == 2){
        Accel = getZAccel();
    }
    for(int i = 0; i < Accel; i++){
        incrementCount();
    }
    delay(1000)
}

