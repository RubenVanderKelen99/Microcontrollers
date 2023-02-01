#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>
#include <TM1636.h>

#define TEMPERATUUR_SENSOR A0
int temperatuur, meetwaarde;
TM1636 tm1636(7, 8); //7-segment display + array
int8_t disp[4] = {17, 17, 17, 17};
unsigned long tijd;
boolean stat = true;

void setup()  {
  Serial.begin(9600);
  while (!Serial) ; // wait until Arduino Serial Monitor opens
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if (timeStatus() != timeSet)
    Serial.println("RTC sync mislukt");
  else
    Serial.println("RTC sync OK");
  tm1636.init(); //Initialize 7-segment display
  tijd = millis();
}

void loop() {
  if (millis() - tijd >= 3000) {
    stat = !stat;
    tijd = millis();
  }
  if (stat) digitalClockDisplay();
  else toonTemperatuur();
    
}

void toonTemperatuur() {
  tm1636.point(false);
  meetwaarde = analogRead (TEMPERATUUR_SENSOR);
  temperatuur = meetwaarde / 4 - 95;
  disp[0] = temperatuur/10;
  disp[1] = temperatuur - (disp[0]*10);
  disp[2] = 18;
  disp[3] = 12; //Hexadecimaal C = 12
  tm1636.display(disp);
}

void digitalClockDisplay() {
  tm1636.point(true);
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
