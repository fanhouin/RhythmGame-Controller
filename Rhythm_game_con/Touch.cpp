#include "Touch.h"

Touch::Touch(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);
    update();
}

void Touch::update(){
    touch = digitalRead(pin);
    if(millis() - lastPress_time > debounceTime){
        state = touch;
        lastPress_time = millis();
    }
}

bool Touch::isPressed(){
    update();
    return state;
}
