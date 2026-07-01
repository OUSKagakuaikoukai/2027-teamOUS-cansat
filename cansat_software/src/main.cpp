#include <Arduino.h>
#include<motor.h>
void setup() {
  // put your setup code here, to run once:
  MotorSetUp(5,18,0);
  MotorSetUp(26,25,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Move(0,200);
  Move(1,200);
}