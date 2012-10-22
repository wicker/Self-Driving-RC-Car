/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 */

#include "stdio.h"
#include "math.h"

#define ARGS 3

int instructions();

int main(int argc, char *argv[]) {

  if (argc != ARGS) {
     return instructions();
  }

  int filter_type = atoi(argv[1]);
  int T = atoi(argv[2]);

  switch(filter_type) {
    case 0:
      printf("Using linear kalman filter. T is %d.\n", T);
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

  int a[2][2] = {1,2,3,4};

  printf("a: %d %d\n   %d %d\n\n",a[0][0],a[0][1],a[1][0],a[1][1]);

  transpose(a);

  printf("a: %d %d\n   %d %d\n\n",a[0][0],a[0][1],a[1][0],a[1][1]);

  return 0;
}

int instructions() {
  printf("\n \
  Usage: ./main <type> <T>\n \
  This program accepts two integer arguments separated by a space.\n \
  Filter Type: 0 (Kalman Filter), 1 (Extended KF), 2 (Unscented KF)\n \
  T: integer value of T for the linear Kalman Filter.\n\n"); 
}
  

