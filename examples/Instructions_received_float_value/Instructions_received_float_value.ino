/*
 *  This example shows how to save the values received from the Label and the values from the slider into a custom variable
 *  GUI：https://github.com/STONElibrary/stone_serial/blob/v1.0.9/Example/Arduino%26ESP32/Instructions_received_float_value/stone_project6.st
 */

#include "stone.h"

extern unsigned char receive_over_flage;
extern recive_group STONER;
extern unsigned char STONE_RX_BUF[RX_LEN];

String my_name;
float my_status;

void setup()
{
   Serial.begin(115200);
}

uint8_t x = 0;
uint8_t clears;
void loop() {

  serial_receive_frame_idel();
  
  if (receive_over_flage == 1)
    {
      my_name = (char*)STONER.widget;
      
      my_status = STONER.float_value;
      Serial.print("name:");
      for (int wds=0;wds<STONER.len-1;wds++)
      Serial.write(my_name[wds]);
      Serial.print("\n");
      Serial.print("int value:");
      Serial.println(STONER.value);
      Serial.print("float value:");
      Serial.println(my_status);
      receive_over_flage = 0;
    }
  
}
