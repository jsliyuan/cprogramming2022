#include <stdio.h>
#include <stdlib.h>

// Given memory [p, p + max_size) in bytes, find a target int.
void* memory_search(void* p, int target, int max_size) {
  for (int i = 0; i < max_size - sizeof(int); i ++) {
  	int* p_int = (int*) (p + i);
    if (*p_int == target) {
      return (void*) p_int;
    }
  }

  return NULL;
}

int main() {
  void* p = malloc(1024 * sizeof(int));
  int size = 1024 * sizeof(int);
  int target = 0;
  printf("address = %p\n", memory_search(p, target, size));

  return 0;
}