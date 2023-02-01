uint8_t  MSB []={0x3B ,0x0C ,0x00 ,0x00 ,0xF3};
uint8_t  LSB []={0x47 ,0x87 ,0x0F ,0x07 ,0x87};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < sizeof(MSB); i++){
    int16_t  waarde_signed = (MSB[i]*256 + LSB[i]) >> 7;
    uint16_t  waarde_unsigned = (MSB[i]*256 + LSB[i]) >> 7;
    Serial.println(waarde_unsigned, DEC);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
