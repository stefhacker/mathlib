#include <stdio.h>
#include "matrix_float/matrix_float.h"
#include "vector_float/vector_float.h"



int main() {
    size_t n = 3;
    Mat* mat = mat_new(n, n);
    Vec* vec = vec_new();
    vec_push(vec,1);
    vec_push(vec,2);
    vec_push(vec,3);


    // Initialize the matrix using mat_push
    mat_push(mat, 0, 0, 4.0); mat_push(mat, 0, 1, 1.0); mat_push(mat, 0, 2, -2.0);
    mat_push(mat, 1, 0, 1.0); mat_push(mat, 1, 1, 2.0); mat_push(mat, 1, 2, 0.0);
    mat_push(mat, 2, 0, -2.0); mat_push(mat, 2, 1, 0.0); mat_push(mat, 2, 2, 3.0);

    
    
    mat_print(mat);
    
    vec_print(vec);
    
    Vec* add = mat_vec_mult(mat,vec);
    if (add != NULL){
        vec_print(add);
    }

    mat_free(mat);
    vec_free(vec);
    vec_free(add);

    return 0;
}
