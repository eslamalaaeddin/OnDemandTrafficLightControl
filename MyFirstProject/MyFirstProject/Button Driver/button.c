#include "button.h"

void Button_init(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_init(portNumber, pinNumber, DIRECTION_IN);
}

void Button_read_state(uint8_t portNumber, uint8_t pinNumber, uint8_t *returnValue)
{
	DIO_read(portNumber, pinNumber, returnValue);
}