#include "mbed.h"
#include "SoundSensor.h"
#include <cmath>

#define INPUT_VOLTAGE 5
#define N_SAMPLES 1000

SoundSensor::SoundSensor(PinName sound_sensor_pin): _sound_sensor(sound_sensor_pin) {
    _sound_sensor = AnalogIn(sound_sensor_pin);
};

float SoundSensor::read_db() {
    float sum = 0.0;
    float avg  = 0.0;
    for (int i = 0; i < N_SAMPLES; i++) {
        sum += pow(_sound_sensor.read(), 2);
        // can not sleep for less than 1ms
        ThisThread::sleep_for(1ms);
    }
    avg = sqrt(sum / N_SAMPLES);

    float vOut = INPUT_VOLTAGE * avg;
    float sensitivity_v_pa = pow(10, 50/20) / 100;
    return 94 + (20 * log10(vOut / sensitivity_v_pa));
}
