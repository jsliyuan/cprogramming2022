#include <stdio.h>

// Returns the second largest number.
// If it does not exist, return -1.
int second_largest(int* val, int len) {
  if (len < 2) {
    return -1;
  }

  int max1, max2, x, i;
  if (val[0] < val[1]) {
    max1 = val[1];
    max2 = val[0];
  } else {
    max1 = val[0];
    max2 = val[1];
  }

  for(i = 2; i < len; i++) {
    if (val[i] > max1) {
      max2 = max1;
      max1 = val[i];
    } else if (val[i] > max2) {
      max2 = val[i];
    }
  }

  return max2;
}

int main() {
  int n, first, second;
  printf("Enter n (>=2): "); 
  scanf("%d", &n);
  if (n < 2) return 0;

  int val[n], i;
  for(i = 1; i <= n; i++) {  
    printf("Enter the %dth number: ", i);
    scanf("%d", val + i - 1);
  }
  printf("The second largest number is %d\n", second_largest(val, n));

  return 0;
}
