
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


void setup() {
  pinMode(a1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(f1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(f2, OUTPUT);
  pinMode(g2, OUTPUT);

}

void loop() {
  for(unsigned i = 0; i < 100; i++){
    outputOnes(i);
    outputTens(i);
    delay(100);
  }
}
