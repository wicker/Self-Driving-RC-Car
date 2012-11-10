/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 * 
 * Matrix math functions for 2x2 matrices needed for Kalman filter.
 */

/* Global Structs for Kalman Filter */

struct matrix_2x2 {
  int m = 2;
  int n = 2;
  float data[m][n];
}

struct matrix_2x1 {
  int m = 2;
  int n = 1;
  float data[m][n];
}

struct matrix_1x2 {
  int m = 1;
  int n = 2;
  float data[m][n];
}

struct matrix_1x1 {
  int m = 1;
  int n = 1;
  float data[m][n];
}

/* Functions */

void matrix_testing(int (*)[2], int (*)[2]);

void inverse(int (*)[2]);

void transpose(int (*)[2]);

void multiply(int (*)[2], int (*)[2]);

void subtract(int (*)[2], int (*)[2]);

void add(int (*)[2], int (*)[2]); 
