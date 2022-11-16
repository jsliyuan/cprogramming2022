#include  <stdio.h>

void paws(int u, int v) {
  int t = u;
  u = v;
  v = t;
  printf("In paws: u = %d, v = %d\n", u, v);
}

int main() {
  int x = 1, y = 2;
  paws(x, y);
  printf("In main: x = %d, y = %d\n", x, y);

  return 0;
}
