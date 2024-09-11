//Printing “Hello World!” on LCD Display
//include the LCD library
#include "LiquidTWI2.h"
//define the LCD adress 
LiquidTWI2 lcd(0x20);
void setup() {
//define the chip information
  lcd.setMCPType(LTI_TYPE_MCP23008);
}

void loop() {
  
  //We specify the rows and columns of the LCD screen.
  lcd.begin(16, 2);
  //We turn on the backlight of the LCD screen. LOW value turns it off.
  lcd.setBacklight(HIGH);
  //We specify its location before writing our text on the LCD screen.
  lcd.setCursor(0, 0);
  //The expression to be printed on the LCD screen
  lcd.print("Hello World!");
}
