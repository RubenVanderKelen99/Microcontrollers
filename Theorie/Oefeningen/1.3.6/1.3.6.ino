void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
  for(int i = 2; i <= 8; i +=2){
    Serial.println(i);
  }
}

void loop() {
	// put your main code here, to run repeatedly:
	
}
