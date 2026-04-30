#ifndef RESIZABLE_ARRAY

#define RESIZABLE_ARRAY
#include <stdlib.h>

typedef struct ResizableArray {
  int capacity;
  int size;
  int *data;

} array_t;

array_t *newArray(size_t arraySize);
void *freeArray(array_t *array);
void push(array_t *array, int n);
void display(array_t *a);
int *pop(array_t *a);
void insert(array_t *a, int ind, int n);
int *get(array_t *a, int ind);
void set(array_t *a, int ind, int n);
double avg(array_t *a);
int max(array_t *a);
int min(array_t *a);
void deleteInd(array_t *a, int ind);
void deleteItem(array_t *a, int item);
void reverseArray(array_t *a);
int linearSearch(array_t *a, int item);
int binarySearch(array_t *a, int item);

#endif // !RESIZABLE_ARRAY
