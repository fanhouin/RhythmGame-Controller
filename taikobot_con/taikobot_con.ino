#include "Motor.h"

String recv;
Motor motors[2] = {Motor(10, 135, 125),Motor(11, 37, 47)};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 2; i++) motors[i].init();
}

void loop() {
  for(int i = 0; i < 2; i++) motors[i].update();
  if(Serial.available()){
    recv = Serial.readStringUntil('\n');
    if(recv == "K") motors[0].click();
    if(recv == "J") motors[1].click();
  }
}
