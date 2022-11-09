#include "mbed.h"
#include "SoundSensor.h"
#include "Grove_LCD_RGB_Backlight.h"

#define MAX_DB 130
#define MAX_BLINK_PERIOD_SEC 1

DigitalOut led(D4);

void flip_led()
{
    led = !led;
}

int main()
{
    SoundSensor soundsensor(A0);
    Grove_LCD_RGB_Backlight screen(D14, D15);
    Ticker ticker;

    while (true) {
        float decibels = soundsensor.read_db();
        printf("dB: %f\n", decibels);

        float period_seconds = MAX_BLINK_PERIOD_SEC - ((decibels / MAX_DB) * MAX_BLINK_PERIOD_SEC);
        ticker.attach(&flip_led, period_seconds);

        if (decibels >= 0 && decibels <= 70)
            screen.setRGB(0x00, 0xB2, 0x00);
        else if (decibels <= 100)
            screen.setRGB(0xFF, 0x32, 0x00);
        else
            screen.setRGB(0xB2, 0x00, 0x00);

        char dB_str[16];
        sprintf(dB_str, "%f", decibels);
        screen.clear();
        screen.locate(0, 0);
        screen.print(dB_str);
        char unit_str[] = "dB";
        screen.locate(14, 0);
        screen.print(unit_str);
    }
}

