//CountdownWith7segmentDisplay
//We include the 7-Segment display library.
#include "LedControl.h"

//We define the potentiometer.
#define POT_PIN     A0

//We define the variable 'count' to observe the countdown.
float count = 0;

//We define a new 7-segment display with the variable name 'lc'.
LedControl lc=LedControl(10,12,11,1);

//We define the variable 'ssContent' to send the value of 'count' as text to the 7-segment display.
String ssContent;

void setup() {
//We set the 7-Segment display to off by setting it to false (off). To turn it off, the True option is used.
  lc.shutdown(0,false);
//We set the brightness sensitivity of the 7-segment display.
  lc.setIntensity(0,8);
//Command to clear the 7-segment display.
  lc.clearDisplay(0);
//We define the potentiometer.
  pinMode(POT_PIN, INPUT);
//We define the button on digital pin 9.
  pinMode(9,INPUT);
}

void loop() {
//Since the potentiometer gives a max value of 1023, the formula below is used to obtain the number 9999.
  count = round((analogRead(POT_PIN) * 9.774));
//Since the 'count' variable is a numeric value, we convert it to text to display on the 7-segment display.
  ssContent = String(round(count));
  
//With the loop below, 'ssContent' will first be broken into characters and each will be added to each column of the 7-segment display.
  for (int i = 0; (i < ssContent.length())/* && i < 4*/; i++) {
    if (i > 3) {
        delay(100);
        lc.setChar(0,0,ssContent.charAt(i-3),false);
        lc.setChar(0,1,ssContent.charAt(i-2),false);
        lc.setChar(0,2,ssContent.charAt(i-1),false);
        lc.setChar(0,3,ssContent.charAt(i),false);
    }
    else{
      lc.setChar(0,i,ssContent.charAt(i),false);
    }
        
  }
  delay(100);
  lc.clearDisplay(0);
//We set the condition for when the button is pressed.
  if(digitalRead(9) == 0){
  //As long as the countdown is not zero, the values within the loop will be added to the 7-segment display at 0.1 second intervals.
    while(!(count == 0)){
      ssContent = String(round(count));
      for (int i = 0; (i < ssContent.length())/* && i < 4*/; i++) {
          if (i > 3) {
            delay(100);
            lc.setChar(0,0,ssContent.charAt(i-3),false);
            lc.setChar(0,1,ssContent.charAt(i-2),false);
            lc.setChar(0,2,ssContent.charAt(i-1),false);
            lc.setChar(0,3,ssContent.charAt(i),false);
          }
          else{
            lc.setChar(0,i,ssContent.charAt(i),false);
          }      
      }
      count += -1;
      delay(100);
      lc.clearDisplay(0);
    }

  }
}
