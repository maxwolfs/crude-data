// Crude Data Installation Code: 7 Segment Module Code. Receiving Data via RS485. Each Module has an unique ID
// and converts assigned number to Display.
// by Maximilian Wolfs (c) 2017

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
  delayMicroseconds(45);
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
