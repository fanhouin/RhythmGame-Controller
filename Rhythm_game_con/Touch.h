#ifndef TOUCH_H
#define TOUCH_H

#include "Arduino.h"

class Touch{
  public:
    Touch(int pin);
    void init();
    void update();
    bool isPressed();
   
  private:
    int pin;
    int state;
    int touch;
    int debounceTime = 50;
    unsigned long lastPress_time = 0;
};

#endif
