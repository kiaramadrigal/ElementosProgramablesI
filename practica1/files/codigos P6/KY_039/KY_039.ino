#include <TinyWireM.h>
#include <Tiny4kOLED.h>

#define pwmPin  3  	
#define enPin   4   

void prepareDisplay() {
  oled.clear();
  oled.begin();
  oled.setFont(FONT6X8);
}

void setup() {
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
    oled.clear();
    oled.on();
    prepareDisplay();
    oled.setFont(FONT8X16);  
}

void loop() {
  if (digitalRead(4) == HIGH) {
    oled.setCursor(5, 1);
    oled.print("ON ");
  } else {
    oled.setCursor(5, 1);
    oled.print("OFF");
  }
}