#include "Ultrasound.h"

Ultrasound::Ultrasound(int echoPin, int trigPin){
  this->echoPin = echoPin;
  this->trigPin = trigPin;
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  update();
}

void Ultrasound::update(){
    digitalWrite(trigPin, LOW);delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    if(millis() - lastPress_time > debounceTime){
        dist = pulseIn(echoPin, HIGH);
        lastPress_time = millis();
    } 
}

int Ultrasound::isDetect(){
  update();
  return dist < 800;
}
