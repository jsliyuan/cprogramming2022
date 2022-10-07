#include <stdio.h>

// Equivalent to the following
// int sum(int x[]) {
// int sum(int* x) {
int sum(int x[5]) {
  int i;
  int result = 0;
  for (i = 0; i < 5; i ++) {
    result += x[i];
  }

  return result;
}

int main() {
  int x[5] = {9, 1, 10, 0, 13};

  printf("sum = %d\n", sum(x));
  return 0;
}