#define K1 9 //definieren van knopppen en LEDS
#define K2 10
#define K3 11
#define LED 5

volatile int helderheid = 10;
int interval = 255/9; 

void pciSetup (byte pin) { 
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void setup() {
  pinMode(K1, INPUT_PULLUP); //knoppen enabled
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pinMode(LED, OUTPUT); //led enabled
  pciSetup(K1); //Setup van knoppen doormiddel van methode ( pciSetup)
  pciSetup(K2);
  pciSetup(K3);
}

void loop() {
  analogWrite(LED, (helderheid*interval));
}

ISR (PCINT0_vect) {
  for (unsigned long i = 0; i < 45000; i++) { //dender
    __asm__("nop\n\t");
  }
  if (digitalRead(K1) == LOW && helderheid != 9) helderheid++; //als knop 1 wordt ingedrukt en helderheid is verschillend van 
  if (digitalRead(K2) == LOW) helderheid = 0;                   //als knop 2 wordt ingedrukt
  if (digitalRead(K3) == LOW && helderheid != 0) helderheid--;  //als knop 3 wordt ingedrukt

}
