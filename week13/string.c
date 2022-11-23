#include <stdio.h>

int main() {
  // This program cannot run.
  char* cp = "I am a string";
  cp[0] = 'i';
  printf("%s\n", cp);

  return 0;
}
