#include <stdio.h>
#include "matrix_float.h"

int main() {
   Mat *matrix = mat_new(2,3);
   mat_push(matrix, 0, 0, 1.5);
   mat_push(matrix, 1, 0, 2.5);
   mat_push(matrix, 0, 1, 3.5);
   mat_push(matrix, 0, 2, 4.5);
   mat_push(matrix, 1, 1, 6.5);
   mat_push(matrix, 1, 2, 7.5);


   float *x = mat_at(matrix, 0,3);

   float *y = mat_at(matrix, 1,2);

   if (y != NULL){

      printf("%2.2f \n", *y);
   }
  

   mat_print(matrix);
   

   mat_free(matrix);
  
}


