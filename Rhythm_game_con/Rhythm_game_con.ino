#include "Touch.h"
#include "Ultrasound.h"
#include "Motor.h"

String recv;
Touch touchs[12] = {Touch(A5),Touch(A4),Touch(A3),Touch(4),Touch(5),Touch(6),
                  Touch(7),Touch(8),Touch(9),Touch(A2),Touch(A1),Touch(A0)};
//Ultrasound us[2] = {Ultrasound(2,3),Ultrasound(8,9)};
Motor motors[2] = {Motor(10, 135, 125),Motor(11, 37, 47)};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 2; i++) motors[i].init();
}

void loop() {

//  for(int i = 0; i < 2; i++){
//    if(us[i].isDetect()){
//      Serial.print('1');JK
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
//    motors[1].click();
  if(Serial.available()){
    recv = Serial.readStringUntil('\n');
    if(recv == "F") motors[0].click();
    if(recv == "D") motors[1].click();
  }
}
