unsigned long time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Tijd: ");
  time = millis (); //  print  tijd na programma start
  Serial.println(time); // om de  seconde  output
  delay (1000);
}
