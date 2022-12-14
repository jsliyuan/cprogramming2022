#include  <stdio.h>

void main() {
  FILE *fp;
  int x, k;
  char fname[40];
  printf("Enter the file name:\n");
  scanf("%s%*c", fname);
  fp = fopen(fname, "w");
  k = 1;
  printf("Enter integers (enter a non-integer to exit):");
  while(scanf("%d", &x) == 1) { /* 能正确输入整数循环 */
    fprintf(fp, "%d\t", x);
    if (k++ % 5 == 0) {
      fprintf(fp, "\n"); 
   }
  }
  fclose(fp);

  printf("\nOuptut %d integers to file %s.\n", k-1, fname);
}
