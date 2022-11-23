#include <stdio.h>

int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int  (*fp) (int,int);
  int x=5, y=8;
  fp = min;
  printf("%d\n" ,(*fp)(x, y));
}
