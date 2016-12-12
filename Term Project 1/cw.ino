#include <Servo.h>

Servo servoLeft, servoRight;

void move(int left, int right, int duration) {
    servoLeft.writeMicroseconds(left);
    servoRight.writeMicroseconds(right);
    delay(duration);
}

char sensorFront = A0;
char sensorBottom = A1;
int trigPin = 8;
int echoPin = 9;

int status = 1;
long last_turn_time = -1;

float infrared_rays_sensor(char sensor) {
    return (24.61 / (map(analogRead(sensor), 0, 1023, 0, 5000) - 0.1696)) * 1000;
}

float in_range_probability(char sensor, double threshold) {
    int count = 0;
    for (int j = 0; j < 50; j++) {
        float infrared_rays = infrared_rays_sensor(sensor);
        if (5.0 <= infrared_rays && infrared_rays <= threshold) {
            count++;
        }
    }
    return (float) count / 50;
}

bool check_hurdle() {
    int count = 0;
    for (int i = 0; i < 40; i++) {
        if (in_range_probability(sensorFront, 80.0) >= 0.8) {
            count++;
        }
        else {
            if (count > 2) {
                move(1470, 1470, 200 * (count / 2 + 1));
                move(1500, 1500, 0);

                return true;
            }
            count = 0;
        }
        move(1530, 1530, 150);
    }
    return false;
}

bool check_hurdle_short() {
    int count = 0;
    for (int i = 0; i < 15; i++) {
        if (in_range_probability(sensorFront, 80.0) >= 0.8) {
            count++;
        }
        else {
            if (count > 2) {
                move(1470, 1470, 200 * (count / 2 + 1));
                move(1500, 1500, 0);

                return true;
            }
            count = 0;
        }
        move(1530, 1530, 150);
    }
    return false;
}

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(13, OUTPUT);
    servoLeft.attach(10);
    servoRight.attach(11);
    digitalWrite(13, LOW);

    int no_answer = 1;
    int warning = 0;

    status = check_hurdle();
    while (status) {
        if (in_range_probability(sensorBottom, 30.0) < 0.8) { // 바닥을 봤을 때
            status = 0;
        }
        else if (in_range_probability(sensorFront, 45.0) >= 0.8) { // 가까이 있을 때
            move(1550, 1440, 10);
        }
        else { // 멀 때
            move(1400, 1600, 350);
            move(1470, 1470, 700);

            status = check_hurdle_short();
        }
    }

    move(1500, 1500, 0);
    digitalWrite(13, HIGH);
}

void loop() {

}
