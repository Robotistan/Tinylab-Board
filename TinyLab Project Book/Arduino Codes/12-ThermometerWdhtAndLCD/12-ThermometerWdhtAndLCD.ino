//We include the LCD screen library.
#include "LiquidTWI2.h"
/*We define the LM35_PIN variable to specify that the temperature sensor is connected to pin A3.*/
#define LM35_PIN        A3
//We create the LCD screen with the 'lcd' variable.
LiquidTWI2 lcd(0x20);
//We set the temperature value in Celsius.
float coefficient = 500.0/1023.0;
/*We create a function called readTemperature to read the air temperature.*/
float readTemperature()  {
    return  coefficient * analogRead(LM35_PIN);
}

void setup() {
  //We initialize the LCD screen.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //We define the temperature sensor.
  pinMode(LM35_PIN,INPUT);
}

void loop() {
  //We set the position on the LCD screen before writing text.
  lcd.setCursor(0, 0);
  lcd.print("Temperature");
  lcd.setCursor(0, 1);  
  //We get the temperature value and write it to the screen, rounding the result.
  lcd.print(round(readTemperature()));  
  //We set the position for the "Degree" text.
  lcd.setCursor(3, 1);  
  //We add the "Degree" text next to the temperature value.
  lcd.print("Degree"); 
  //We wait for 1 second.
  delay(1000);
  //We clear the LCD screen.
  lcd.clear();
}
