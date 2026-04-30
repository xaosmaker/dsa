

#include "resizableArray.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static void resizeArray(array_t *a) {
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

static void shiftLeft(array_t *a, int ind) {

  for (int i = a->size; i > ind; i--) {
    *(a->data + i) = *(a->data + i - 1);
  }
}

array_t *newArray(size_t arraySize) {

  array_t *array = (array_t *)malloc(sizeof(array_t));

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

void *freeArray(array_t *a) {
  free(a->data);
  free(a);
  return NULL;
}

void push(array_t *array, int n) {
  resizeArray(array);
  *(array->data + array->size++) = n;
}

void display(array_t *a) {
  printf("[");
  for (int i = 0; i < a->size; i++) {
    printf("%d", *(a->data + i));
    if (i != a->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}
int *pop(array_t *a) {
  if (a->size != 0) {
    return a->data + --a->size;
  }
  return NULL;
}

void insert(array_t *a, int ind, int n) {

  if (ind < 0 || ind > a->size) {
    return;
  }

  resizeArray(a);
  shiftLeft(a, ind);

  a->size++;
  *(a->data + ind) = n;
}

int *get(array_t *a, int ind) {
  if (ind < 0 || ind >= a->size) {
    return NULL;
  }

  return a->data + ind;
}

int max(array_t *a) {
  int maxVal = INT_MIN;
  for (int i = 0; i < a->size; i++) {
    int val = *(a->data + i);
    if (val > maxVal) {
      maxVal = val;
    }
  }
  return maxVal;
}

int min(array_t *a) {
  int minVal = INT_MAX;
  for (int i = 0; i < a->size; i++) {
    int val = *(a->data + i);
    if (val < minVal) {
      minVal = val;
    }
  }
  return minVal;
}
double avg(array_t *a) {
  double sum = 0.0;
  for (int i = 0; i < a->size; i++) {
    sum += *(a->data + i);
  }
  double av = sum / a->size;
  return av;
}

void deleteInd(array_t *a, int ind) {
  if (ind < 0 || ind >= a->size) {
    return;
  }

  for (; ind <= a->size; ind++) {
    *(a->data + ind) = *(a->data + ind + 1);
  }
  a->size--;
}

void deleteItem(array_t *a, int item) {

  int ind = INT_MIN;
  for (int i = 0; i < a->size; i++) {
    if (*(a->data + i) == item) {
      ind = i;
      break;
    }
  }

  if (ind == INT_MIN) {
    return;
  }

  for (; ind <= a->size; ind++) {
    *(a->data + ind) = *(a->data + ind + 1);
  }
}

void reverseArray(array_t *a) {
  //
  int i = 0, j = a->size - 1;
  while (i < j) {
    swap(a->data + i++, a->data + j--);
  }
}
int linearSearch(array_t *a, int item) {
  for (int i = 0; i < a->size; i++) {
    if (*(a->data + i) == item) {
      return i;
    }
  }
  return -1;
}

static int binSearch(int *data, int start, int finish, int item) {

  // sleep(1);
  // printf("binSearh( start %d,finish %d, item %d)\n", start, finish, item);

  if (start > finish) {
    return -1;
  }
  int mid = (finish + start) / 2;
  // printf("mid %d\n", mid);
  if (*(data + mid) == item) {
    return mid;
  }

  if ((*(data + mid)) < item) {
    return binSearch(data, mid + 1, finish, item);
  }
  return binSearch(data, start, mid - 1, item);
}

int binarySearch(array_t *a, int item) {
  return binSearch(a->data, 0, a->size - 1, item);
}

void set(array_t *a, int ind, int n) {
  if (ind < 0 || ind >= a->size) {
    return;
  }
  *(a->data + ind) = n;
}
