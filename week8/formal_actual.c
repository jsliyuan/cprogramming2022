#include <stdio.h>

void func(int x, int y) {
  x += 10;
  y += 10;
  printf("In function func: x = %d,  y = %d\n", x, y);
}

int main() {
  int x = 5, y = 8;
  printf("In main function, initially: x = %d, y = %d\n", x, y);
  func(x, y);
  printf("After func: x=%d, y=%d\n", x, y);
  return 0;
} 
