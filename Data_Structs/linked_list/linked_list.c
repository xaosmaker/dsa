#include "linked_list.h"
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
  struct ll_node *curr = ll->next;

  while (curr != ll) {
    count++;
    curr = curr->next;
  }
  return count;
}
