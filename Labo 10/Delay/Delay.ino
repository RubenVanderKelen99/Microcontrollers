#include <TimerOne.h> //Schets - > bib gebruiken
long int teller1 = 0;
long int teller2 = 0;
unsigned long tijd;

void setup() {
  Timer1.initialize(1000); //1 ms bij begin
  Timer1.attachInterrupt(timerIsr); //interrupt
  Serial.begin(9600); //seriele poort open zetten
  tijd = millis();
}

void loop() {
  delay(1);
  teller1++;
  if (teller1 % 1000 == 0  ) {
    Serial.print("delay: ");
    Serial.println(teller1);
  }

if (teller2 % 1000 == 0  ) {
    Serial.println("timer: ");
    Serial.println(teller2);
}
  tijd = millis();
}

void timerIsr() {
  teller2++;
}
