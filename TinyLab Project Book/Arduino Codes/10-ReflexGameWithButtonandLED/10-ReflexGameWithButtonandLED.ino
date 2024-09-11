//Reflex Game With Button and LED
//LCD screen library is included.
#include "LiquidTWI2.h"
//The 'turn' variable is used to calculate whose turn it is for the button.
int turn = 0;
//The speed of the game is set in milliseconds.
int game_speed = 100;
//The LCD screen is created with the 'lcd' variable.
LiquidTWI2 lcd(0x20);

void setup() {
  //LCD screen settings are initialized.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //LEDs on TinyLab are initialized.
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  //Buttons are initialized.
  pinMode(9,INPUT);
  pinMode(8,INPUT);  
  pinMode(A5,INPUT);  
  //Game speed is set to 300 milliseconds.
  game_speed = 300;
  
  //The turn will be determined with each button press.
  turn = 0;
  
  //An infinite loop is created using while(1) to continuously cycle through the LEDs.
  while(1) {
    //1st LED turns on and 'turn' variable is set to 1.
    turn = 1;
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    delay(int(game_speed));
  //2nd LED turns on and 'turn' variable is set to 2.
    turn = 2;
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,0);
    delay(int(game_speed));
  //3rd LED turns on and 'turn' variable is set to 3.
    turn = 3;
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(10,0);
    delay(int(game_speed));
  //4th LED turns on and 'turn' variable is set to 4.
    turn = 4;
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    delay(int(game_speed));  
  }
    
}

void loop() {
  //If S1 button is pressed, the if condition is triggered.
  if(digitalRead(9) == 0){
      //The 'turn' variable indicates whether we caught the LED.
    if(turn == 1){
      lcd.clear();
      lcd.setCursor(0, 0);

      lcd.print("Congrats, You Win");

    }else{
      lcd.clear();
      lcd.setCursor(0, 0);

      lcd.print("Sorry");
      lcd.setCursor(0, 1);

      lcd.print("Try Again");
    }
  }
  //If S2 button is pressed, the if condition is triggered.
  if(digitalRead(8) == 0){
    if(turn == 2){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Congrats, You Win");

    }else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sorry");
      lcd.setCursor(0, 1);
      lcd.print("Try Again");
    }
  }
  
  //If S3 button is pressed, the if condition is triggered.
  if((analogRead(A5) > 185)  &&  (225 > analogRead(A5))){
    if(turn == 3){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Congrats, You Win");
    }else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sorry");
      lcd.setCursor(0, 1);
      lcd.print("Try Again");
    }
  }

  //If S4 button is pressed, the if condition is triggered.
  if((analogRead(A5) > 489)  &&  (529 > analogRead(A5))){
    if(turn == 4){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Congrats, You Win");

    }else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sorry");
      lcd.setCursor(0, 1);
      lcd.print("Try Again");
    }
  }
}
