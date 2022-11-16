#include <stdio.h>
#include <string.h>

// Generate all permutations of {0, 1, ..., n-1} recursively.
// The permutation is saved in list[n].
// At this point, we are choosing element list[i].
// chosen[n] is an array of Boolean value, that is, chosen[i] = 1
// if element i is chosen.
void generate_permutations(int n, int i, int* list, int* chosen) {
  if (i >= n) {
  	for (int j = 0; j < n; j ++)
      printf("%d ", list[j]);
    printf("\n");
    return;
  }

  for (int val = 0; val < n; val ++) {
  	if (chosen[val] == 0) {
  	  list[i] = val;
  	  chosen[val] = 1;
  	  generate_permutations(n, i + 1, list, chosen);
  	  chosen[val] = 0;
  	}
  }
}

int main() {
  int n = 5;
  int list[n], chosen[n];
  memset(chosen, 0, n * sizeof(int));
  generate_permutations(n, 0, list, chosen);

  return 0;
}