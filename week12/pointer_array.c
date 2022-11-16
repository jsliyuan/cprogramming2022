#include <stdio.h>

int main() {
  int prime[] = {2, 3, 5, 7, 11, 13};
  int* p = prime;
  for (int i = 0; i < 6; i ++) {
    printf("%d\n", *p);
    p ++;
  }

  return 0;
}