#include <Servo.h>

Servo myservo; // create Servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int servoPin = 9; // PWM Pin to drive servo
int val;          // variable to read the value from the analog pin

void setup() {
    myservo.attach(servoPin); // attaches the servo on pin 9 to the Servo object
}

void loop() {
    // val = analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023)
    // myservo.write(val);       // sets the servo position according to the scaled value
    // delay(15);                // waits for the servo to get there

    // CAN USE FOR LOOP IF POTENTIOMETER IS NOT AVAILABLE (simulating a potentiometer)
    for(int i = 0; i < 1024; i++) {
        val = map(i, 0, 1023, 0, 180); // scale it for use with the servo (value between 0 and 180)
        myservo.write(val);            // sets the servo position according to the scaled value
        delay(15);                     // waits for the servo to get there
    }
}