/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 * 
 * Kalman filter algorithm came mostly from Dan Simon's article
 * in June 2001 issue of Embedded Systems Programming.
 */

#include "use_kf.h"

void use_kf(float T, float duration) {

  // 'T' is time step in seconds
  // 'duration' in seconds 

  // This set up for variables works for a 2 state, 1 input, 1 output system

  int n = 2; // states
  int m = 1; // inputs
  int r = 1; // outputs
  
  printf("Hi. T is %f.\n",T);

  float measure_noise = 10;  // feet
  float process_noise = 0.2; // feet/sec^2

  struct mat_2x2 A;     // [n][n]
  struct mat_2x1 B;     // [n][m]
  struct mat_1x1 C;     // [r][n]
 
  struct mat_2x1 x;     // [n][m]
  struct mat_2x2 Sw;    // [n][n]
  
  struct mat_2x2 P;     // [n][n]
  struct mat_1x1 u;     // [m][1]
  struct mat_1x1 y;     // [r][1]

  struct mat_1x1 x_hat; // [n][1]

  A.data = {1,T,0,1}; // transition matrix
  B.data = {sqrt(T)/2,T};
  C.data = {1,0};

  x.data = {0,0};    // initial state estimate
  Sw.data = {(1/4)*T^4,(1/2)*T^3,(1/2)*T^3,T^2} // process noise
  Sw = accel_noise^2 * Sw;
  float Sz = meas_noise^2;
  P.data = Sw;       // initial uncertainty
  u.data = {1};  // external motion
  y.data = {matrix_multiply(C * x) + meas_noise};

  x_hat.data = {0,0};

  // still not sure which these are, with difference in notation
  /*
  float F.data[n][n];  // next state transition matrix
  float H.data[1][2];  // measurement function
  float R = 1;    // measurement uncertainty (noise)
  float I.data[2][2];  // identity
  float Z = 1;    // actual input measurement
  float K.data[2][1];  // Kalman gain */

  for (T = 0; T < duration; T++) {
    predict(float x, float F, float u, float P);
    measure();
  }

}
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

