void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String string = "Content-Type: text/html";
  if(string.substring(19).equals("html")){
    Serial.println("gelijk aan html");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
