//We include communication libraries.
#include <Wire.h>
#include <SoftwareSerial.h>

//We include the nRF24L01 library.
#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"
//We include the Joystick library.
#include "DynamicHID.h"
#include "Joystick.h"

//We define the pins for the nRF24L01 and create a wireless variable.
RF24 wireless(9, 8);  // CE, CSN

//Wireless communication channels are created.
const byte channel[][6] = { "00001", "00002", "00003", "00004" };

//Joystick variable is defined for the joystick.
Joystick_ Joystick;

//Joystick button positions are defined.
int pos_x = 0;
int pos_y = 0;
int a_btn = 0;
int b_btn = 0;
int c_btn = 0;
int d_btn = 0;
int e_btn = 0;
int f_btn = 0;
int joy_btn = 0;

//Function to split the data from wireless communication and assign it to joystick buttons.
void readValues(String message) {

  String joy_x = message.substring(1, 5);
  //Convert x-axis value to integer.
  pos_x = joy_x.toInt();
  String joy_y = message.substring(6, 10);
  pos_y = joy_y.toInt();

  String btn_a = message.substring(11, 13);
  //Convert a button value to integer.
  a_btn = btn_a.toInt();

  String btn_b = message.substring(13, 15);
  //Convert b button value to integer.
  b_btn = btn_b.toInt();

  String btn_c = message.substring(15, 17);
  //Convert c button value to integer.
  c_btn = btn_c.toInt();

  String btn_d = message.substring(17, 19);
  //Convert d button value to integer.
  d_btn = btn_d.toInt();

  String btn_e = message.substring(19, 21);
  //Convert e button value to integer.
  e_btn = btn_e.toInt();

  String btn_f = message.substring(21, 23);
  //Convert f button value to integer.
  f_btn = btn_f.toInt();

  String btn_joy = message.substring(23, 25);
  //Convert joystick button value to integer.
  joy_btn = btn_joy.toInt();
  //Clear the message string.
  message = "";
}

void setup() {
  //nRF24L01 is initialized.
  wireless.begin();
  wireless.openWritingPipe(channel[0]);
  wireless.setPALevel(RF24_PA_MIN);
  wireless.startListening();
  delay(150);
  //Communication is initialized.
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);

  //Joystick is initialized.
  Joystick.begin();
}

void loop() {
  /*The following if condition checks if wireless is available.
   * The incoming data is placed into the nrf_text variable,
   * split using the readValues function,
   * and assigned to the joystick button variables.
   */
  if (wireless.available()) {
    char nrf_text[32] = "";
    wireless.read(&nrf_text, sizeof(nrf_text));
    readValues(String(nrf_text));
    Joystick.setXAxis(pos_x);
    Joystick.setYAxis(pos_y);
    Joystick.setButton(0, !a_btn);
    Joystick.setButton(1, !b_btn);
    Joystick.setButton(2, !c_btn);
    Joystick.setButton(3, !d_btn);
    Joystick.setButton(4, !e_btn);
    Joystick.setButton(5, !f_btn);
    Joystick.setButton(6, !joy_btn);
  }
}
