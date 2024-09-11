//required libraries: ExtEEPROM.h for 24LC256, Wire.h for I2C communication
#include "extEEPROM.h"
#include <Wire.h>
//24LC256 I2C address
#define hwaddress 0x50
//Definition for I2C EEPROM
extEEPROM eeprom(kbits_256, 1, 64, hwaddress);

void setup() {
  Serial.begin(9600);
  Serial.println("EEPROM write example.");
  delay(3000);
  //Write temperature values to EEPROM until the address value reaches 256
  for (int addr = 0; addr <= 256; addr++) {
    //Read the LM35 sensor and convert the value to Celsius
    int val = (5.0 * analogRead(A3) * 100.0) / 1024;
    //Write the value to the byte specified by the 'addr' in EEPROM
    eeprom.write(addr, val);
    //Print the current EEPROM address being read
    Serial.print(addr);
    //Leave a space
    Serial.print("\t");
    //Print the temperature value written to EEPROM
    Serial.println(val);
    delay(200);
  }
  Serial.print("End of memory reached.");
}

void loop() {
}
