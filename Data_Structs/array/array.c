#include "array.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool grow_array(Array *arr) {
  int tmp_capacity = arr->capacity << 1;
  int *tmp_data =
      realloc((void *)arr->data, sizeof(int) * (size_t)tmp_capacity);
  if (!tmp_data) {
    return false;
  }
  arr->data = tmp_data;
  arr->capacity = tmp_capacity;

  return true;
}
static void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

Array *create_array(int capacity) {
  if (capacity <= 0) {
    assert(capacity > 0 && "array capacity should be greater 0");
  }
  Array *array = malloc(sizeof(Array));
  if (!array) {
    return NULL;
  }
  int *data = (int *)malloc(sizeof(int) * (size_t)capacity);
  if (!data) {
    free(array);
    return NULL;
  }
  array->data = data;
  array->capacity = capacity;
  array->size = 0;
  return array;
}
void *free_array(Array *arr) {
  free(arr->data);
  free(arr);
  return NULL;
}

void add(Array *arr, int data) {
  if (arr->capacity == arr->size) {
    if (!grow_array(arr)) {
      perror("Add");
      return;
    }
  }
  arr->data[arr->size++] = data;
}

void clear(Array *arr) { arr->size = 0; }
void print_arr(Array *arr) {
  printf("[");
  for (int i = 0; i < arr->size; i++) {
    printf("%d", arr->data[i]);
    if (i + 1 != arr->size) {
      printf(", ");
    }
  }
  printf("]\n");
}

int pop(Array *arr) {
  if (arr->size <= 0) {
    return INT_MIN;
  }
  return arr->data[--(arr->size)];
}

int count(Array *arr, int data) {
  int found = 0;
  for (int i = 0; i < arr->size; i++) {
    if (arr->data[i] == data) {
      found++;
    }
  }
  return found;
}

Array *copy(Array *arr) {
  int *data = (int *)malloc(sizeof(int) * (size_t)arr->capacity);
  if (!data) {
    return NULL;
  }
  Array *new_arr = (Array *)malloc(sizeof(Array));
  if (!new_arr) {
    free(data);
    return NULL;
  }

  memcpy((void *)data, (void *)arr->data, sizeof(int) * (size_t)arr->capacity);

  new_arr->capacity = arr->capacity;
  new_arr->size = arr->size;
  new_arr->data = data;

  return new_arr;
}
Array *slice(Array *arr, int idx_start, int idx_end) {
  int size = idx_end - idx_start;
  // check if idx < 0 negative position
  // if idx_end > array size
  // and if the difference of the array is  <= 0
  // idx_end < 0 i don't add this because then we have size < 0
  if (idx_start < 0 || idx_end > arr->size || size <= 0) {
    return NULL;
  }

  Array *new_arr = (Array *)malloc(sizeof(Array));
  if (!new_arr) {
    return NULL;
  }

  int *data = (int *)malloc(sizeof(int) * (size_t)size);
  if (!data) {
    free(new_arr);
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    data[i] = arr->data[i + idx_start];
  }

  new_arr->capacity = size;
  new_arr->size = size;
  new_arr->data = data;
  return new_arr;
}

void reverse(Array *arr) {
  int i = 0, j = arr->size - 1;
  while (i < j) {
    swap(&arr->data[i++], &arr->data[j--]);
  }
}

// test from here
void insert(Array *arr, int data, int index);
int *delete(Array *arr, int index);
void sort(Array *arr, bool reverse);
