#include <stdio.h>
#include <math.h>

#define EPS 1e-4

// Compute pi using formula
// pi = 4 - 4/3 + 4/5 - 4/7 + ...
int main() {
  int sign = 1;
  long i, m = 1;	
  double pi = 4, t = 4;
  for(i = 1; fabs(t) > EPS; i++) {
    sign = -sign;
    m += 2;
    t = sign * 4.0 / m;
    pi += t;
  }
  printf("pi = %f\n", pi);
 }
