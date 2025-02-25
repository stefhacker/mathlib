#ifndef MATRIX_FLOAT_H
#define MATRIX_FLOAT_H

#include <stdbool.h>
#include <stddef.h>
#include "vector_float.h"



struct Mat;

typedef struct Mat Mat;


Mat *mat_new(size_t rows, size_t cols);

void mat_free(Mat *xs);


float *mat_at(Mat *xs, size_t i, size_t j);


/* note the indices start with 0*/
void mat_push(Mat *xs, size_t i, size_t j, float x);


void mat_print(Mat *xs);

size_t mat_rows(Mat *xs);

size_t mat_cols(Mat *xs);

Mat *mat_zero(size_t n, size_t m);

Mat *mat_id(size_t n);

Mat *mat_add(Mat* x_1, Mat* x_2);

Vec* mat_vec_mult(Mat* mat, Vec* vec);

Mat *mat_mat_mult(Mat* mat1, Mat* mat2);




#endif /* MATRIX_FLOAT_H*/
