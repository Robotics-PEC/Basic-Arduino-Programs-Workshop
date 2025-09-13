int TRIG = 10; // transmitter
int ECHO = 11; // receiver

void setup() {
    pinMode(TRIG, OUTPUT);   // Set Transmitter pin (TRIG) as OUTPUT
    pinMode(ECHO, INPUT);    // Set Receiver pin (ECHO) as INPUT
    digitalWrite(TRIG, LOW); // make sure trig is low before measuring
    Serial.begin(115200);    // Set baud rate (bits/sec)
}

// TRIG -> HIGH for 10 us -> LOW
// ECHO -> HIGH (receiving for how many secons)

// let the distance to the object be x
// let speed of sound = s
// let time taken for sound to reach object and come back = t

// s = 2x/t
// x = s * t / 2

// Speed of sound = 343 m/s (approx) -> 0.0343 cm/us

void loop() {
    digitalWrite(TRIG, HIGH); // set TRIG pin HIGH for transmitting
    delayMicroseconds(10);    // delay by 10 microseconds
    digitalWrite(TRIG, LOW);  // set TRIG pin Low to stop transmitting

    int dur = pulseIn(ECHO, HIGH);    // measure the pulse duration on the receiver (ECHO) (in microseconds)
    double dist = (0.0343 * dur) / 2; // dist in cm

    Serial.print("Distance : "); // print the distance to the monitor
    Serial.println(dist);
    delay(50);
}