#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ll_node {
  int data;
  struct ll_node *next;
  struct ll_node *prev;
};

struct ll_node *ll_add_head(struct ll_node *ll, int data);
struct ll_node *ll_add_tail(struct ll_node *ll, int data);
struct ll_node *ll_destroy(struct ll_node *ll);
void ll_display(struct ll_node *ll);
int ll_count(struct ll_node *ll);
struct ll_node *ll_find(struct ll_node *ll, int data);
struct ll_node *ll_peek_head(struct ll_node *ll);
struct ll_node *ll_peek_tail(struct ll_node *ll);
struct ll_node *ll_insert(struct ll_node *ll, int data, int index);
struct ll_node *ll_pop_tail(struct ll_node *ll);

#endif // !LINKED_LIST_H
