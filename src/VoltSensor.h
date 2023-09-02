#ifndef VOLT_SENSOR_H
#define VOLT_SENSOR_H

#include <Arduino.h>

#define DEFAULT_R1 30000.00f
#define DEFAULT_R2 7500.00f
#define DEFAULT_BIT 4095.00f
#define DEFAULT_VOLT 5.00f
#define DEFAULT_LINEAR_A 0.6541f
#define DEFAULT_LINEAR_B 0.0968f
// #define DEFAULT_LINEAR_C 0.9947
// #define DEFAULT_LINEAR_D 0.0296
// #define DEFAULT_CALIB_VIN 1.01864407

class VoltSensor {
    public:
        VoltSensor();
        void setPins(uint8_t pinADC);
        void setResistor(int R1, int R2);
        void setBitRef(float nilai);
        void setVoltRef(float volt);
        void setVoutCalib(float a, float b);
        float getVout();
        float getVin();
        uint8_t getPercent(float Volt_Min, float Volt_Max);

    private:
        uint8_t _pinADC;
        uint8_t _battery = 0;
        float _R1 = DEFAULT_R1;
        float _R2 = DEFAULT_R2;
        float _bitRef = DEFAULT_BIT;
        float _voltRef = DEFAULT_VOLT;
        float _a = DEFAULT_LINEAR_A;
        float _b = DEFAULT_LINEAR_B;
};

extern VoltSensor Volt;
#endif