/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 * 
 * Matrix math functions for 2x2 matrices needed for Kalman filter.
 */

#ifndef MATRIX_H
#define MATRIX_H

/* Typedef for matrix struct */

typedef struct {
  int m;
  int n;
  float data[2][2];
} matrix_2x2;

/* Functions */

void matrix_testing();

void inverse();

void transpose();

void multiply();

void subtract();

void add(); 

void print_matrix_2x2(matrix_2x2);

#endif
