#include <check.h>

#include "my_matrix.h"

double src_1[1] = {5.25};
double src_2[2] = {5.23, -2.56};
double src_3[6] = {102.455, -455.463, 563.23, 4517.89, 0.398741, 0};
double src_4[6] = {1, 2, 3, 4, 5, 6};
double src_5[6] = {1.0000001, 2, 3, 4, 5, 6};
double src_6_zero[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double src_7_identity[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
double src_8[9] = {3.5,    -2.0034, 4.007,  5.0067,   4.77,
                   3.0078, 2.4,     -4.567, -5.234567};
double src_9[9] = {25.256, -4.2147,   457.698, -4,   895.962,
                   63.56,  -78.95478, 8.9,     0.245};
double src_10[16] = {2.5,  -4.5, 4.7, -9.5, 0.5,  6.5,  -7.5, 8.5,
                     0.23, 5.5,  1.5, 2.5,  14.5, -9.5, 5.5,  0.0};
double src_11[16] = {-2.5,  4.5,  -4.7, 9.5,  -0.5,  -6.5, +7.5, -8.5,
                     -0.23, -5.5, -1.5, -2.5, -14.5, 9.5,  -5.5, 0.0};

START_TEST(create_matrix_test) {
  int rows_1 = 3;
  int columns_1 = 3;
  matrix_t Matrix_1 = func_create_matrix(rows_1, columns_1);
  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++)
      ck_assert_double_eq_tol(Matrix_1.matrix[i][j], 0, 1e-6);
  }
  ck_assert_int_eq(Matrix_1.rows, 3);
  ck_assert_int_eq(Matrix_1.columns, 3);
  ck_assert_int_eq(Matrix_1.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Matrix_1);

  int rows_2 = 5;
  int columns_2 = 3;
  matrix_t Matrix_2 = func_create_matrix(rows_2, columns_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++)
      ck_assert_double_eq_tol(Matrix_2.matrix[i][j], 0, 1e-6);
  }
  ck_assert_int_eq(Matrix_2.rows, 5);
  ck_assert_int_eq(Matrix_2.columns, 3);
  ck_assert_int_eq(Matrix_2.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Matrix_2);

  int rows_3 = 0;
  int columns_3 = 3;
  matrix_t Matrix_3 = func_create_matrix(rows_3, columns_3);
  ck_assert_ptr_null(Matrix_3.matrix);
  ck_assert_int_eq(Matrix_3.rows, 0);
  ck_assert_int_eq(Matrix_3.columns, 0);
  ck_assert_int_eq(Matrix_3.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Matrix_3);

  int rows_4 = 0;
  int columns_4 = -3;
  matrix_t Matrix_4 = func_create_matrix(rows_4, columns_4);
  ck_assert_ptr_null(Matrix_4.matrix);
  ck_assert_int_eq(Matrix_4.rows, 0);
  ck_assert_int_eq(Matrix_4.columns, 0);
  ck_assert_int_eq(Matrix_4.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Matrix_4);
}
END_TEST

START_TEST(matrix_eq_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_9 = func_create_matrix(3, 3);
  fill_matrix(&A_9, src_9, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);
  ck_assert_int_eq(func_eq_matrix(&A_1, &A_1), 1);
  ck_assert_int_eq(func_eq_matrix(&A_1, &A_2), 0);
  ck_assert_int_eq(func_eq_matrix(&A_2, &A_2), 1);
  ck_assert_int_eq(func_eq_matrix(&A_2, &A_3), 0);
  ck_assert_int_eq(func_eq_matrix(&A_3, &A_3), 1);
  ck_assert_int_eq(func_eq_matrix(&A_3, &A_4), 0);
  ck_assert_int_eq(func_eq_matrix(&A_4, &A_4), 1);
  ck_assert_int_eq(func_eq_matrix(&A_4, &A_5), 0);
  ck_assert_int_eq(func_eq_matrix(&A_5, &A_5), 1);
  ck_assert_int_eq(func_eq_matrix(&A_5, &A_6), 0);
  ck_assert_int_eq(func_eq_matrix(&A_6, &A_6), 1);
  ck_assert_int_eq(func_eq_matrix(&A_6, &A_7), 0);
  ck_assert_int_eq(func_eq_matrix(&A_7, &A_7), 1);
  ck_assert_int_eq(func_eq_matrix(&A_7, &A_8), 0);
  ck_assert_int_eq(func_eq_matrix(&A_8, &A_8), 1);
  ck_assert_int_eq(func_eq_matrix(&A_8, &A_9), 0);
  ck_assert_int_eq(func_eq_matrix(&A_9, &A_9), 1);
  ck_assert_int_eq(func_eq_matrix(&A_9, &A_10), 0);
  ck_assert_int_eq(func_eq_matrix(&A_10, &A_10), 1);
  ck_assert_int_eq(func_eq_matrix(&A_10, &A_11), 0);
  ck_assert_int_eq(func_eq_matrix(&A_11, &A_11), 1);
  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_9);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_11);
}
END_TEST

