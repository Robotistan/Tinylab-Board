//Notes with the buzzer
//define the buzzer pin and notes
#define buzzerPin A1
int C = 262;
int D = 294;
int E = 330;
int F = 349;
int G = 392;
int A = 440;
int B = 494;
int C_ = 523;

void setup() {
  //define the buzzer pin
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  //We call the notes with 0.5 second intervals.
  tone(buzzerPin, C);
  delay(500);
  noTone(buzzerPin);
  tone(buzzerPin, D);
  delay(500);
  noTone(buzzerPin);
  tone(buzzerPin, E);
  delay(500);
  noTone(buzzerPin);
  tone(buzzerPin, F);
  delay(500);
  noTone(buzzerPin);
  tone(buzzerPin, G);
  delay(500);
  noTone(buzzerPin);
  tone(buzzerPin, A);
  delay(500);
  noTone(buzzerPin);
  tone(buzzerPin, B);
  delay(500);
  noTone(buzzerPin);
  tone(buzzerPin, C_);
  delay(500);
  noTone(buzzerPin);
}
