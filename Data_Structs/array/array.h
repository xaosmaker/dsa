#ifndef ARRAY_H
#define ARRAY_H

struct array {
  int *data;
  int capacity;
  int size;
};

typedef struct array Array;

void *free_array(Array *arr);
Array *create_array(int capacity);
void add(Array *arr, int data);
void print_arr(Array *arr);
int pop(Array *arr);
void clear(Array *arr);
Array *slice(Array *arr, int idx_start, int idx_end);
Array *copy(Array *arr);
int count(Array *arr, int data);
void reverse(Array *arr);

void insert(Array *arr, int data, int index);
int *delete (Array *arr, int index);
void sort(Array *arr, bool reverse);

#endif // !ARRAY_H
