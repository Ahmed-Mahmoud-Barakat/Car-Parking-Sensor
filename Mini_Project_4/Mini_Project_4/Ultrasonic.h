#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"
#define ULTRA_PORT	PORTD_ID
#define ECHO_PIN		PIN6_ID
#define TRIGGER_PIN		PIN7_ID
#define SOUND_SPEED_CM_PER_US 0.035

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);

#endif
