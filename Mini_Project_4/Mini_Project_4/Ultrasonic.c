#include "Ultrasonic.h"
#include "icu.h"
#include "std_types.h"
#include "gpio.h"
#include "util/delay.h"

uint32 timeHigh = 0;
uint8 edgeCount = 0;
uint16 distance = 0;
ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};

void Ultrasonic_init(void)
{

	GPIO_setupPinDirection(ULTRA_PORT, TRIGGER_PIN, PIN_OUTPUT);

	ICU_init(&ICU_Configurations);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRA_PORT, TRIGGER_PIN, LOGIC_HIGH);

	_delay_us(10);

	GPIO_writePin(ULTRA_PORT, TRIGGER_PIN, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{

	Ultrasonic_Trigger();

	_delay_us(10);

	timeHigh = ICU_getInputCaptureValue();

	distance = ((timeHigh * SOUND_SPEED_CM_PER_US)/4);

	return distance;
}

void Ultrasonic_edgeProcessing(void)
{
	edgeCount++;

	if (edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if (edgeCount == 2)
	{
		timeHigh = ICU_getInputCaptureValue();

		ICU_setEdgeDetectionType(RAISING);

		edgeCount = 0;
	}
}
