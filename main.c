#include <stdio.h>
#include "matrix_float.h"
#include "vector_float.h"



int main() {
    size_t n = 3;
    Mat* mat = mat_new(n, n);
    Mat* vec = mat_new(3,1);
    mat_push(vec, 0, 0, 1);
    mat_push(vec, 1 ,0, 2);
    mat_push(vec, 2, 0 ,3);


    // Initialize the matrix using mat_push
    mat_push(mat, 0, 0, 4.0); mat_push(mat, 0, 1, 1.0); mat_push(mat, 0, 2, -2.0);
    mat_push(mat, 1, 0, 1.0); mat_push(mat, 1, 1, 2.0); mat_push(mat, 1, 2, 0.0);
    mat_push(mat, 2, 0, -2.0); mat_push(mat, 2, 1, 0.0); mat_push(mat, 2, 2, 3.0);

    
    
    mat_print(mat);
    
    mat_print(vec);
    
    Mat* add = mat_mat_mult(mat,vec);
    if (add != NULL){
        mat_print(add);
    }

    mat_free(mat);
    mat_free(vec);
    mat_free(add);

    return 0;
}
