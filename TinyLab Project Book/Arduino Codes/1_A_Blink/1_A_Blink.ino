//Blink Project
void setup() {
//define the LED Pin's 
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
 

}


void loop() {
  
//We make the LEDs flash sequentially once in 0.5 seconds.
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,0);
  delay(500);
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,0);
  digitalWrite(10,0);
  delay(500);
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,1);
  digitalWrite(10,0);
  delay(500);
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,1);
  delay(500);
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,0);
  delay(500);
}
