
#include "btree.h"
#include <stdio.h>

int main(void)

{
  struct btree *t;

  printf("insert: %d\n", btree_insert(&t, 5)->val);
  btree_preorder(t);
  printf("insert: %d\n", btree_insert(&t->left, 15)->val);
  btree_preorder(t);
  printf("insert: %d\n", btree_insert(&t->right, 10)->val);
  btree_preorder(t);

  btree_destroy(&t);
  printf("empty tree\n");
  btree_preorder(t);
  printf("empty tree\n");

  printf("insert sorted: %p\n", btree_insert_sorted(&t, 10));
  printf("%p\n", t);
  printf("insert sorted: %p\n", btree_insert_sorted(&t, 5));
  printf("insert sorted: %p\n", btree_insert_sorted(&t, 15));
  printf("insert sorted: %p\n", btree_insert_sorted(&t, 16));
  printf("insert sorted: %p\n", btree_insert_sorted(&t, 13));
  printf("insert sorted: %p\n", btree_insert_sorted(&t, 15));
  printf("insert sorted: %p\n", btree_insert_sorted(&t, 4));
  btree_preorder(t);
  btree_destroy(&t);

  return 0;
}
