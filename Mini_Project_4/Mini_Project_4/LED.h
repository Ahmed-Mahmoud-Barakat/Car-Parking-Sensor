#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include "gpio.h"

#define LED_PORT 						PORTC_ID
#define RED_LED_PIN 					PIN0_ID
#define GREEN_LED_PIN 					PIN1_ID
#define BLUE_LED_PIN 					PIN2_ID
#define LOGIC							0

typedef enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE
} LED_ID;

typedef enum {
    POSITIVE_LOGIC,
    NEGATIVE_LOGIC
} LED_LogicType;


void LEDS_init(void);

void LED_on(LED_ID id);

void LED_off(LED_ID id);



#endif
