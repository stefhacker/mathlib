#ifndef MATRIX_FLOAT_H
#define MATRIX_FLOAT_H

#include <stdbool.h>
#include <stddef.h>


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




#endif /* MATRIX_FLOAT_H*/
