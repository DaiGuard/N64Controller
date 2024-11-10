#include <Arduino.h>

#include "n64_controller.h"


void setup() 
{
  // モニタ用シリアルを設定
  Serial.begin(115200);

  // N64通信用
  Serial2.setTimeout(1);
  Serial2.begin(1250000);  
}

void loop()
{
  uint8_t data[32];
  
  N64_readStatus(data);
  
  size_t ret = N64_readPoll(data);

  N64StickAndButton input;
  N64_parseStickAndButton(data, &input);

  Serial.print("A:"); Serial.print(input.btn_A); Serial.print(",");
  Serial.print("B:"); Serial.print(input.btn_B); Serial.print(",");
  Serial.print("Z:"); Serial.print(input.btn_Z); Serial.print(",");
  Serial.print("START:"); Serial.print(input.btn_START); Serial.print(",");
  Serial.print("DU:"); Serial.print(input.btn_DU); Serial.print(",");
  Serial.print("DD:"); Serial.print(input.btn_DD); Serial.print(",");
  Serial.print("DL:"); Serial.print(input.btn_DL); Serial.print(",");
  Serial.print("DR:"); Serial.print(input.btn_DR); Serial.print(",");
  Serial.print("L:"); Serial.print(input.btn_L); Serial.print(",");
  Serial.print("R:"); Serial.print(input.btn_R); Serial.print(",");
  Serial.print("CU:"); Serial.print(input.btn_CU); Serial.print(",");
  Serial.print("CD:"); Serial.print(input.btn_CD); Serial.print(",");
  Serial.print("CL:"); Serial.print(input.btn_CL); Serial.print(",");
  Serial.print("CR:"); Serial.print(input.btn_CR); Serial.print(",");
  Serial.print("AX:"); Serial.print(input.analog_X); Serial.print(",");
  Serial.print("AY:"); Serial.print(input.analog_Y); Serial.print(",");
  Serial.println();
}
