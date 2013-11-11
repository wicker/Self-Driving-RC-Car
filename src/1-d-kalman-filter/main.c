/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 */

#include "stdio.h"
#include "math.h"
#include "matrix.h"

#define ARGS 4

int instructions();

int main(int argc, char *argv[]) {

  if (argc != ARGS) {
     return instructions();
  }

  int filter_type = atoi(argv[1]);
  float T = atoi(argv[2]);
  int duration = atoi(argv[3]);

  switch(filter_type) {
    case 0:
      printf("Using linear kalman filter. T is %f and duration is %d.\n", T,duration);
      int n = 4;
      int m = 3;
      float a = n%m;
      printf("a = %f.",a);

      use_kf(T, duration);
      break;
    case 1:
      printf("Using extended kalman filter. Not written yet. Exiting.\n");
      break;
    case 2:
      printf("Using unscented kalman filter. Not written yet. Exiting.\n");
      break;
    default:
      printf("Failure.\n");
      break;
  }

  return 0;

}

int instructions() {
  printf("\n \
  Usage: ./main <type> <T>\n \
  This program accepts three integer arguments separated by a space.\n \
  Filter Type: 0 (Kalman Filter), 1 (Extended KF), 2 (Unscented KF)\n \
  T: integer value of T for the linear Kalman Filter.\n \
  duration: total number of time steps over which to apply the filter.\n\n"); 
}
  

