#include <stdio.h>
#include <math.h>

#define EPSILON    1.0e-6

// Find the root of f(x) = x^2 - c = 0 using Newton's iteration.

int main() {
  double c;
  scanf("%lf", &c);
  double x, d;
  x = c;
  do {
   d = (x*x - c)/ (2*x); /* f(x)/f'(x) */
   x = x-d;
  } while (fabs(d) > EPSILON);
  printf("The square root of %.6f is %.6f\n", c, x);

  return 0;
}