//We include the LCD screen library.
#include "LiquidTWI2.h"
//The LCD screen is created with the variable name 'lcd'.
LiquidTWI2 lcd(0x20);
//The variable 'str1' is defined to store the incoming data.
String str1 = "";
//The incoming data will be received as a char variable.
char ch;

void setup() {
  //We initialize the LCD screen.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //We open the communication port for Bluetooth.
  Serial1.begin(9600);
  //Button S1 is defined to clear the screen and the 'str1' variable.
  pinMode(9, INPUT);
}

void loop() {
  //When communication is available, the condition will become TRUE.
  if (Serial1.available()) {
    //We receive the data from communication and store it in the 'ch' char variable.
    ch = Serial1.read();
    /* To display the message on the screen,
     * we convert it into a string format.
     */
    str1 = str1 + ch;
    //We set the cursor position on the LCD screen.
    lcd.setCursor(0, 0);
    lcd.print(str1);
  }

  //When button S1 is pressed, we clear the 'str1' variable and the screen.
  if (digitalRead(9) == 0) {
    lcd.clear();
    str1 = "";
  }
}
 