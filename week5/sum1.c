#include <stdio.h>
#include <math.h>

// Compute the sum 1 - 1/3 + 1/5 - 1/7 ...
// until the |term| < 1e-6
int main() {
  double sum = 0.0;
  double term = 1.0;
  int d = 1; 
  while (fabs(term) >= 1.0e-6) {
    sum += term;
    d += 2;
    term = ((d - 1) % 4) ? -1.0/d : 1.0/d;
  }

  printf("sum = %lf\n", sum);

  return 1;
}