#include <stdio.h>

int min(int x, int y) {
  return x < y ? x : y;
}

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  int  (*fp) (int,int);
  int x=5, y=8;
  fp = min;
  printf("min(x, y) = %d\n" ,(*fp)(x, y));
  fp = max;
  printf("max(x, y) = %d\n" ,(*fp)(x, y));
}
