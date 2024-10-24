#include "lcd.h"
#include "LED.h"
#include"buzzer.h"
#include "icu.h"
#include "Ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */
#include "util/delay.h"

uint16 distance_ = 0;

int main(void)
{
	SREG |= (1<<7);

	LCD_init();

	Ultrasonic_init();

	LEDS_init();

	Buzzer_init();

	Ultrasonic_init();

	while(1)
	{

		distance_ = Ultrasonic_readDistance();
		LCD_moveCursor(0,0);
		LCD_displayString("Distance=");
		LCD_intgerToString(distance_);
		LCD_displayString(" CM");
		if(distance_ > 20)
		{
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			Buzzer_off();
		}
		else if(distance_ >=16 && distance_ <=20)
		{
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			Buzzer_off();

		}
		else if(distance_ >=11 && distance_ <=15)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
			Buzzer_off();
		}
		else if(distance_ >=6 && distance_ <=10)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
			Buzzer_off();
			if(distance_ < 10)
			{
				LCD_moveCursor(0,13);
				LCD_displayString(" ");
			}
			LCD_moveCursor(1,6);
			LCD_displayString("      ");

		}
		else if(distance_ <=5)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
			_delay_us(100);
			Buzzer_on();
			LCD_moveCursor(1,6);
			LCD_displayString("Stop !");
		}

	}
}

