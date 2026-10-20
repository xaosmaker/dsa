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
void insert(Array *arr, int data, int index);
void delete (Array *arr, int index);
int find(Array *arr, int data);
int pop(Array *arr);
int count(Array *arr, int data);
void reverse(Array *arr);
void clear(Array *arr);
Array *slice(Array *arr, int idx_start, int idx_end);

Array *copy(Array *arr);

// check to implement this
void array_display();
void array_append();
void array_insert();
void array_delete();
void array_search();
void array_bsearch();
void array_get();
void array_set();
void array_min();
void array_max();
void array_sum();
void array_avg();
void array_is_sorted();
void array_insert_sorted();
// sort array first negative then positive
void array_sort_neg_pos();
// merge 2 sorted arrays
void array_merge();
// append the second array to the end
void array_concat();
// array union unsorted;
// union is merge 2 arrays with unique elements
void array_union();
void array_union_sorted();
// merge 2 arrays with dublicte elements
void array_intersection();
void array_intersection_sorted();
// check if array a has unique ellements than array b
void array_difference();
void array_difference_sorted();
void array_find_missing();        // (n*(n+1) / 2) - sum(array), where n is the
void array_find_missing_sorted(); // (n*(n+1) / 2) - sum(array), where n is the
                                  // last ellement
                                  // l = start number h= end number n = len
                                  // array and the diff is the index
void array_find_dublicates();
void array_find_dublicates_sorted();
void array_find_pair_sorted();
void array_find_pair();
void array_pop();
void array_count();
void array_reverse();
void array_clear();
void array_slice();
void array_copy();

#endif // !ARRAY_H
