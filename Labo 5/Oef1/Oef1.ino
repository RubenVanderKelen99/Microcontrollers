#define K1 9 
#define K2 10 
#define K3 11 
#define LED1 2 

boolean status = false;
unsigned long tijd;

void setup() {
  pinMode ( K1 , INPUT_PULLUP ) ; 
  pinMode ( K2 , INPUT_PULLUP ) ; 
  pinMode ( K3 , INPUT_PULLUP ) ; 
  pinMode ( LED1 , OUTPUT ) ; 
}

void loop() {
  if ( digitalRead ( K1 ) == LOW ){
    status = true; 
    tijd = millis();
  }

  if (status){
    do{
      if (digitalRead( K2) == LOW)
        digitalWrite(LED1, HIGH);

      if (digitalRead( K3) == LOW)
        digitalWrite(LED1, LOW);
    }
    while((millis() - tijd) < 1000);    
    status = false; 
    while(digitalRead(K1) == LOW); 
  }


}
