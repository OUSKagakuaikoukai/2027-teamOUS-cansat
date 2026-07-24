#include <Arduino.h>
#include<motor.h>
#include <ESP32Servo.h>

Servo servo0,servo1;

#define SERVO_PIN0 32
#define SERVO_PIN1 33

#define MOTOR0_PIN1 17
#define MOTOR0_PIN2 18
#define MOTOR1_PIN1 25
#define MOTOR1_PIN2 26



void setup() {
  
  MotorSetUp(MOTOR0_PIN1,MOTOR0_PIN2,0);
  MotorSetUp(MOTOR1_PIN1,MOTOR1_PIN2,1);
  

  servo0.setPeriodHertz(50);
  servo1.setPeriodHertz(50);

// サーボを接続
// 最小パルス幅500us、最大2500us（一般的な値）
  servo0.attach(SERVO_PIN0, 500, 2500);
  servo1.attach(SERVO_PIN1, 500, 2500);

}

void loop() {
  
  Move(0,200);
  Move(1,200);
  

  // 0°
    servo0.write(0);
	servo1.write(0);
    delay(1000);

    // 45°
    servo0.write(45);
	servo1.write(45);
    delay(1000);

}