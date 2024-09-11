//We include communication libraries.
#include <Wire.h>
#include <SoftwareSerial.h>
//We include the nRF24L01 library.
#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"

//We define the pins for the nRF24L01 and create a wireless variable.
RF24 wireless(9, 8);  // CE, CSN

//Wireless communication channels are created.
const byte channel[][6] = { "00001", "00002", "00003", "00004" };

//Joystick button positions are defined.
#define x_axis A0  // x-axis
#define y_axis A1  // y-axis
#define button1 8  // joystick button
#define button2 2  // A button
#define button3 3  // B button
#define button4 4  // C button
#define button5 5  // D button
#define button6 6  // E button
#define button7 7  // F button

//The data string to be sent is defined as 'dataString'.
String dataString = "";


void setup() {
  //nRF24L01 is initialized.
  wireless.begin();
  wireless.openWritingPipe(channel[0]);
  wireless.setPALevel(RF24_PA_MIN);
  wireless.stopListening();
}


void loop() {
  //Start character for the data string.
  dataString += "$";
  //If the x-axis value is less than 1000, add a 0.
  if (analogRead(x_axis) < 1000) dataString += "0";
  //If the x-axis value is less than 100, add a 0.
  if (analogRead(x_axis) < 100) dataString += "0";
  //If the x-axis value is less than 10, add a 0.
  if (analogRead(x_axis) < 10) dataString += "0";
  //Add the x-axis value to the string to be sent.
  dataString += String(analogRead(x_axis));
  dataString += ",";
  //If the y-axis value is less than 1000, add a 0.
  if (analogRead(y_axis) < 1000) dataString += "0";
  //If the y-axis value is less than 100, add a 0.
  if (analogRead(y_axis) < 100) dataString += "0";
  //If the y-axis value is less than 10, add a 0.
  if (analogRead(y_axis) < 10) dataString += "0";
  //Add the y-axis value to the string to be sent.
  dataString += String(analogRead(y_axis));
  dataString += ",";
  //Add button1 value to the string to be sent.
  dataString += String(digitalRead(button1));
  dataString += ",";
  //Add button2 value to the string to be sent.
  dataString += String(digitalRead(button2));
  dataString += ",";
  //Add button3 value to the string to be sent.
  dataString += String(digitalRead(button3));
  dataString += ",";
  //Add button4 value to the string to be sent.
  dataString += String(digitalRead(button4));
  dataString += ",";
  //Add button5 value to the string to be sent.
  dataString += String(digitalRead(button5));
  dataString += ",";
  //Add button6 value to the string to be sent.
  dataString += String(digitalRead(button6));
  dataString += ",";
  //Add button7 value to the string to be sent.
  dataString += String(digitalRead(button7));
  dataString += "#";
  String nrf_data = dataString;
  int nrf_data_len = nrf_data.length() + 1;
  char nrf_text[nrf_data_len];
  nrf_data.toCharArray(nrf_text, nrf_data_len);
  wireless.write(&nrf_text, sizeof(nrf_text));
  dataString = "";
  delay(50);
}
