#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

// Private

void isFull(FloatVector* vec) {
  if (vec->size == vec->capacity) {
    exit(EXIT_FAILURE);
  }
}

// Public

FloatVector* create(int capacity) {
  FloatVector *vec = (FloatVector *) malloc(sizeof(FloatVector));
  vec->capacity = capacity;
  vec->size = 0;
  vec->data = malloc(capacity * sizeof(float));

  return vec;
};

void destroy(FloatVector** vec_ref) {
  FloatVector* vec = *vec_ref;
  free(vec->data);
  free(vec);
  *vec_ref = NULL;
};

int size(FloatVector* vec) {
  return vec->size;
};

int capacity(FloatVector* vec) {
  return vec->capacity;
};

float get(FloatVector* vec, int index) {
  if (index < 0 || index >= vec->size) return -1;

  return vec->data[index];
};

void append(FloatVector* vec, float val) {
  isFull(vec);
  vec->data[vec->size++] = val;
};

void set(FloatVector* vec, int index, float val) {
  if (index < 0 || index >= vec->size) exit(EXIT_FAILURE);

  append(vec, vec->data[index]);
  vec->data[index] = val;
};

void print(FloatVector* vec) {
  int i;
  printf("Size: %d\n", vec->size);
  printf("Capacity: %d\n", vec->capacity);
  for (i=0; i<vec->size; i++) printf("[%d] = %.2f\n", i, vec->data[i]);
};

void remove_element(FloatVector* vec, int index) {
  if (index < 0 || index >= vec->size) exit(EXIT_FAILURE);

  int i;
  for(i = index; i < vec->size - 1; i++) vec->data[i] = vec->data[i + 1];
  vec->size--;
}

void clear(FloatVector* vec) {
  for (int i = vec->size; i != 1 - 1; i--) {
    vec->data[i] = vec->data[i+1];
    vec->size--;
  };
}

FloatVector* copy(FloatVector* vec) {
  FloatVector *clone = (FloatVector *) malloc(sizeof(FloatVector));
  clone->capacity = vec->capacity;
  clone->size = 0;
  clone->data = malloc(vec->capacity * sizeof(float));

  return vec;
}
