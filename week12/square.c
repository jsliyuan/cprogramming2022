#include <stdio.h>

int squreByValue(int n) {
  return n*n;
}

void squreByPointer(int *nPtr) {
  *nPtr = *nPtr * *nPtr;
}

int main() {
  int m = 5;
  printf("m = %d\n", m);
  printf("squreByValue(m) = %d\n", squreByValue(m));
  printf("m = %d\n", m);

  printf("m = %d\n", m);
  squreByPointer(&m);
  printf("m = %d\n", m);
  return 0;
}
