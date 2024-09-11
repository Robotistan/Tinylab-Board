//We include the LCD screen library.
#include "LiquidTWI2.h"
/*We define the LDR light sensor with the LDR_PIN variable, 
 specifying that it is connected to pin A2.*/
#define LDR_PIN  A2
/*We create a formula to calculate the LDR reading value.*/
#define readLDR() (((2500.0 / (analogRead(LDR_PIN) * (5.0 / 1024.0))) - 500) / 10.0)
//We define the relay.
#define relay_pin A4
//We create the LCD screen using the 'lcd' variable.
LiquidTWI2 lcd(0x20);
//We assign the light value to the 'light' variable.
float light = 0;  
void setup() {
  //We initialize the LCD screen.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //We define the LDR sensor.
  pinMode(LDR_PIN,INPUT);
  //We define the relay.
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  /*Based on the LDR value, we set a condition with the if command.
   Depending on the situation, we activate the relay.
   */
   if(readLDR() < 30){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("It's Dark");
      lcd.setCursor(0, 1);
      lcd.print(readLDR());
      digitalWrite(relay_pin, HIGH);

    }else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("It's Bright");
      lcd.setCursor(0, 1);
      lcd.print(readLDR());
      digitalWrite(relay_pin, LOW);
    }
    //We wait for 1 second.
    delay(1000);
}
