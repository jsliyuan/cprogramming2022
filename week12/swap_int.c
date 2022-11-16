#include <stdio.h>

void swap(int *, int *);

void main() {
  int a = 1, b = 2;
  printf("a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("a = %d, b = %d\n", a, b);
}

void swap(int* pu, int* pv) {
  int t = *pu;
  *pu = *pv;
  *pv = t;
}
