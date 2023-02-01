#define K1 9 
#define K2 10
#define K3 11 
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

int huidig = 2, periode = 512;
volatile int richting = 1;
volatile unsigned long INtStart;
volatile boolean stat1, stat2, stat3;

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)); 
  PCIFR |= bit (digitalPinToPCICRbit(pin)); 
  PCICR |= bit (digitalPinToPCICRbit(pin));
}

void setup() {
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pciSetup(K1); 
  pciSetup(K2); 
  pciSetup(K3);
  INtStart = millis();
  digitalWrite(huidig, HIGH);
}

void loop() {
  switch (richting) {
    case -1:
      if ((millis() - INtStart) >= periode) {
        digitalWrite(huidig, LOW);
        if (huidig != 2) {
          huidig--;
          digitalWrite(huidig, HIGH);
        }
        else {
          huidig = LED4;
          digitalWrite(huidig, HIGH);
        }
        INtStart = millis();
      }
      break;
    case 0:
      break;
    case 1:
      if ((millis() - INtStart) >= periode) {
        digitalWrite(huidig, LOW);
        if (huidig != 5) {
          huidig++;
          digitalWrite(huidig, HIGH);
        }
        else {
          huidig = LED1;
          digitalWrite(huidig, HIGH);
        }
        INtStart = millis();
      }
      break;
  }
}

ISR (PCINT0_vect) {
  if((millis() - INtStart) < periode){
  if (digitalRead(K1) == HIGH) ;
  if ((digitalRead(K1) == LOW) ) {
    richting = -1;
    stat1 = true;
  }
  if (digitalRead(K2) == HIGH) ;
  if ((digitalRead(K2) == LOW)) {
    richting = 0;
    stat2 = true;
  }
  if (digitalRead(K3) == HIGH) ;
  if ((digitalRead(K3) == LOW) ) {
    richting = 1;
    stat3 = true;
  }

  }
  INtStart = millis();
}
