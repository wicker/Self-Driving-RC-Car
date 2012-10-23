/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 * 
 * Matrix math functions for 2x2 matrices needed for Kalman filter.
 */

void matrix_testing(int (*)[2], int (*)[2]);

void transpose(int (*)[2]);

void multiply(int (*)[2], int (*)[2]);

void subtract(int (*)[2], int (*)[2]);

void add(int (*)[2], int (*)[2]); 
