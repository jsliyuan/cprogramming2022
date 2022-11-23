#include <stdio.h>
#include <string.h>

int main() {
  printf("%d\n", strcmp("alice", "Alice"));
  printf("%d\n", strcmp("alicebob", "alice"));
  printf("%d\n", strcmp("alice", "alice"));
  printf("%d\n", strcmp("", "alice"));

  return 0;
}
