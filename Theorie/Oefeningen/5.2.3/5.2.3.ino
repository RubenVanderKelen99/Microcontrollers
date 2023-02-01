void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  unsigned int a = 0x1234;
  unsigned int b = 0x0FFF;
  unsigned int c = 0x00F0;
  unsigned int d = 0xF00F;
  unsigned int e = a&b;
  unsigned int f = e|c;
  unsigned int g = f^d;
  Serial.println(e,HEX);
  Serial.println(e,BIN);
  Serial.println(f,HEX);
  Serial.println(f,BIN);
  Serial.println(g,HEX);
  Serial.println(g,BIN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
