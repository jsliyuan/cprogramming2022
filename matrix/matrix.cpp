#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#include "matrix.h"

#define DEBUG

using std::swap;

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
    printf("ERR: the sizes of m1 and m2 do not match.");
    return result;
  }
  for (int i = 0; i < m1.m; i++) {
    for (int j = 0; j < m1.n; j++) {
      result.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
    }
  }
  return result;
}

void multiply_matrices(const matrix_type& m1, const matrix_type& m2, matrix_type& result) {
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
}

void multiply_matrix_by_scalar(const matrix_type& m, int scalar, matrix_type& result) {
  if(result.mat == NULL) {
    return;
  }
  if(result.m!=m.m || result.n!=m.n) {
    result.mat = NULL;
    return;
  }
  for (int i = 0; i < m.m; i++) {
    for (int j = 0; j < m.n; j++) {
      result.mat[i][j] = m.mat[i][j] * scalar;
    }
  }
}
matrix_type multiply_matrix_by_scalar(const matrix_type& m, int scalar) {
  matrix_type result = create_matrix(m.m, m.n, NULL);
  multiply_matrix_by_scalar(m, scalar, result);
  return result;
}

void transpose_matrix(const matrix_type& m, matrix_type& result) {
  if(result.mat == NULL) {
    return;
  }
  if(result.m!=m.n || result.n!=m.m) {
    result.mat = NULL;
    return;
  }
  for (int i = 0; i < m.m; i++) {
    for (int j = 0; j < m.n; j++) {
      result.mat[j][i] = m.mat[i][j];
    }
  }
}
matrix_type transpose_matrix(const matrix_type& m) {
  matrix_type result = create_matrix(m.n, m.m, NULL);
  transpose_matrix(m, result);
  return result;
}

void determinant(const matrix_type& m, long long& result) {
  if (m.m != m.n) {
    return;
  }

  if (m.m == 1) {
    result = m.mat[0][0];
    return;
  }

  if (m.m == 2) {
    result = m.mat[0][0] * m.mat[1][1] - m.mat[0][1] * m.mat[1][0];
    return;
  }

  //use Gaussian elimination to reduce the matrix to upper triangular form
  matrix_type temp = create_matrix(m.m, m.n, NULL);
  for (int i = 0; i < m.m; i++) {
    for (int j = 0; j < m.n; j++) {
      temp.mat[i][j] = m.mat[i][j];
    }
  }
  long long res=1;
  int w=1;
	for(int i=0;i<m.m;i++) { 
		for(int j=i+1;j<m.m;++j) {
    	while(temp.mat[i][i]) {
     	  int div=temp.mat[j][i]/temp.mat[i][i];
        for(int k=i;k<=m.m;++k) {
        	temp.mat[j][k]=temp.mat[j][k]-1ll*div*temp.mat[i][k];
        }
        swap(temp.mat[i],temp.mat[j]);w=-w;
    	}
    	swap(temp.mat[i],temp.mat[j]);w=-w;
		}
	}
	for(int i=0;i<m.m;i++)res=1ll*temp.mat[i][i]*res;
	result=1ll*w*res;
  free_matrix(temp);
}
long long determinant(const matrix_type& m) {
  long long result = 0;
  determinant(m, result);
  return result;
}