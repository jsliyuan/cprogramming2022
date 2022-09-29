#include <stdio.h>

int global_x = 0;

void increase_global_x() {
  global_x ++;
}

void dummy() {
  int global_x;
  global_x = 10;
}

int main() {
  global_x ++;

  increase_global_x();

  dummy();

  printf("global_x = %d\n", global_x);

  return 0;
}