#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./matrix_float.h"

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



float *vec_at(Mat *xs, size_t i, size_t j){
  
 
 

};


size_t mat_rows(Mat *xs){
  return xs->rows;
};


size_t mat_cols(Mat *xs){
  return xs->cols;
};

