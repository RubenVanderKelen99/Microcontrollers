#include <TM1636.h> 
TM1636 tm1636(7,8); 
int8_t disp[4]; 
boolean puntStatus = true; 

void setup() {
  tm1636.init(); 
}

void loop() {
  disp[0]=1; 
  disp[1]=2; 
  disp[2]=3;
  disp[3]=4;
  tm1636.display(disp);  
  tm1636.point(puntStatus); 
  puntStatus = !puntStatus; 
  delay(500);
}
