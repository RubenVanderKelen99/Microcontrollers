#include <TimerOne.h>

#define LED 5
volatile long int helderheid = 30;
volatile boolean optellen = true;

void setup() {
  Timer1.initialize(5000);
  Timer1.attachInterrupt(timerIsr);
  Serial.begin(9600);
}

void loop() {
  analogWrite(LED,helderheid); //laat het led branden met de meegegeven helderheid
  Serial.println(helderheid); //print helderheid
}

void timerIsr() {
  if (helderheid <= 0 || helderheid >= 255) optellen = !optellen;
  if (optellen) helderheid++;
  if (!optellen) helderheid--;
}
