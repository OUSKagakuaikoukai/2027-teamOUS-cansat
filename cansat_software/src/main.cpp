#include <Arduino.h>
#include<motor.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire);

Servo servo0,servo1;

#define SERVO_PIN0 32
#define SERVO_PIN1 33

#define MOTOR0_PIN1 17
#define MOTOR0_PIN2 18
#define MOTOR1_PIN1 25
#define MOTOR1_PIN2 26

#define SDA_PIN 21
#define SCL_PIN 22


void setup() {

   Serial.begin(115200);
   Wire.begin(SDA_PIN, SCL_PIN);
  
  
	if (!bno.begin())
    {
        Serial.println("BNO055が見つかりません");
        while (1)
        {
            delay(10);
        }
    }

    Serial.println("BNO055 OK");

    delay(1000);

}

void loop() {
  
   sensors_event_t event;

    bno.getEvent(&event);

    Serial.print("X: ");
    Serial.print(event.orientation.x);

    Serial.print("  Y: ");
    Serial.print(event.orientation.y);

    Serial.print("  Z: ");
    Serial.println(event.orientation.z);

    delay(100);
	
}