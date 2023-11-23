#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

// #define DEBUG

/*
matrix_type a, b;
// creation
int entries[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
a = create_matrix(3, 3, entries);
// print
print_matrix(a, 3, 3);
// c = a*b;
c = mult(a, b);
c = add(a, b);
double d = det(a);
*/

void set_null_matrix(matrix_type* a) {
  a->mat = NULL;
  a->m = 0;
  a->n = 0;
}

matrix_type create_matrix(int num_row, int num_col, int* entries) {
  matrix_type result;
  result.m = num_row;
  result.n = num_col;
  
#ifdef DEBUG
  printf("m = %d, n = %d\n", result.m, result.n);
  printf("MAX_MATRIX_SIZE = %d\n", MAX_MATRIX_SIZE);
#endif

  if (num_col > MAX_MATRIX_SIZE || num_row > MAX_MATRIX_SIZE) {
    printf("ERR: Max size of matrix exceeded.\n");
    set_null_matrix(&result);
    return result;
  }

  result.mat = (int**) malloc(num_row * sizeof(int*));
#ifdef DEBUG
  printf("malloc num_row succeeded\n");
#endif
  int i;
  for (i = 0; i < num_row; i++) {
    result.mat[i] = (int*) calloc(num_col, sizeof(int));
  }
#ifdef DEBUG
  printf("calloc succeeded\n");
#endif

  if (entries == NULL)
    return result;
    
#ifdef DEBUG
  printf("entries != NULL\n");
#endif

  int j;
  for (i = 0; i < num_row; i ++) {
    for (j = 0; j < num_col; j ++) {
      result.mat[i][j] = entries[i*num_col + j];
    }
  }

  return result;
}

matrix_type create_random_matrix(int num_row, int num_col, int lower_bound, int upper_bound) {
  matrix_type result = create_matrix(num_row, num_col, NULL);
  int len = upper_bound - lower_bound + 1;
  for (int i = 0; i < num_row; i ++) {
    for (int j = 0; j < num_col; j ++) {
      result.mat[i][j] = rand() % len + lower_bound;
    }
  }
  return result;
}

void free_matrix(matrix_type a) {
  int i;
  for (i = 0; i < a.m; i++) {
  	free(a.mat[i]);
  }
  free(a.mat);

  set_null_matrix(&a);
}

void print_matrix(matrix_type m) {
  int i, j;
  for (i = 0; i < m.m; i ++) {
  	for (j = 0; j < m.n; j ++) {
  	  printf("%d ", m.mat[i][j]);
	}
	printf("\n");
  }
}

matrix_type add_matrices(matrix_type m1, matrix_type m2) {
  matrix_type result = create_matrix(m1.m, m1.n, NULL);
  if (m1.m != m2.m || m1.n != m2.n) {
    printf("ERR: the sizes of m1 and m2 do not match.\n");
    return result;
  }
  for (int i = 0; i < m1.m; i++) {
    for (int j = 0; j < m1.n; j++) {
      result.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
    }
  }
  return result;
}

matrix_type multiply_matrices(matrix_type m1, matrix_type m2) {
  matrix_type result = create_matrix(m1.m, m2.n, NULL);
  if (m1.n != m2.m) {
    printf("ERR: m1.n(%d) != m2.m(%d).\n", m1.n, m2.m);
    return result;
  }
  int temp = 0;
  for (int i = 0; i < m1.m; i++) {
    for (int j = 0; j < m2.n; j++) {
      for (int k = 0; k < m1.n; k++) {
        temp += m1.mat[i][k] * m2.mat[k][j];
      }

      result.mat[i][j] = temp;
      temp = 0;
    }
  }
  return result;
}

bool matrices_equal(matrix_type m1, matrix_type m2) {
  if (m1.m != m2.m || m1.n != m2.n) {
    return false;
  }
  for (int i = 0; i < m1.m; i++) {
    for (int j = 0; j < m1.n; j++) {
      if (m1.mat[i][j] != m2.mat[i][j]) {
        return false;
      }
    }
  }
  return true;
}


