#include "LED Driver/led.h"
#include "Button Driver/button.h"
#include "registers.h"
#include "main.h"

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>


short interruptBeginned = FALSE;
uint8_t *button_state;

int timerOverflowCount = 0;
int maxOverflowCount;


short stopMainDelay = FALSE;

short carRedOn = FALSE;
short pedGreenOn = FALSE; 
short pressedWhenRed = FALSE;

short carGreenOn = FALSE;
short pressedWhenGreen = FALSE;

short carYellowOn = FALSE;
short pressedWhenYellow = FALSE;




ISR (INT1_vect)  //External interrupt_one ISR
{
 	_delay_ms(500); // work well
	Button_read_state(PORT_D, 3, button_state);
	if (*button_state == 1)
	{
	 	LED_toggle(PORT_C, 4);
	}
	else
	{
	
		if (carRedOn == TRUE && pedGreenOn == TRUE)
		{
			//Do nothing
		}
		else
		{
			if (interruptBeginned == FALSE)
			{
				LED_toggle(PORT_C, 0);
				interruptBeginned = TRUE; // to prevent multiple clicks while the interrupt is being handled
				
				if (carRedOn == TRUE)
				{
					//Stop the main delay
					stopMainDelay = TRUE;
					pressedWhenRed = TRUE;
				}
				
				if (carGreenOn == TRUE)
				{
					//Stop the main delay
					stopMainDelay = TRUE;
					pressedWhenGreen = TRUE;
				}
				
				if (carYellowOn == TRUE)
				{
					//Stop the main delay
					stopMainDelay = TRUE;
					pressedWhenYellow = TRUE;
				}
			}
		}
		
	}
	
}

void handleRedPress()
{
	LED_on(PORT_A, 1); // Ped green led is on
	LED_on(PORT_C, 3); // Car red led is on
	_delay_ms(5000);
	
	// at the end 1 ...
	LED_off(PORT_C, 3); // Car red led is off
	for (short i = 0 ; i < 5 ; i++) // Both yellow are blinking
	{
		LED_on(PORT_C, 2);
		LED_on(PORT_A, 2);
		_delay_ms(500);
		LED_off(PORT_C, 2);
		LED_off(PORT_A, 2);
		_delay_ms(500);
	}
	// at the end 2 ...
	LED_off(PORT_A, 1); // Ped green led is off
	LED_on(PORT_A, 3); // Ped red led is on
	LED_on(PORT_C, 1); // Car green led is on
	_delay_ms(5000);
	LED_off(PORT_A, 3); // Ped red led is off
	LED_off(PORT_C, 1); // Car green led is off
	
	interruptBeginned = FALSE; // Making it false means the interrupt has been handled and the MCU is ready for another press
	LED_toggle(PORT_C, 0);
}

void handleGreenPress()
{
	LED_on(PORT_A, 3); // Ped red led is on
	//_delay_ms(5000);
	
	
	for (short i = 0 ; i < 5 ; i++) // Both yellow are blinking
	{
		LED_on(PORT_C, 2);
		LED_on(PORT_A, 2);
		_delay_ms(500);
		LED_off(PORT_C, 2);
		LED_off(PORT_A, 2);
		_delay_ms(500);
	}
	LED_off(PORT_A, 3); // Ped red led is off
	LED_on(PORT_C, 3); // Car red led is on 
	LED_on(PORT_A, 1); // Ped green led in on
	_delay_ms(5000);
	
	///////////// at the end
	// at the end 1 ...
	LED_off(PORT_C, 3); // Car red led is off
	for (short i = 0 ; i < 5 ; i++) // Both yellow are blinking
	{
		LED_on(PORT_C, 2);
		LED_on(PORT_A, 2);
		_delay_ms(500);
		LED_off(PORT_C, 2);
		LED_off(PORT_A, 2);
		_delay_ms(500);
	}
	// at the end 2 ...
	LED_off(PORT_A, 1); // Ped green led is off
	LED_on(PORT_A, 3); // Ped red led is on
	LED_on(PORT_C, 1); // Car green led is on
	_delay_ms(5000);
	LED_off(PORT_A, 3); // Ped red led is off
	LED_off(PORT_C, 1); // Car green led is off
	
	interruptBeginned = FALSE; // Making it false means the interrupt has been handled and the MCU is ready for another press
	LED_toggle(PORT_C, 0);
	
}

void goGreen()
{
	LED_on(PORT_A, 3);
	LED_on(PORT_C, 1);
	carGreenOn = TRUE;
	_delay_ms(5000);
	LED_off(PORT_C, 1);
	carGreenOn = FALSE;
	if (pressedWhenGreen == TRUE)
	{
		pressedWhenGreen = FALSE;
		handleGreenPress();
	}
	LED_off(PORT_A, 3);
}
void goRed()
{
	LED_on(PORT_A, 1);
	LED_on(PORT_C, 3);
	carRedOn = TRUE;
	pedGreenOn = TRUE;
	_delay_ms(5000);
	LED_off(PORT_C, 3);
	carRedOn = FALSE;
	pedGreenOn = FALSE;
	if (pressedWhenRed == TRUE)
	{
		handleRedPress();
	}
	LED_off(PORT_A, 1);
}
void goYellow()
{
	carYellowOn = TRUE;
	for (short i = 0 ; i < 5 ; i++)
	{
		LED_on(PORT_C, 2);
		LED_on(PORT_A, 2);
		_delay_ms(500);
		LED_off(PORT_C, 2);
		LED_off(PORT_A, 2);
		_delay_ms(500);
		if (pressedWhenYellow == TRUE)
		{
			handleGreenPress(); // as the logic for yellow is the same with green 
			carYellowOn = FALSE;
			break;
		}
	}
	carYellowOn = FALSE;
}

int main(void)
{
	//1.Set Timer Mode
	TCCR0 = 0x00; //To set Timer in normal mode and not start it.
	
	// 2.Set Timer initial value
	TCNT0 = 0; //Time initial value
	
	
	Button_init(PORT_D, 3);
	
	LED_init(PORT_C, 0);
	LED_init(PORT_C, 4);
	
	//Car LEDs
	LED_init(PORT_C, 1);
	LED_init(PORT_C, 2);
	LED_init(PORT_C, 3);
	
	//Ped LEDs
	LED_init(PORT_A, 1);
	LED_init(PORT_A, 2);
	LED_init(PORT_A, 3);
	
	
	
	// Enable global interrupts by setting global interrupt enable bit in SREG
	sei();     
	
	//Configure INT1 as rising edge
	MCUCR = 0x0d;
	
	//Enable External Interrupt 1
	GICR |= (1 << INT1);
	
	
	while (1)
	{
		goGreen();
		goYellow();
		
		if (pressedWhenYellow == TRUE)
		{
			pressedWhenYellow = FALSE;
			goYellow();
		}
		goRed();
		goYellow();
		
		if (pressedWhenYellow == TRUE)
		{
			pressedWhenYellow = FALSE;
			goYellow();
			goRed();
		}
		
		if (pressedWhenRed == TRUE)
		{
			pressedWhenRed = FALSE;
			goRed();
			goYellow();
		}
		
    }
}

