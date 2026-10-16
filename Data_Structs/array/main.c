#include "array.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
  //
  int ar_capacity = 5;
  Array *t = create_array(ar_capacity);
  assert(t != NULL &&
         "test create array should return a pointer of struct array");
  assert(t->size == 0 && "test array size should be 0 on initialization");
  assert(t->capacity == ar_capacity &&
         "test array capacity should be the value");
  t = free_array(t);
  assert(t == NULL && "test free_array should succeed");
  t = create_array(5);
  add(t, 10);
  add(t, 5);
  assert(t->size == 2 && "arr size should be 2");
  clear(t);
  assert(t->size == 0 && "arr size should be 0");
  free_array(t);
  t = create_array(1);
  add(t, 5);
  assert(t->size == 1 && "arr size should be 1");
  assert(t->capacity == 1 && "test arr capacity should be 1");
  add(t, 10);
  assert(t->capacity == 2 && "test arr capacity should be 2");
  assert(t->size == 2 && "arr size should be 2");
  add(t, 15);
  assert(t->capacity == 4 && "test arr capacity should be 4");
  assert(t->size == 3 && "arr size should be 3");
  assert(pop(t) == 15 && "Pop last element should succeed");
  assert(pop(t) == 10 && "Pop last element should succeed");
  assert(pop(t) == 5 && "Pop last element should succeed");
  assert(pop(t) == INT_MIN && "Pop last element should succeed");
  add(t, 5);
  add(t, 10);
  add(t, 15);
  add(t, 10);
  assert(count(t, 10) == 2 && "test count should succeed");
  assert(count(t, 20) == 0 && "test count should succeed");
  Array *x = NULL;
  x = copy(t);
  assert(x->capacity == t->capacity && "test copy array capacity should match");
  assert(x->size == t->size && "test copy array size should match");
  assert(x->data[0] == t->data[0] && "test copy array data[0] should match");
  assert(x->data[3] == t->data[3] && "test copy array data[3] should match");
  free_array(x);
  x = slice(t, 1, 3);
  assert(x->capacity == 2 && "test slice array capacity should match");
  assert(x->size == 2 && "test slice array size should match");
  assert(x->data[0] == t->data[1] && "test slice array data[0] should match");
  assert(x->data[1] == t->data[2] && "test slice array data[3] should match");
  free_array(x);
  x = slice(t, 0, 3);
  assert(x->capacity == 3 && "test slice array capacity should match");
  assert(x->size == 3 && "test slice array size should match");
  assert(x->data[0] == t->data[0] && "test slice array data should match");
  assert(x->data[1] == t->data[1] && "test slice array data should match");
  assert(x->data[2] == t->data[2] && "test slice array data should match");
  free_array(x);
  assert(slice(t, -1, 3) == NULL &&
         "test slice array with negative start should fail");
  assert(slice(t, 1, 5) == NULL &&
         "test slice array with bigger end should fail");
  assert(slice(t, 1, -1) == NULL &&
         "test slice array with negative end should fail");
  assert(slice(t, 1, 1) == NULL && "test slice array with 0 copy should fail");

  print_arr(t);
  reverse(t);
  print_arr(t);
  assert(t->data[0] == 10 && "test reverse array should succed");
  assert(t->data[1] == 15 && "test reverse array should succed");
  assert(t->data[2] == 10 && "test reverse array should succed");
  assert(t->data[3] == 5 && "test reverse array should succed");
  print_arr(t);
  insert(t, 3, 0);
  insert(t, 4, 4);
  insert(t, 6, 6);
  delete(t, 6);
  delete(t, 4);
  delete(t, 0);
  print_arr(t);

  free_array(t);

  return 0;
}
