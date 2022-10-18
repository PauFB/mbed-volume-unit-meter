#include "mbed.h"
#include "SoundSensor.h"
#include <cmath>

#define INPUT_VOLTAGE 3.3
#define MAX_LUX_VALUE 728

SoundSensor::SoundSensor(PinName sound_sensor_pin): _sound_sensor(sound_sensor_pin) {
    _sound_sensor = AnalogIn(sound_sensor_pin);
};

float SoundSensor::read_db() {
    float vOut = INPUT_VOLTAGE * _sound_sensor.read();
    float sensitivity_v_pa = pow(10, 50/20);
    return 94 + (20 * log10(vOut / sensitivity_v_pa));
}
