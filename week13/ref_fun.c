#include <stdio.h>

void print(int &p) {
   printf("%d\n", p);
   p = 0;
}

int main() {
  int i = 10, j = 5;
  print(i);
  printf("%d\n", i);
  print(j);
  printf("%d\n", j);
  
  return 0;
}
