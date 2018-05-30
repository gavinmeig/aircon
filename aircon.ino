int PowerOn = D1;
int tempUp = D3;
int tempDwn = D2;

void setup() {

    //Pins and outputs
    pinMode(PowerOn,OUTPUT);
    pinMode(tempUp,OUTPUT);
    pinMode(tempDwn,OUTPUT);

    // Make them all nighty night
    digitalWrite(PowerOn,LOW);
    digitalWrite(tempUp,LOW);
    digitalWrite(tempDwn,LOW);

    // IFTT functions
    Particle.function("POOWER", POOWER);
    Particle.function("tempyUp", tempyUp);
    Particle.function("tempyDwn", tempyDwn);
}

void loop() {

}

int POOWER(String command) {
    if (command=="On") {
        digitalWrite(PowerOn,HIGH);
        // We will set the digital pin fanOff on
        delay(300);
        // A delay of 100 milliseconds are set on all commands to ensure the relay gets toggled
        digitalWrite(PowerOn,LOW);
        // We will set the digital pin off
        return 1;
    }
    else return -1;

}

int tempyUp(String command) {
    if (command=="Up1") {
        digitalWrite(tempUp,HIGH);
        // We will set the digital pin fanOff on
        delay(100);
        // A delay of 100 milliseconds are set on all commands to ensure the relay gets toggled
        digitalWrite(tempUp,LOW);

        delay(200);

        digitalWrite(tempUp,HIGH);
        // We will set the digital pin fanOff on
        delay(100);
        // A delay of 100 milliseconds are set on all commands to ensure the relay gets toggled
        digitalWrite(tempUp,LOW);

        return 1;
    }
    else return -1;

}

int tempyDwn(String command) {
    if (command=="Up1") {
        digitalWrite(tempDwn,HIGH);
        // We will set the digital pin fanOff on
        delay(100);
        // A delay of 100 milliseconds are set on all commands to ensure the relay gets toggled
        digitalWrite(tempDwn,LOW);

        delay(200);

        digitalWrite(tempDwn,HIGH);
        // We will set the digital pin fanOff on
        delay(100);
        // A delay of 100 milliseconds are set on all commands to ensure the relay gets toggled
        digitalWrite(tempDwn,LOW);

        return 1;
    }
    else return -1;

}
