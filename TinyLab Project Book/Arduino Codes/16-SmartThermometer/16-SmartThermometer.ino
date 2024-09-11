//Temperature sensor variable is defined.
#define LM35_PIN A3
//Temperature is converted to Celsius degrees.
float coefficient = 500.0 / 1023.0;
//Temperature reading function is created.
float readTemperature() {
  return coefficient * analogRead(LM35_PIN);
}

void setup() {
  //Temperature value is defined.
  pinMode(LM35_PIN, INPUT);
  //Potentiometer is defined.
  pinMode(A1, INPUT);
  //Fan motor is defined.
  pinMode(5, OUTPUT);
}

void loop() {
  /*When the temperature exceeds 27 degrees,
   * the condition for starting the fan and 
   * adjusting the fan speed based on the potentiometer 
   * is written below.
   * The potentiometer value ranges between 0 and 1023,
   * The fan motor value ranges between 0-255.
   * The potentiometer value is multiplied by 0.249 for 
   * the conversion for the fan.
   */
  if (readTemperature() > 27) {
    analogWrite(5, round((analogRead(A1) * 0.249)));

  } else {
    analogWrite(5, 0);
  }
}
