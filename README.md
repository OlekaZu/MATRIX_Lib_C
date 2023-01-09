# PROJECT_MATRIX_C
The static library helps work with matrices.

The library is developed in **C language** (**C11 standard**) using **gcc** compiler.

_**The Compilation is checked only on MacOS and Linux Ubuntu 20.04.**_

### How to Compile the Library
Use the following Makefile instruction:
```bash
make my_matrix.a 
```

The static library file will be created.

### How to Use the Library
- Include header `my_matrix.h` in your code.
- Inform link editor the name of the library file and the path where it's situated during the linkage.

For example:
```bash
g++ test.c -L . -lmy_matrix -o test
```

### Structure of the Matrix
In this project the matrix has the following structure:
```c
typedef enum {
  CORRECT_MATRIX = 0, // defines a matrix as correct and not identity or null matrix
  INCORRECT_MATRIX = 1, // in case of errors in actions with matrices
  IDENTITY_MATRIX = 2,  // defines a matrix as identity matrix
  ZERO_MATRIX = 3 // defines a matrix as null matrix
} matrix_type_t;

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
  matrix_type_t matrix_type;
} matrix_t;
```
### Basic Operations with matrices
In the library the following operations with matrices are implemented:
- create_matrix (creation), 
- remove_matrix (cleaning and destruction), 
- eq_matrix (comparison), 
- sum_matrix (addition), 
- sub_matrix (subtraction), 
- mult_matrix (multiplication), 
- mult_number (multiplication by number), 
- transpose (transpose), 
- determinant (calculation of determinant), 
- calc_complements (calculation of matrix of algebraic complements), 
- inverse_matrix (finding inverse of the matrix).

### Testing
You can test the library using my unit-tests (file **test.c**). 

The tests are made by using the Check library. Apply the next Makefile instructions for checking tests:
```bash
make test
```

Also you can check unit tests cover by gcov:
```bash
make gcov_report 
```
Or if you don't trust in my tests you can create or add own unit-tests.
