#include <stdio.h>
#include <math.h>

int main() {
  double  a, b, c;
  double  delta, re, im, root1, root2;
  printf("Input a,b,c:");
  scanf("%lf%lf%lf", &a, &b, &c);
  if (a != 0.0) {
    delta = b*b - 4.0*a*c;
    re = -b/(2.0*a);
    im = sqrt(fabs(delta))/(2.0*a);
    if (delta>= 0.0) {
      root1 = re + (b < 0.0 ? im : -im);
      root2 = c / (a*root1);
      printf("Two real roots are : %7.5f, %7.5f\n", root1, root2);
    } 
    else
      printf("Two complex roots are %7.5f+%7.5fI，%7.5f-%7.5fI\n", re, fabs(im), re, fabs(im));
 }
 else {
   if (b != 0.0)  
     printf("Single root: %7.5f\n", -c/b);
   else if (!c)  
     printf("Infinite number of roots.\n");
   else
     printf("Not root.\n");
  }

  return 0;
} 
