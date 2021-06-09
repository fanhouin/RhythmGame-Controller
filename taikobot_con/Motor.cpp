#include "Motor.h"

Motor::Motor(int pin, int angleUp, int angleDown){
  this->pin = pin;
  this->angleUp = angleUp;
  this->angleDown = angleDown;
}

void Motor::init(){
  servo.attach(pin);
  servo.write(angleUp);
  update();
}

void Motor::update(){
    //Up and down need some time to move,
    //but servo also can click when it has not yet returned to the top
    if(millis() - lastChangeTime < speed && !CanClick) 
        return;
        
    if(Up && CanClick){
        servo.write(angleDown);
        Up = false;
        CanClick = false;
        lastChangeTime = millis();
    } 
    else if(!Up){
        servo.write(angleUp);
        Up = true;
        lastChangeTime = millis();
    }
     
}

void Motor::click(){
    CanClick = true;
}
