#include <TM1636.h>

#define K1 9
#define K2 10
#define K3 11
int8_t geboortejaar[4] = {1, 9, 9, 9};  
int8_t geboortemaand[4] = {17, 17, 0, 1}; 
int8_t geboortedag[4] = {17, 17, 2, 7};  
int8_t disp[4]; 
int periode = 500;
boolean punt = true; 
unsigned long seconden;
TM1636 tm1636(7, 8);

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR |= bit (digitalPinToPCICRbit(pin));
  PCICR |= bit (digitalPinToPCICRbit(pin));
}
void setup() {
  tm1636.init();
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pciSetup(K1);
  pciSetup(K2); 
  pciSetup(K3);
  seconden = millis(); 
}

void loop() {
  tm1636.point(punt);
  tm1636.display(disp);
  if ((millis()) - seconden >= periode) {
    punt = !punt;
    seconden = millis();
  }
}
ISR (PCINT0_vect) {
  wacht(); 
  if (digitalRead(K1) == LOW) {
    for (int i = 0; i < 4; i++) {
      disp[i] = geboortejaar[i];
    }
  }
  if (digitalRead(K2) == LOW) {
    for (int i = 0; i < 4; i++) {
      disp[i] = geboortemaand[i];
    }
  }
  if (digitalRead(K3) == LOW) {
    for (int i = 0; i < 4; i++) {
      disp[i] = geboortedag[i];
    }
  }
}

void wacht() {
  for (unsigned long i = 0; i < 30000
  
  ; i++) {
    __asm__("nop\n\t");
  }
}
