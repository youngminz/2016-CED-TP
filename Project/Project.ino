#include <Servo.h>

Servo servoLeft, servoRight;

void move(int left, int right, int duration) {
    servoLeft.writeMicroseconds(left);
    servoRight.writeMicroseconds(right);
    delay(duration);
}

void setup() {
    Serial.begin(9600);

    servoLeft.attach(12);
    servoRight.attach(13);

    move(1530, 1470, 1000);
    move(1470, 1530, 1000);
    move(1500, 1470, 1000);
    move(1530, 1500, 1000);
    move(1500, 1530, 1000);
    move(1470, 1500, 1000);
    move(1470, 1470, 1000);
    move(1530, 1530, 1000);

    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);

    Serial.print(">>> ");
}

void loop() {
    if (Serial.available()) {
        byte inbyte = Serial.read();

        Serial.print("Received ");
        Serial.print(inbyte);
        Serial.println();

        Serial.print(">>> ");

        switch (inbyte) {
            case 'w':
                move(1530, 1470, 0);
                break;
            case 's':
                move(1470, 1530, 0);
                break;
            case 'a':
                move(1470, 1470, 0);
                break;
            case 'd':
                move(1530, 1530, 0);
                break;
        }
    }
}
