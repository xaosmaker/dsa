#include <stddef.h>

static void swap(int *ptr1, int *ptr2) {
  int tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

void bubble_sort(int *arr, size_t size) {
  int swapping = 1;
  while (swapping) {
    swapping = 0;
    for (int i = 0; i < size; i++) {
      if (*(arr + i - 1) > *(arr + i)) {
        swap(arr + i - 1, arr + i);
        swapping = 1;
      }
    }
    size--;
  }
}
