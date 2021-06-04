#include "Touch.h"
#include "Ultrasound.h"

Touch touchs[4] = {Touch(4),Touch(5),Touch(6),Touch(7)};
Ultrasound us[2] = {Ultrasound(2,3),Ultrasound(8,9)};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 4; i++){
    if(touchs[i].isPressed()){
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
