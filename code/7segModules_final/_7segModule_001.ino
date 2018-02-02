// Crude Data Installation Code: 7 Segment Module Code. Receiving Data via RS485. Each Module has an unique ID
// and converts assigned number to Display.
// by Maximilian Wolfs (c) 2017

#include <SoftwareSerial.h>
#include "Streaming.h"
#include "SerialReceiver.h"

#define myID 0

#define SSerialRX        0  //Serial Receive pin
#define SSerialTX        1  //Serial Transmit pin

#define SSerialTxControl 3   //RS485 Direction control
#define RS485Transmit    HIGH
#define RS485Receive     LOW

SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX
SerialReceiver receiver = SerialReceiver();
int currentNumber =-2;
int currentState[7] = { -1, -1, -1, -1, -1, -1, -1};
int nextState[7] = {0, 0, 0, 0, 0, 0, 0};

int FORW = 3; // 5
int BACK = 4; // 6

int AD0 = 11; //17
int AD1 = 12; //18
int AD2 = 13; //19

int EN = A5;// 28 (analog 5)
int STAT_PIN = A2;

int c = 0;
int stat = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(FORW, OUTPUT);
  pinMode(BACK, OUTPUT);

  pinMode(AD0, OUTPUT);
  pinMode(AD1, OUTPUT);
  pinMode(AD2, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(STAT_PIN, OUTPUT);

  RS485Serial.begin(4800);   // set the data rate

  //initDisplay();
  digitalWrite(EN, 0);
  digitalWrite(AD1, 0);
  digitalWrite(AD2, 0);
  digitalWrite(AD2, 0);
  digitalWrite(STAT_PIN, 0);

setDigit(-1);
  updateSegments();
delay(10000);
}



void loop() {
  if (RS485Serial.available()) {
    Serial.println("dd");
    receiver.process(RS485Serial.read());
    if (receiver.messageReady()) {
      int id = receiver.readInt(0);
      int val = receiver.readInt(1);
      if (id == myID) {
        if (val != currentNumber) {
        setDigit(-1);
        updateSegments();
        delay(250);
        setDigit(val);
        updateSegments();
        }
      }
      receiver.reset();
      /*
        Serial.print("id=");
        Serial.print(id);
        Serial.print("   val=");
        Serial.println(val);
        receiver.reset();
      */
    }
  }

  stat = !stat;

  digitalWrite(STAT_PIN, stat);
  /*

    digitalWrite(FORW, 0);
    digitalWrite(BACK, 1);

    digitalWrite(EN, 1);
    delay(1000);
    digitalWrite(EN, 0);

    digitalWrite(FORW, 1);
    digitalWrite(BACK, 0);

    digitalWrite(EN, 1);
    delay(1000);
    digitalWrite(EN, 0);
  */
  /*
    setDigit(-1);
    updateSegments();
    setDigit(c % 10);
    updateSegments();
    delay(2000);
    c++;
  */

  // int r = random(7);
  // nextState[r] = !currentState[r];

}


void setDigit(int number) {
currentNumber = number;
  switch (number) {
    case -1:
      setState(0, 0);
      setState(1, 0);
      setState(2, 0);
      setState(3, 0);
      setState(4, 0);
      setState(5, 0);
      setState(6, 0);
      break;

    case 0:
      setState(0, 1);
      setState(1, 1);
      setState(2, 1);
      setState(3, 1);
      setState(4, 1);
      setState(5, 1);
      setState(6, 0);
      break;
    case 1:
      setState(0, 0);
      setState(1, 1);
      setState(2, 1);
      setState(3, 0);
      setState(4, 0);
      setState(5, 0);
      setState(6, 0);
      break;
    case 2:
      setState(0, 1);
      setState(1, 1);
      setState(2, 0);
      setState(3, 1);
      setState(4, 1);
      setState(5, 0);
      setState(6, 1);
      break;
    case 3:
      setState(0, 1);
      setState(1, 1);
      setState(2, 1);
      setState(3, 1);
      setState(4, 0);
      setState(5, 0);
      setState(6, 1);
      break;
    case 4:
      setState(0, 0);
      setState(1, 1);
      setState(2, 1);
      setState(3, 0);
      setState(4, 0);
      setState(5, 1);
      setState(6, 1);
      break;
    case 5:
      setState(0, 1);
      setState(1, 0);
      setState(2, 1);
      setState(3, 1);
      setState(4, 0);
      setState(5, 1);
      setState(6, 1);
      break;
    case 6:
      setState(0, 1);
      setState(1, 0);
      setState(2, 1);
      setState(3, 1);
      setState(4, 1);
      setState(5, 1);
      setState(6, 1);
      break;
    case 7:
      setState(0, 1);
      setState(1, 1);
      setState(2, 1);
      setState(3, 0);
      setState(4, 0);
      setState(5, 0);
      setState(6, 0);
      break;
    case 8:
      setState(0, 1);
      setState(1, 1);
      setState(2, 1);
      setState(3, 1);
      setState(4, 1);
      setState(5, 1);
      setState(6, 1);
      break;
    case 9:
      setState(0, 1);
      setState(1, 1);
      setState(2, 1);
      setState(3, 1);
      setState(4, 0);
      setState(5, 1);
      setState(6, 1);
      break;

  }

}

void initDisplay() {
  updateSegments();
}

void setState(int sec, int pos) {
  nextState[sec] = pos;
}
