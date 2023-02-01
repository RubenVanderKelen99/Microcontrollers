void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  byte a = 12;  // DEC
  byte b = B10; // BIN
  Serial.println(a*b,HEX);
  int c = 0x1234;
  int d = 0x100;
  Serial.println(c*d,HEX);
}

void loop() {
  // put your main code here, to run repeatedly:

}
