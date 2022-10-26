#include <stdio.h>

void move(int m, char from, char to) {
  printf( "Move disk %d from %c to %c. \n", m, from, to);
}

void hanoi(int n,char a, char b, char c)
{
  if (n == 1) {
    move(n, a, b);
    return;
  }

  hanoi(n-1, a, c, b);
  move(n, a, b);
  hanoi(n-1, c, b, a);
}

int main () {
  int n;
  printf("Enter n: ");
  scanf ("%d", &n);
  // Move n disks from A to C, using B.
  hanoi (n, 'A', 'C', 'B');
  return 0;
}
