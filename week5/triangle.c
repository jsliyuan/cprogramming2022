#include <stdio.h>

int main() {
  int a, b, c;
  const int MIN_LEN = 3;
  const int MAX_LEN = 25;

  for(c = MIN_LEN; c <= MAX_LEN; c++)
    for(b = 1; b < c; b++)
      for(a = 1; a <= b; a++)
        if (a*a + b*b == c*c) {
          printf("A=%d\t B=%d\t C=%d\n", a, b, c);
          // Press enter to continue
          scanf("%*c");
	     }

  return 1;
}
