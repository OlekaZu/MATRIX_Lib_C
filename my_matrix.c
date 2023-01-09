#include "my_matrix.h"

matrix_t func_create_matrix(int rows, int columns) {
  matrix_t Result;
  Result.matrix = NULL;
  Result.rows = rows;
  Result.columns = columns;
  Result.matrix_type = INCORRECT_MATRIX;
  if (rows > 0 && columns > 0) {
    Result.matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
      Result.matrix[i] = (double *)malloc(columns * sizeof(double));
    for (int n = 0; n < rows; n++) {
      for (int m = 0; m < columns; m++) Result.matrix[n][m] = 0.0;
    }
    Result.matrix_type = ZERO_MATRIX;
  } else {
    Result.rows = 0;
    Result.columns = 0;
  }
  return Result;
}

void func_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
  A->matrix_type = INCORRECT_MATRIX;
}

void fill_matrix(matrix_t *A, double *const src, int size) {
  if (size <= A->rows * A->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        A->matrix[i][j] = src[i * A->columns + j];
    }
    check_matrix_type(A);
  } else {
    printf("Error! Your source has more elements that matrix\n");
  }
}

int check_if_matrix_zero(matrix_t A) {
  int check = 0;
  int count_zero = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (A.matrix[i][j] == 0) count_zero++;
    }
  }
  if (count_zero == A.rows * A.columns) check = 1;
  return check;
}

int check_if_matrix_identity(matrix_t A) {
  int check = 0;
  if (A.rows == A.columns) {
    int count_zero = 0;
    int count_identity = 0;
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        if (A.matrix[i][j] == 0) count_zero++;
        if (A.matrix[i][j] == 1 && i == j) count_identity++;
      }
    }
    if (count_identity == A.rows &&
        (count_zero == A.rows * A.rows - count_identity))
      check = 1;
  }
  return check;
}

void check_matrix_type(matrix_t *A) {
  A->matrix_type = CORRECT_MATRIX;
  int check_type_zero = check_if_matrix_zero(*A);
  int check_type_identity = check_if_matrix_identity(*A);
  if (check_type_zero) A->matrix_type = ZERO_MATRIX;
  if (check_type_identity) A->matrix_type = IDENTITY_MATRIX;
}

int func_eq_matrix(matrix_t *A, matrix_t *B) {
  int Result = 0;
  if (A->rows == B->rows && A->columns == B->columns &&
      A->matrix_type == B->matrix_type && A->matrix_type != INCORRECT_MATRIX &&
      A->rows > 0) {
    double tolerance = 1e-7;
    int count_non_equal = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) < tolerance)
          Result = 1;
        else
          count_non_equal++;
      }
    }
    if (count_non_equal) Result = 0;
  }
  return Result;
}

matrix_t func_sum_matrix(matrix_t *A, matrix_t *B) {
  matrix_t Result_sum = func_create_matrix(A->rows, A->columns);
  if (A->rows == B->rows && A->columns == B->columns &&
      A->matrix_type != INCORRECT_MATRIX && A->matrix != NULL &&
      B->matrix != NULL && A->rows > 0 && A->columns > 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        Result_sum.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
    check_matrix_type(&Result_sum);
  } else {
    Result_sum.matrix_type = INCORRECT_MATRIX;
  }
  return Result_sum;
}

matrix_t func_sub_matrix(matrix_t *A, matrix_t *B) {
  matrix_t Result_sub = func_create_matrix(A->rows, A->columns);
  if (A->rows == B->rows && A->columns == B->columns &&
      A->matrix_type != INCORRECT_MATRIX && A->matrix != NULL &&
      B->matrix != NULL && A->rows > 0 && A->columns > 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        Result_sub.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
    check_matrix_type(&Result_sub);
  } else {
    Result_sub.matrix_type = INCORRECT_MATRIX;
  }
  return Result_sub;
}

matrix_t func_mult_number(matrix_t *A, double number) {
  matrix_t Result_mult_number = func_create_matrix(A->rows, A->columns);
  if (A->matrix_type != INCORRECT_MATRIX && A->matrix != NULL && A->rows > 0 &&
      A->columns > 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        Result_mult_number.matrix[i][j] = A->matrix[i][j] * number;
    }
    check_matrix_type(&Result_mult_number);
  } else {
    Result_mult_number.matrix_type = INCORRECT_MATRIX;
  }
  return Result_mult_number;
}

