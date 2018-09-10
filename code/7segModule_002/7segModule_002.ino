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

byte rx = 127;

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

setDigit(0);
  updateSegments();
delay(5000);
}

void loop() {
  if (RS485Serial.available()) {
    if (rx == 127) {
      rx = RS485Serial.read();
    } else {
      byte val = RS485Serial.read();
      if (rx == myID) {
        setDigit(val);
        updateSegments();
      }
      rx = 127;
      receiver.reset();
    }
  }
}

void setDigit(byte val) {
      setState(0, bitRead(val, 6));
      setState(1, bitRead(val, 5));
      setState(2, bitRead(val, 4));
      setState(3, bitRead(val, 3));
      setState(4, bitRead(val, 2));
      setState(5, bitRead(val, 1));
      setState(6, bitRead(val, 0));
}

void initDisplay() {
  updateSegments();
}

void setState(int sec, int pos) {
  nextState[sec] = pos;
}

void setDir(int d) {
  if (d == 1) {
    digitalWrite(FORW, 0);
    digitalWrite(BACK, 1);
  } else {
    digitalWrite(FORW, 1);
    digitalWrite(BACK, 0);
  }
}


void selectSegment(int sec) {
  switch (sec) {
    case 0:
      digitalWrite(AD0, 0);
      digitalWrite(AD1, 0);
      digitalWrite(AD2, 0);
      break;
    case 1:
      digitalWrite(AD0, 1);
      digitalWrite(AD1, 0);
      digitalWrite(AD2, 0);
      break;
    case 2:
      digitalWrite(AD0, 0);
      digitalWrite(AD1, 1);
      digitalWrite(AD2, 0);
      break;
    case 3:
      digitalWrite(AD0, 1);
      digitalWrite(AD1, 1);
      digitalWrite(AD2, 0);
      break;
    case 4:
      digitalWrite(AD0, 0);
      digitalWrite(AD1, 0);
      digitalWrite(AD2, 1);
      break;
    case 5:
      digitalWrite(AD0, 1);
      digitalWrite(AD1, 0);
      digitalWrite(AD2, 1);
      break;
    case 6:
      digitalWrite(AD0, 0);
      digitalWrite(AD1, 1);
      digitalWrite(AD2, 1);
      break;

  }
}


void setSegment(int sec, int pos) {
  setDir(pos);
  // delay(100);
  selectSegment(sec);
  //  delay(100);
//  digitalWrite(EN, 1);
//  delay(400);
  softpwm(12000);
  digitalWrite(EN, 0);
}

void softpwm(long t) {
 for (int i = 0; i< t;i++) {
  digitalWrite(EN, 1);
  delayMicroseconds(55);
  digitalWrite(EN, 0);
  delayMicroseconds(5);
 }
}


void updateSegments() {
  if (currentState[6] == 0 && nextState[6] == 1) {
    for (int i = 6; i >= 0; i--) {
      if (currentState[i] != nextState[i]) {
        setSegment(i, nextState[i]);
        currentState[i] = nextState[i];
        //delay(500);
      }
    }
  } else {
    for (int i = 0; i < 7; i++) {
      if (currentState[i] != nextState[i]) {
        setSegment(i, nextState[i]);
        currentState[i] = nextState[i];
        //delay(500);
      }
    }

  }
}
