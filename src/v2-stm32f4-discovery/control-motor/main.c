// Servo control
//
// Servo on pin PB8 uses TIM4 channel 3 on alternate function 2
// TIM4 supports PWM driving.
// PWMD4 is a HAL-defined driver associated with TIM4.
 
#include "ch.h"
#include "hal.h"
 
#define LEFT 0
#define RIGHT 1

#define INAPIN 1 // PB1
#define INBPIN 2 // PB2
 
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
  halInit();
  chSysInit();
  
  palSetPadMode(GPIOB, 0, PAL_MODE_ALTERNATE(2)); // alt mode is PWM-enabled TIM3
  palSetPadMode(GPIOB, INAPIN, PAL_MODE_OUTPUT_PUSHPULL); // set INA to be an output
  palSetPadMode(GPIOB, INBPIN, PAL_MODE_OUTPUT_PUSHPULL); // set INB to be an output
   
  pwmStart(&PWMD3, &pwmcfg); // TIM3 for motors
 
  while (TRUE) {
    // one direction (possibly forward)
    pwmEnableChannel(&PWMD3, 3, 500);
    palSetPad(GPIOB, INAPIN);
    palClearPad(GPIOB, INBPIN);
    chThdSleepMilliseconds(3000);

    // the other direction (possibly backward)
    pwmEnableChannel(&PWMD3, 3, 500);
    palSetPad(GPIOB, INBPIN);
    palClearPad(GPIOB, INAPIN);
    chThdSleepMilliseconds(3000);
  }
}
