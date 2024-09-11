//LCD screen and DS1307 libraries are included.
#include "LiquidTWI2.h"
#include "Bonezegei_DS1307.h"
//An LCD screen is created using the 'lcd' variable.
LiquidTWI2 lcd(0x20);
//The DS1307 is created using the 'rtc' variable.
Bonezegei_DS1307 rtc(0x68);

void setup() {
  //LCD screen initialization.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //DS1307 is started.
  rtc.begin();
}

void loop() {
//We retrieve the time from DS1307.
  rtc.getTime();
//We clear the LCD screen.
  lcd.clear();
//We set the position before writing text on the screen.
  lcd.setCursor(0, 0);
//We concatenate and display day/month/year on the top line of the screen.
  lcd.print(String(rtc.getDate()) + String(String("/") + String(String(rtc.getMonth()) + String(String("/") + String(rtc.getYear())))));
 //We set the position before writing text on the screen.
  lcd.setCursor(0, 1);
//We concatenate and display hour/minute/second on the bottom line of the screen.
  lcd.print(String(rtc.getHour()) + String(String(":") + String(String(rtc.getMinute()) + String(String(":") + String(rtc.getSeconds())))));
//We wait for 1 second.
  delay(1000);
}
