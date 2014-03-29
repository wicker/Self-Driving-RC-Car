#include "ch.h"
#include "hal.h"

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

  halInit();
  chSysInit();

  palSetPadMode(GPIOD, 15, PAL_MODE_ALTERNATE(2));
  pwmStart(&PWMD4, &pwmcfg);
  pwmEnableChannel(&PWMD4, 3, 50000);

  while (TRUE) {
    chThdSleepMilliseconds(5000);
  }

}

