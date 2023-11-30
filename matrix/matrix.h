#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_MATRIX_SIZE 1000

// sizeof(matrix_type) = 4*2 + 8 = 16;

struct matrix_type {
 int** mat;

 // m - # rows
 // n - # columns
 int m, n;
};

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

// Create a matrix of size num_row * num_col, and set all

// initial values to entries.

// If entries == NULL, then set all entries to zero.

matrix_type create_matrix(int num_row, int num_col, int* entries);


// Create a matrix of size num_row * num_col, where each entry is a random element
// in [lower_bound, upper_bound].
matrix_type create_random_matrix(int num_row, int num_col, int lower_bound, int upper_bound);

// Free a matrix ...
void free_matrix(matrix_type a);

void set_null_matrix(matrix_type* a);

// Print a matrix...

void print_matrix(matrix_type m);

// Add two matrices, and return their sum.
// If their dimensions do not match, print an error message.
// Example use case:
//   c = add_matrices(a, b);
//   d = add_matrices(c, c);
matrix_type add_matrices(matrix_type m1, matrix_type m2);

matrix_type multiply_matrices(matrix_type m1, matrix_type m2);

// Return true if two matrices are equal (by value).
bool matrices_equal(matrix_type m1, matrix_type m2);


void multiply_matrix_by_scalar(const matrix_type& m, int scalar, matrix_type& result);
matrix_type multiply_matrix_by_scalar(const matrix_type& m, int scalar);

void transpose_matrix(const matrix_type& m, matrix_type& result);
matrix_type transpose_matrix(const matrix_type& m);

void determinant(const matrix_type& m, int64_t& result);
int64_t determinant(const matrix_type& m);

matrix_type identity_matrix(int size);

matrix_type zero_matrix(int m, int n);
matrix_type zero_matrix(int size);

bool trace(const matrix_type& m, int* tr);

#endif

