#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_float.h"


struct Mat {
  float *data;       /* dynamic memory area containing the integers */
  size_t rows;   /* how many integers are currently stored in data */
  size_t cols; /* how many integers can be stored in data */
};



Mat *mat_new(size_t n, size_t m){
   
  Mat *xs = malloc(sizeof(Mat));
  if (!xs) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  xs->data = malloc(n * m * sizeof(float));
  if (!xs->data) {
    free(xs);
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  xs->rows = n;
  xs->cols = m;
  return xs;
  };


 
void mat_free(Mat *xs){
  
  free(xs->data);
  free(xs);
}

void mat_push(Mat *xs, size_t i, size_t j, float x){
  if(i >= xs->rows){
    printf("row index is out of range");
    return;
  }
  if(j >= xs->cols){
    printf("column index is out of range");
    return;
  }
  xs->data[xs->cols * i + j] = x;

}

void mat_print(Mat *xs){
  printf("{");
  for (size_t i = 0; i < xs->rows; ++i) {
    printf("{");
    for (size_t j = 0; j < xs->cols; ++j) {
      printf("%.2f", xs->data[i * xs->cols + j]);
      if (j < xs->cols - 1) {
        printf(", ");
      }
    }
    printf(" }");
    if (i < xs->rows - 1) {
      printf(",\n");
    }
  }
  printf("}\n");
}


float* mat_at(Mat* xs, size_t i, size_t j) {
    if (i >= xs->rows || j >= xs->cols) {
        printf("Indices are out of range\n");
        return NULL;
    }

    float* result = &(xs->data[i * xs->cols + j]);
    return result ;
}



size_t mat_rows(Mat *xs){
  return xs->rows;
}


size_t mat_cols(Mat *xs){
  return xs->cols;
}

Mat *mat_zero(size_t n, size_t m){
  
  Mat* zero = mat_new(n, m);
  for(int i = 0; i < n; i++){
    for(int j; j < m; j++){
      mat_push(zero, i,j, 0);
    }

  }
  return zero;

}

Mat *mat_id(size_t n){
  
  Mat* identity = mat_zero(n, n);
  for(int i = 0; i < n; i++){
    
    mat_push(identity, i ,i ,1);
  }
  return identity;

}

Mat *mat_add(Mat* x_1, Mat* x_2){
  if(mat_cols(x_1) != mat_cols(x_2)){
    printf("columns do not align");
    return NULL;
  }

   if(mat_rows(x_1) != mat_rows(x_2)){
    printf("rows do not align");
    return NULL;
  }


  Mat* add = mat_new(mat_rows(x_1), mat_cols(x_1));
  for(int i = 0; i < mat_rows(x_1); i++){
    for(int j = 0; j < mat_cols(x_1); j++){
      mat_push(add, i,j, x_1->data[i * x_1->cols + j] + x_2->data[i * x_1->cols + j] );
    }

  }
  return add;

}

Vec *mat_vec_mult(Mat* mat, Vec* vec){

  if(mat_cols(mat) != vec_length(vec)){
    printf("dimensions do not align");
  }
  Vec* result = vec_new();
   for (size_t i = 0; i < mat_rows(mat); i++) {
        float component = 0;
        for (size_t j = 0; j < mat_cols(mat); j++) {
             component += *mat_at(mat, i, j) * *vec_at(vec, j);
        }
        vec_push(result, component);
    }
    return result;

}

Mat *mat_vec_mult(Mat* mat, Mat* vec)

