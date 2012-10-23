/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 */

#include "math.h"

void matrix_testing(int a[2][2], int b[2][2]) {

  printf("Testing transpose, multiply, add, and subtract of a matrix.\n");

  printf("a: %d %d\n   %d %d\n\n",a[0][0],a[0][1],a[1][0],a[1][1]);

//  transpose(a);

//  multiply(a,b);

//  add(a,b);

//  subtract(a,b);

  printf("a: %d %d\n   %d %d\n\n",a[0][0],a[0][1],a[1][0],a[1][1]);

}

void transpose(int a[][2]) {
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

void inverse(int a[][2]) {
  float d1 = a[0][0];
  float d2 = a[0][1];
  float d3 = a[1][0];
  float d4 = a[1][1];
  float invert[2][2] = {d4,-d2,-d3,d1};

  float temp = 1 / (d1*d4 - d2*d3);

  a = temp * invert;
}

void multiply(int a(*)[2], int b(*)[2], int temp[2][2], int row, int col) {

  // multiply
  for (row = 0; row < 2; row++)
  {
      for (col = 0; col < 2; col++)
      {
          temp[row][col] = a[row][col] + b[row][col];
      }
  }

  // copy results of temp into a
  for (row = 0; row < 2; row++)
  {
      for (col = 0; col < 2; col++)
      {
          a[row][col] = temp[row][col];
      }
  }
}

void subtract(int a(*)[2], int b(*)[2]) {
  
}

void add(int a(*)[2], int b(*)[2]) {
  
}

