#include <stdio.h>
#include "matrix_float.h"

int main() {
   Mat *matrix = mat_new(3,3);
   mat_push(matrix, 0, 0, 1.5);
   mat_push(matrix, 1, 0, 2.5);
   mat_push(matrix, 0, 1, 3.5);
   mat_push(matrix, 0, 2, 4.5);
   mat_push(matrix, 1, 1, 6.5);
   mat_push(matrix, 1, 2, 7.5);
   mat_push(matrix, 2, 0, 7.5);
   mat_push(matrix, 2, 1, 7.5);
   mat_push(matrix, 2, 2, 7.5);


   Mat *mat1 = mat_id(3);

   Mat *add = mat_add(matrix, mat1);
   

   if (add != NULL){
      mat_print(add);

   }

   


   mat_print(matrix);
   
   mat_free(add);
   mat_free(mat1);
   mat_free(matrix);
  
}


