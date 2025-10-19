#include "matrix.h"
#include <stdbool.h>

matrix_t matrix_create(int rows, int cols) { 
  /* TODO */
  double* elts = calloc(rows*cols, sizeof(double));
  matrix_t m = {rows, cols, elts};
  return m;
}

double matrix_get(matrix_t m, int r, int c) { 
  /* TODO */
  assert(r < m.rows && c < m.cols);

  return m.elts[r*m.cols+c];
}

void matrix_set(matrix_t m, int r, int c, double d) { 
  assert(r < m.rows && c < m.cols);
  m.elts[r*m.cols+c] = d;

  /* TODO */
}


void matrix_free(matrix_t m) { 
  /* TODO */
  free(m.elts);
}

matrix_t matrix_multiply(matrix_t m1, matrix_t m2) { 
  /* TODO */
  double* elts = calloc(m1.rows * m2.cols, sizeof(double));
  int temp_val = 0;
  for (int row = 0; row < m1.rows; row++){
    for (int col = 0; col < m2.cols; col++){
      temp_val = 0;
      for (int k = 0; k < m1.cols; k ++){
        temp_val += m1.elts[row * m1.cols + k] * m2.elts[k * m2.cols + col];
      }
      elts[row * m2.cols + col] = temp_val;
    }
  }

  matrix_t m = {m1.rows, m2.cols, elts};
  return m;
}

matrix_t matrix_transpose(matrix_t m) { 
  double* elts = calloc(m.rows * m.cols, sizeof(double));

  for (int row = 0; row < m.rows; row++){
    for (int col = 0; col < m.cols; col++){
      elts[col * m.rows + row] = m.elts[row * m.cols + col];
    }
  }

  /* TODO */
  matrix_t t = {m.cols, m.rows, elts}; 
  return t;
}

matrix_t matrix_multiply_transposed(matrix_t m1, matrix_t m2) { 
  assert(m1.cols == m2.cols);
  /* TODO */

  double* elts = calloc(m1.rows * m2.rows, sizeof(double));
  double temp_val = 0.0;
  for (int row = 0; row < m1.rows; row++){
    for (int col = 0; col < m2.rows; col++){
      temp_val = 0.0;
      for (int k = 0; k < m1.cols; k ++){
        temp_val += m1.elts[row * m1.cols + k] * m2.elts[col * m2.cols + k];
      }
      elts[row * m2.rows + col] = temp_val;
    }
  }

  matrix_t m = {m1.rows, m2.rows, elts};

  return m;
}

matrix_t matrix_multiply_fast(matrix_t m1, matrix_t m2) { 
  matrix_t m2_T = matrix_transpose(m2);

  /* TODO */
  matrix_t result = matrix_multiply_transposed(m1,m2_T);
  matrix_free(m2_T);
  return result;
}

void matrix_print(matrix_t m) { 
  for (int i = 0; i < m.rows; i++) { 
    for (int j = 0; j < m.cols; j++) { 
      printf("%g\t", matrix_get(m, i, j));
    }
    printf("\n");
  }
  printf("\n");
}


