/* Implementing a multi-dimensional Kalman filter in C
 * 
 * Copyright (C) 2012 Jenner Hanni
 * 
 * This program is open source software released under the 
 * BSD Three-Clause license. See the LICENSE file for more information.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Globals */

/*int x[2][1];  // initial state estimate
int P[2][2];  // initial uncertainty
int u[2][1];  // external motion
int F[2][2];  // next state transition matrix
int H[1][2];  // measurement function
int R = 1;    // measurement uncertainty (noise)
int I[2][2];  // identity
int Z = 1;    // actual input measurement
int K[2][1];  // Kalman gain

int MATRIX[2][2] = {1,2,3,4};
*/
/* Function prototypes */

void transpose(int m, int n);

int multiply();

int add();

int inverse();

int subtract();

void predict();

void measure();

void update_matrix();

/* Main program */

int main() {

  // accept measurements from user

  // apply measurement function
//  measure();

  // apply prediction function
//  predict();

  // return mean and covariance
//  printf("Mean: %d, Uncertainty: %d\n",x,P);

  printf("This is a transpose test.\n");

//  matrix[][] = {1,2,3,4};

  int m = 1;
  int n = 1;

  transpose(m,n);

  printf("Oops.");

  return 0;
}

/* Function definitions */

void predict() {
//  x = F * x + u;
//  P = F * P * tranpose(F);
}

void measure() {
//  y = Z - H*x;

//  S = H*P*transpose(H) + R;
//  K = P*transpose(H)*inverse(S);

//  x = x + K*y;
//  P = (I - K*H) * P;
}

void transpose(int m, int n) {
  int row;
  int col;
  int new_row;
  int new_col;

  int temp[2][2];
  for (row = 0; row < m; row++) 
  {
      for (col = 0; col < n; col++)
      {
          temp[new_row][new_col] = MATRIX[row][col];
          new_row++;
      }
      new_col++;
      new_row = 0;
  }

/*  for (row = 0; row<m; row++)
  {
      for (col = 0; col < n; col++)
      {
          MATRIX[row][col] = temp[row][col];
      }
  }*/

}
