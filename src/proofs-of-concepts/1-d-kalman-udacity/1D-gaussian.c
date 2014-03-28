/* 
* Author: Jenner Hanni
* Language: C 
* 1-dimensional Kalman filter 
* Uses the python-based example from Udacity's CS373
*/

#include <math.h>

#define BLAH

int main ()
{

  int mean1, mean2, var1, var2, new_mean, new_var;

  int update(int mean1, int mean2, int var1, int var2) {
    new_mean = (var2 * mean1 + var1 * mean2) / (var1 + var2);
    new_var  = 1/var1 + 1/var2;
    return new_mean, new_var;
  }

  int predict(int mean1, mean2, var1, var2) {
    new_mean = mean1 + mean2;
    new_var  = var1 + var2;
    return new_mean, new_var;
  }
  
  for n in range(len(measurements))
  {
    [mu,sig] = update(mu, sig, measurements[n], measurements_sig)
    print 'update: ', [mu,sig]
    [mu,sig] = predict(mu, sig, motion[n], motion_sig)
    print 'predict: ', [mu, sig]
  }

  print [mu,sig]

  return 0;

}



