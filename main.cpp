#include "mbed.h"
#include "SoundSensor.h"
#include <string>

#define MAX_DB 52

int main()
{
    SoundSensor soundsensor(A0);
    DigitalOut led(D4);
    Grove_LCD_RGB_Backlight screen(D14, D15);
    while (true) {
        float decibels = soundsensor.read_db();
        printf("dB: %f\n", decibels);

        char dB_str[16];
        sprintf(dB_str, "%f", decibels);
        screen.clear();
        screen.locate(0, 0);
        screen.print(dB_str);
        char unit_str[] = "dB";
        screen.locate(14, 0);
        screen.print(unit_str);

        ThisThread::sleep_for(1s);
    }
}

