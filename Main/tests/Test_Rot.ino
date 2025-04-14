//Increment the ones for one direction and increment the tens for the other direction

//Inits LCD Displays and counts to 100 pretty fast.

// Digital 5 - Increment Ones Counter
// Digibal 8 - Reset Ones counter
// Digital 9 - Tens Reset counter
// Digital 10 - Tens increment counter
// Digibal 2 - Out B Rotary Encoder 
// Digital 4 - Out A Rotary Encoder

#define Ones 5
#define Tens 10
#define ResetOnes 8
#define ResetTens 9

#define OutA = 4
#define OutB = 2

int counter = 0;
int currentStateA;
int lastStateA;
bool dir = null;

int OnesVal = 0;
int TensVal = 0;
int TotalVal = 0;

void incrementOnes(){
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
    }
}

void incrementTens(){
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

void setup(){
    pinMode(Ones, OUTPUT);
    pinMode(Tens, OUTPUT);
    pinMode(ResetOnes, OUTPUT);
    pinMode(ResetTens, OUTPUT);
}

void loop(){
    currentStateA = digitalRead(outputA);
    if (currentStateA != lastStateA  && currentStateA == 1){
        // If the outputB state is different than the outputA state then
        // the encoder is rotating CCW so decrement
        if (digitalRead(outputB) != currentStateA) {
            counter ++;
            incrementOnes();
        } else {
            // Encoder is rotating CW so increment
            counter --;
            incrementTens();
        }
    }
    lastStateA = currentStateA;


}

