#include  <stdio.h>

int main() {
  FILE *fp;
  int x, k;
  char fname[40];
  printf("Enter file name:\n");
  scanf(" %s%*c", fname);
  if ((fp=fopen(fname, "r")) == NULL)  { /* 以输入方式打开正文文件 */
    printf("Cannot open file %s.\n", fname);
    return 0;
  }
  k = 1;
  while(fscanf(fp, " %d ", &x) == 1) {
    printf("%d\t", x);
    if (k++ % 5 == 0) {
      printf("\n");
    }
  }
  fclose(fp);
  printf(" \nRead %d integers from file %s.\n", k-1, fname);
  return 1;
}
