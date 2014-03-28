// This is the blink LEDs demo from Elia's Electronics
// http://eliaselectronics.com/stm32f4-tutorials/getting-started-with-chibios-on-stm32f4/

#include "ch.h"
#include "hal.h"

int main(void) {
 
  halInit();
  chSysInit();

  palSetPadMode(GPIOD, 15, PAL_MODE_OUTPUT_PUSHPULL);

  while(1) {
    palSetPad(GPIOD, 15);
    chThdSleepMilliseconds(2000);
    palClearPad(GPIOD, 15);
    chThdSleepMilliseconds(2000);
  }

}

