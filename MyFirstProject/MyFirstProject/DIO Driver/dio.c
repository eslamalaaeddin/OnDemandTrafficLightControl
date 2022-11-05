/*
 * dio.c
 *
 * Created: 10/8/2022 10:47:20 PM
 *  Author: IslamAlaaEddin
 */ 
//include lower layer modules
//function defs
//global variables

#include "dio.h"
//#include "..\registers.h"
#include <avr/io.h>


void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber)
	{
		/////////////////////// PORT A /////////////////////////
		case PORT_A:
			if (direction == DIRECTION_IN)
			{
				DDRA &= ~(1 << pinNumber);
			}
			else if (direction == DIRECTION_OUT)
			{
				DDRA |= (1 << pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
		/////////////////////// PORT B /////////////////////////	
		case PORT_B:
		if (direction == DIRECTION_IN)
		{
			DDRB &= ~(1 << pinNumber);
		}
		else if (direction == DIRECTION_OUT)
		{
			DDRB |= (1 << pinNumber);
		}
		else
		{
			//Error Handling
		}
		break;
		/////////////////////// PORT C /////////////////////////
		case PORT_C:
		if (direction == DIRECTION_IN)
		{
			DDRC &= ~(1 << pinNumber);
		}
		else if (direction == DIRECTION_OUT)
		{
			DDRC |= (1 << pinNumber);
		}
		else
		{
			//Error Handling
		}
		break;
		/////////////////////// PORT D /////////////////////////
		case PORT_D:
		if (direction == DIRECTION_IN)
		{
			DDRD &= ~(1 << pinNumber);
		}
		else if (direction == DIRECTION_OUT)
		{
			DDRD |= (1 << pinNumber);
		}
		else
		{
			//Error Handling
		}
		break;

	}
}

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch(portNumber)
	{
		/////////////////////// PORT A /////////////////////////
		case PORT_A:
		if (value == LOW)
		{
			PORTA &= ~(1 << pinNumber);
		}
		else if (value == HIGH)
		{
			PORTA |= (1 << pinNumber);
		}
		else
		{
			//Error Handling
		}
		break;
		/////////////////////// PORT B /////////////////////////
		case PORT_B:
		if (value == LOW)
		{
			PORTB &= ~(1 << pinNumber);
		}
		else if (value == HIGH)
		{
			PORTB |= (1 << pinNumber);
		}
		else
		{
			//Error Handling
		}
		break;
		/////////////////////// PORT C /////////////////////////
		case PORT_C:
		if (value == LOW)
		{
			PORTC &= ~(1 << pinNumber);
		}
		else if (value == HIGH)
		{
			PORTC |= (1 << pinNumber);
		}
		else
		{
			//Error Handling
		}
		break;
		/////////////////////// PORT D /////////////////////////
		case PORT_D:
		if (value == LOW)
		{
			PORTD &= ~(1 << pinNumber);
		}
		else if (value == HIGH)
		{
			PORTD |= (1 << pinNumber);
		}
		else
		{
			//Error Handling
		}
		break;

	}
}
//void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *returnValue)
{
	switch(portNumber)
	{
		case PORT_A:
			*returnValue = (PINA & (1 << pinNumber)) >> pinNumber;
		break;

		case PORT_B:
			*returnValue = (PINB & (1 << pinNumber)) >> pinNumber;
		break;

		case PORT_C:
			*returnValue = (PINC & (1 << pinNumber)) >> pinNumber;
		break;

		case PORT_D:
			*returnValue = (PIND & (1 << pinNumber)) >> pinNumber;
		break;
	}
}

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
		PORTA ^= (1 << pinNumber);
		break;

		case PORT_B:
		PORTB ^= (1 << pinNumber);
		break;

		case PORT_C:
		PORTC ^= (1 << pinNumber);
		break;

		case PORT_D:
		PORTD ^= (1 << pinNumber);
		break;
	}
	//portNumber ^= (1 << pinNumber);
}