#define K1 9
#define K2 10 
#define K3 11 
#define LED1 2 

int teller = 0;
boolean statusLED = false;

void setup() {
  pinMode ( K1 , INPUT_PULLUP ) ; 
  pinMode ( K2 , INPUT_PULLUP ) ; 
  pinMode ( K3 , INPUT_PULLUP ) ; 
  pinMode ( LED1 , OUTPUT ) ; 
  Serial.begin(9600) ;
}

void loop() {

digitalWrite(LED1, HIGH);
delay(50);
digitalWrite(LED1, LOW);

/*if(statusLED == false){
    digitalWrite(LED1, HIGH);
    statusLED = true;
  }else{
    digitalWrite(LED1, LOW);
    statusLED = false;
  }*/
    
  if(digitalRead(K1) == LOW){ 
    teller++;
  }
  
  if(digitalRead(K2) == LOW){
     Serial.println(teller);
  }
  
  if (digitalRead(K3) == LOW){ 
    teller = 0;
  }
}
