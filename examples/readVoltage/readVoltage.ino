#include <VoltSensor.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Volt.setPins(36);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Vin_Value = Volt.getVin();
  Serial.println("Voltage Input  : " + String(Vin_Value) + " Volt");
  float Percent_Batt = Volt.getPercent(10.6, 12.6);
  Serial.println("Percent Battery: " + String(Percent_Batt) + " Volt");
  delay(1000);
}
