/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 */

#include "stdio.h"

#define ARGS 3

int instructions();
void transpose(int (*)[2]);

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

void transpose(int a[0][2]) {
  int row = 0;
  int col = 0;
  int new_row = 0;
  int new_col = 0;

  int temp[2][2];

  for (row = 0; row < 2; row++)
  {
      for (col = 0; col < 2; col++)
      {
          temp[new_row][new_col] = a[row][col];
          new_row++;
      }
      new_col++;
      new_row = 0;
  }

  for (row = 0; row < 2; row++)
  {
      for (col = 0; col < 2; col++)
      {
          a[row][col] = temp[row][col];
      }
  }
}

int instructions() {
  printf("\n \
  Usage: ./main <type> <T>\n \
  This program accepts two integer arguments separated by a space.\n \
  Filter Type: 0 (Kalman Filter), 1 (Extended KF), 2 (Unscented KF)\n \
  T: integer value of T for the linear Kalman Filter.\n\n"); 
}
  

