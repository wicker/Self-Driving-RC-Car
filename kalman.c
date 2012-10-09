/* Implementing a multi-dimensional Kalman filter in C using the GSL
 * 
 * Copyright (C) 2012 Jenner Hanni
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <math.h>
#include <stdio.h>

/* Globals */

int x[2][1];  // initial state estimate
int P[2][2];  // initial uncertainty
int u[2][1];  // external motion
int F[2][2];  // next state transition matrix
int H[1][2];  // measurement function
int R = 1;    // measurement uncertainty (noise)
int I[2][2];  // identity
int Z = 1;    // actual input measurement
int K[2][1];  // Kalman gain

/* Function prototypes */

int transpose();

int multiply();

int add();

int inverse();

int subtract();

void predict();

void measure();

/* Main program */

int main()
{

  // accept measurements from user

  // apply measurement function
  measure();

  // apply prediction function
  predict();

  // return mean and covariance
  printf("Mean: %d, Uncertainty: %d\n",x,P);

  return 0;
}

/* Function definitions */

void predict() {
  x = F*x + u;
  P = F*P*tranpose(F);
}

void measure() {
  y = Z - H*x;

  S = H*P*transpose(H) + R;
  K = P*transpose(H)*inverse(S);

  x = x + K*y;
  P = (I - K*H) * P;
}


