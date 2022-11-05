/*
 * registers.h
 *
 * Created: 10/8/2022 10:28:48 PM
 *  Author: IslamAlaaEddin
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include ".\utils\types.h"

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//Port A 
// #define PORTA *((volatile uint8_t*)0x3B);	
// #define DDRA *((volatile uint8_t*)0x3A);	
// #define PINA *((volatile uint8_t*)0x39);	


/************************************************************************/
/* Timer 0 Reg                                                          */
/************************************************************************/

#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR *((volatile uint8_t*)0x58)

#endif /* REGISTERS_H_ */