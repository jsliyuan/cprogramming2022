#include <stdio.h>

int max2(int a, int b) {
  if (a > b)
  	return a;
  else
  	return b;
}

int max3(int a, int b, int c) {
  return max2(max2(a, b), c);
}

int main() {
  printf("max among 3, 1, 5 is %d\n", max3(3, 1, 5));
  printf("max among 9, 1, 2 is %d\n", max3(9, 1, 2));
  printf("max among 0, 1, 2 is %d\n", max3(0, 1, 2));

  return 1;
}