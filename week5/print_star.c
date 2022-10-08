#include <stdio.h>

/* 
When n = 4,
                                         *
                                       * * *
                                     * * * * *
                                   * * * * * * *
                                 * * * * * * * * *
                                   * * * * * * *
                                     * * * * *
                                       * * *
                                         *
*/

int main() {
  int n, j, k;
  printf("Enter n:");
  scanf("%d", &n);

  // Upper part
  for(j = 0; j <= n; j++) { 
    // Print 40 - 2j spaces.
    printf("%*c", 40 - 2*j, ' ');
    for(k = 1; k <= 2*j+1; k++)
      printf(" *");
    printf("\n");
  }

  // Lower part
  for(j = n-1; j >= 0; j--) { 
    printf("%*c", 40 - 2*j, ' ');
    for(k = 1; k <= 2*j+1; k++)
      printf(" *");
    printf("\n");
  }

  return 0;
}
