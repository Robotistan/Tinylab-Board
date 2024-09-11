//DS1307 library is included.
#include "Bonezegei_DS1307.h"
//Temperature sensor is defined.
#define LM35_PIN A3
//SD card library is included.
#include <SD.h>
//Communication libraries are included.
#include <Wire.h>
#include <SoftwareSerial.h>
//DS1307 is created with the variable name 'rtc'.
Bonezegei_DS1307 rtc(0x68);
//Air temperature is converted to Celsius value.
float coefficient = 500.0 / 1023.0;

//Function to read air temperature is defined.
float readTemperature() {
  return coefficient * analogRead(LM35_PIN);
}

//SD card pin selection.
const int chipSelect = 4;

void setup() {
  //DS1307 initialization.
  rtc.begin();

  //Temperature sensor initialization.
  pinMode(LM35_PIN, INPUT);
  delay(3000);
  //SD card check.
  if (!SD.begin(chipSelect)) {
  }
  /* According to the SD card status, LED L1 and L4 will work.
   * If the SD card can write data, LED L1 will turn on.
   * If there is an issue or failure, LED L4 will turn on.
   * When creating or naming files, avoid using special characters
   * and keep file names short.
   */
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  //Get the time from the DS1307.
  rtc.getTime();
  //Create a file named 'file.txt' on the SD card.
  File dataFile = SD.open("file.txt", FILE_WRITE);
  //If the file is writable.
  if (dataFile) {
    dataFile.println(String(String(rtc.getHour()) + String(String(":") + String(String(rtc.getMinute()) +
      String(String(":") + String(rtc.getSeconds()))))) + String(String(String(" ") + String(String(rtc.getDate()) +
      String(String("/") + String(String(rtc.getMonth()) + String(String("/") + String(rtc.getYear())))))) +
      String(String(" Temp:") + String(String(readTemperature()) + String(" Celsius")))));
    dataFile.close();
    //If data is written, LED L1 will turn on.
    digitalWrite(13, 1);
  } else {
    //If data cannot be written, LED L4 will turn on.
    digitalWrite(10, 1);
  }
  //Wait for 10 seconds.
  delay(10000);
}
