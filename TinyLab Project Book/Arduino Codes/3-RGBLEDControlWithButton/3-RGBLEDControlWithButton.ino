//RGB LED Control With Button
void setup() {

//define the RGB LED's
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

//define the buttons
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(A5,INPUT);
  
}
 
void loop() {
//We condition the moment when the button is pressed with an if interrupt.
   if(digitalRead(9) == 0){
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
  }
     
  if(digitalRead(8) == 0){
    analogWrite(3,0);
    analogWrite(5,255);
    analogWrite(6,0);
  }
   
  if((analogRead(A5) > 185)  &&  (225 > analogRead(A5))){
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,255);

  } 

  if((analogRead(A5) > 489)  &&  (529 > analogRead(A5))){
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,0);

  }
}
