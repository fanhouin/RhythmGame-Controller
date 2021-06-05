#include "Motor.h"

Motor::Motor(int pin){
  this->pin = pin;
}

void Motor::init(){
  servo.attach(pin);
  update();
}

void Motor::update(){
    //Up and down need some time to move,
    //but servo also can click when it has not yet returned to the top
    if(millis() - lastChangeTime < speed) 
        return;
        
    if(Up){
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
