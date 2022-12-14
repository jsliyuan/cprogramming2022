#include  <stdio.h>

void main() {
  FILE *fp;
  int ch;
  char fname[40];
  printf("Enter file name:\n ");
  scanf(" %s%*c ", fname);
  fp = fopen(fname, "w");  
  while((ch = getchar()) != '\n') { /* 逐行处理，至空行结束 */
    do {
      fputc(ch, fp);   /* 行内字符逐一复制 */
    } while ((ch = getchar()) != '\n'); /* 处理当前行 */
    fputc(ch, fp);  /* 输出换行符 */
  }
  fclose(fp);
  printf("End.\n ");
}
