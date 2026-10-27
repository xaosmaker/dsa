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

void ll_reverse();
void ll_search();
void ll_max();
void ll_min();
void ll_sum();
void ll_insert();
void ll_insert_sorted();
void ll_pop_head();
void ll_pop_tail();
void ll_peek_head();
void ll_peek_tail();

#endif // !LINKED_LIST_H
