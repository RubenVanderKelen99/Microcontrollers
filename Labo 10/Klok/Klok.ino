#include <TimerOne.h> //Schets -> bibliotheek gebruiken
#include <TM1636.h>

TM1636 tm1636(7, 8); //7-segment display + array
int8_t disp[4] = {17, 17, 17, 17}; // 17 = empty spot (wordt niet getoond op 7-segment display)

int minuut; //decl
int seconde = 0; //teller begint bij 0 seconden

void setup() {
  Timer1.initialize(1000000); //1s voor normaal
  // Timer1.initialize(200000); //200ms voor test
  Timer1.attachInterrupt(timerIsr);
  tm1636.init(); //Initialize 7-segment display
  tm1636.point(true); //zet dubbelpunt aan
  tm1636.display(disp);
}

void loop() {
  //Resetten van Sec.
  if (seconde > 59) {
    minuut++;
    seconde = 0;
  }

  //  Seconden schrijven naar Disp-array
  if (seconde < 10) {
    disp[2] = 0;
    disp[3] = seconde;
  } else {
    disp[2] = seconde / 10;
    disp[3] = seconde - (disp[2] * 10);
  }

  // Minuten schrijven naar Disp-array
  if (minuut < 10 && minuut != 0) {
    disp[0] = 0;
    disp[1] = minuut;
  } else {
    disp[0] = minuut / 10;
    disp[1] = minuut - (disp[0] * 10);
  }
  tm1636.display(disp);
}

void timerIsr() {
  seconde++; //update teller
}
