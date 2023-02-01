const byte ledArray [] = {2 ,3 ,4 ,5};

void setup() {
  // put your setup code here, to run once:
  for ( int x = 2; x <= 5; x ++) {
  pinMode (x , OUTPUT ) ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for ( int x = 0; x <= sizeof(ledArray); x ++) {
  digitalWrite ( ledArray [x] , HIGH ) ;
  delay (500) ;
  digitalWrite ( ledArray [x] , LOW ) ;
  delay (500) ;
  }
}
