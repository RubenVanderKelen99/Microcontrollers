int teller = 0;
int richting = 1;
const byte ledArray [] = {2 ,3 ,4 ,5};

void setup() {
  // put your setup code here, to run once:
  for ( int x = 0; x <= 3; x ++) {
  pinMode (ledArray [x] , OUTPUT ) ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (teller == 0) {
    richting = 1 ;
  }
  else if (teller == 3){
    richting = -1 ;
  }
  digitalWrite ( ledArray [teller] , HIGH );
  delay (1000);
  digitalWrite ( ledArray [teller] , LOW ) ;
  teller = teller + richting;
  
  
 }
