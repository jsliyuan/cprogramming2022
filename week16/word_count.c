#include  <stdio.h>
#include  <ctype.h>

#define  INWORD   1   /* 正在单词中 */
#define  OUTWORD  0   /* 当前不在单词中 */

int main() {
  FILE *fp;
  int nl, nw, nc, ch, state /* 状态变量 */;
  char fname[40];  /* 存储文件名 */
  printf("Enter file name:\n");
  scanf("%s%*c", fname);

  if ((fp=fopen(fname, "r")) == NULL)  { /* 以输入方式打开正文文件 */
    printf("Cannot open file %s.\n", fname);
    return 0;
  }
  state = OUTWORD;
  nl = nw = nc = 0;
  while((ch = fgetc(fp)) != EOF) { 
    ++ nc; //字符数加1
    if (ch == '\n')
      ++ nl;  //行数加1
    if (!isalpha(ch))//ch中内容不是英文字母
    state = OUTWORD;
    else if (state == OUTWORD) {/*从原先不在单词中，遇到了英文字母*/
      state = INWORD;//置状态在单词中
      ++ nw; //单词计数器增1
    }
  }

  fclose(fp);
  printf("File %s has %d lines, %d words, %d chars.\n", fname, nl, nw, nc);
  return 1;
}

