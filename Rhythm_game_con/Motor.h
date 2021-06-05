#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include <Servo.h>

class Motor{
	public:
		Motor(int pin);
    void init();
		void update();
		void click();
	
	private:
		Servo servo;
		int pin;
		int angleUp = 15;
		int angleDown = 0;
		int speed = 50;
		bool Up = true;
		bool CanClick = false;
		unsigned long lastChangeTime = 0;
};


#endif
