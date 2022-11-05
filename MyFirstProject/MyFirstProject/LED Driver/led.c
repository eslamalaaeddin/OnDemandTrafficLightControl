
#include "led.h"
#include "..\registers.h"

void LED_init(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_init(portNumber, pinNumber, DIRECTION_OUT);
}

void LED_on(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_write(portNumber, pinNumber, HIGH);
}

void LED_off(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_write(portNumber, pinNumber, LOW);
}

void LED_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_toggle(portNumber, pinNumber);
}

void LED_blink(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_write(portNumber, pinNumber, HIGH);
	//1.Set Timer Mode
	TCCR0 = 0x00; //To set Timer in normal mode and not start it.
	
	//2.Set Timer initial value
	TCNT0 = 0; //Time initial value
	
	int timerOverflowCount = 0;
	int  maxOverFlowCount = 3000;
	
	while(1)
	{
		//3.Start Timer -> Set Prescaler
		TCCR0 |= (1 << 0); //No Prescaler

		//wait until overflow occurs
		while((TIFR & (1 << 0)) == 0);

		timerOverflowCount++;

		//clear overflow flag
		TIFR |= (1 << 0);
		
		if (timerOverflowCount >= maxOverFlowCount)
		{
			//LED_toggle(PORT_A, 4);
			//LED_toggle(PORT_C, 1);
			//LED_toggle(PORT_C, 2);
			DIO_write(portNumber, pinNumber, LOW);
			//LED_toggle(PORT_C, 3);
			timerOverflowCount = 0;
		}

		
		//Stop timer
		TCCR0 = 0x00;
		
			
	}
}

