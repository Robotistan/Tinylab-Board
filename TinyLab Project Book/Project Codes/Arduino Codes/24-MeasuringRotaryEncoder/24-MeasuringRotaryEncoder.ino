//LCD screen library is included.
#include "LiquidTWI2.h"
//RotaryEncoder library is included.
#include "RotaryEncoder.h"
//Communication library is included.
#include <SoftwareSerial.h>
//LCD screen is created with the variable name 'lcd'.
LiquidTWI2 lcd(0x20);
//RotaryEncoder is created with the variable name 'tinyEncoder', connected to pins 6 and 7.
RotaryEncoder tinyEncoder(6, 7);

void setup() {
  //LCD screen initialization commands
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //Button definition
  pinMode(A5, INPUT);
}

void _loop() {
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  //Getting the position of the tinyEncoder.
  lcd.print(tinyEncoder.getPosition());
  //If the button is pressed, the selected number will be displayed on the screen.
  if ((analogRead(A5) > 80) && (analogRead(A5) < 100)) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(String("Selected number:") + String(tinyEncoder.getPosition()));
  }
  delay(100);
  //Constantly checking the rotation of the tinyEncoder.
  tinyEncoder.tick();
}
