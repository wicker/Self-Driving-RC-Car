#include "ch.h"
#include "hal.h"
/*#include "servo.h"

Servo servo1 = {
	GPIOB,
	9,
	&PWMD4,
	3,
	500,
	2000
};

Servo servo2 = {
	GPIOE,
	0,
	&PWMD4,
	4,
	500,
	2000
};
*/

static PWMConfig pwmcfg = {
  10000,
  50000,
  NULL,
  {
    {PWM_OUTPUT_DISABLED, NULL},
    {PWM_OUTPUT_DISABLED, NULL},
    {PWM_OUTPUT_DISABLED, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
  },
  0
};

int main(void) {
//	uint16_t i;

	halInit();
	chSysInit();

//	servoInit(&servo1);
//	servoInit(&servo2);

  palSetPadMode(GPIOD, 15, PAL_MODE_ALTERNATE(2));
  pwmStart(&PWMD4, &pwmcfg);

  while (TRUE) {
    pwmEnableChannel(&PWMD4, 3, 50000);
    chThdSleepMilliseconds(5000);
    pwmEnableChannel(&PWMD4, 4, 50000);
    chThdSleepMilliseconds(5000);
  }

	/*while(TRUE)  {

		* sweep the servos from one end to the other
		 * you might want to use the servoGetMax() and
		 * servoGetMin() routines to get the values
		 *
		for(i = 700; i < 2000; i += 50) {
			servoSetValue(&servo1, i);
			chThdSleepMilliseconds(5000);
		}
		for(i = 2000; i > 700; i -= 50) {
			servoSetValue(&servo1, i);
			chThdSleepMilliseconds(5000);
		}
	}
*/
	return 0;
}

