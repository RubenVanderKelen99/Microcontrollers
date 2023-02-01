void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
  byte a = 0x80;
  byte b = 0x90;
  Serial.println(a+b,HEX);
  byte c = a-b;
  Serial.println(a-b,HEX);
  Serial.println(c,HEX);
}

void loop() {
	// put your main code here, to run repeatedly:
	
}
