int PowerOnACpin = D1;
int tempDown = D2;
int tempUp = D3;
int degrees = 0;

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
    if (degrees > 0) {
        int i = -1;
        do {
            i++;
            digitalWrite(tempUp,HIGH);
            delay(100);
            digitalWrite(tempUp,LOW);
        } while( i<=degrees );return 1;
    } else return -1;
}

int tempyDown(String command) {
    if(degrees > 0){
        int i = -1;
        do {
            i++;
            digitalWrite(tempDown,HIGH);
            delay(100);
            digitalWrite(tempDown,LOW);
        } while( i<=degrees );
        return 1;
    } else return -1;
}
