

#include <stdio.h>
#include <stdlib.h>
int *new2DArray(int rows, int columns) {
  int *array = (int *)malloc((rows * columns) * sizeof(int));
  if (!array) {
    exit(1);
  }
  return array;
}

void acc2DA(int *a, int row, int col, int colLen) {

  printf("%d\n", *(a + row * colLen + col));
}

int main(void) {
  int rows = 3, cols = 4;

  int *arr = new2DArray(rows, cols);

  for (int i = 0; i < rows * cols; i++) {
    *(arr + i) = i + 1;
  }
  for (int i = 0; i < rows * cols; i++) {
    printf("%d\n", *(arr + i));
  }
  printf("\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      acc2DA(arr, i, j, cols);
    }
  }

  free(arr);
  return 0;
}
