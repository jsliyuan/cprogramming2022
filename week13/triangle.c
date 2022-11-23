#include <stdio.h>

#define  N  8

int main() {
  int p[N*(N+1)/2], i, j, *pt[N];
  for (pt[0] = p, i = 1; i < N; i ++) {
    pt[i] = pt[i-1] + i;
  }

  for (i = 0; i < N; i++) {
    pt[i][0] = pt[i][i] = 1;
    for (j = 1; j < i; j++) {
      pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
    }
  }

  for(i = 0; i < N; i++) {
    printf ( "%*c", 40-2*i, ' ' );
    for (j = 0; j <= i; j++ )
      printf ( "%4d", pt[i][j] );
    printf ( "\n" );
  }

  return 0;
}
