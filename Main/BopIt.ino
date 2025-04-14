/*
Digibal 2 - Out B Rotary Encoder 
Digital 4 - Out A Rotary Encoder
Digital 5 - Increment Ones Counter
Digital 6 - Game butten
Digital 7 - Startbrtton
bigibal 8 - Reset Ones cunter
Digital 9 - Tens Reset comtor
Digital 10 - Tens increment Countor
Pins 27 and 28 are
SDA & SCL
*/
double time_per_instruction = 10000 //ms

void setup(){

}

void loop(){
    //Wait for start button
    while(!digitalRead(START_BUTTON)){
        delay(100);
    }

    //Game init


    for(int i = 0; i < 99; i++){ //instruction count
        int instruction = random(0, 3); //random number between 0 and 2
        if(instruction == 0){
            // Pan
        } else if(instruction == 1){
            // Zoom
        } else if(instruction == 2){
            // Shoot
        }
        

    }
}