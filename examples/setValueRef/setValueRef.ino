#include <VoltSensor.h>

VoltSensor Volt(39); // Pin ADC ESP32

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Volt.setResistor(30000.0, 7500.0); //Default value resistor R1 and R2
  Volt.setBitRef(4095.0); //Default value bit adc micro
  Volt.setVoltRef(3.3); //Default value voltage
}

void loop() {
  // put your main code here, to run repeatedly:
  float Vout_Value = Volt.Vout();
  Serial.println("Vout    : " + String(Vout_Value) + " Volt");
  float Vin_Value = Volt.Vin();
  Serial.println("Vin     : " + String(Vin_Value) + " Volt");
  int Battery = Volt.BattPersen(10.5, 12.4); // set Min and Max value Battery
  Serial.println("Percent : " + String(Battery) + "%");
  delay(1000);
}
