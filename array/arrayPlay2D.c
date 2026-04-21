/*
 * i know im not consistent here and
 * i access the array vs [] or with pointer arithmetics
 * but its for purpose of learnign myself
 * not teaching to anyone
 * */

#include <stdio.h>
#include <stdlib.h>

void arr2d() {

  // work as expected one continues block of memory
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 9; i++) {
    printf("arr: %d\n", *(int *)(*arr + i));
  }
}

void array2dStackHeap() {

  int *arr2[3] = {};
  // alocate memory
  for (int i = 0; i < 3; i++) {
    arr2[i] = malloc(3 * sizeof(int));
  }

  // initialize array
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      arr2[i][j] = 3 * i + j + 1;
    }
  }

  // print array data
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("arr2: %d\n", arr2[i][j]);
    }
  }

  // wont work memory allocated on diff places
  // for (int i = 0; i < 9; i++) {
  //   printf("arr2: %d\n", *(int *)(*arr2 + i));
  // }

  // free memory
  for (int i = 0; i < 3; i++) {
    free(arr2[i]);
  }
}

void array2dHeap2Allocations() {

  int **arr3;
  arr3 = (int **)malloc(3 * sizeof(int *));
  for (int i = 0; i < 3; i++) {
    arr3[i] = (int *)malloc(3 * sizeof(int));
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      arr3[i][j] = 3 * i + j + 1;
    }
  }

  // print array data
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("arr3: %d\n", arr3[i][j]);
    }
  }

  // wont work memory allocated on heap but the address is diffrent
  // for (int i = 0; i < 9; i++) {
  //   printf("arr2: %d\n", *(int *)(*arr3 + i));
  // }

  for (int i = 0; i < 3; i++) {
    free(arr3[i]);
  }
  free(arr3);
}

void array2dHeap1allocation(int rows, int columns) {

  int *arr4;
  arr4 = malloc((rows * columns) * sizeof(int));

  for (int i = 0; i < (rows * columns); i++) {

    arr4[i] = i + 1;
  }

  for (int i = 0; i < (rows * columns); i++) {
    printf("arr4: %d\n", *(int *)(arr4 + i));
  }

  printf("\n");
  // this wont work with the normal syntax arr4[i][j]
  //  this wont work because we have to specify the formula for this
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("arr4Nested: %d\n", *(arr4 + (columns * i + j)));
    }
  }
  free(arr4);
}
int main(void) {

  arr2d();
  printf("\n");
  array2dStackHeap();

  printf("\n");
  array2dHeap2Allocations();
  printf("\n");
  array2dHeap1allocation(3, 4);

  return 0;
}
