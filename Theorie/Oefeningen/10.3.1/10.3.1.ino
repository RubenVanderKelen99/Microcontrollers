#include <Time.h>
#include <TimeLib.h>
time_t tijd1 = 1460504736;
time_t tijd2 = 1460508456;

void setup() {
  // put your setup code here, to run once:
  setTime(tijd2);
  Serial.begin(9600);
  delay(1001);
  Serial.println(hour(now() - tijd1));
  Serial.println(minute(now() - tijd1));
  Serial.println(second(now() - tijd1));
  Serial.println((now() - tijd1)/60);
}

void loop() {
  // put your main code here, to run repeatedly:

}