matrix_t func_mult_matrix(matrix_t *A, matrix_t *B) {
  matrix_t Result_mult = func_create_matrix(A->rows, B->columns);
  if (A->matrix_type != INCORRECT_MATRIX &&
      B->matrix_type != INCORRECT_MATRIX && A->columns == B->rows &&
      A->matrix != NULL && B->matrix != NULL && A->rows > 0 && A->columns > 0 &&
      B->rows > 0 && B->columns > 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        double sum_matrix_elements = 0.0;
        for (int k = 0; k < A->columns; k++) {
          double mult_matrix_elements = A->matrix[i][k] * B->matrix[k][j];
          sum_matrix_elements += mult_matrix_elements;
        }
        Result_mult.matrix[i][j] = sum_matrix_elements;
      }
    }
    check_matrix_type(&Result_mult);
  } else {
    Result_mult.matrix_type = INCORRECT_MATRIX;
  }
  return Result_mult;
}

matrix_t func_transpose(matrix_t *A) {
  matrix_t Result_transpose = func_create_matrix(A->columns, A->rows);
  if (A->matrix_type != INCORRECT_MATRIX && A->matrix != NULL && A->rows > 0 &&
      A->columns > 0) {
    for (int i = 0; i < Result_transpose.rows; i++) {
      for (int j = 0; j < Result_transpose.columns; j++)
        Result_transpose.matrix[i][j] = A->matrix[j][i];
    }
    check_matrix_type(&Result_transpose);
  } else {
    Result_transpose.matrix_type = INCORRECT_MATRIX;
  }
  return Result_transpose;
}

double func_determinant(matrix_t *A) {
  double Result = 0;
  if (A->rows == A->columns && A->matrix_type != INCORRECT_MATRIX &&
      A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == 1) {
      Result = A->matrix[0][0];
    } else {
      double sum_of_koef = 0.0;
      for (int k = 0; k < A->rows; k++) {
        matrix_t Tmp_matrix = new_matrix_for_determinant(*A, 0, k);
        double koef_first_line = A->matrix[0][k] * pow(-1, (1 + k + 1)) *
                                 func_determinant(&Tmp_matrix);
        sum_of_koef += koef_first_line;
        func_remove_matrix(&Tmp_matrix);
      }
      Result = sum_of_koef;
    }
  } else {
    Result = NAN;
  }
  return Result;
}

matrix_t new_matrix_for_determinant(matrix_t A, int row_index,
                                    int column_index) {
  int size = A.rows - 1;
  matrix_t Result = func_create_matrix(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j >= column_index && i >= row_index)
        Result.matrix[i][j] = A.matrix[i + 1][j + 1];
      else if (j >= column_index && i < row_index)
        Result.matrix[i][j] = A.matrix[i][j + 1];
      else if (j < column_index && i >= row_index)
        Result.matrix[i][j] = A.matrix[i + 1][j];
      else
        Result.matrix[i][j] = A.matrix[i][j];
    }
  }
  Result.matrix_type = CORRECT_MATRIX;

  return Result;
}

matrix_t func_calc_complements(matrix_t *A) {
  matrix_t Result_complements = func_create_matrix(A->rows, A->columns);
  if (A->rows == A->columns && A->matrix_type != INCORRECT_MATRIX &&
      A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == 1) {
      Result_complements.matrix[0][0] = 1;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t New_matrix = new_matrix_for_determinant(*A, i, j);
          Result_complements.matrix[i][j] =
              pow(-1, (i + 1 + j + 1)) * func_determinant(&New_matrix);
          func_remove_matrix(&New_matrix);
        }
      }
    }
    check_matrix_type(&Result_complements);
  } else {
    Result_complements.matrix_type = INCORRECT_MATRIX;
  }
  return Result_complements;
}

matrix_t func_inverse_matrix(matrix_t *A) {
  matrix_t Result_inverse = {NULL, A->rows, A->columns, CORRECT_MATRIX};
  double det_A = func_determinant(A);
  if (det_A != 0 && isnan(det_A) == 0) {
    matrix_t A_complements = func_calc_complements(A);
    matrix_t A_transpose = func_transpose(&A_complements);
    func_remove_matrix(&A_complements);
    Result_inverse = func_mult_number(&A_transpose, (1 / det_A));
    func_remove_matrix(&A_transpose);
    check_matrix_type(&Result_inverse);
  } else {
    Result_inverse.matrix_type = INCORRECT_MATRIX;
  }
  return Result_inverse;
}
