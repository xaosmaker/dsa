#ifndef RESIZABLE_ARRAY

#define RESIZABLE_ARRAY
#include <stdlib.h>

typedef struct ResizableArray {
  int capacity;
  int size;
  int *data;

} resizable_array_t;

resizable_array_t *newArray(size_t arraySize);
void *freeArray(resizable_array_t *array);
void push(resizable_array_t *array, int n);
void display(resizable_array_t *a);
int *pop(resizable_array_t *a);
void insert(resizable_array_t *a, int ind, int n);

#endif // !RESIZABLE_ARRAY
