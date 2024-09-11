//LCD screen and DS1307 libraries are included.
#include "LiquidTWI2.h"
#include "Bonezegei_DS1307.h"
//Relay is created.
#define relay_pin A4
//A system status variable is added.
float status = 0;
//LCD and DS1307 are created using the 'lcd' and 'rtc' variables.
LiquidTWI2 lcd(0x20);
Bonezegei_DS1307 rtc(0x68);

void setup() {
//LCD screen initialization code is added.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
//DS1307 initialization commands are added.
  rtc.begin();
//Buzzer is defined.
  pinMode(A1,OUTPUT);
//Relay is defined.
  pinMode(relay_pin, OUTPUT);
//Button S1 is defined to stop the alarm.
  pinMode(9,INPUT);
//Button S2 is defined to turn off the relay.
  pinMode(8,INPUT);
  status = 0;
}

void loop() {
//We retrieve the time from the DS1307.
  rtc.getTime();
//We display the time on the screen.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(String(rtc.getHour()) + String(String(":") + String(String(rtc.getMinute()) + String(String(":") + String(rtc.getSeconds())))));
   
  /*We set the alarm for 23:10:3 here.
    If the condition is met, the status variable will be set to 1,
    The buzzer will sound, and 
    "Alarm Time" will be displayed on the screen.
    However, the relay will not yet be activated.
  */
    if((rtc.getHour() == 23)  &&  ((rtc.getMinute() == 10)  &&  (rtc.getSeconds() == 3))){
      analogWrite(A1,255);
      status = 1;
      lcd.setCursor(0, 1);
      lcd.print("Alarm Time");
    }

  /*When button S1 is pressed, if the status variable is 1, 
  the relay will be activated, and the status will be set to 0.*/
    if(digitalRead(9) == 0){
      if(status == 1){
        status = 0;
        analogWrite(A1,0);
        digitalWrite(relay_pin, HIGH);
      }  
    }
    //Button S2 will turn off the relay.
    if(digitalRead(8) == 0){
      digitalWrite(relay_pin, LOW);
    }
   //We wait 0.1 seconds.
  delay(100);
}
