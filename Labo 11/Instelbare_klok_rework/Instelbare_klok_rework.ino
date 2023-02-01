#include <Time.h>
#include <TimeLib.h>
#include <TM1636.h>

#define K1 9
#define K2 10
#define K3 11

boolean selector, stat;
TM1636 tm1636(7, 8); //7-segment display + array
int8_t disp[4] = {17, 17, 17, 17};
unsigned long tijd;
time_t t = 1526053890 + 7200; //2 uur bijtellen voor GMT+2

void setup() {
  setTime(t);
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
  tm1636.init();
}

void loop() {
  if (millis() - tijd >= 500) {
    digitalClockDisplay();
    tm1636.point(stat);
    tm1636.display(disp);
    tijd = millis();
    stat = !stat;
  }
 /* if (millis() - tijd >= 500) {
      if (selector) {
        disp[0] = 17;
        disp[1] = 17;
        tm1636.display(disp);
      }
      else {
        disp[2] = 17;
        disp[3] = 17;
        tm1636.display(disp);
      }
  }*/
}

void digitalClockDisplay() {
  //Schrijven van seconden naar Disp-array
  if (minute() < 10) {
    disp[2] = 0;
    disp[3] = minute();
  } else {
    disp[2] = minute() / 10;
    disp[3] = minute() - (disp[2] * 10);
  }

  //Schrijven van minuten naar Disp-array
  if (hour() < 10 && hour() != 0) {
    disp[0] = 0;
    disp[1] = hour();
  } else {
    disp[0] = hour() / 10;
    disp[1] = hour() - (disp[0] * 10);
  }
  tm1636.display(disp);
}

void pciSetup (byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect) {
  for (unsigned long i = 0; i < 45000; i++) { //dender
    __asm__("nop\n\t");
  }
  if (digitalRead(K1) == LOW) selector = !selector; //selector true = uren, false = minuten
  if (digitalRead(K2) == LOW && selector) {
    adjustTime(-3600); // 1 uur aftrekken
    digitalClockDisplay();
  }
  if (digitalRead(K2) == LOW && !selector) {
    adjustTime(-60); // 1 minuut aftrekken
    digitalClockDisplay();
  }
  if (digitalRead(K3) == LOW && selector) {
    adjustTime(3600); // 1 uur bijtellen
    digitalClockDisplay();
  }
  if (digitalRead(K3) == LOW && !selector) {
    adjustTime(60); // 1 minuut bijtellen
    digitalClockDisplay();
  }
}
