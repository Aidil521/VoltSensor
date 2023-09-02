#include <VoltSensor.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Volt.setPins(36);
  Volt.setResistor(30000.0, 7500.0); //Default value resistor R1 and R2
  Volt.setBitRef(4095.0); //Default value bit adc micro
  Volt.setVoltRef(5.0); //Default value voltage
  Volt.setVoutCalib(DEFAULT_LINEAR_A, DEFAULT_LINEAR_B); //Default value calibration linear Vout data A = sensor, and B = mannual measurement
}

void loop() {
  // put your main code here, to run repeatedly:
  float Vout_Value = Volt.getVout();
  Serial.println("Voltage Output : " + String(Vout_Value) + " Volt"); //range value 0 - 3.3V
  float Vin_Value = Volt.getVin();
  Serial.println("Voltage Input  : " + String(Vin_Value) + " Volt"); //range value in power input
  delay(1000);
}
