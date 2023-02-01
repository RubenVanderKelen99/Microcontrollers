const byte ledArray [] = {2 , 3, 4, 5 } ;
int x = 2 ;
#define K1 9
#define K2 10
#define K3 11


void setup() {
  // put your setup code here, to run once:
  for ( int x = 2; x <= 5; x ++) {
    pinMode (x , OUTPUT ) ;
  }
  digitalWrite (x , HIGH ) ;
  pinMode (K1 ,  INPUT_PULLUP ) ;
  pinMode (K2 , INPUT_PULLUP ) ;
  pinMode (K3 ,  INPUT_PULLUP ) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(K1) == LOW) {
    digitalWrite(x , LOW ) ;
    if ( x == 2 ) {
      x = 5 ;
    }
    else {
      x--;
    }
  }

  if (digitalRead(K3) == LOW) {
    digitalWrite(x , LOW ) ;
    if ( x == 5 ) {
      x = 2 ;
    }
    else {
      x++;
    }
  }
  if (digitalRead(K2) == LOW) {
    digitalWrite(x , LOW ) ;
    x = 2 ;
  }

  digitalWrite(x, HIGH ) ;
  delay(200);
}
