#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"

class SoundSensor {
    public:
        SoundSensor(PinName sound_sensor_pin);
        float read_db();
    private:
        AnalogIn _sound_sensor;
};
