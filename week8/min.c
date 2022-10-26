#include <stdio.h>

// Function forward declaration
double min(double, double);

int main() {
  double a, b;
  printf("Input a, b: ");
  scanf("%lf%lf", &a, &b);
  printf("Min(%f, %f) = %f\n", a, b, min(a, b));

  return 0;
}

double min(double x, double y) {
  return x < y ? x : y;
}
