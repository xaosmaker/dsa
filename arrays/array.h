#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;
  int size;
  int len;
} ;

struct Array *CreateArray(int size);
void Append(struct Array *a, int n);
void Display(struct Array *a);
void Insert(struct Array *a, int index, int n);
int Delete(struct Array *a, int index);
int lSearch(struct Array *a, int key);
int ilSearch(struct Array *a, int key);
int bSearch(struct Array *a, int low, int high, int key);
int rbSearch(struct Array *a, int low, int high, int key);

#endif // !ARRAY_H
