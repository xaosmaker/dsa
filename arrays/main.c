#include "array.h"

int main(void) {
  //
  struct Array *a = CreateArray(10);

  Display(a);
  printf("size: %d len: %d\n", a->size, a->len);
  Append(a, 0);
  Append(a, 2);
  Append(a, 3);
  Append(a, 4);
  Append(a, 5);
  Append(a, 6);
  Append(a, 7);
  Insert(a, 1, 1);
  Insert(a, 1, 12);
  Insert(a, 0, -1);
  Insert(a, a->len, 8);
  Display(a);
  printf("size: %d len: %d\n", a->size, a->len);
  printf("%d\n", Delete(a, 0));
  printf("%d\n", Delete(a, 1));
  printf("%d\n", Delete(a, 22));
  Display(a);
  printf("size: %d len: %d\n", a->size, a->len);

  free(a->A);
  free(a);
  return 0;
}
