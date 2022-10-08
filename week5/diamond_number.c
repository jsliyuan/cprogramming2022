#include <stdio.h>

int main() {
  int n, j, k, space;
  printf("Input n: ");
  scanf("%d", &n);
  space = 40;

  // The upper part
  for(j = 1; j <= n; j++, space -= 2) {
    printf("%*c", space, ' ');
    for(k = 1; k <= j; k++)
      printf("%2d", k);

    for(k = j-1; k >= 1; k--)
      printf("%2d", k);
    printf("\n");
  }

  // The lower part
  space += 4;
  for(j=n-1; j >= 1; j--, space +=2) {
    printf("%*c", space, ' ');
    for(k = 1; k <= j; k++)
      printf("%2d", k);
    for(k = j-1; k >= 1; k--)
      printf("%2d", k);
    printf("\n");
  }

  return 0;
}
