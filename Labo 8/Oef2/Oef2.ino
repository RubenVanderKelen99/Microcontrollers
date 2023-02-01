#include <Licht.h>

Licht licht(13);

void setup() {
  // put your setup code here, to run once: 
}

void loop() {
  // put your main code here, to run repeatedly:
  licht.aan();
  delay(100);
  licht.flits (50);
  delay(100); 
  licht.uit(); 
}
