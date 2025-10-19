#include "array.h"

int main(void) {
  //
  struct Array *a = CreateArray(10);

  Display(a);
  printf("size: %d len: %d\n", a->size, a->len);
  insertSorted(a, -1);
  Append(a, 0);
  Append(a, 2);
  Append(a, 3);
  Append(a, 4);
  Append(a, 6);
  Append(a, 5);
  Append(a, 7);
  Insert(a, 2, 1);
  Insert(a, 1, 12);
  Insert(a, 0, -1);
  Insert(a, a->len, 8);
  Insert(a, a->len, 12);
  Display(a);
  printf("size: %d len: %d\n", a->size, a->len);
  printf("delete pos 0 element: %d\n", Delete(a, 0));
  Display(a);
  printf("delete pos 1 element: %d\n", Delete(a, 1));
  Display(a);
  printf("delete pos 22 element: %d\n", Delete(a, 22));
  Display(a);
  Display(a);
  printf("size: %d len: %d\n", a->size, a->len);
  printf("search number 10 index: %d\n", lSearch(a, 10));
  printf("search number 5 index: %d\n", lSearch(a, 5));
  printf("search number 5 index: %d\n", ilSearch(a, 5));
  Display(a);
  printf("binary search number 4 index: %d\n", bSearch(a, 0, a->len, 4));
  printf("binary search number 8 index: %d\n", bSearch(a, 0, a->len, 8));
  printf("binary search number 0 index: %d\n", bSearch(a, 0, a->len, 0));
  printf("recursive binary search number 10 index: %d\n",
         rbSearch(a, 0, a->len, 10));
  printf("recursive binary search number 5 index: %d\n",
         rbSearch(a, 0, a->len, 5));
  // Set(a, 2, 22);
  printf("get  val of array[2] %d\n", Get(a, 2));
  printf("get max val of array %d\n", Max(a));
  printf("get min val of array %d\n", Min(a));
  printf("get sum of array %d\n", Sum(a));
  printf("get avg of array %.2lf\n", Avg(a));
  ReverseArr(a);
  printf("isReverse Sorted: %s\n", isSortedArr(a, true) ? "true" : "false");
  Display(a);
  ReverseArr(a);
  printf("is Sorted: %s\n", isSortedArr(a, false) ? "true" : "false");
  Display(a);
  insertSorted(a, 1);
  Display(a);
  insertSorted(a, 10);
  Display(a);
  insertSorted(a, 9);

  Display(a);

  free(a->A);
  free(a);
  return 0;
}
