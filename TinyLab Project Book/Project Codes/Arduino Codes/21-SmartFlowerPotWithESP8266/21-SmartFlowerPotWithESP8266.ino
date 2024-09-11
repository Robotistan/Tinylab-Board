//Communication library is included.
#include <SoftwareSerial.h>
//Function to send data is created.
String sendData(String command, const int timeout, boolean debug) {
  //Response is initially empty.
  String response = "";
  //The Command variable from the function is sent.
  Serial1.print(command);
  //A timeout variable is created.
  long int time = millis();
  /*If a response comes from Serial within the expected time,
   * it is stored in the char variable 'c'.
   */
  while ((time + timeout) > millis()) {
    while (Serial1.available()) {
      //The incoming data is read.
      char c = Serial1.read();
      response += c;
    }
  }
  //If there is an error, the error message will be read.
  if (debug) {
    Serial.print(response);
  }
  return response;
}
//WIFI SSID is defined.
String _SSID = "SSID";
//WIFI password is written.
String _PSWD = "PASSWORD";
//thingspeak.com IP address
#define IP "184.106.153.149"
//Enter your API key for retrieving data from thingspeak.com here.
String api_key = "WMZKC04WJ9HU982Q";
//Function to send humidity data is created.
void send_temp(int temp, String field) {
  /*The 'temp' variable in the function represents the value from the humidity sensor, 
   * the 'field' variable indicates the column in thingspeak where the data will be sent.
   * If you haven't assigned a name to the field, simply use 'field1'.
   */
  //The start command is sent using ESP commands.
  Serial.println(String("AT+CIPSTART=\"TCP\",\"") + IP + "\",80");
  Serial1.println(String("AT+CIPSTART=\"TCP\",\"") + IP + "\",80");
  delay(1000);
  //Checks for any errors.
  if (Serial1.find("Error"))

  {
    Serial.println("AT+CIPSTART Error");
    return;
  }
  //This part will create the URL for thingspeak.
  String cmd = "GET /update?key=";
  cmd += api_key;
  cmd += "&" + field + "=";
  cmd += (int(temp));
  cmd += "\r\n\r\n";
  delay(3000);
  //ESP commands to send data are written.
  Serial.print("AT+CIPSEND=");
  Serial1.print("AT+CIPSEND=");
  Serial.println(cmd.length() + 2);
  Serial1.println(cmd.length() + 2);
  delay(1000);

  if (Serial1.find(">")) {
    Serial.print(cmd);
    Serial1.print(cmd);
    Serial.print("\r\n\r\n");
    Serial1.print("\r\n\r\n");
  }

  else {
    Serial.println("AT+CIPCLOSE");
    Serial1.println("AT+CIPCLOSE");
  }
}

void setup() {
  //ESP communication and serial communication are initiated.
  Serial.begin(9600);
  Serial1.begin(115200);
  //Humidity sensor is defined.
  pinMode(A1, INPUT);
  //DC motor is defined.
  pinMode(5, OUTPUT);
  //A startup message is sent to the ESP module.
  sendData("AT\r\n", 1000, true);
  sendData("AT\r\n", 1000, true);
  //The ESP mode is set to mode 1.
  sendData("AT+CWMODE=1\r\n", 2000, true);
  //The ESP is restarted.
  sendData("AT+RST\r\n", 3000, true);
  //The ESP searches for WiFi.
  sendData("AT+CWQAP\r\n", 3000, true);
  sendData("AT+CWLAP\r\n", 5000, true);
  //The ESP connects to the WiFi network.
  sendData("AT+CWJAP=\"" + _SSID + "\",\"" + _PSWD + "\"\r\n", 10000, true);
  sendData("AT+CIFSR\r\n", 4000, true);
}

void loop() {
  //The soil moisture sensor sends its value.
  send_temp(analogRead(A1), "field1");
  if (analogRead(A1) < 100) {
    //The DC motor is activated.
    analogWrite(5, 255);
    delay(100000);
    analogWrite(5, 0);

  } else {
    analogWrite(5, 0);
  }
  //The system waits for 30 seconds.
  delay(30000);
}
