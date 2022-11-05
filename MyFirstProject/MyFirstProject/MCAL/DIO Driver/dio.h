/*
 * dio.h
 *
 * Created: 10/8/2022 10:47:10 PM
 *  Author: IslamAlaaEddin
 */ 


#ifndef DIO_H_
#define DIO_H_

//all internal typedefs
//all driver macros
//all driver function prototypes

#include "..\..\utils\types.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define DIRECTION_IN 0
#define DIRECTION_OUT 1

#define LOW 0
#define HIGH 1

#define FALSE 0
#define TRUE 1

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *returnValue);


#endif /* DIO_H_ */