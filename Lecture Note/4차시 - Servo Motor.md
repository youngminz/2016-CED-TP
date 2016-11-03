# 4차시 - Servo Motor

## 사용되는 함수들
```c
#include <Servo.h>
Servo servo;

servo.attach(Pin);
servo.writeMicroseconds(Value); // 1300이 시계방향, 1700이 반시계방향
```

## 펄스 폭 변조 (Pulse Width Modulation)

* 순수 아날로그 제어를 모방한 것
* 디지털 신호를 아날로그 신호와 비슷하게 만들 수 있음
* 신호를 켜고 끄는 방식으로 네모파의 Duty Cycle를 변조하여 사용
* 전체 시간 중 1 상태인 시간의 비율

## Servo Motor

* Standard servo motor: 입력으로 주어지는 PWM 신호에 의해 서보모터가 일정한 **각도**로 회전함. 좌우 주행방향 제어 등에 사용됨
* **Continuous servo motor**: 입력으로 주어지는 PWM 신호에 따라 서보모터의 **회전 속도와 방향**이 결정됨. 주행속도 제어 등에 사용됨

## 실습

* 전원 꺼진 상태에서 연결
* 연결 핀 번호와 방향 확인 (위에서부터 흰색, 빨간색, 검정색 순서)

영점 조절: 

```c
#include <Servo.h>

Servo servo;

void setup() {
    servo.attach(13);
    servo.writeMicroseconds(1500);
}

void loop() {

}
```

속도 및 방향 제어:

```c
#include <Servo.h>

Servo servo;

void setup() {
    servo.attach(13);
    servo.writeMicroseconds(1300);
    // servo.writeMicroseconds(1700);
    // servo.writeMicroseconds(1480);
}

void loop() {

}
```