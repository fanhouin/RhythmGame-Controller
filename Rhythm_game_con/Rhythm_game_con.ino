#include "Touch.h"
#include "Ultrasound.h"
#include "Motor.h"

Touch touchs[12] = {Touch(A5),Touch(A4),Touch(A3),Touch(4),Touch(5),Touch(6),
                  Touch(7),Touch(8),Touch(9),Touch(A2),Touch(A1),Touch(A0)};
Ultrasound us[2] = {Ultrasound(2,3),Ultrasound(10,11)};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 12; i += 2){
    if(touchs[i].isPressed() || touchs[i+1].isPressed()){
      Serial.print('1');
      Serial.print(',');
    }
    else {
      Serial.print('0');
      Serial.print(',');
    }
  }
  for(int i = 0; i < 2; i++){
    if(us[i].isDetect()){
      Serial.print('1');
      Serial.print(',');
    }
    else {
      Serial.print('0');
      Serial.print(',');
    }
  }
  Serial.println();

}
