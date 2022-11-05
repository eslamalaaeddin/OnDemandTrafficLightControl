/*
 * button.h
 *
 * Created: 10/9/2022 12:05:31 AM
 *  Author: IslamAlaaEddin
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "..\..\DIO Driver\dio.h"

#define BUTTON1_PORT PORT_C
#define BUTTON1_PIN PIN1

#define BUTTON2_PORT PORT_D
#define BUTTON2_PIN PIN7

#define BUTTON_LOW 0
#define BUTTON_HIGH 1

//Button init to make pin whic is ocnnected to button as input pin
void Button_init(uint8_t portNumber, uint8_t pinNumber);

void Button_read_state(uint8_t portNumber, uint8_t pinNumber, uint8_t *returnValue);



#endif /* BUTTON_H_ */