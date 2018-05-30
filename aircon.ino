int PowerOnACpin = D1;
int tempDown = D2;
int tempUp = D3;

void setup() {

    // Pins and outputs
    pinMode(PowerOnACpin,OUTPUT);
    pinMode(tempUp,OUTPUT);
    pinMode(tempDown,OUTPUT);

    // Set all pins to low
    digitalWrite(PowerOnACpin,LOW);
    digitalWrite(tempUp,LOW);
    digitalWrite(tempDown,LOW);

    // IFTT functions
    Particle.function("PowerOnAC", PowerOnAC);
    Particle.function("tempyUp", tempyUp);
    Particle.function("tempyDown", tempyDown);
}

void loop() {

}

int PowerOnAC(String command) {
    if (command=="On") {
        digitalWrite(PowerOnACpin,HIGH);
        delay(300);
        digitalWrite(PowerOnACpin,LOW);
        return 1;
    }
    else return -1;

}

int tempyUp(String command) {
    if (command=="Up") {
        int x = x;
        int i = -1;
        do {
            i++;
            digitalWrite(tempUp,HIGH);
            delay(100);
            digitalWrite(tempUp,LOW);
        } while( i<=x );return 1;
    } else return -1;
}

int tempyDown(String command) {
    if(command=="Down"){
        int x = x;
        int i = -1;
        do {
            i++;
            digitalWrite(tempDown,HIGH);
            delay(100);
            digitalWrite(tempDown,LOW);
        } while( i<=x );
        return 1;
    } else return -1;
}