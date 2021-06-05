#include "Touch.h"
#include "Ultrasound.h"
#include "Motor.h"

String recv;
Touch touchs[4] = {Touch(4),Touch(5),Touch(6),Touch(7)};
Ultrasound us[2] = {Ultrasound(2,3),Ultrasound(8,9)};
Motor motors[2] = {Motor(10),Motor(11)};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 2; i++) motors[i].init();
}

void loop() {
//  for(int i = 0; i < 4; i++){
//    if(touchs[i].isPressed()){
//      Serial.print('1');
//      Serial.print(',');
//    }
//    else {
//      Serial.print('0');
//      Serial.print(',');
//    }
//  }
//
//  for(int i = 0; i < 2; i++){
//    if(us[i].isDetect()){
//      Serial.print('1');
//      Serial.print(',');
//    }
//    else {
//      Serial.print('0');
//      Serial.print(',');
//    }
//  }
//  Serial.println();

  motors[0].update();
  motors[1].update();
  if(Serial.available()){
    recv = Serial.readStringUntil('\n');
    if(recv == "D") motors[0].click();
    if(recv == "F") motors[1].click();
  }

  
}
