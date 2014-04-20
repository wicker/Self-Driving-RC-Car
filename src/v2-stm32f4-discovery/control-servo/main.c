// Servo control
//
// TIM4 supports PWM driving.
// Servo on pin PB8 uses TIM4 channel 3 on alternate function 2
// PWMD4 is a HAL-defined driver associated with TIM4.
 
#include "ch.h"
#include "hal.h"
 
#define LEFT 0
#define RIGHT 1
 
static PWMConfig pwmcfg = {
  1000000, // 1MHz PWM clock
  20000, // PWM period 20ms 
  NULL, // No callback 
  {
    {PWM_OUTPUT_DISABLED, NULL},      
    {PWM_OUTPUT_DISABLED, NULL},     
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},   
    {PWM_OUTPUT_DISABLED, NULL},       
  },
  0
};
 
int main(void)
{
  static int step = 100, width = 500; /* starts at .7ms, ends at 2.5ms */
 
  halInit();
  chSysInit();
  
  // sets alternate mode 2 which is TIM4 
  palSetPadMode(GPIOB, 8, PAL_MODE_ALTERNATE(2));
   
  pwmStart(&PWMD4, &pwmcfg);
 
  while (TRUE) {
    pwmEnableChannel(&PWMD4, 2, width);
    // if all the way to the left or right, go back the way you came
    if (width <= 700) step = 100;
    else if (width >= 2500) step = -100;
    // now increment the width by step
    width += step;
    // brief delay
    chThdSleepMilliseconds(100);
  }
}
