#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

#define LED 6
#define INTERRUPT 0

boolean ledstate = false;

void update_vals() {
  ledstate = !ledstate;
  digitalWrite(LED, ledstate);
}

void setup() {
  Wire.begin();
  rtc.begin();

  // Activate the 1hz output
  rtc.writeSqwPinMode(SquareWave1HZ);

  pinMode(LED, OUTPUT);
  attachInterrupt(INTERRUPT, update_vals, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
}
