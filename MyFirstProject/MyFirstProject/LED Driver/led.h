/*
 * led.h
 *
 * Created: 10/8/2022 11:37:18 PM
 *  Author: IslamAlaaEddin
 */ 


#ifndef LED_H_
#define LED_H_

#include "..\DIO Driver\dio.h"

void LED_init(uint8_t portNumber, uint8_t pinNumber);
void LED_on(uint8_t portNumber, uint8_t pinNumber);
void LED_off(uint8_t portNumber, uint8_t pinNumber);
void LED_toggle(uint8_t portNumber, uint8_t pinNumber);

void LED_blink(uint8_t portNumber, uint8_t pinNumber);
#endif /* LED_H_ */