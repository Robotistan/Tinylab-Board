//define the libraries
#include <SoftwareSerial.h>
//define the variable 
int case=0;
void setup(){
//define the buttons
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(A5,INPUT);
//define the potentiometer and RGB LED
  pinMode(A0,INPUT);
  Serial.begin(115200);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
    
}

void loop() {

  case = 0;
  if(digitalRead(9) == 0){
    case = 1;
  }    
  if(digitalRead(8) == 0){
    case = 2;
  }  
  if((analogRead(A5) > 185)  &&  (225 > analogRead(A5))){
    case = 3;

  }     
  if((analogRead(A5) > 489)  &&  (529 > analogRead(A5))){
    case = 4;
  }
 
//Conditioning is done according to the value of the case variable.
  if(case == 1){
    Serial.println(String("Kırmızı:") + String(round((analogRead(A0) * 0.249))));
    analogWrite(3,round((analogRead(A0) * 0.249)));
    analogWrite(5,0);
    analogWrite(6,0);

  }
  if(case == 2){
    Serial.println(String("Yeşil:") + String(round((analogRead(A0) * 0.249))));
    analogWrite(3,0);
    analogWrite(5,round((analogRead(A0) * 0.249)));
    analogWrite(6,0);

  }
  if(case == 3){
    Serial.println(String("Mavi:") + String(round((analogRead(A0) * 0.249))));
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,round((analogRead(A0) * 0.249)));

  }
  if(case == 4){
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,0);
  }
}
