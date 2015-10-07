// Arduino Clock
//

#include "SevSeg.h"

#define d1 13
#define a 0
#define f 7
#define d2 12
#define d3 11
#define b 1
#define e 6
#define d 5
#define dp 9
#define c 4
#define g 8 
#define d4 10 
#define HOUR_BUTTON 2
#define MINUTE_BUTTON 3

volatile int hour = 1;
volatile int minute = 0;
SevSeg sevseg;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(HOUR_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(HOUR_BUTTON), hourUp, RISING);
  pinMode(MINUTE_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MINUTE_BUTTON), minuteUp, RISING);

  byte numDigits = 4;
  byte digitPins[] = {d1, d2, d3, d4};
  byte segmentPins[] = {a, b, c, d, e, f, g, dp};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

void loop() {
  // put your main code here, to run repeatedly:
  sevseg.setNumber(hour * 100 + minute, 3);
  sevseg.refreshDisplay();
}

void hourUp() {
  hour = hour + 1;
  if (hour > 12) {
    hour = 1;
  }
}
void minuteUp() {
  minute = minute + 1;
  if (minute > 59) {
    minute = 0;
    hourUp();
  }
}
