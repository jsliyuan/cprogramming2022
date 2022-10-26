#include <stdio.h>
#include <string.h>

# define MAXLINE 256

int main() {
  int  len, max;
  char line[MAXLINE], save[MAXLINE];
  max = 0;
  while (1) {
    printf("Enter a line (return to finish): \n");
    gets(line);

    if ((len = strlen(line)) == 0) {
      break;
    }
    if (len > max) {
      max = len;
      strcpy(save, line);
    }
  }

  if (max > 0) {
    printf("The max length of line is:\n%s\n", save);
  }
  return 0;
}
