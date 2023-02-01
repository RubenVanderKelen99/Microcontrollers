#include <Time.h>
#include <TimeLib.h>

time_t tijd = 1526464961 + 7200; //2 uur bijtellen voor GMT+2

void setup() {
  setTime(tijd);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    delay(1000);
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.print("     ");
    Serial.print(dayStr(weekday()));
    Serial.print(" ");
    Serial.print(day());
    Serial.print(" ");
    Serial.print(monthStr(month()));
    Serial.print(" ");
    Serial.print(year());
    Serial.println();
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print("0");
  Serial.print(digits);
}
