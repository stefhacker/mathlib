#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./vector_float.h"

struct Vec {
  float *data;       /* dynamic memory area containing the integers */
  size_t length;   /* how many integers are currently stored in data */
  size_t capacity; /* how many integers can be stored in data */
};



Vec *vec_new(){
  Vec *xs = malloc(sizeof(Vec));
  if(xs == NULL){
    return NULL;
  }
  xs->length = 0;
  xs->capacity = 1;
  xs->data = malloc(xs->capacity * sizeof(float));
  if (xs->data == NULL){
    return NULL;
  }
  return xs;

};


 
void vec_free(Vec *xs){
  
  free(xs->data);
  free(xs);
};


float *vec_at(Vec *xs, size_t i){
  if (i < (xs->length))
  {
    float* s = xs->data + i;
    return s;
  }
  else{
    return NULL;
  }
  
 
 

};


size_t vec_length(Vec *xs){
  return xs->length;
};


size_t vec_capacity(Vec *xs){
  return xs->capacity;
};


bool vec_push(Vec *xs, float x) {
    if (xs->length == xs->capacity) {
        // Allocate more memory if capacity is exhausted
        float *new_data = realloc(xs->data, 2 * xs->capacity * sizeof(float));
        if (new_data == NULL) {
            return false;  // Memory allocation failed
        }
        xs->data = new_data;  // Update xs->data to point to the newly allocated memory
        xs->capacity *= 2;    // Update capacity to reflect the new size
    }

    // Add the new element at xs->length position
    xs->data[xs->length] = x;
    xs->length++;
    return true;
}

/* Remove the last element of vector `xs` if it exists. Otherwise do nothing.
 *
 * If the resulting vector's length is half of its capacity, the vector's
 * capacity is shrunk to its new length to save memory.
 */
void vec_pop(Vec *xs) {
    if (xs->length > 0) {
        xs->length--;
        // Adjust capacity if necessary
        if (xs->length > 0 && xs->length * 2 <= xs->capacity) {
            xs->capacity = xs->length > 1 ? xs->length : 1;
            float *new_data = realloc(xs->data, xs->capacity * sizeof(float));
            if (new_data != NULL) {
                xs->data = new_data;
            }
        }
    }
}

/* Print the address, length, capacity, and elements of `xs`. */
void vec_print(Vec *xs) {
    
    printf("{ ");
    for (size_t i = 0; i < xs->length; i++) {
        printf("%.2f", xs->data[i]);
        if (i < xs->length - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}


/* Returns a pointer to the smallest element in `xs` which has an index greater
 * or equal to `begin` but less than `end`.
 *
 * If the range between `begin` and `end` is invalid or contains no elements,
 * then the NULL-pointer is returned.
 */
float *vec_min_between(Vec *xs, size_t begin, size_t end){
  if (end <= begin || end > xs->length){
    return NULL;
  }
  float *min = xs->data + begin;
  for(int i = begin + 1; i < end; i++){
    
    if(xs->data[i] < *min){
      min = xs->data + i;
    }


  }
  return min;
};

void swap_float(float* x, float *y){
  float tmp = *x;
  *x = *y;
  *y = tmp;

}
/* Sorts the elements of `xs` in increasing order. */
void vec_sort(Vec *xs){
  size_t len = vec_length(xs);
  for ( size_t i = 0; i < len; i++){
    swap_float(vec_min_between(xs,i,len),vec_at(xs, i));
  }
};



Vec *vec_add(Vec *xs1, Vec *xs2){

  if(vec_length(xs1) != vec_length(xs2) ){
    printf("length of vec 1 (%zu) does not align with vec 2 (%zu)\n",xs1->length,xs2->length);
    return NULL;
  }
size_t len = vec_length(xs1);
Vec *addition = vec_new();
for ( size_t i = 0; i < len; i++){
    
    float x = xs1->data[i]+xs2->data[i];
    vec_push(addition, x);

  }
return addition;

};


Vec *vec_scalarmult(float scalar, Vec *xs){

  
size_t len = vec_length(xs);
Vec *scalarmultiplication = vec_new();
for ( size_t i = 0; i < len; i++){
    
    float mult = scalar * xs->data[i];
    vec_push(scalarmultiplication, mult);

  }
return scalarmultiplication;

};

Vec *vec_scalarprod(Vec *xs1, Vec *xs2){

  if(vec_length(xs1) != vec_length(xs2) ){
    printf("length of vec 1 (%zu) does not align with vec 2 (%zu)\n",xs1->length,xs2->length);
    return NULL;
  }
size_t len = vec_length(xs1);
Vec *multiplication= vec_new();
for ( size_t i = 0; i < len; i++){
    
    float x = xs1->data[i] * xs2->data[i];
    vec_push(multiplication, x);

  }
return multiplication;

};
