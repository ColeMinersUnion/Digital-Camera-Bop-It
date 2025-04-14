//Inits LCD Displays and counts to 100 pretty fast.

// Digital 5 - Increment Ones Counter
// Digibal 8 - Reset Ones counter
// Digital 9 - Tens Reset counter
// Digital 10 - Tens increment counter

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
    pinMode(Ones, OUTPUT);
    pinMode(Tens, OUTPUT);
    pinMode(ResetOnes, OUTPUT);
    pinMode(ResetTens, OUTPUT);
}

void loop(){
    for(int i = 0; i < 100; i++){
        incrementCount();
        delay(100);
    }
    delay(5000);
}

