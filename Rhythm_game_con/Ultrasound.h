#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include "Arduino.h"

class Ultrasound{
  public:
    Ultrasound(int echoPin, int trigPin);
    void update();
    int isDetect();
   
  private:
    int echoPin;
    int trigPin;
    int dist;
    int debounceTime = 50;
    unsigned long lastPress_time = 0;
};

#endif
