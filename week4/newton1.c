#include <stdio.h>
#include <math.h>

#define EPSILON    1.0e-6

// Find the root of f(x) = 3x^3 + 4x^2 - 2x + 5.

int main() {
  double x, d;
  x = -2.0;
  do {
   d = (((3.0*x+4.0)*x-2.0)*x+5.0)/
       ((9.0*x+8.0)*x-2.0); /* f(x)/f'(x) */
   x = x-d;
  } while (fabs(d) > EPSILON);
  printf("The root is %.6f\n", x);

  return 0;
}