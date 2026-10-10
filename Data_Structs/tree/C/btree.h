#ifndef BTREE_H
#define BTREE_H

struct btree {
  int val;
  struct btree *left;
  struct btree *right;
};

/*
 * Inserts a value into the tree.
 *
 * Root can be any node in the tree.
 *
 * If the given root is NULL, the value is inserted as the root.
 * If the root is already occupied, the value is inserted according
 * to the tree's ordering rules.
 *
 * Duplicate values are not inserted. If val already exists in
 * the tree, the tree is left unchanged.
 *
 * Returns a pointer to the newly created node on successful insertion,
 * or NULL if the value already exists or memory allocation fails.
 * On failure, the existing tree remains unchanged and is not freed.
 */
struct btree *btree_insert(struct btree **root, int val);

/*
 * Inserts a value into the tree while preserving sorted order.
 *
 * The given root represents the subtree on which the operation is
 * performed. The function places the value according to the ordering
 * relation defined by the tree.
 *
 * Duplicate values are not inserted. If val already exists in
 * the tree, the tree is left unchanged.
 *
 * Returns a pointer to the newly created node on successful insertion,
 * or NULL if the value already exists or memory allocation fails.
 * On failure, the existing tree remains unchanged and is not freed.
 */

struct btree *btree_insert_sorted(struct btree **root, int val);
/*
 * Destroys the tree rooted at the given node.
 *
 * The given root represents the subtree on which the operation is
 * performed. All nodes in the subtree are freed recursively.
 *
 * If the given root is NULL, the function does nothing.
 *
 * After the tree is destroyed, the root is set to NULL.
 *
 * Returns true if the tree was destroyed, or false if the given
 * tree was already empty.
 */
bool btree_destroy(struct btree **root);
void btree_preorder(struct btree *root);
void btree_inorder(struct btree *root);
void btree_postorder(struct btree *root);
struct btree *btree_search(struct btree *root, int val, bool sorted);

bool btree_remove(struct btree *root, int val);
int btree_count_nodes(struct btree *root);
int btree_count_height(struct btree *root);
int btree_count_leaf_nodes(struct btree *root);
int btree_count_not_leaf_nodes(struct btree *root);

#endif // !BTREE_H
