#include <VoltSensor.h>

VoltSensor::VoltSensor(int pinADC) {
    _pinADC = pinADC;
    setResistor(_R1, _R2);
    setVoltRef(_voltRef);
    setBitRef(_bitRef);
    setVoutCalib(_a, _b);
    // setVinCalib(_c, _d);
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

// void VoltSensor::setVinCalib(float c, float d) {
//     _c = c;
//     _d = d;
// }

float VoltSensor::Vout() {
    for (uint8_t _j = 0; _j < 200; _j++) {
        read_adc += analogRead(_pinADC);
    }
    read_adc /= 200;
    float Vout_real = ((float)read_adc * _voltRef) / _bitRef;
    float Vout_Calib = 0.6589*Vout_real + 0.1554;
    return Vout_Calib;
}

// float VoltSensor::Vinreal() {
//     //Formula Linear y = ax + b; (x = adc) and (y = Vout Real)
//     float Volt = Vout() / (_R2 / (_R1 + _R2)); 
//     return Volt;
// }

float VoltSensor::Vin() {
    //Formula Linear y = cx + d; (x = Vout / B) and (y = Vin Real)
    //Value B = R2/(R1+R2)
    // float Volt = _c * Vinreal() + _d;
    float Vin_real = Vout() / (_R2 / (_R1 + _R2));  
    // float Vin_Calib = 0.063 + 1.0148 * Vin_real;
    return Vin_real;
}

int VoltSensor::BattPersen(float Volt_Min, float Volt_Max) {
    _baterai = map((Vin()*10.0), (Volt_Min * 10.0), (Volt_Max * 10.0), 0, 100);
    if(_baterai > 100) {
        _baterai = 100;
    }
    else if(_baterai < 0) {
        _baterai = 0;
    }
    return _baterai;
}