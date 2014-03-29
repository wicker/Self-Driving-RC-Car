/*
 * ChibiOS/Servo is a small library to easily interface RC servos with ChibiOS/RT.
 *
 * BSD licensed
 *
 * Author: Joel Bodenmann aka Tectu   <joel@unormal.org>
 */

#include "servo.h"

static PWMConfig pwmcfg = {
    1000000,	// 1MHz PWM clock frequency
    20000,		// PWM period 20 milliseconds
  	NULL,		// no callback
  	{NULL},		// channel configuration set dynamicall in servoInit()
    0,
    0
};

void servoInit(Servo *servo) {
	/* create the channel configuration */
	PWMChannelConfig chcfg = { PWM_OUTPUT_ACTIVE_HIGH, NULL };
	pwmcfg.channels[servo->pwm_channel] = chcfg;

	/* configure PAL */
//	#if defined(STM32F1XX)
//		palSetPadMode(servo->port, servo->pin, PAL_MiODE_STM32_ALTERNATE_PUSHPULL);
  palSetPadMode(GPIOB,9,PAL_MODE_OUTPUT_PUSHPULL);
//	#else
//		#error "PAL configuration for this device not implemented yet - Please modify servoInit()"
//	#endif

	/* start the PWM unit */
	pwmStart(servo->pwm_driver, &pwmcfg);
}

void servoSetValue(Servo *servo, uint16_t value) {
	/* a bit of safty here */
	if(value > servo->max)
		value = servo->max;
	if(value < servo->min)
		value = servo->min;

	pwmEnableChannel(servo->pwm_driver, servo->pwm_channel, (pwmcnt_t)value);
}

void servoSetMax(Servo *servo, uint16_t value) {
	servo->max = value;	
}

void servoSetMin(Servo *servo, uint16_t value) {
	servo->min = value;
}

uint16_t servoGetMax(Servo *servo) {
	return (servo->max);
}

uint16_t servoGetMin(Servo *servo) {
	return (servo->min);
}

