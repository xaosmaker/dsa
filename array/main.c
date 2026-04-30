

#include "resizableArray.h"
#include <stdio.h>

int main(void) {
  array_t *a = newArray(1);
  display(a);
  push(a, 5);
  display(a);
  int *f = pop(a);
  if (f) {
    printf("pop Last %d\n", *f);
  }
  int *r = pop(a);
  if (r) {
    printf("pop Last %d\n", *r);
  }

  push(a, 1);
  push(a, 2);
  push(a, 4);
  push(a, 5);
  insert(a, 2, 3);

  insert(a, 0, 0);
  insert(a, 6, 6);
  insert(a, 7, 7);
  insert(a, 8, 8);

  display(a);
  printf("%d\n", *get(a, 2));
  set(a, 2, 10);
  printf("min: %d\n", min(a));
  printf("max: %d\n", max(a));
  printf("avg: %lf\n", avg(a));
  printf("size %d,capacity %d\n", a->size, a->capacity);
  deleteInd(a, 2);
  deleteItem(a, 25);
  deleteItem(a, 2);
  display(a);
  reverseArray(a);
  display(a);
  reverseArray(a);
  display(a);
  printf("linSearch 7: %d\n", linearSearch(a, 7));
  printf("linSearch 25: %d\n", linearSearch(a, 25));

  printf("binSearch 7: %d\n", binarySearch(a, 7));
  printf("binSearch 25: %d\n", binarySearch(a, 25));
  printf("binSearch 1: %d\n", binarySearch(a, 1));
  printf("binSearch 2: %d\n", binarySearch(a, 2));
  printf("size %d,capacity %d\n", a->size, a->capacity);
  freeArray(a);

  return 0;
}
