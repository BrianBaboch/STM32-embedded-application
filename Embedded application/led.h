#ifndef LED_H
#define LED_H

enum values {LED_OFF = 0, LED_YELLOW = 1, LED_BLUE = 2};

void led_init();
void led_g_on();
void led_g_off();
void led(int state);

#endif
