#include <VoltSensor.h>

VoltSensor::VoltSensor() {
    setResistor(_R1, _R2);
    setVoltRef(_voltRef);
    setBitRef(_bitRef);
    setVoutCalib(_a, _b);
}

void VoltSensor::setPins(uint8_t pinADC) {
    _pinADC = pinADC;
    pinMode(_pinADC, INPUT);
}

void VoltSensor::setResistor(int R1, int R2) {
    _R1 = R1;
    _R2 = R2;
}

void VoltSensor::setBitRef(float nilai) {
    _bitRef = nilai;
}

void VoltSensor::setVoltRef(float volt) {
    _voltRef = volt;
}

void VoltSensor::setVoutCalib(float a, float b) {
    _a = a;
    _b = b;
}

float VoltSensor::getVout() {
    static float read_adc;
    for (uint16_t _i = 0; _i < 500; _i++) {
        read_adc += (float)analogRead(_pinADC);
    }
    read_adc /= 500.0f;
    return (_a * ((read_adc * _voltRef) / _bitRef)) + _b; // y = a*x + b
}

float VoltSensor::getVin() {
    //Formula Voltage Divider: Vin = Vout / (R2/(R1+R2))
    return (getVout() / (_R2 / (_R1 + _R2))); 
}

uint8_t VoltSensor::getPercent(float Volt_Min, float Volt_Max) {
    _battery = map((getVin() * 10.0f), (Volt_Min * 10.0f), (Volt_Max * 10.0f), 0, 100);
    if(_battery > 100) _battery = 100;
    if(_battery < 0)   _battery = 0;
    return _battery;
}

VoltSensor Volt;