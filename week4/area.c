#include <stdio.h>
#include <math.h>

double area(double a, double b, double c) {
  if (a + b >= c && a + c >= b && b + c >= a) {
 	double s;    
  	s = (a+b+c) / 2.0 ;
  	return sqrt(s*(s-a)*(s-b)*(s-c)) ;
  } else {
    printf("invalid parameters: they cannot form a triangle.\n");
    return 0.00;
  }
}

int main() {
  printf("%lf\n", area(3,4,5));
  return 0;
}