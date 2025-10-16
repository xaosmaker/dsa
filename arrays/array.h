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

#endif // !ARRAY_H
