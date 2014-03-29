/*
 * ChibiOS/Servo is a small library to easily interface RC servos with ChibiOS/RT.
 *
 * BSD licensed
 *
 * Author: Joel Bodenmann aka Tectu   <joel@unormal.org>
 */

#include "ch.h"
#include "hal.h"

typedef struct Servo_t {
	ioportid_t port;			// The GPIO port on which the servo is connected
	ioportmask_t pin;			// The GPIO pin on which the servo is connected
	PWMDriver *pwm_driver;		// The PWM driver to use
	pwmchannel_t pwm_channel;	// The PWM channel to use
	uint16_t min;				// The minimum value the servo shall never go below
	uint16_t max;				// The maximum value the servo shall never go over
} Servo;

void servoInit(Servo *servo);
void servoSetMin(Servo *servo, uint16_t value);
void servoSetMax(Servo *servo, uint16_t value);
void servoSetValue(Servo *servo, uint16_t value);
uint16_t servoGetMin(Servo *servo);
uint16_t servoGetMax(Servo *servo);

