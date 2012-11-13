/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 * 
 * Kalman filter algorithm came mostly from Dan Simon's article
 * in June 2001 issue of Embedded Systems Programming.
 */

#include "math.h"
#include "use_kf.h"

/* Use regular Kalman Filter */

void use_kf(float T, int duration) {

/* Step 1: Customize the Kalman Filter for your system
 * 'T' is time step and duration is total number of time steps.
 * Currently set up for 2 state, 1 input, 1 output system
 */

  int n = 2; // states
  int m = 1; // inputs
  int r = 1; // outputs

  int time;  // actual time displacement

  float position_noise = 10;  // feet
  float accel_noise = 0.2; // feet/sec^2

  float A[n][n]; // transition matrix 
  float B[n][m]; // input matrix
  float C[r][n]; // measurement matrix

  float A_T[n][n]; // transpose of A
  float C_T[n][r]; // transpose of C

  float xhat[n][m]; // state estimate containing position and velocity
  float x[n][m];    // state containing position and velocity

  float u = 1; // input: commanded acceleration in ft/sec^2
  float y;     // measured output

  float Sz = pow(position_noise,2); // measurement error covariance
  float Sw[n][n];                   // process noise covariance
  Sw[0][0] = pow(accel_noise,2) * pow(T,4)/4;
  Sw[0][1] = pow(accel_noise,2) * pow(T,3)/2;
  Sw[1][0] = pow(accel_noise,2) * pow(T,3)/2;
  Sw[1][1] = pow(accel_noise,2) * pow(T,2);

  float s;                 // covariance of the innovation vector
  float inn_var;               // innovation variable
  float w_k[n][m];         // process noise
  float z_k;               // measurement noise

  float P[n][n];           // initial estimate covariance
  P[0][0] = Sw[0][0];  
  P[0][1] = Sw[0][1];
  P[1][0] = Sw[1][0];
  P[1][1] = Sw[1][1];

  float pos[duration];     // true position array
  float poshat[duration];  // estimated position array
  float posmeas[duration]; // measured position array
  float vel[duration];     // true velocity array
  float velhat[duration];  // estimated velocity array

  float state_temp[2][1];  // temporary array for matrix math
  float input_temp[2][1];  // temporary array for matrix math
  int row = 0;
  int col = 0;
  int new_row = 0;
  int new_col = 0;

  printf("Hey, this works.\n");

  for (time = 0; time < duration; time++)
  {
    printf("time: %d, duration: %d\n",time,duration);

    /* Simulate the process noise */

    w_k[0][0] = accel_noise * pow(T,2)/2 * rand();
    w_k[0][1] = accel_noise * T * rand();

    state_temp[0][0] = A[0][0] * x[0][0] + A[0][1] * x[1][0];
    state_temp[1][0] = A[1][0] * x[0][0] + A[1][1] * x[1][0];

    input_temp[0][0] = B[0][0] * u;
    input_temp[1][0] = B[1][0] * u;

    x[0][0] = state_temp[0][0] + input_temp[0][0] + w_k[0][0];
    x[1][0] = state_temp[1][0] + input_temp[1][0] + w_k[1][0];

    /* Simulate the measurement noise */

    z_k = position_noise * rand();
    printf("z_k = %f\n",z_k);  // test, delete me

    y = (C[0][0] * x[0][0]) + (C[0][1] * x[1][0]) + z_k;

    /* Extrapolate most recent state estimate to the present time */
    /* xhat = A * xhat + B * u */

    state_temp[0][0] = A[0][0] * xhat[0][0] + A[0][1] * xhat[1][0];
    state_temp[1][0] = A[1][0] * xhat[0][0] + A[1][1] * xhat[1][0];

    input_temp[0][0] = B[0][0] * u;
    input_temp[1][0] = B[1][0] * u;

    xhat[0][0] = state_temp[0][0] + input_temp[0][0];

    /* Form innovation vector and compute its covariance */

    printf("%f %f\n",C[0][0],C[0][1]);

    C_T[0][0] = C[0][0];
    C_T[1][0] = C[0][1];

    printf("%f %f\n",C_T[0][0],C[1][0]);

//    Inn = y - C * xhat;
//    s = C * P * transp(C) + Sz;
    
    /* Calculate the Kalman Gain matrix */
//    K = A * P * transp(C) * inv(s);

    /* Update state estimate */
//    xhat = xhat + K * Inn;

    /* Compute covariance of the estimation error */
//    P = A * P * transp(A) - A * P * transp(C) * inv(s) * C * P * transp(A) + Sw;

    /* Add variables to the tracking arrays for later analysis */
//    pos[time] = x[0][0];
//    posmeas[time] = y;
//    poshat[time] = xhat[0][0];
//    vel[time] = x[1][0];
//    velhat[time] = xhat[1][0];
  }

}

