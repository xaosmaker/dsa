
#include "btree.h"
#include <stdio.h>

int main(void)

{
  struct btree *t;

  printf("insert: %d\n", btree_insert(&t, 5)->val);
  printf("insert: %d\n", btree_insert(&t->left, 15)->val);
  printf("insert: %d\n", btree_insert(&t->right, 10)->val);
  btree_preorder(t);

  btree_destroy(&t);
  printf("\nemptying tree\n");
  btree_preorder(t);
  printf("\nempty tree\n\n");

  printf("insert sorted: %p, %d\n", (void *)btree_insert_sorted(&t, 10), 10);
  printf("insert sorted: %p, %d\n", (void *)btree_insert_sorted(&t, 5), 5);
  printf("insert sorted: %p, %d\n", (void *)btree_insert_sorted(&t, 15), 15);
  printf("insert sorted: %p, %d\n", (void *)btree_insert_sorted(&t, 16), 16);
  printf("insert sorted: %p, %d\n", (void *)btree_insert_sorted(&t, 13), 13);
  printf("insert sorted: %p, %d\n", (void *)btree_insert_sorted(&t, 15), 15);
  printf("insert sorted: %p, %d\n\n", (void *)btree_insert_sorted(&t, 4), 4);
  btree_preorder(t);

  printf("\nfound unsorted: %p, %d\n", (void *)btree_search(t, 10, false), 10);
  printf("found unsorted: %p, %d\n", (void *)btree_search(t, 5, false), 5);
  printf("found unsorted: %p, %d\n", (void *)btree_search(t, 13, false), 13);
  printf("found unsorted: %p, %d\n", (void *)btree_search(t, 15, false), 15);
  printf("found unsorted: %p, %d\n", (void *)btree_search(t, 16, false), 16);
  printf("found unsorted: %p, %d\n", (void *)btree_search(t, 4, false), 4);

  printf("not found unsorted: %p, %d\n\n", (void *)btree_search(t, 25, false),
         25);

  printf("found sorted: %p, %d\n", (void *)btree_search(t, 10, true), 10);
  printf("found sorted: %p, %d\n", (void *)btree_search(t, 13, true), 13);
  printf("found sorted: %p, %d\n", (void *)btree_search(t, 15, true), 15);
  printf("found sorted: %p, %d\n", (void *)btree_search(t, 16, true), 16);
  printf("found sorted: %p, %d\n", (void *)btree_search(t, 4, true), 4);

  printf("not found sorted: %p, %d\n", (void *)btree_search(t, 25, true), 25);

  btree_preorder(t);
  printf("count nodes: %d\n", btree_count_nodes(t));
  btree_destroy(&t);

  return 0;
}