START_TEST(matrix_sum_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_9 = func_create_matrix(3, 3);
  fill_matrix(&A_9, src_9, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);

  matrix_t Result_1 = func_sum_matrix(&A_1, &A_1);
  for (int i = 0; i < Result_1.rows; i++) {
    for (int j = 0; j < Result_1.columns; j++)
      ck_assert_double_eq_tol(Result_1.matrix[i][j],
                              A_1.matrix[i][j] + A_1.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_1.rows, 1);
  ck_assert_int_eq(Result_1.columns, 1);
  ck_assert_int_eq(Result_1.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_1);

  matrix_t Result_2 = func_sum_matrix(&A_1, &A_2);
  ck_assert_int_eq(Result_2.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_2);

  matrix_t Result_3 = func_sum_matrix(&A_3, &A_4);
  ck_assert_int_eq(Result_3.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_3);

  matrix_t Result_4 = func_sum_matrix(&A_4, &A_5);
  for (int i = 0; i < Result_4.rows; i++) {
    for (int j = 0; j < Result_4.columns; j++)
      ck_assert_double_eq_tol(Result_4.matrix[i][j],
                              A_4.matrix[i][j] + A_5.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_4.rows, 2);
  ck_assert_int_eq(Result_4.columns, 3);
  ck_assert_int_eq(Result_4.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_4);

  matrix_t Result_5 = func_sum_matrix(&A_6, &A_6);
  for (int i = 0; i < Result_5.rows; i++) {
    for (int j = 0; j < Result_5.columns; j++)
      ck_assert_double_eq_tol(Result_5.matrix[i][j],
                              A_6.matrix[i][j] + A_6.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_5.rows, 3);
  ck_assert_int_eq(Result_5.columns, 3);
  ck_assert_int_eq(Result_5.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Result_5);

  matrix_t Result_6 = func_sum_matrix(&A_6, &A_7);
  for (int i = 0; i < Result_6.rows; i++) {
    for (int j = 0; j < Result_6.columns; j++)
      ck_assert_double_eq_tol(Result_6.matrix[i][j],
                              A_6.matrix[i][j] + A_7.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_6.rows, 3);
  ck_assert_int_eq(Result_6.columns, 3);
  ck_assert_int_eq(Result_6.matrix_type, IDENTITY_MATRIX);
  func_remove_matrix(&Result_6);

  matrix_t Result_7 = func_sum_matrix(&A_8, &A_9);
  for (int i = 0; i < Result_7.rows; i++) {
    for (int j = 0; j < Result_7.columns; j++)
      ck_assert_double_eq_tol(Result_7.matrix[i][j],
                              A_8.matrix[i][j] + A_9.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_7.rows, 3);
  ck_assert_int_eq(Result_7.columns, 3);
  ck_assert_int_eq(Result_7.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_7);

  matrix_t Result_8 = func_sum_matrix(&A_10, &A_11);
  for (int i = 0; i < Result_8.rows; i++) {
    for (int j = 0; j < Result_8.columns; j++)
      ck_assert_double_eq_tol(Result_8.matrix[i][j],
                              A_10.matrix[i][j] + A_11.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_8.rows, 4);
  ck_assert_int_eq(Result_8.columns, 4);
  ck_assert_int_eq(Result_8.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Result_8);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_9);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_11);
}
END_TEST

START_TEST(matrix_sub_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_9 = func_create_matrix(3, 3);
  fill_matrix(&A_9, src_9, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);

  matrix_t Result_1 = func_sub_matrix(&A_1, &A_1);
  for (int i = 0; i < Result_1.rows; i++) {
    for (int j = 0; j < Result_1.columns; j++)
      ck_assert_double_eq_tol(Result_1.matrix[i][j],
                              A_1.matrix[i][j] - A_1.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_1.rows, 1);
  ck_assert_int_eq(Result_1.columns, 1);
  ck_assert_int_eq(Result_1.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Result_1);

  matrix_t Result_2 = func_sub_matrix(&A_1, &A_2);
  ck_assert_int_eq(Result_2.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_2);

  matrix_t Result_3 = func_sub_matrix(&A_3, &A_4);
  ck_assert_int_eq(Result_3.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_3);

  matrix_t Result_4 = func_sub_matrix(&A_4, &A_5);
  for (int i = 0; i < Result_4.rows; i++) {
    for (int j = 0; j < Result_4.columns; j++)
      ck_assert_double_eq_tol(Result_4.matrix[i][j],
                              A_4.matrix[i][j] - A_5.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_4.rows, 2);
  ck_assert_int_eq(Result_4.columns, 3);
  ck_assert_int_eq(Result_4.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_4);

  matrix_t Result_5 = func_sub_matrix(&A_6, &A_6);
  for (int i = 0; i < Result_5.rows; i++) {
    for (int j = 0; j < Result_5.columns; j++)
      ck_assert_double_eq_tol(Result_5.matrix[i][j],
                              A_6.matrix[i][j] - A_6.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_5.rows, 3);
  ck_assert_int_eq(Result_5.columns, 3);
  ck_assert_int_eq(Result_5.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Result_5);

  matrix_t Result_6 = func_sub_matrix(&A_6, &A_7);
  for (int i = 0; i < Result_6.rows; i++) {
    for (int j = 0; j < Result_6.columns; j++)
      ck_assert_double_eq_tol(Result_6.matrix[i][j],
                              A_6.matrix[i][j] - A_7.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_6.rows, 3);
  ck_assert_int_eq(Result_6.columns, 3);
  ck_assert_int_eq(Result_6.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_6);

  matrix_t Result_7 = func_sub_matrix(&A_8, &A_9);
  for (int i = 0; i < Result_7.rows; i++) {
    for (int j = 0; j < Result_7.columns; j++)
      ck_assert_double_eq_tol(Result_7.matrix[i][j],
                              A_8.matrix[i][j] - A_9.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_7.rows, 3);
  ck_assert_int_eq(Result_7.columns, 3);
  ck_assert_int_eq(Result_7.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_7);

  matrix_t Result_8 = func_sub_matrix(&A_10, &A_11);
  for (int i = 0; i < Result_8.rows; i++) {
    for (int j = 0; j < Result_8.columns; j++)
      ck_assert_double_eq_tol(Result_8.matrix[i][j],
                              A_10.matrix[i][j] - A_11.matrix[i][j], 1e-6);
  }
  ck_assert_int_eq(Result_8.rows, 4);
  ck_assert_int_eq(Result_8.columns, 4);
  ck_assert_int_eq(Result_8.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_8);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_9);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_11);
}
END_TEST

START_TEST(mult_number_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);

  matrix_t Result_1 = func_mult_number(&A_1, 0.0);
  for (int i = 0; i < Result_1.rows; i++) {
    for (int j = 0; j < Result_1.columns; j++)
      ck_assert_double_eq_tol(Result_1.matrix[i][j], A_1.matrix[i][j] * 0.0,
                              1e-6);
  }
  ck_assert_int_eq(Result_1.rows, 1);
  ck_assert_int_eq(Result_1.columns, 1);
  ck_assert_int_eq(Result_1.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Result_1);

  matrix_t Result_2 = func_mult_number(&A_1, 2.3);
  for (int i = 0; i < Result_2.rows; i++) {
    for (int j = 0; j < Result_2.columns; j++)
      ck_assert_double_eq_tol(Result_2.matrix[i][j], A_1.matrix[i][j] * 2.3,
                              1e-6);
  }
  ck_assert_int_eq(Result_2.rows, 1);
  ck_assert_int_eq(Result_2.columns, 1);
  ck_assert_int_eq(Result_2.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_2);

  matrix_t Result_3 = func_mult_number(&A_4, 0.5);
  for (int i = 0; i < Result_3.rows; i++) {
    for (int j = 0; j < Result_3.columns; j++)
      ck_assert_double_eq_tol(Result_3.matrix[i][j], A_4.matrix[i][j] * 0.5,
                              1e-6);
  }
  ck_assert_int_eq(Result_3.rows, 2);
  ck_assert_int_eq(Result_3.columns, 3);
  ck_assert_int_eq(Result_3.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_3);

  matrix_t Result_4 = func_mult_number(&A_6, 0.5);
  for (int i = 0; i < Result_4.rows; i++) {
    for (int j = 0; j < Result_4.columns; j++)
      ck_assert_double_eq_tol(Result_4.matrix[i][j], A_6.matrix[i][j] * 0.5,
                              1e-6);
  }
  ck_assert_int_eq(Result_4.rows, 3);
  ck_assert_int_eq(Result_4.columns, 3);
  ck_assert_int_eq(Result_4.matrix_type, ZERO_MATRIX);
  func_remove_matrix(&Result_4);

  matrix_t Result_5 = func_mult_number(&A_7, 1);
  for (int i = 0; i < Result_5.rows; i++) {
    for (int j = 0; j < Result_5.columns; j++)
      ck_assert_double_eq_tol(Result_5.matrix[i][j], A_7.matrix[i][j] * 1,
                              1e-6);
  }
  ck_assert_int_eq(Result_5.rows, 3);
  ck_assert_int_eq(Result_5.columns, 3);
  ck_assert_int_eq(Result_5.matrix_type, IDENTITY_MATRIX);
  func_remove_matrix(&Result_5);

  matrix_t Result_6 = func_mult_number(&A_8, 1000);
  for (int i = 0; i < Result_6.rows; i++) {
    for (int j = 0; j < Result_6.columns; j++)
      ck_assert_double_eq_tol(Result_6.matrix[i][j], A_8.matrix[i][j] * 1000,
                              1e-6);
  }
  ck_assert_int_eq(Result_6.rows, 3);
  ck_assert_int_eq(Result_6.columns, 3);
  ck_assert_int_eq(Result_6.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_6);

  matrix_t Result_7 = func_mult_number(&A_10, -1.89);
  for (int i = 0; i < Result_7.rows; i++) {
    for (int j = 0; j < Result_7.columns; j++)
      ck_assert_double_eq_tol(Result_7.matrix[i][j],
                              A_10.matrix[i][j] * (-1.89), 1e-6);
  }
  ck_assert_int_eq(Result_7.rows, 4);
  ck_assert_int_eq(Result_7.columns, 4);
  ck_assert_int_eq(Result_7.matrix_type, CORRECT_MATRIX);
  func_remove_matrix(&Result_7);

  matrix_t A_12 = {NULL, 1, 2, INCORRECT_MATRIX};
  matrix_t Result_8 = func_mult_number(&A_12, -1.89);
  ck_assert_int_eq(Result_8.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_8);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_12);
}
END_TEST

START_TEST(matrix_mult_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_9 = func_create_matrix(3, 3);
  fill_matrix(&A_9, src_9, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);

  matrix_t Result_1 = func_mult_matrix(&A_1, &A_2);
  matrix_t Original_1 = func_create_matrix(1, 2);
  double original_src_1[2] = {27.4575, -13.44};
  fill_matrix(&Original_1, original_src_1, 2);
  for (int i = 0; i < Result_1.rows; i++) {
    for (int j = 0; j < Result_1.columns; j++)
      ck_assert_double_eq_tol(Result_1.matrix[i][j], Original_1.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_1.rows, Original_1.rows);
  ck_assert_int_eq(Result_1.columns, Original_1.columns);
  ck_assert_int_eq(Result_1.matrix_type, Original_1.matrix_type);
  func_remove_matrix(&Result_1);
  func_remove_matrix(&Original_1);

  matrix_t Result_2 = func_mult_matrix(&A_2, &A_3);
  ck_assert_int_eq(Result_2.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_2);

  matrix_t Result_3 = func_mult_matrix(&A_4, &A_5);
  ck_assert_int_eq(Result_3.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_3);

  matrix_t Result_4 = func_mult_matrix(&A_3, &A_4);
  matrix_t Original_4 = func_create_matrix(3, 3);
  double original_src_4[9] = {-1719.397, -2072.405, -2425.413,
                              18634.79,  23715.91,  28797.03,
                              0.398741,  0.797482,  1.196223};
  fill_matrix(&Original_4, original_src_4, 9);
  for (int i = 0; i < Result_4.rows; i++) {
    for (int j = 0; j < Result_4.columns; j++)
      ck_assert_double_eq_tol(Result_4.matrix[i][j], Original_4.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_4.rows, Original_4.rows);
  ck_assert_int_eq(Result_4.columns, Original_4.columns);
  ck_assert_int_eq(Result_4.matrix_type, Original_4.matrix_type);
  func_remove_matrix(&Result_4);
  func_remove_matrix(&Original_4);

  matrix_t Result_5 = func_mult_matrix(&A_6, &A_7);
  matrix_t Original_5 = func_create_matrix(3, 3);
  double original_src_5[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  fill_matrix(&Original_5, original_src_5, 9);
  for (int i = 0; i < Result_5.rows; i++) {
    for (int j = 0; j < Result_5.columns; j++)
      ck_assert_double_eq_tol(Result_5.matrix[i][j], Original_5.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_5.rows, Original_5.rows);
  ck_assert_int_eq(Result_5.columns, Original_5.columns);
  ck_assert_int_eq(Result_5.matrix_type, Original_5.matrix_type);
  func_remove_matrix(&Result_5);
  func_remove_matrix(&Original_5);

  matrix_t Result_6 = func_mult_matrix(&A_8, &A_9);
  matrix_t Original_6 = func_create_matrix(3, 3);
  double original_src_6[9] = {-219.962203, -1774.059421, 1475.588611,
                              -130.110972, 4279.406422,  2595.474688,
                              492.176486,  -4148.561380, 806.914211};
  fill_matrix(&Original_6, original_src_6, 9);
  for (int i = 0; i < Result_6.rows; i++) {
    for (int j = 0; j < Result_6.columns; j++)
      ck_assert_double_eq_tol(Result_6.matrix[i][j], Original_6.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_6.rows, Original_6.rows);
  ck_assert_int_eq(Result_6.columns, Original_6.columns);
  ck_assert_int_eq(Result_6.matrix_type, Original_6.matrix_type);
  func_remove_matrix(&Result_6);
  func_remove_matrix(&Original_6);

  matrix_t Result_7 = func_mult_matrix(&A_10, &A_11);
  matrix_t Original_7 = func_create_matrix(4, 4);
  double original_src_7[16] = {
      132.669, -75.6,   -0.3,   50.25,   -126.025, 82,    10.9,    -31.75,
      -39.92,  -19.215, 24.169, -48.315, -32.765,  96.75, -147.65, 204.75};
  fill_matrix(&Original_7, original_src_7, 16);
  for (int i = 0; i < Result_7.rows; i++) {
    for (int j = 0; j < Result_7.columns; j++)
      ck_assert_double_eq_tol(Result_7.matrix[i][j], Original_7.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_7.rows, Original_7.rows);
  ck_assert_int_eq(Result_7.columns, Original_7.columns);
  ck_assert_int_eq(Result_7.matrix_type, Original_7.matrix_type);
  func_remove_matrix(&Result_7);
  func_remove_matrix(&Original_7);

  matrix_t A_12 = {NULL, 1, 2, INCORRECT_MATRIX};
  matrix_t Result_8 = func_mult_matrix(&A_12, &A_4);
  ck_assert_int_eq(Result_8.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_8);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_9);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_11);
  func_remove_matrix(&A_12);
}
END_TEST

START_TEST(matrix_transpose_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);

  matrix_t Result_1 = func_transpose(&A_1);
  matrix_t Original_1 = func_create_matrix(1, 1);
  double original_src_1[1] = {5.25};
  fill_matrix(&Original_1, original_src_1, 1);
  for (int i = 0; i < Result_1.rows; i++) {
    for (int j = 0; j < Result_1.columns; j++)
      ck_assert_double_eq_tol(Result_1.matrix[i][j], Original_1.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_1.rows, Original_1.rows);
  ck_assert_int_eq(Result_1.columns, Original_1.columns);
  ck_assert_int_eq(Result_1.matrix_type, Original_1.matrix_type);
  func_remove_matrix(&Result_1);
  func_remove_matrix(&Original_1);

  matrix_t Result_2 = func_transpose(&A_2);
  matrix_t Original_2 = func_create_matrix(2, 1);
  double original_src_2[2] = {5.23, -2.56};
  fill_matrix(&Original_2, original_src_2, 2);
  for (int i = 0; i < Result_2.rows; i++) {
    for (int j = 0; j < Result_2.columns; j++)
      ck_assert_double_eq_tol(Result_2.matrix[i][j], Original_2.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_2.rows, Original_2.rows);
  ck_assert_int_eq(Result_2.columns, Original_2.columns);
  ck_assert_int_eq(Result_2.matrix_type, Original_2.matrix_type);
  func_remove_matrix(&Result_2);
  func_remove_matrix(&Original_2);

  matrix_t Result_3 = func_transpose(&A_3);
  matrix_t Original_3 = func_create_matrix(2, 3);
  double original_src_3[6] = {102.455, 563.23, 0.398741, -455.463, 4517.89, 0};
  fill_matrix(&Original_3, original_src_3, 6);
  for (int i = 0; i < Result_3.rows; i++) {
    for (int j = 0; j < Result_3.columns; j++)
      ck_assert_double_eq_tol(Result_3.matrix[i][j], Original_3.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_3.rows, Original_3.rows);
  ck_assert_int_eq(Result_3.columns, Original_3.columns);
  ck_assert_int_eq(Result_3.matrix_type, Original_3.matrix_type);
  func_remove_matrix(&Result_3);
  func_remove_matrix(&Original_3);

  matrix_t Result_4 = func_transpose(&A_4);
  matrix_t Original_4 = func_create_matrix(3, 2);
  double original_src_4[6] = {1, 4, 2, 5, 3, 6};
  fill_matrix(&Original_4, original_src_4, 6);
  for (int i = 0; i < Result_4.rows; i++) {
    for (int j = 0; j < Result_4.columns; j++)
      ck_assert_double_eq_tol(Result_4.matrix[i][j], Original_4.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_4.rows, Original_4.rows);
  ck_assert_int_eq(Result_4.columns, Original_4.columns);
  ck_assert_int_eq(Result_4.matrix_type, Original_4.matrix_type);
  func_remove_matrix(&Result_4);
  func_remove_matrix(&Original_4);

  matrix_t Result_5 = func_transpose(&A_5);
  matrix_t Original_5 = func_create_matrix(3, 2);
  double original_src_5[6] = {1.0000001, 4, 2, 5, 3, 6};
  fill_matrix(&Original_5, original_src_5, 6);
  for (int i = 0; i < Result_5.rows; i++) {
    for (int j = 0; j < Result_5.columns; j++)
      ck_assert_double_eq_tol(Result_5.matrix[i][j], Original_5.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_5.rows, Original_5.rows);
  ck_assert_int_eq(Result_5.columns, Original_5.columns);
  ck_assert_int_eq(Result_5.matrix_type, Original_5.matrix_type);
  func_remove_matrix(&Result_5);
  func_remove_matrix(&Original_5);

  matrix_t Result_6 = func_transpose(&A_6);
  matrix_t Original_6 = func_create_matrix(3, 3);
  double original_src_6[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  fill_matrix(&Original_6, original_src_6, 9);
  for (int i = 0; i < Result_6.rows; i++) {
    for (int j = 0; j < Result_6.columns; j++)
      ck_assert_double_eq_tol(Result_6.matrix[i][j], Original_6.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_6.rows, Original_6.rows);
  ck_assert_int_eq(Result_6.columns, Original_6.columns);
  ck_assert_int_eq(Result_6.matrix_type, Original_6.matrix_type);
  func_remove_matrix(&Result_6);
  func_remove_matrix(&Original_6);

  matrix_t Result_7 = func_transpose(&A_7);
  matrix_t Original_7 = func_create_matrix(3, 3);
  double original_src_7[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  fill_matrix(&Original_7, original_src_7, 9);
  for (int i = 0; i < Result_7.rows; i++) {
    for (int j = 0; j < Result_7.columns; j++)
      ck_assert_double_eq_tol(Result_7.matrix[i][j], Original_7.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_7.rows, Original_7.rows);
  ck_assert_int_eq(Result_7.columns, Original_7.columns);
  ck_assert_int_eq(Result_7.matrix_type, Original_7.matrix_type);
  func_remove_matrix(&Result_7);
  func_remove_matrix(&Original_7);

  matrix_t Result_11 = func_transpose(&A_11);
  matrix_t Original_11 = func_create_matrix(4, 4);
  double original_src_11[16] = {-2.5, -0.5, -0.23, -14.5, 4.5, -6.5, -5.5, 9.5,
                                -4.7, 7.5,  -1.5,  -5.5,  9.5, -8.5, -2.5, 0};
  fill_matrix(&Original_11, original_src_11, 16);
  for (int i = 0; i < Result_11.rows; i++) {
    for (int j = 0; j < Result_11.columns; j++)
      ck_assert_double_eq_tol(Result_11.matrix[i][j], Original_11.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_11.rows, Original_11.rows);
  ck_assert_int_eq(Result_11.columns, Original_11.columns);
  ck_assert_int_eq(Result_11.matrix_type, Original_11.matrix_type);
  func_remove_matrix(&Result_11);
  func_remove_matrix(&Original_11);

  matrix_t A_12 = {NULL, 1, 2, INCORRECT_MATRIX};
  matrix_t Result_12 = func_transpose(&A_12);
  ck_assert_int_eq(Result_12.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_12);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_11);
  func_remove_matrix(&A_12);
}
END_TEST

START_TEST(matrix_determinant_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_9 = func_create_matrix(3, 3);
  fill_matrix(&A_9, src_9, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);

  double Result_1 = func_determinant(&A_1);
  ck_assert_double_eq_tol(Result_1, 5.25, 1e-6);
  double Result_2 = func_determinant(&A_2);
  ck_assert_double_nan(Result_2);
  double Result_3 = func_determinant(&A_3);
  ck_assert_double_nan(Result_3);
  double Result_4 = func_determinant(&A_4);
  ck_assert_double_nan(Result_4);
  double Result_5 = func_determinant(&A_5);
  ck_assert_double_nan(Result_5);
  double Result_6 = func_determinant(&A_6);
  ck_assert_double_eq_tol(Result_6, 0.0, 1e-6);
  double Result_7 = func_determinant(&A_7);
  ck_assert_double_eq_tol(Result_7, 1.0, 1e-6);
  double Result_8 = func_determinant(&A_8);
  ck_assert_double_eq_tol(Result_8, -243.774411, 1e-6);
  double Result_9 = func_determinant(&A_9);
  ck_assert_double_eq_tol(Result_9, 32373887.178389, 1e-6);
  double Result_10 = func_determinant(&A_10);
  ck_assert_double_eq_tol(Result_10, 4333.713, 1e-6);
  double Result_11 = func_determinant(&A_11);
  ck_assert_double_eq_tol(Result_11, 4333.713, 1e-6);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_9);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_11);
}
END_TEST

START_TEST(calc_complements_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_9 = func_create_matrix(3, 3);
  fill_matrix(&A_9, src_9, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);

  matrix_t Result_1 = func_calc_complements(&A_1);
  matrix_t Original_1 = func_create_matrix(1, 1);
  double original_src_1[1] = {1};
  fill_matrix(&Original_1, original_src_1, 1);
  for (int i = 0; i < Result_1.rows; i++) {
    for (int j = 0; j < Result_1.columns; j++)
      ck_assert_double_eq_tol(Result_1.matrix[i][j], Original_1.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_1.rows, Original_1.rows);
  ck_assert_int_eq(Result_1.columns, Original_1.columns);
  ck_assert_int_eq(Result_1.matrix_type, Original_1.matrix_type);
  func_remove_matrix(&Result_1);
  func_remove_matrix(&Original_1);

  matrix_t Result_2 = func_calc_complements(&A_2);
  ck_assert_int_eq(Result_2.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_2);

  matrix_t Result_3 = func_calc_complements(&A_3);
  ck_assert_int_eq(Result_3.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_3);

  matrix_t Result_4 = func_calc_complements(&A_4);
  ck_assert_int_eq(Result_4.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_4);

  matrix_t Result_5 = func_calc_complements(&A_5);
  ck_assert_int_eq(Result_5.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_5);

  matrix_t Result_6 = func_calc_complements(&A_6);
  matrix_t Original_6 = func_create_matrix(3, 3);
  double original_src_6[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  fill_matrix(&Original_6, original_src_6, 9);
  for (int i = 0; i < Result_6.rows; i++) {
    for (int j = 0; j < Result_6.columns; j++)
      ck_assert_double_eq_tol(Result_6.matrix[i][j], Original_6.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_6.rows, Original_6.rows);
  ck_assert_int_eq(Result_6.columns, Original_6.columns);
  ck_assert_int_eq(Result_6.matrix_type, Original_6.matrix_type);
  func_remove_matrix(&Result_6);
  func_remove_matrix(&Original_6);

  matrix_t Result_7 = func_calc_complements(&A_7);
  matrix_t Original_7 = func_create_matrix(3, 3);
  double original_src_7[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  fill_matrix(&Original_7, original_src_7, 9);
  for (int i = 0; i < Result_7.rows; i++) {
    for (int j = 0; j < Result_7.columns; j++)
      ck_assert_double_eq_tol(Result_7.matrix[i][j], Original_7.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_7.rows, Original_7.rows);
  ck_assert_int_eq(Result_7.columns, Original_7.columns);
  ck_assert_int_eq(Result_7.matrix_type, Original_7.matrix_type);
  func_remove_matrix(&Result_7);
  func_remove_matrix(&Original_7);

  matrix_t Result_8 = func_calc_complements(&A_8);
  matrix_t Original_8 = func_create_matrix(3, 3);
  double original_src_8[9] = {-11.232262, 33.426627,  -34.313599,
                              -28.786901, -27.937785, 11.17634,
                              -25.139217, 9.534547,   26.725423};
  fill_matrix(&Original_8, original_src_8, 9);
  for (int i = 0; i < Result_8.rows; i++) {
    for (int j = 0; j < Result_8.columns; j++)
      ck_assert_double_eq_tol(Result_8.matrix[i][j], Original_8.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_8.rows, Original_8.rows);
  ck_assert_int_eq(Result_8.columns, Original_8.columns);
  ck_assert_int_eq(Result_8.matrix_type, Original_8.matrix_type);
  func_remove_matrix(&Result_8);
  func_remove_matrix(&Original_8);

  matrix_t Result_9 = func_calc_complements(&A_9);
  matrix_t Original_9 = func_create_matrix(3, 3);
  double original_src_9[9] = {-346.17331,     -5017.385817, 70704.882598,
                              4074.544802,    36143.632616, 107.992311,
                              -410347.901808, -3436.06336,  22611.557472};
  fill_matrix(&Original_9, original_src_9, 9);
  for (int i = 0; i < Result_9.rows; i++) {
    for (int j = 0; j < Result_9.columns; j++)
      ck_assert_double_eq_tol(Result_9.matrix[i][j], Original_9.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_9.rows, Original_9.rows);
  ck_assert_int_eq(Result_9.columns, Original_9.columns);
  ck_assert_int_eq(Result_9.matrix_type, Original_9.matrix_type);
  func_remove_matrix(&Result_9);
  func_remove_matrix(&Original_9);

  matrix_t Result_10 = func_calc_complements(&A_10);
  matrix_t Original_10 = func_create_matrix(4, 4);
  double original_src_10[16] = {467,   452.8725, -448.9475, -769.915,
                                472.5, 330.6075, -674.6325, -366.027,
                                168.1, 596.85,   587.75,    52.3,
                                199.4, -98.949,  91.345,    144.536};
  fill_matrix(&Original_10, original_src_10, 16);
  for (int i = 0; i < Result_10.rows; i++) {
    for (int j = 0; j < Result_10.columns; j++)
      ck_assert_double_eq_tol(Result_10.matrix[i][j], Original_10.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_10.rows, Original_10.rows);
  ck_assert_int_eq(Result_10.columns, Original_10.columns);
  ck_assert_int_eq(Result_10.matrix_type, Original_10.matrix_type);
  func_remove_matrix(&Result_10);
  func_remove_matrix(&Original_10);

  matrix_t Result_11 = func_calc_complements(&A_11);
  matrix_t Original_11 = func_create_matrix(4, 4);
  double original_src_11[16] = {-467,   -452.8725, 448.9475, 769.915,
                                -472.5, -330.6075, 674.6325, 366.027,
                                -168.1, -596.85,   -587.75,  -52.3,
                                -199.4, 98.949,    -91.345,  -144.536};
  fill_matrix(&Original_11, original_src_11, 16);
  for (int i = 0; i < Result_11.rows; i++) {
    for (int j = 0; j < Result_11.columns; j++)
      ck_assert_double_eq_tol(Result_11.matrix[i][j], Original_11.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_11.rows, Original_11.rows);
  ck_assert_int_eq(Result_11.columns, Original_11.columns);
  ck_assert_int_eq(Result_11.matrix_type, Original_11.matrix_type);
  func_remove_matrix(&Result_11);
  func_remove_matrix(&Original_11);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_9);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_11);
}
END_TEST

START_TEST(inverse_matrix_test) {
  matrix_t A_1 = func_create_matrix(1, 1);
  fill_matrix(&A_1, src_1, 1);
  matrix_t A_2 = func_create_matrix(1, 2);
  fill_matrix(&A_2, src_2, 2);
  matrix_t A_3 = func_create_matrix(3, 2);
  fill_matrix(&A_3, src_3, 6);
  matrix_t A_4 = func_create_matrix(2, 3);
  fill_matrix(&A_4, src_4, 6);
  matrix_t A_5 = func_create_matrix(2, 3);
  fill_matrix(&A_5, src_5, 6);
  matrix_t A_6 = func_create_matrix(3, 3);
  fill_matrix(&A_6, src_6_zero, 9);
  matrix_t A_7 = func_create_matrix(3, 3);
  fill_matrix(&A_7, src_7_identity, 9);
  matrix_t A_8 = func_create_matrix(3, 3);
  fill_matrix(&A_8, src_8, 9);
  matrix_t A_9 = func_create_matrix(3, 3);
  fill_matrix(&A_9, src_9, 9);
  matrix_t A_10 = func_create_matrix(4, 4);
  fill_matrix(&A_10, src_10, 16);
  matrix_t A_11 = func_create_matrix(4, 4);
  fill_matrix(&A_11, src_11, 16);

  matrix_t Result_1 = func_inverse_matrix(&A_1);
  matrix_t Original_1 = func_create_matrix(1, 1);
  double original_src_1[1] = {0.190476};
  fill_matrix(&Original_1, original_src_1, 1);
  for (int i = 0; i < Result_1.rows; i++) {
    for (int j = 0; j < Result_1.columns; j++)
      ck_assert_double_eq_tol(Result_1.matrix[i][j], Original_1.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_1.rows, Original_1.rows);
  ck_assert_int_eq(Result_1.columns, Original_1.columns);
  ck_assert_int_eq(Result_1.matrix_type, Original_1.matrix_type);
  func_remove_matrix(&Result_1);
  func_remove_matrix(&Original_1);

  matrix_t Result_2 = func_inverse_matrix(&A_2);
  ck_assert_int_eq(Result_2.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_2);

  matrix_t Result_3 = func_inverse_matrix(&A_3);
  ck_assert_int_eq(Result_3.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_3);

  matrix_t Result_4 = func_inverse_matrix(&A_4);
  ck_assert_int_eq(Result_4.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_4);

  matrix_t Result_5 = func_inverse_matrix(&A_5);
  ck_assert_int_eq(Result_5.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_5);

  matrix_t Result_6 = func_inverse_matrix(&A_6);
  ck_assert_int_eq(Result_6.matrix_type, INCORRECT_MATRIX);
  func_remove_matrix(&Result_6);

  matrix_t Result_7 = func_inverse_matrix(&A_7);
  matrix_t Original_7 = func_create_matrix(3, 3);
  double original_src_7[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  fill_matrix(&Original_7, original_src_7, 9);
  for (int i = 0; i < Result_7.rows; i++) {
    for (int j = 0; j < Result_7.columns; j++)
      ck_assert_double_eq_tol(Result_7.matrix[i][j], Original_7.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_7.rows, Original_7.rows);
  ck_assert_int_eq(Result_7.columns, Original_7.columns);
  ck_assert_int_eq(Result_7.matrix_type, Original_7.matrix_type);
  func_remove_matrix(&Result_7);
  func_remove_matrix(&Original_7);

  matrix_t Result_8 = func_inverse_matrix(&A_8);
  matrix_t Original_8 = func_create_matrix(3, 3);
  double original_src_8[9] = {0.046076,  0.118088,  0.103125,
                              -0.137121, 0.114605,  -0.039112,
                              0.140760,  -0.045847, -0.109632};
  fill_matrix(&Original_8, original_src_8, 9);
  for (int i = 0; i < Result_8.rows; i++) {
    for (int j = 0; j < Result_8.columns; j++)
      ck_assert_double_eq_tol(Result_8.matrix[i][j], Original_8.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_8.rows, Original_8.rows);
  ck_assert_int_eq(Result_8.columns, Original_8.columns);
  ck_assert_int_eq(Result_8.matrix_type, Original_8.matrix_type);
  func_remove_matrix(&Result_8);
  func_remove_matrix(&Original_8);

  matrix_t Result_9 = func_inverse_matrix(&A_9);
  matrix_t Original_9 = func_create_matrix(3, 3);
  double original_src_9[9] = {-0.000011, 0.000126, -0.012675,
                              -0.000155, 0.001116, -0.000106,
                              0.002184,  0.000003, 0.000698};
  fill_matrix(&Original_9, original_src_9, 9);
  for (int i = 0; i < Result_9.rows; i++) {
    for (int j = 0; j < Result_9.columns; j++)
      ck_assert_double_eq_tol(Result_9.matrix[i][j], Original_9.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_9.rows, Original_9.rows);
  ck_assert_int_eq(Result_9.columns, Original_9.columns);
  ck_assert_int_eq(Result_9.matrix_type, Original_9.matrix_type);
  func_remove_matrix(&Result_9);
  func_remove_matrix(&Original_9);

  matrix_t Result_10 = func_inverse_matrix(&A_10);
  matrix_t Original_10 = func_create_matrix(4, 4);
  double original_src_10[16] = {0.10776,   0.109029,  0.038789, 0.046011,
                                0.1045,    0.076287,  0.137723, -0.022832,
                                -0.103594, -0.155671, 0.135623, 0.021078,
                                -0.177657, -0.08446,  0.012068, 0.033352};
  fill_matrix(&Original_10, original_src_10, 16);
  for (int i = 0; i < Result_10.rows; i++) {
    for (int j = 0; j < Result_10.columns; j++)
      ck_assert_double_eq_tol(Result_10.matrix[i][j], Original_10.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_10.rows, Original_10.rows);
  ck_assert_int_eq(Result_10.columns, Original_10.columns);
  ck_assert_int_eq(Result_10.matrix_type, Original_10.matrix_type);
  func_remove_matrix(&Result_10);
  func_remove_matrix(&Original_10);

  matrix_t Result_11 = func_inverse_matrix(&A_11);
  matrix_t Original_11 = func_create_matrix(4, 4);
  double original_src_11[16] = {-0.10776, -0.109029, -0.038789, -0.046011,
                                -0.1045,  -0.076287, -0.137723, 0.022832,
                                0.103594, 0.155671,  -0.135623, -0.021078,
                                0.177657, 0.08446,   -0.012068, -0.033352};
  fill_matrix(&Original_11, original_src_11, 16);
  for (int i = 0; i < Result_11.rows; i++) {
    for (int j = 0; j < Result_11.columns; j++)
      ck_assert_double_eq_tol(Result_11.matrix[i][j], Original_11.matrix[i][j],
                              1e-6);
  }
  ck_assert_int_eq(Result_11.rows, Original_11.rows);
  ck_assert_int_eq(Result_11.columns, Original_11.columns);
  ck_assert_int_eq(Result_11.matrix_type, Original_11.matrix_type);
  func_remove_matrix(&Result_11);
  func_remove_matrix(&Original_11);

  func_remove_matrix(&A_1);
  func_remove_matrix(&A_2);
  func_remove_matrix(&A_3);
  func_remove_matrix(&A_4);
  func_remove_matrix(&A_5);
  func_remove_matrix(&A_6);
  func_remove_matrix(&A_7);
  func_remove_matrix(&A_8);
  func_remove_matrix(&A_9);
  func_remove_matrix(&A_10);
  func_remove_matrix(&A_11);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_matrix_test);
  tcase_add_test(tc1_1, matrix_eq_test);
  tcase_add_test(tc1_1, matrix_sum_test);
  tcase_add_test(tc1_1, matrix_sub_test);
  tcase_add_test(tc1_1, mult_number_test);
  tcase_add_test(tc1_1, matrix_mult_test);
  tcase_add_test(tc1_1, matrix_transpose_test);
  tcase_add_test(tc1_1, matrix_determinant_test);
  tcase_add_test(tc1_1, calc_complements_test);
  tcase_add_test(tc1_1, inverse_matrix_test);

  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
