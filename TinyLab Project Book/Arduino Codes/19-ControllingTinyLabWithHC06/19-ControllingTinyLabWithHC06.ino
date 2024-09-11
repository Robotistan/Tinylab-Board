//We include the LCD screen library.
#include "LiquidTWI2.h"
//We define the temperature sensor to the variable LM35_PIN.
#define LM35_PIN A3
//We define the light sensor to the variable LDR_PIN.
#define LDR_PIN A2
//We convert the value from the light sensor to a percentage.
#define readLDR() (((2500.0 / (analogRead(LDR_PIN) * (5.0 / 1024.0))) - 500) / 10.0)
//We include the DS1307 library.
#include "Bonezegei_DS1307.h"
//We create a new LCD screen with the name 'lcd'.
LiquidTWI2 lcd(0x20);
//We will store the incoming data from Bluetooth in the variable str1.
String str1 = "";
//The raw form of the incoming data will be of char type.
char ch;
//Command to convert the temperature value to Celsius.
float coefficient = 500.0 / 1023.0;
//Function to read and convert the temperature to Celsius.
float readTemperature() {
  return coefficient * analogRead(LM35_PIN);
}
//Variable for the light sensor.
float light = 0;
//We define a new DS1307 variable with the name 'rtc'.
Bonezegei_DS1307 rtc(0x68);

void setup() {
  //We initialize the LCD screen.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //Communication is initiated at 9600 baud rate.
  Serial1.begin(9600);
  //We define the LEDs on the TinyLab.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  //We define the fan motor.
  pinMode(5, OUTPUT);
  //We define the buzzer.
  pinMode(A1, OUTPUT);
  //We define the temperature sensor.
  pinMode(LM35_PIN, INPUT);
  //We define the LDR light sensor.
  pinMode(LDR_PIN, INPUT);
  //We initialize the DS1307.
  rtc.begin();
}


void loop() {
  /*If there is any data coming from the serial port,
   * the condition will be triggered.
   */
  if (Serial1.available()) {
    //The data from Bluetooth is stored in the char variable 'ch'.
    ch = Serial1.read();

    //If the incoming value is 1, the L1 LED will turn on.
    if (String(ch).indexOf(String("1")) > -1) {
      digitalWrite(13, 1);
      Serial1.println("L1 ON");
    }
    //If the incoming value is 2, the L2 LED will turn on.
    if (String(ch).indexOf(String("2")) > -1) {
      digitalWrite(12, 1);
      Serial1.println("L2 ON");
    }
    //If the incoming value is 3, the L3 LED will turn on.
    if (String(ch).indexOf(String("3")) > -1) {
      digitalWrite(11, 1);
      Serial1.println("L3 ON");
    }
    //If the incoming value is 4, the L4 LED will turn on.
    if (String(ch).indexOf(String("4")) > -1) {
      digitalWrite(10, 1);
      Serial1.println("L4 ON");
    }
    //If the incoming value is 5, the L1 LED will turn off.
    if (String(ch).indexOf(String("5")) > -1) {
      digitalWrite(13, 0);
      Serial1.println("L1 OFF");
    }
    //If the incoming value is 6, the L2 LED will turn off.
    if (String(ch).indexOf(String("6")) > -1) {
      digitalWrite(12, 0);
      Serial1.println("L2 OFF");
    }
    //If the incoming value is 7, the L3 LED will turn off.
    if (String(ch).indexOf(String("7")) > -1) {
      digitalWrite(11, 0);
      Serial1.println("L3 OFF");
    }
    //If the incoming value is 8, the L4 LED will turn off.
    if (String(ch).indexOf(String("8")) > -1) {
      digitalWrite(10, 0);
      Serial1.println("L4 OFF");
    }

    //If the incoming value is 9, the DC motor will turn on.
    if (String(ch).indexOf(String("9")) > -1) {
      analogWrite(5, 255);
      Serial1.println("DC MOTOR ON");
    }
    //If the incoming value is 0, the DC motor will turn off.
    if (String(ch).indexOf(String("0")) > -1) {
      analogWrite(5, 0);
      Serial1.println("DC MOTOR OFF");
    }
    //If the incoming value is 'b', the buzzer will turn on.
    if (String(ch).indexOf(String("b")) > -1) {
      analogWrite(A1, 255);
      Serial1.println("BUZZER ON");
    }
    //If the incoming value is 'z', the buzzer will turn off.
    if (String(ch).indexOf(String("z")) > -1) {
      analogWrite(A1, 0);
      Serial1.println("BUZZER OFF");
    }
    //If the incoming value is 'h', the temperature value will be sent.
    if (String(ch).indexOf(String("h")) > -1) {
      Serial1.println(String("AIR TEMPERATURE:") + String(readTemperature()));
    }
    //If the incoming value is 'i', the light value will be sent.
    if (String(ch).indexOf(String("i")) > -1) {
      Serial1.println(String("LIGHT LEVEL:") + String(readLDR()));
    }
    //If the incoming value is 's', the time will be sent.
    if (String(ch).indexOf(String("s")) > -1) {
      rtc.getTime();
      Serial1.println(String(rtc.getHour()) + String(String(":") + String(String(rtc.getMinute()) + String(String(":") + String(rtc.getSeconds())))));
    }
    //If the incoming value is 't', the date will be sent.
    if (String(ch).indexOf(String("t")) > -1) {
      rtc.getTime();
      Serial1.println(String(rtc.getDate()) + String(String("/") + String(String(rtc.getMonth()) + String(String("/") + String(rtc.getYear())))));
    }
  }
  delay(100);
}
