#define OutA = 4
#define OutB = 2

int counter = 0;
int currentStateA;
int lastStateA;
bool dir = null;

void setup(){
    pinMode(OutA, INPUT);
    pinMode(OutB, INPUT);
}

void loop(){
    currentStateA = digitalRead(outputA);
    if (currentStateA != lastStateA  && currentStateA == 1){
        // If the outputB state is different than the outputA state then
        // the encoder is rotating CCW so decrement
        if (digitalRead(outputB) != currentStateA) {
            counter ++;
            currentDir ="CW";
        } else {
            // Encoder is rotating CW so increment
            counter --;
            currentDir ="ACW";
        }
    }
    lastStateA = currentStateA;
}