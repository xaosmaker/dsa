#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

static struct btree *btree_create_node(int val) {
  struct btree *t = (struct btree *)malloc(sizeof(struct btree));
  if (!t) {
    return NULL;
  }

  t->val = val;
  t->left = NULL;
  t->right = NULL;
  return t;
}

struct btree *btree_insert(struct btree **root, int val) {

  if (!(*root)) {

    struct btree *t = btree_create_node(val);

    if (!t) {
      return t;
    }

    *root = t;
    return *root;
  }
  return btree_insert_sorted(root, val);
}

struct btree *btree_insert_sorted(struct btree **root, int val) {

  if (!(*root)) {

    struct btree *t = btree_create_node(val);

    if (!t) {
      return NULL;
    }
    *root = t;
    return *root;
  }
  if (val < (*root)->val) {
    return btree_insert_sorted(&(*root)->left, val);
  } else if (val > (*root)->val) {
    return btree_insert_sorted(&(*root)->right, val);
  }

  return NULL;
}

bool btree_destroy(struct btree **root) {
  if (*root) {
    btree_destroy(&(*root)->left);
    btree_destroy(&(*root)->right);
    free(*root);
    *root = NULL;
    return 1;
  }
  return 0;
}

void btree_preorder(struct btree *root) {
  if (root) {

    printf("%d\n", root->val);
    btree_preorder(root->left);
    btree_preorder(root->right);
  }
}

void btree_inorder(struct btree *root) {
  if (root) {

    btree_inorder(root->left);
    printf("%d\n", root->val);
    btree_inorder(root->right);
  }
}

void btree_postorder(struct btree *root) {
  if (root) {

    btree_postorder(root->left);
    printf("%d\n", root->val);
    btree_postorder(root->right);
  }
}
