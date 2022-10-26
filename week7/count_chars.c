#include  <stdio.h>

void main() {
  char buf[120];
  int i, count[52];

  printf("Enter letter line.\n");
  gets(buf);

  // Initialize count
  for(i = 0; i < 52; i++)
    count[i] = 0;

  for(i = 0; buf[i] != '\0'; i++) {
    if (buf[i] >= 'A' && buf[i] <= 'Z') {
      count[buf[i] - 'A'] ++;
    } else { 
      if (buf[i] >= 'a' && buf[i] <= 'z')
        count[buf[i] - 'a' + 26] ++;
    }
  }

  // Print
  for(i = 0; i < 52; i++) {
    if (count[i])
      printf("%c(%d)\t", i < 26 ? i+'A' : i-26+'a', count[i]);
  }
  printf("\n\n");
}
