//LED Control With Button

void setup() {
//define the LED's
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

 //define the buttons
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(A5,INPUT);
  
}
  
void loop() {
  //LEDs light up when button(s) are pressed
  if(digitalRead(9) == 0){
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
  }
  if(digitalRead(8) == 0){
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
  }
  if((analogRead(A5) > 185)  &&  (225 > analogRead(A5))){
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
  }
  if((analogRead(A5) > 489)  &&  (529 > analogRead(A5))){
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
  }
}
