#include <Arduino.h>
#include<motor.h>
#include <ESP32Servo.h>

Servo servo;

#define SERVO_PIN 17

#define MOTOR0_PIN1 17
#define MOTOR0_PIN2 18
#define MOTOR1_PIN1 26
#define MOTOR1_PIN2 25



void setup() {
  
  MotorSetUp(MOTOR0_PIN1,MOTOR0_PIN2,0);
  MotorSetUp(MOTOR1_PIN1,MOTOR1_PIN2,1);
  

servo.setPeriodHertz(50);

// サーボを接続
// 最小パルス幅500us、最大2500us（一般的な値）
servo.attach(SERVO_PIN, 500, 2500);

}

void loop() {
  
  Move(0,200);
  Move(1,200);
  

  // 0°
    //servo.write(0);
    delay(1000);

    // 45°
    //servo.write(45);
    delay(1000);

}