// Crude Data Installation Code: ESP8266 MCU connects to API, gets real time value of Crude Oil every 15s
// and transmits Data to electromechanical 7 Segment Modules.
// by Maximilian Wolfs (c) 2017

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define SSerialRX        16//10  //Serial Receive pin R0
#define SSerialTX        4//11  //Serial Transmit pin DI
#define SSerialTxControl 5   //RS485 Direction control DE+RE
#define RS485Transmit    HIGH
#define RS485Receive     LOW
#define Pin13LED         //13

SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

const char* ssid     = "XT1052";
const char* password = "xast0952";

const char* host = "api.thingspeak.com";
const char* streamId   = "....................";
const char* privateKey = "....................";

int byteReceived;
int byteSend;
int t = 0;

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  pinMode(SSerialTxControl, OUTPUT);
  digitalWrite(SSerialTxControl, RS485Receive);  // Init Transceiver
  RS485Serial.begin(4800);   // set the data rate
  digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit

}

void setData(int receiverID, int value) {
  RS485Serial.print("[");
  RS485Serial.print(receiverID);
  RS485Serial.print(",");
  RS485Serial.print(value);
  RS485Serial.print("]");
  delay(20);
}

int value = 0;

void loop() {
  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);



if (client.available()) {


    setData(0, kurs[0] - '0');
    setData(1, kurs[1] - '0');
    setData(2, kurs[3] - '0');
    setData(3, kurs[4] - '0');

    Serial.println(kurs);


    delay(15000);

  }
}
