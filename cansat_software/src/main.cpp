#include <Arduino.h>
#include <Wire.h>
#include<motor.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

#define SDA_PIN 21
#define SCL_PIN 22

#define MOTOR_PIN1 25
#define MOTOR_PIN2 26

void setup() {
    Serial.begin(115200);
	MotorSetUp(MOTOR_PIN1,MOTOR_PIN2,0);

	    Wire.begin(SDA_PIN, SCL_PIN);

    if (!mpu.begin()) {
        Serial.println("MPU6050 not found!");
        while (1) {
            delay(10);
        }
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

}
void loop() {
	Move(0,100);
	delay(1000);
	Move(0,0);
	delay(100);
}