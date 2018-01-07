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

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

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
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/apps/thinghttp/send_request?api_key=3F0DI2Q4C7W0SLZ8";

  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  /* 
   *  
// Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  */
  
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
  
  Serial.println();
  Serial.println("closing connection");


    setData(0, kurs[0] - '0');
    setData(1, kurs[1] - '0');
    setData(2, kurs[3] - '0');
    setData(3, kurs[4] - '0');

    Serial.println(kurs);

    //t++;

    delay(15000);

  }
}


