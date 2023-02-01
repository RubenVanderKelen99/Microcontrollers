int toestand = 0;
int vorigeToestand = 0;
int i = 0;
int j = 0;
void setup() {
  pinMode (9, INPUT_PULLUP);
  pinMode (2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  toestand = digitalRead(9);
  delay(50);
  if (toestand != vorigeToestand){
     if (toestand==HIGH and i==0) {
        digitalWrite (2, HIGH);
        j=1;
      }
     else if (toestand==LOW and j==1){
      i=1;
     }
   else if (toestand==HIGH and i==1){
    digitalWrite (2, LOW);
    j=0;
   }
   else if (toestand==LOW and j==0) {
    i=0;
   }
   }
    vorigeToestand=toestand;
   }
