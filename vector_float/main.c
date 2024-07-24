#include <stdio.h>
#include "vector_float.h"

int main() {
   
    Vec *vec1 = vec_new();
    Vec *vec2 = vec_new();

    // Fill vec1 with some values
    vec_push(vec1, 1);
    vec_push(vec1, 2);
    vec_push(vec1, 3);

    // Fill vec2 with some values
    vec_push(vec2, 4);
    vec_push(vec2, 5);
    vec_push(vec2, 6);

    // Print the vectors
    printf("Vector 1: ");
    vec_print(vec1);

    printf("Vector 2: ");
    vec_print(vec2);

    // Add the vectors
    Vec *result = vec_add(vec1, vec2);

    // Check if the result is not NULL and print the result
    if (result != NULL) {
        printf("Result of addition: ");
        vec_print(result);
        // Free the result vector
        vec_free(result);
    }

    Vec *result1 = vec_scalarmult(3, vec2);

    // Check if the result is not NULL and print the result
    if (result != NULL) {
        printf("Result of scalar mult with 3: ");
        vec_print(result1);
        // Free the result vector
        vec_free(result1);
    }

    Vec *result2 = vec_scalarprod(vec1, vec2);

    // Check if the result is not NULL and print the result
    if (result2 != NULL) {
        printf("Result of scalar prod: ");
        vec_print(result2);
        // Free the result vector
        vec_free(result2);
    }



    // Free the vectors
    vec_free(vec1);
    
    vec_free(vec2);



    
    return 0;
}


