/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 */

#include "math.h"

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


