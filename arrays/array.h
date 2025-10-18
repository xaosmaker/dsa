#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array {
  int *A;
  int size;
  int len;
} ;

struct Array *CreateArray(int size);
void Append(struct Array *a, int val);
void Display(struct Array *a);
void Insert(struct Array *a, int index, int val);
int Delete(struct Array *a, int index);
int lSearch(struct Array *a, int key);
int ilSearch(struct Array *a, int key);
int bSearch(struct Array *a, int low, int high, int key);
int rbSearch(struct Array *a, int low, int high, int key);
void Set(struct Array *a, int index, int val);
int Get(struct Array *a, int index);
int Max(struct Array *a);
int Min(struct Array *a);
int Sum(struct Array *a);
float Avg(struct Array *a);
void ReverseArr(struct Array *a);

void insertSorted(struct Array *a, int val); 
bool isSortedArr(struct Array *a, bool reverse);

#endif // !ARRAY_H
