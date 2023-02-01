void setup() {
  // put your setup code here, to run once:
  for ( int x = 2; x <= 5; x ++) {
  pinMode (x , OUTPUT ) ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for ( int x = 2; x <= 5; x ++) {
  digitalWrite ( x , HIGH ) ;
  delay (500) ;
  digitalWrite (x , LOW ) ;
  delay (500) ;
  }
}
