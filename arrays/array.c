#include "array.h"
#include <math.h>

void ReallocArray(struct Array *a) {
  if (a->len >= a->size - 1) {
    int *newArr = (int *)realloc(a->A, (a->size * 2) * sizeof(int));
    if (newArr == NULL) {
      printf("fail to reallocate memory for array");
      free(a->A);
      free(a);
      exit(1);
    }

    a->A = newArr;
    a->size = a->size * 2;
    newArr = NULL;
  }
}

void swap(int *n, int *n2) {
  int temp = *n;
  *n = *n2;
  *n2 = temp;
}

struct Array *CreateArray(int size) {

  struct Array *p = (struct Array *)malloc(sizeof(struct Array));

  if (p == NULL) {
    printf("cannot allocate memory for struct array");
    exit(1);
  }
  p->A = (int *)malloc(sizeof(int) * size);

  if (p->A == NULL) {
    printf("cannot allocate memory for array");
    exit(1);
  }
  p->size = size;
  p->len = 0;
  return p;
}

void Append(struct Array *a, int val) {
  ReallocArray(a);

  a->A[a->len] = val;
  a->len++;
}

void Display(struct Array *a) {
  printf("[");
  for (int i = 0; i < a->len; i++) {
    printf("%d", a->A[i]);
    if (i < a->len - 1) {
      printf(",");
    }
  }
  printf("]\n");
}

void Insert(struct Array *a, int index, int val) {
  if (index >= 0 && index <= a->len) {

    ReallocArray(a);
    for (int i = a->len; i > index; i--) {
      a->A[i] = a->A[i - 1];
    }
    a->A[index] = val;
    a->len++;
  }
}
int Delete(struct Array *a, int index) {
  if (index >= 0 && index < a->len) {
    int val = a->A[index];
    for (; index < a->len - 1; index++) {
      a->A[index] = a->A[index + 1];
    }
    a->len--;
    return val;
  }
  return NAN;
}

int lSearch(struct Array *a, int key) {
  for (int i = 0; i < a->len; i++) {
    if (a->A[i] == key) {
      return i;
    }
  }

  return -1;
}

int ilSearch(struct Array *a, int key) {

  for (int i = 0; i < a->len; i++) {
    if (a->A[i] == key) {
      if (i == 0) {

        return i;
      } else {
        swap(&a->A[i], &(a->A[i - 1]));
        return i - 1;
      }
    }
  }

  return -1;
}

int bSearch(struct Array *a, int low, int high, int key) {

  while (low <= high) {

    int mid = (low + high) / 2;
    if (a->A[mid] == key) {
      return mid;
    } else if (key > a->A[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int rbSearch(struct Array *a, int low, int high, int key) {

  if (low <= high) {

    int mid = (low + high) / 2;
    if (a->A[mid] == key) {
      return mid;
    } else if (key > a->A[mid]) {
      return rbSearch(a, mid + 1, high, key);
    } else {
      return rbSearch(a, low, mid - 1, key);
    }
  }
  return -1;
}

int Get(struct Array *a, int index) {
  if (index >= 0 && index < a->len) {
    return a->A[index];
  }
  return NAN;
}

void Set(struct Array *a, int index, int val) {
  if (index >= 0 && index < a->len) {
    a->A[index] = val;
  }
}
int Max(struct Array *a) {
  int max = a->A[0];

  for (int i = 1; i < a->len; i++) {
    if (a->A[i] > max) {
      max = a->A[i];
    }
  }
  return max;
}

int Min(struct Array *a) {

  int min = a->A[0];
  for (int i = 1; i < a->len; i++) {
    if (a->A[i] < min) {
      min = a->A[i];
    }
  }
  return min;
}

int Sum(struct Array *a) {
  int sum = 0;

  for (int i = 0; i < a->len; i++) {
    sum += i;
  }
  return sum;
}

float Avg(struct Array *a) {
  float sum = Sum(a);
  return sum / a->len;
}
void ReverseArr(struct Array *a) {

  for (int i = 0, j = a->len - 1; i < j; i++, j--)
    swap(&a->A[i], &a->A[j]);
}

void insertSorted(struct Array *a, int val) {
  ReallocArray(a);

  int i = 0;
  for (; i < a->len; i++) {
    if (a->A[i] > val) {
      break;
    }
  }
  for (int j = a->len; j > i; j--) {
    swap(&a->A[j], &a->A[j - 1]);
  }
  a->A[i] = val;
  a->len++;
}
bool isSortedArr(struct Array *a, bool reverse) {

  for (int i = 0; i < a->len - 1; i++) {
    if (reverse) {
      if (a->A[i] < a->A[i + 1]) {
        return false;
      }
    } else {

      if (a->A[i] > a->A[i + 1]) {
        return false;
      }
    }
  }
  return true;
}
