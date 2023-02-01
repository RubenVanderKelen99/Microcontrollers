#include <TM1636.h>

#define TEMPERATUUR_SENSOR A0
int temperatuur;
int meetwaarde;
int8_t disp[4];
TM1636 tm1636(7, 8);

void setup () {
  tm1636.init();
  Serial.begin(9600);
  disp[2] = 18; 
  disp[3] = 12; 
}

void loop () {
  meetwaarde = analogRead (TEMPERATUUR_SENSOR);
  temperatuur = meetwaarde / 4 - 110;
  disp[0] = temperatuur/10;
  disp[1] = temperatuur - (disp[0]*10);
  tm1636.display(disp);
  Serial.println(temperatuur);
  delay(1000);
}
