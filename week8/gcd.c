#include <stdio.h>

int gcd(int a,int b) {
  int r = a;
  do {
    a = b;   
    b = r;  
    r = a % b;
  } while (r);

  return b;
}

void main() {
  int a,b;
  printf("Enter a,b:");
  scanf("%d%d",&a,&b);
  printf ("(%d, %d)=%d\n", a, b, gcd(a,b));
 }
