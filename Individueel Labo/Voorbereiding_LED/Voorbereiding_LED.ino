#define K1 9
#define LED 3

long tijd = 0;
int teller = 0;
boolean dimmen = true;
int waarde = 255;


void setup() {
  // put your setup code here, to run once:
  pinMode(K1,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((digitalRead(K1) == LOW)){
    if (dimmen){
      waarde -=10;
    }else{
      waarde += 10;
    }
    tijd = millis();
    teller ++;
    
  }
  
  if(waarde < 0){
   waarde = 0; 
  }else if( waarde > 255){
    waarde = 255;
  }
  
  analogWrite(LED,waarde);

  if ((digitalRead(K1) == HIGH)){
    if (dimmen){
      waarde = 255;
    }else{
      waarde = 0;
    }
    tijd = millis();
    teller = 0;
    digitalWrite(LED,LOW);
  }
  delay(200);
  
  if(teller%25 == 0){
    dimmen = !dimmen;
  }
  
}
