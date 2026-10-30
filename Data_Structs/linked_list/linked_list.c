#include "linked_list.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * node_addr, prev_addr, value, next_addr
 * 0x1,0x2,1,0x2 | | 0x2,0x1,2,0x1
 *
 *           add middle 0x3,0,3,0
 * 0x1,0x2,1,0x3 | 0x3,0x1,3,0x2 | 0x2,0x3,2,0x1
 *
 * */

struct ll_node *ll_add_head(struct ll_node *ll, int data) {
  struct ll_node *new_node = (struct ll_node *)malloc(sizeof(struct ll_node));
  if (!new_node) {
    return NULL;
  }
  new_node->data = data;

  if (!ll) {
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
  }

  // new node is the head
  // assign the next to the currect head;
  new_node->next = ll;
  // the previus of the new node should be the previous of the root;
  new_node->prev = ll->prev;
  // the previous of the previous head should be the current head
  ll->prev = new_node;
  // the next of ghe previous node of the previous head should be the current
  // node
  new_node->prev->next = new_node;
  return new_node;
}

/*
 * we pass the head or the linked list in arguments and return the tail pointer
 */
struct ll_node *ll_add_tail(struct ll_node *ll, int data) {
  return ll_add_head(ll, data);
}

struct ll_node *ll_destroy(struct ll_node *ll) {
  if (!ll) {
    return NULL;
  }
  struct ll_node *curr = ll, *tmp = NULL;

  do {
    tmp = curr;
    curr = curr->next;
    free(tmp);

  } while (curr != ll);

  return NULL;
}

void ll_display(struct ll_node *ll) {
  struct ll_node *node = ll;

  printf("[");
  do {
    printf("%d", node->data);
    node = node->next;
    if (node != ll) {
      printf(" -> ");
    }
  } while (node != ll);
  printf("]\n");
}

int ll_count(struct ll_node *ll) {
  int count = 0;

  if (!ll) {
    return 0;
  }
  // fun implementation
  // struct ll_node *curr = NULL;
  // for (curr = ll; curr != ll || count == 0; curr = curr->next, count++)
  //   ;

  struct ll_node *curr = ll;

  do {
    count++;
    curr = curr->next;

  } while (curr != ll);
  return count;
}

struct ll_node *ll_find(struct ll_node *ll, int data) {
  if (!ll) {
    return NULL;
  }
  struct ll_node *curr = ll;
  do {
    if (curr->data == data) {
      return curr;
    }
    curr = curr->next;

  } while (curr != ll);

  return NULL;
}

struct ll_node *ll_peek_head(struct ll_node *ll) {
  if (!ll) {
    return NULL;
  }
  return ll;
}
struct ll_node *ll_peek_tail(struct ll_node *ll) {

  if (!ll) {
    return NULL;
  }
  return ll->prev;
}

struct ll_node *ll_insert(struct ll_node *ll, int data, int index) {
  if (!ll || index == 0) {
    return ll_add_head(ll, data);
  }
  struct ll_node *curr = ll;
  for (int i = 0; i < index; i++) {
    curr = curr->next;
    if (curr == ll) {
      return NULL;
    }
  }
  return ll_add_head(curr, data);
}

struct ll_node *ll_pop_tail(struct ll_node *ll) {
  if (!ll) {
    return NULL;
  }
  struct ll_node *pop_data = ll->prev;
  ll->prev = pop_data->prev;
  ll->prev->next = ll;
  pop_data->next = pop_data;
  pop_data->prev = pop_data;

  return pop_data;
}
