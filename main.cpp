#include "mbed.h"
#include "SoundSensor.h"
#include <string>

#define N_SAMPLES 1000

int main()
{
    SoundSensor soundsensor(A0);
    Grove_LCD_RGB_Backlight screen(D14, D15);
    while (true) {
        float sum = 0.0;
        float avg  = 0.0;
        for (int i = 0; i < N_SAMPLES; i++) {
            sum += soundsensor.read_db();
            ThisThread::sleep_for(1ms);
        }
        avg = sum / N_SAMPLES;
        printf("avg: %f\n", avg);
        printf("sum: %f\n\n", avg);
        char avg_str[] = "abc\0";
        screen.clear();
        screen.setRGB(255, 192, 203);
        screen.print(avg_str);
        ThisThread::sleep_for(1s);
    }
}

