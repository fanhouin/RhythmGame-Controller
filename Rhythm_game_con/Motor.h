#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include <Servo.h>

class Motor{
	public:
		Motor(int pin, int angleUp, int angleDown);
    void init();
		void update();
		void click();
	
	private:
		Servo servo;
		int pin;
		int angleUp; 
		int angleDown; 
		int speed = 80;
		bool Up = true;
		bool CanClick = false;
		unsigned long lastChangeTime = 0;
};


#endif
