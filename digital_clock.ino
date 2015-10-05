// Arduino Clock
//

#include "SevSeg.h"

SevSeg sevseg;

#define d1 13
#define a 2

void setup() {
  // put your setup code here, to run once:
byte numDigits = 4;
   byte digitPins[] = {2, 3, 4, 5};
   byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
   sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

void loop() {
  // put your main code here, to run repeatedly:
sevseg.setNumber(3141,3); // Displays '3.141'
sevseg.refreshDisplay();
}
