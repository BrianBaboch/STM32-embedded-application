#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdio.h>
#include <stdint.h>
#include "stm32l475xx.h"
#include "stm32l4xx.h"
#include "led.h"

void buttons_init();
void buttons_handler();

#endif //BUTTONS_H
