// Crude Data Installation Code:  MCU connects to API, gets real time value of Crude Oil every 15s
// and transmits Data to electromechanical 7 Segment Modules.
// by Maximilian Wolfs (c) 2017

/*-----( Import needed libraries )-----*/
#include <SoftwareSerial.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define SSerialRX        6//10  //Serial Receive pin
#define SSerialTX        7//11  //Serial Transmit pin
#define SSerialTxControl 3   //RS485 Direction control
#define RS485Transmit    HIGH
#define RS485Receive     LOW
#define Pin13LED         //13

/*-----( Ethernet )-----*/
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE4 };
byte server[] = { 52, 1, 229, 129 };
IPAddress ip(192, 168, 0, 177);
EthernetClient client;

/*-----( Declare objects )-----*/
SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX
/*-----( Declare Variables )-----*/
int byteReceived;
int byteSend;
int t = 0;
//char kurs[5] = "12,34";

void setup()   /****** SETUP: RUNS ONCE ******/
{
  // Start the built-in serial port, probably to Serial Monitor
  Serial.begin(9600);

  /*-----( start the Ethernet Connection Setup )-----*/
  if (Ethernet.begin(mac) == 0) {
    // Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    // Serial.println("connected");
    // // Make a HTTP request:
    // client.println("GET /apps/thinghttp/send_request?api_key=3F0DI2Q4C7W0SLZ8 HTTP/1.1"); //
    // client.println("Host: api.thingspeak.com\n");
    // client.println("Connection: close");
    // client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

  /*-----( End of Ethernet Connection Setup )-----*/

  pinMode(SSerialTxControl, OUTPUT);

  digitalWrite(SSerialTxControl, RS485Receive);  // Init Transceiver

  // Start the software serial port, to another device
  RS485Serial.begin(4800);   // set the data rate
  digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit

}

//--(end setup )---

void setData(int receiverID, int value) {
  // RS485Serial.print("[");
  // RS485Serial.print(receiverID);
  // RS485Serial.print(",");
  // RS485Serial.print(value);
  // RS485Serial.print("]");
  delay(20);
}
void loop()   {

  /*-----( Internet & Parse Kurs )-----*/

  if (client.available()) {
    char c = client.read();
    //Serial.print(c);
    delay(1000);
    int requestLength = client.available();
    char request[requestLength];
    delay(1000);
    for (int i = 0; i < requestLength ; i++) {
      request[i] = client.read();
    }
    //Serial.println(request[requestLength-5]);
    //Serial.println(request[requestLength-4]);
    //Serial.println(request[requestLength-3]);
    //Serial.println(request[requestLength-2]);
    //Serial.println(request[requestLength-1]);

    char kurs[] = {(request[requestLength - 5]),
                   (request[requestLength - 4]),
                   (request[requestLength - 3]),
                   (request[requestLength - 2]),
                   (request[requestLength - 1])
                  };

    /*-----( Set Date für RS485 Send )-----*/

    setData(0, kurs[0] - '0');
    setData(1, kurs[1] - '0');
    setData(2, kurs[3] - '0');
    setData(3, kurs[4] - '0');

    // Serial.println(kurs);

    //t++;

    delay(15000);

  }



}

//--(end main loop )---
