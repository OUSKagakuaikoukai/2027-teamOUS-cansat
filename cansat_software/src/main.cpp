#include <Arduino.h>
//#include <Wire.h>
#include<motor.h>
#define SDA_PIN 21
#define SCL_PIN 22

#define MOTOR_PIN1 25
#define MOTOR_PIN2 26

void setup() {
    Serial.begin(115200);
	MotorSetUp(MOTOR_PIN1,MOTOR_PIN2,0);
}
void loop() {
	Move(0,100);
	delay(1000);
	Move(0,0);
	delay(100);
}