#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ll_node {
  int data;
  struct ll_node *next;
  struct ll_node *prev;
};

typedef struct linked_list {
  struct ll_node *head;
  struct ll_node *tail;
  int size;
} LList;

// R is for recurcive;
void ll_display();
void ll_R_display();
void ll_R_reverse_display();
void ll_R_count();
void ll_reverse();
void ll_search();
void ll_R_search();
void ll_count();
void ll_max();
void ll_R_max();
void ll_min();
void ll_R_mn();
void ll_sum();
void ll_R_sum();
void ll_insert();
void ll_insert_sorted();
void ll_add_head();
void ll_add_tail();
void ll_pop_head();
void ll_pop_tail();
void ll_peek_head();
void ll_peek_tail();

#endif // !LINKED_LIST_H
