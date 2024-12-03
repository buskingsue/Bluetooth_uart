#include "led.h"



void ledInit(LED *led)
{
    *(led->port - 1) |=(1<<led->pin);   // 출력 설정

}


void ledOn(LED *led)
{
    *(led->port) |= (1<<led->pin);

}


void ledOff(LED *led)
{
    *(led->port) &= ~(1<<led->pin);
}
