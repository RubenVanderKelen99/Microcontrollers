#define var 0x41
#define var2 0x0D
#define var3 0x0A
String voorNaam = "Ruben" ;
String achterNaam = "Van der Kelen" ;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(var) ;
  Serial.write(var) ;
  Serial.print("Ruben") ;
  Serial.write(var2) ;
  Serial.write(var3) ;
  Serial.write("Van der Kelen");
}

void loop() {
  // put your main code here, to run repeatedly:

}
