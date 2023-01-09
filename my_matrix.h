#ifndef MY_MATRIX_H_
#define MY_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  CORRECT_MATRIX = 0,
  INCORRECT_MATRIX = 1,
  IDENTITY_MATRIX = 2,
  ZERO_MATRIX = 3
} matrix_type_t;

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
  matrix_type_t matrix_type;
} matrix_t;

//  =========  MATRIX FUNCTIONS  =========
//  1. Creation of the matrix
matrix_t func_create_matrix(int rows, int columns);
//  2. Deletion of the matrix
void func_remove_matrix(matrix_t *A);
//  3. Comparison of two matrixes (return 1 - SUCCESS, 0 - FAILURE);
int func_eq_matrix(matrix_t *A, matrix_t *B);
//  4. Addition of two matrixes
matrix_t func_sum_matrix(matrix_t *A, matrix_t *B);
//  5. Substraction of two matrixes
matrix_t func_sub_matrix(matrix_t *A, matrix_t *B);
//  6. Multiplication of the matrix and the number
matrix_t func_mult_number(matrix_t *A, double number);
//  7. Multiplication of two matirixes
matrix_t func_mult_matrix(matrix_t *A, matrix_t *B);
//  8. Transposition of the matrix
matrix_t func_transpose(matrix_t *A);
//  9. Calculation of the cofactor matrix (using minor)
matrix_t func_calc_complements(matrix_t *A);
//  10. Calculation of the matrix determinant by the 1st row
double func_determinant(matrix_t *A);
//  11. Calculation of the inverse matrix
matrix_t func_inverse_matrix(matrix_t *A);

//  =========  HELPER FUNCTIONS  =========
//  1. Fillment of the matrix by constant double massive
void fill_matrix(matrix_t *A, double *src, int size);
//  2. Check if the matrix is zero matrix (success - return 1)
int check_if_matrix_zero(matrix_t A);
//  3. Check if the matrix is identity matrix (success - return 1)
int check_if_matrix_identity(matrix_t A);
//  4. Change matrix_type according to the checking its elements
void check_matrix_type(matrix_t *A);
//  5. Create the new matrix removing i-row and j-column of the original matrix
matrix_t new_matrix_for_determinant(matrix_t A, int row_index,
                                    int column_index);

#endif  // MY_MATRIX_H_
