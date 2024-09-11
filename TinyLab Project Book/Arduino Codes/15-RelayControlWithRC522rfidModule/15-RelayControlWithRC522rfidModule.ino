//We include the LCD screen library.
#include "LiquidTWI2.h"
//We include the RFID card library.
#include "MFRC522.h"
#include "SPI.h"
//We assign relay information to the variable.
#define relay_pin A4
//We create the LCD screen with the 'lcd' variable.
LiquidTWI2 lcd(0x20);
//We write our own RFID card ID to the 'str1' variable.
String str1 = "c0aa9ae";
//A byte variable is created for the RFID card ID.
byte readCard[4];
//The 'successRead' variable is created to check if the card is read successfully.
int successRead;
//The RFID card's ID is assigned to the 'kartid' variable.
String kartid;
//RFID is created with the 'mfrc522' variable.
MFRC522 mfrc522(10, 9);
MFRC522::MIFARE_Key key;
//A function is created to get the ID.
int getID() {
  //The new card reading state of the 'mfrc522' variable is checked.
  if ( !mfrc522.PICC_IsNewCardPresent()) {
    return 0;
  }
  //The card's ID reading state is checked.
  if ( !mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }
  //The 'kartid' variable is cleared.
  kartid = "";
  //The RFID card is written byte by byte to the 'kartid' variable.
  for (int i = 0; i < mfrc522.uid.size; i++) {
    readCard[i] = mfrc522.uid.uidByte[i];
    /*Since 'kartid' is a string,
      * each byte from the card reading 
      * is added to the 'kartid' variable.
      */
    kartid = kartid + String(readCard[i], HEX);
  }
  //Card reading is stopped.
  mfrc522.PICC_HaltA();
  //If reading is successful, it returns 1.
  return 1;
}

void setup() {
//The LCD screen is initialized.
  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
//SPI communication is started for the RFID.
  SPI.begin();
//RFID card is initialized.
  mfrc522.PCD_Init();
//The relay is defined.
  pinMode(relay_pin, OUTPUT);
//Button S1 is defined to turn off the relay.
  pinMode(9,INPUT);
}

void loop() {
  /*The card is read and 
   * returns 1 if successful, otherwise 0.
   */
  successRead = getID();
  if(successRead){
      /*The condition is created 
       * based on the validity of the card data in 'kartid' and 'str1'.
       */
    if(kartid == str1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CARD CORRECT");
      //If the card is correct, the relay will turn on.
      digitalWrite(relay_pin, HIGH);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CARD INCORRECT");
      digitalWrite(relay_pin, LOW);
    }
  }
     //When button S1 is pressed, the relay will be turned off.
  if(digitalRead(9) == 0){
    digitalWrite(relay_pin, LOW);
  }
       
}
