unsigned long time;
unsigned long diff = 0;
boolean status = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  time = millis();
  Serial.print(time);
  Serial.print(diff); 
  diff = ( millis () - time );
  
}
