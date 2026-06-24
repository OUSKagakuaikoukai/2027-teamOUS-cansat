#include<Arduino.h>

#define PWM_FREQ 20000
#define PWM_RES 8

int MOTOR_CH = 0;

/*
	ledcSetup(MOTORA_CH0, PWM_FREQ, PWM_RES);
	ledcAttachPin(MOTORA_PIN1, MOTORA_CH0);
	PWM制御の基本の形
*/

struct MotorData{
	int ch1;
	int ch2;
};
MotorData motor[16];

void PWMSetUp(int CH){
	if(CH < 16){
		ledcSetup(CH, PWM_FREQ, PWM_RES);
	}
}
void PWMAttachPin(int Pin,int CH){
	if(CH < 16){
		ledcAttachPin(Pin,CH);
	}
}
void MotorSetUp(int pin1,int pin2,int Motor){
	motor[Motor].ch1 = MOTOR_CH;
	PWMSetUp(MOTOR_CH);
	PWMAttachPin(pin1,MOTOR_CH);
	++MOTOR_CH;
	motor[Motor].ch2 = MOTOR_CH;
	PWMSetUp(MOTOR_CH);
	PWMAttachPin(pin2,MOTOR_CH);
	++MOTOR_CH;
}
void Move(int Motor,int Speed){
	//スピードは-255から255まで
	if(Speed > 0){
		ledcWrite(motor[Motor].ch1, Speed);
		ledcWrite(motor[Motor].ch2, 0);
	}else{
		Speed *= -1;
		ledcWrite(motor[Motor].ch1, 0);
		ledcWrite(motor[Motor].ch2, Speed);
	}
}