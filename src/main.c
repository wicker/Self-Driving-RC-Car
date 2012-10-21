/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 */

#include "input.h"

int main(void) {

//  int filter_type = receive_input();
  int filter_type = 0;

  switch(filter_type) {
    case 0: 
      printf("Using linear kalman filter."\n);
      break;
    case 1:
      printf("Using extended kalman filter."\n);
      break;
    case 2:
      printf("Using unscented kalman filter."\n);
      break;
    else: 
      printf("Failure."\n);
      break;
  }

  return 0;
}

