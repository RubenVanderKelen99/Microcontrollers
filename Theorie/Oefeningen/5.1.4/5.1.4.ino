void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int b = 0x4445;
  int a = 0x100;
  Serial.println(b/a,HEX);
  
  Serial.println(float(9/2));
  Serial.println (9/float(2));
}

void loop() {
  // put your main code here, to run repeatedly:

}
