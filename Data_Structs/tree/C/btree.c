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
static int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
  // explicit is better
  // return a > b ? a : b;
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
    btree_postorder(root->right);
    printf("%d\n", root->val);
  }
}

struct btree *btree_search(struct btree *root, int val, bool sorted) {
  struct btree *found = NULL;
  if (!root) {
    return NULL;
  }
  if (val == root->val) {
    return root;
  }

  if (sorted) {
    if (val < root->val) {

      found = btree_search(root->left, val, sorted);
      if (found) {
        return found;
      }
    }

    found = btree_search(root->right, val, sorted);
    if (found) {
      return found;
    }

  } else {

    found = btree_search(root->left, val, sorted);
    if (found) {
      return found;
    }
    found = btree_search(root->right, val, sorted);
    if (found) {
      return found;
    }
  }

  return found;
}

int btree_count_nodes(struct btree *root) {
  if (!root) {
    return 0;
  }

  int nodes = 1;

  nodes += btree_count_nodes(root->left);
  nodes += btree_count_nodes(root->right);
  return nodes;
}

// TODO: need to study and understand exactly
int btree_count_height(struct btree *root) {
  int left = 0, right = 0;

  if (!root) {
    return -1;
  }

  left += btree_count_height(root->left) + 1;
  right += btree_count_height(root->right) + 1;

  return max(left, right);
  /*
   * is the same as the above but i have to unserstand the recursion well to go
   * return max(btree_count_height(root->left),
   * btree_count_height(root->right));
   */
}

int btree_count_leaf_nodes(struct btree *root) {
  int left = 0, right = 0;

  if (!root) {
    return 0;
  }

  if (!root->left && !root->right) {
    return 1;
  }

  left += btree_count_leaf_nodes(root->left);
  right += btree_count_leaf_nodes(root->right);

  return left + right;
}
int btree_count_non_leaf_nodes(struct btree *root) {

  int left = 0, right = 0;

  if (!root) {
    return 0;
  }

  if (root->left || root->right) {
    left++;
  }

  left += btree_count_non_leaf_nodes(root->left);
  right += btree_count_non_leaf_nodes(root->right);

  return left + right;
}

struct btree *btree_remove(struct btree *root, int val, bool sorted) {}
