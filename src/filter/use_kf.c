/* Copyright (c) 2012 Jenner Hanni <jeh.wicker@gmail.com>
 * Licensed under the BSD three-clause license. See LICENSE.
 * 
 * Kalman filter algorithm came mostly from Dan Simon's article
 * in June 2001 issue of Embedded Systems Programming.
 */

#include "use_kf.h"

void use_kf(float T) {
  
  printf("Hi. T is %f.\n",T);

  float T_a = sqrt(T) / 2;
  printf("T_a = %f.\n",T_a);

  float A[2][2] = {1,T,0,1};
  float B[2][1] = {T_a,T};
  float C[1][2] = {1,0};

  float x[2][1];  // initial state estimate
  float P[2][2];  // initial uncertainty
  float u[2][1];  // external motion
  float F[2][2];  // next state transition matrix
  float H[1][2];  // measurement function
  float R = 1;    // measurement uncertainty (noise)
  float I[2][2];  // identity
  float Z = 1;    // actual input measurement
  float K[2][1];  // Kalman gain

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

