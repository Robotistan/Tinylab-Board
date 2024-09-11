//LCD screen and 7-Segment Display libraries are included.
#include "LiquidTWI2.h"
#include "LedControl.h"

//Variables are created below to split the number in the guessing game.
float number = 0;
float thousands = 0;
float hundreds = 0;
float tens = 0;
float ones = 0;
float generated_number = 0;

//A position variable is defined to move the desired column of the 7-Segment Display.
float position = 0;
//LCD screen and 7-Segment Display are created with the lcd and lc variable commands.
LiquidTWI2 lcd(0x20);
LedControl lc=LedControl(10,12,11,1);

void setup() {
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //We set the 7-Segment display to off by setting it to false (off). To turn it off, the True option is used.
  lc.shutdown(0,false);
  //We set the brightness sensitivity of the 7-segment display.
  lc.setIntensity(0,8);
  //Command to clear the 7-segment display.
  lc.clearDisplay(0);
  
  //We define the potentiometer.
  pinMode(A0,INPUT);
  //We define the buttons.
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(A5,INPUT);
  //We generate our random number.
  number = round(random(1000, 9999 +1));
  //We set the position to 1 to start from the first column of the 7-Segment Display.
  position = 1;
  //We set the position to write text on the LCD screen.
  lcd.setCursor(0, 0);
  lcd.print("Guess the Number");

}

void loop() {
  
  /*According to the value of 'position', the corresponding column of the 7-Segment Display will display a number. 
   At the start, position is set to 1, meaning the first column of the 7-Segment Display will show the thousands digit.
   Since the potentiometer gives a value between 0-1023, we divide the incoming value by 110 to get a number, rounding it using the round function.
   According to the position, the set values from the potentiometer are assigned to thousands, hundreds, tens, and ones variables.*/ 
 if(position == 1){
      lc.setChar(0,0,round((analogRead(A0) / 110)),false);
      thousands = round((analogRead(A0) / 110));

    }
    if(position == 2){
      lc.setChar(0,1,round((analogRead(A0) / 110)),false);
      hundreds = round((analogRead(A0) / 110));

    }
    if(position == 3){
      lc.setChar(0,2,round((analogRead(A0) / 110)),false);
      tens = round((analogRead(A0) / 110));

    }
    if(position == 4){
      lc.setChar(0,3,round((analogRead(A0) / 110)),false);
      ones = round((analogRead(A0) / 110));

    }

    //When Button1 is pressed, it will move to the hundreds digit.
    if(digitalRead(9) == 0){
    position = 2;
  }
     //When Button2 is pressed, it will move to the tens digit.
    if(digitalRead(8) == 0){
    position = 3;
  }
  //When Button3 is pressed, it will move to the ones digit.
    if((analogRead(A5) > 185)  &&  (225 > analogRead(A5))){
    position = 4;
  }
    //When Button4 is pressed, the set numbers will be combined: thousands, hundreds, tens, ones.
    if((analogRead(A5) > 489)  &&  (529 > analogRead(A5))){
    generated_number = (thousands * 1000 + (hundreds * 100 + (tens * 10 + ones)));
  
  //If the generated number matches the random number, this condition will trigger.
      if(generated_number == number){
      lc.clearDisplay(0);
      position = 1;
      lcd.clear();
      lcd.setCursor(0, 0);

      lcd.print("Congratulations");
      delay(3000);
      lcd.setCursor(0, 0);

      lcd.print("Restarting...");
      number = round(random(1000, 9999 +1));
      delay(3000);
      lcd.clear();

    } else {

      lc.clearDisplay(0);
      position = 1;
      lcd.clear();
      lcd.setCursor(0, 0);

      lcd.print("Sorry, My Number");
      lcd.setCursor(0, 1);

      lcd.print(round(number));
      delay(3000);
      lcd.setCursor(0, 0);

      lcd.print("Restarting...");
      number = round(random(1000, 9999 +1));
      delay(3000);
      lcd.clear();

    }
    }
    delay(100);
    
}
