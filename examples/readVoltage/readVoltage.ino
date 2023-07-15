#include <VoltSensor.h>

VoltSensor Volt(39); // Pin ADC ESP32

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Vin_Value = Volt.Vin();
  Serial.println("Vin     : " + String(Vin_Value) + " Volt");
  int Battery = Volt.BattPersen(10.5, 12.4);  // set Min and Max value Battery
  Serial.println("Percent : " + String(Battery) + "%");
  delay(1000);
}
