#include <stdio.h>

int main() {
  int n;
  printf("input n: ");
  scanf("%d", &n);  
  int m[n], j;

  m[0] = 1;
  j = 1;
  int e2, e3;
  e2 = e3 = 0;
  while (j < n) {
    if (m[e3]*3+1 >= m[e2]*2+1) {
      m[j] = m[e2]*2+1;
      e2 ++;
      if (m[e3]*3+1 == m[j]) {
        e3++;
      }
    } else {
      m[j] = m[e3]*3+1;
      e3 ++;
    }
    j++;
  }

  int i;
  for (i = 0; i < n; i ++) {
    printf("%d\n", m[i]);
  }

  return 1;
}
