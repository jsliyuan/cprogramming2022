#include <stdio.h>

int main() {
  // an array of length 14
  char s[] = {'h', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!'};

  char *p_char = s;
  printf("%c\n", s[0]);
  printf("%c\n", s[1]);

  unsigned int *p_int = (unsigned int *) p_char;
  printf("%x\n", p_int[0]);
  printf("%x\n", p_int[1]);
  return 0;
}