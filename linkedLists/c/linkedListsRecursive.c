#include "linkedListsRecursive.h"
#include <limits.h>

void DisplayNodesRec(struct Node *nd) {

  if (nd) {
    printf("%d", nd->data);
    if (nd->next) {
      printf("->");
    } else {
      printf("\n");
    }
    DisplayNodesRec(nd->next);
  }
}

int rCountNodes(struct Node *nd) {
  if (nd) {

    return 1 + rCountNodes(nd->next);
  }
  return 0;
}

int rSumNodes(struct Node *nd) {
  if (nd) {
    return nd->data + rSumNodes(nd->next);
  }
  return 0;
}

int rMaxNode(struct Node *nd) {
  int max = INT_MIN;
  if (nd) {
    max = rMaxNode(nd->next);
    if (max < nd->data) {
      max = nd->data;
    }
  }
  return max;
}

int rMinNode(struct Node *nd) {
  int min = INT_MAX;
  if (nd) {
    min = rMinNode(nd->next);
    if (nd->data < min) {
      min = nd->data;
    }
  }
  return min;
}

struct Node *rSearch(struct Node *nd, int key) {

  if (nd) {
    if (nd->data == key) {
      return nd;
    }
    return rSearch(nd->next, key);
  }
  return NULL;
}

static struct Node *irSearchHelper(struct Node *nd, struct Node *prevNode,
                                   int key) {
  if (nd) {
    if (nd->data == key) {
      if (prevNode) {
        prevNode->next = nd->next;
      }
      return nd;
    }
    return irSearchHelper(nd->next, nd, key);
  }
  return NULL;
}

struct Node *irSearch(ll_t *ll, int key) {
  struct Node *node = NULL;

  node = irSearchHelper(ll->head, NULL, key);
  if (node && ll->head != node) {
    node->next = ll->head;
    ll->head = node;
  }
  return node;
}

static struct Node *reverseLLRecHelper(struct Node *node,
                                       struct Node *prevNode) {

  if (node) {
    struct Node *retNode = reverseLLRecHelper(node->next, node);
    node->next = prevNode;
    return retNode;
  }
  return prevNode;
}

void reverseLLRec(ll_t *ll) {
  //
  ll->head = reverseLLRecHelper(ll->head, NULL);
}
