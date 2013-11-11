/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 */

#include "math.h"
#include "matrix.h"

void print_matrix_2x2(matrix_2x2 temp) {

  printf("wut");

  int i;
  int j;
  for (i; i < temp.m; i++)
  {
    for (j; j < temp.n; j++)
         printf("%f",temp.data[i][j]);
    printf("\n");
  } 
}

// old set_matrix_2x2
/*matrix set_matrix_2x2(matrix temp) {


  temp.m = 2;
  temp.n = 2;
  float adata[2][2] = {0,0,0,0};
  temp.data = adata;
  return temp;
}*/


/*void matrix_testing(matrix,matrix) {

  printf("Testing transpose, multiply, add, and subtract of a matrix.\n");

  print_matrix(A);

//  transpose(a);

//  multiply(a,b);

//  add(a,b);

//  subtract(a,b);

  printf("a: %d %d\n   %d %d\n\n",a[0][0],a[0][1],a[1][0],a[1][1]);

}

void transpose() {
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

void inverse() {
  float d1 = a[0][0];
  float d2 = a[0][1];
  float d3 = a[1][0];
  float d4 = a[1][1];
  float invert[2][2] = {d4,-d2,-d3,d1};

  float temp = 1 / (d1*d4 - d2*d3);

  a = temp * invert;
}

void multiply() {

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

void subtract() {
  
}

void add() {
  
}
*/
