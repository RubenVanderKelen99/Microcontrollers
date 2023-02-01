int karakter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available () > 0) {
    karakter = Serial.read();
    Serial.print("Het karakter is: ") ;
    Serial.print(karakter, HEX) ;
    Serial.write("H") ;
    Serial.println("") ;
  }
}
