

#include "resizableArray.h"
#include <stdio.h>

int main(void) {
  resizable_array_t *a = newArray(10);
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

  display(a);
  printf("%d\n", *get(a, 2));
  set(a, 2, 10);
  printf("min: %d\n", min(a));
  printf("max: %d\n", max(a));
  printf("avg: %lf\n", avg(a));
  display(a);
  freeArray(a);

  return 0;
}
