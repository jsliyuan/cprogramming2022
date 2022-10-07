#include <stdio.h>
#include <math.h>

// Compute the sum 1 - 1/3 + 1/5 - 1/7 ...
// until the |term| < 1e-6
int main() {
  double sum = 0.0;
  double term = 1.0;
  int d;
  for (d = 1; fabs(term) >= 1e-6; d+=2) {
    term = ((d - 1) % 4) ? -1.0/d : 1.0/d;
    sum += term;
  }

  printf("sum = %lf\n", sum);
  return 1;
}