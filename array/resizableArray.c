

#include "resizableArray.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void resizeArray(resizable_array_t *a) {
  if (a->capacity == a->size) {

    int *resizedData = realloc(a->data, 2 * a->capacity * sizeof(int));
    if (!resizedData) {

      printf("fail to resize array");
      exit(1);
    }
    a->data = resizedData;
    resizedData = NULL;
    a->capacity *= 2;
  }
}

static void shiftLeft(resizable_array_t *a, int ind) {

  for (int i = a->size; i > ind; i--) {
    *(a->data + i) = *(a->data + i - 1);
  }
}

resizable_array_t *newArray(size_t arraySize) {

  resizable_array_t *array =
      (resizable_array_t *)malloc(sizeof(resizable_array_t));

  if (!array) {
    return NULL;
  }
  int *data = malloc(arraySize * (sizeof(int)));
  if (!data) {
    return NULL;
  }

  array->data = data;
  array->capacity = arraySize;
  array->size = 0;
  return array;
}

void *freeArray(resizable_array_t *a) {
  free(a->data);
  free(a);
  return NULL;
}

void push(resizable_array_t *array, int n) {
  resizeArray(array);
  *(array->data + array->size++) = n;
}

void display(resizable_array_t *a) {
  printf("[");
  for (int i = 0; i < a->size; i++) {
    printf("%d", *(a->data + i));
    if (i != a->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}
int *pop(resizable_array_t *a) {
  if (a->size != 0) {
    return a->data + --a->size;
  }
  return NULL;
}

void insert(resizable_array_t *a, int ind, int n) {

  if (ind < 0 || ind > a->size) {
    return;
  }

  resizeArray(a);
  shiftLeft(a, ind);

  a->size++;
  *(a->data + ind) = n;
}

int *get(resizable_array_t *a, int ind) {
  if (ind < 0 || ind >= a->size) {
    return NULL;
  }

  return a->data + ind;
}

int max(resizable_array_t *a) {
  int maxVal = INT_MIN;
  for (int i = 0; i < a->size; i++) {
    int val = *(a->data + i);
    if (val > maxVal) {
      maxVal = val;
    }
  }
  return maxVal;
}

int min(resizable_array_t *a) {
  int minVal = INT_MAX;
  for (int i = 0; i < a->size; i++) {
    int val = *(a->data + i);
    if (val < minVal) {
      minVal = val;
    }
  }
  return minVal;
}
double avg(resizable_array_t *a) {
  double sum = 0.0;
  for (int i = 0; i < a->size; i++) {
    sum += *(a->data + i);
  }
  double av = sum / a->size;
  return av;
}

void set(resizable_array_t *a, int ind, int n) {
  if (ind < 0 || ind >= a->size) {
    return;
  }
  *(a->data + ind) = n;
}
