// Crude Data Installation Code: 7 Segment Module Code. Receiving Data via RS485. Each Module has an unique ID
// and converts assigned number to Display.
// by Maximilian Wolfs (c) 2017

#include <SoftwareSerial.h>
#include "Streaming.h"
#include "SerialReceiver.h"

const byte myID = 0; // Id of Module

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
    // Serial.println("dd");
    receiver.process(RS485Serial.read());
    if (receiver.messageReady()) {
      byte id = (byte)receiver.readChar(0,0);
      byte val = (byte)receiver.readChar(1,0);
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

    }
  }

  stat = !stat;

  digitalWrite(STAT_PIN, stat);

}

void setDigit(byte val) {
currentNumber = val;
      setState(0, bitRead(val, 0));
      setState(1, bitRead(val, 1));
      setState(2, bitRead(val, 2));
      setState(3, bitRead(val, 3));
      setState(4, bitRead(val, 4));
      setState(5, bitRead(val, 5));
      setState(6, bitRead(val, 6));
}

void initDisplay() {
  updateSegments();
}

void setState(int sec, int pos) {
  nextState[sec] = pos;
}
