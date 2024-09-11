//define the buzzer pin 
#define buzzerPin A1
//define the notes.
int C = 262;
int D = 294;
int E = 330;
int F = 349;
int G = 392;
int A = 440;
int B = 494;
int C_ = 523;

void setup() {
  //Define the sensors
  pinMode(buzzerPin,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(8,INPUT);
}

void loop() {
  //If the button is pressed, play the notes according to the potentiometer.
  if(digitalRead(8) == 1){
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, G);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, A);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, D);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, B);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, C_);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, B);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, G);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, B);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, D);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, D);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, B);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, F);
    delay(analogRead(A0));
    noTone(buzzerPin);
    tone(buzzerPin, E);
    delay(analogRead(A0));
    noTone(buzzerPin);
  }    
}
