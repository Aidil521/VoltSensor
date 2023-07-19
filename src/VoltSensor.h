#ifndef VOLT_SENSOR
#define VOLT_SENSOR

#include <Arduino.h>

#define DEFAULT_R1 30000.00
#define DEFAULT_R2 7500.00
#define DEFAULT_BIT 4095.00
#define DEFAULT_VOLT 5.00
#define DEFAULT_LINEAR_A 0.6589
#define DEFAULT_LINEAR_B 0.1554
// #define DEFAULT_LINEAR_C 0.9947
// #define DEFAULT_LINEAR_D 0.0296
// #define DEFAULT_CALIB_VIN 1.01864407

class VoltSensor {
    public:
        VoltSensor(int pinADC);
        void setResistor(int R1, int R2);
        void setBitRef(float nilai);
        void setVoltRef(float volt);
        void setVoutCalib(float a, float b);
        // void setVinCalib(float c, float d);
        float Vout();
        // float Vinreal();
        // float Vin();
        float Vin();
        int BattPersen(float Volt_Min, float Volt_Max);

    private:
        int _pinADC;
        int _baterai = 0;
        int read_adc = 0;
        float _R1 = DEFAULT_R1;
        float _R2 = DEFAULT_R2;
        float _bitRef = DEFAULT_BIT;
        float _voltRef = DEFAULT_VOLT;
        float _a = DEFAULT_LINEAR_A;
        float _b = DEFAULT_LINEAR_B;
        // float _c = DEFAULT_LINEAR_C;
        // float _d = DEFAULT_LINEAR_D;
};

#endif