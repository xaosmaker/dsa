#include "linkedList.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

ll_t *CreateLL() {
  ll_t *p = (ll_t *)malloc(sizeof(ll_t));
  if (!p) {
    printf("Fail to create linked list");
    exit(1);
  }
  p->head = NULL;
  p->len = 0;
  return p;
}

void AddNode(ll_t *ll, int n) {

  struct Node *p = (struct Node *)malloc(sizeof(struct Node));
  p->next = NULL;
  p->data = n;
  if (!ll->head) {
    ll->head = p;
    ll->len++;
  } else {

    struct Node *lastNode = ll->head;
    while (lastNode->next) {
      lastNode = lastNode->next;
    }
    lastNode->next = p;
    ll->len++;
  }
}

void DisplayNodes(ll_t *ll) {
  struct Node *nextNode = ll->head;
  while (nextNode) {
    printf("%d", nextNode->data);
    if (nextNode->next) {
      printf("->");
    } else {
      printf("\n");
    }
    nextNode = nextNode->next;
  }
}

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

void DeleteAllNodes(ll_t *ll) {
  struct Node *node = ll->head;
  struct Node *dnode = NULL;

  while (node) {
    dnode = node;
    node = node->next;
    free(dnode);
  }
  ll->head = NULL;
}

int CountNodes(ll_t *ll) {

  if (ll->head) {
    int count = 0;

    struct Node *head = ll->head;
    while (head) {
      count++;
      head = head->next;
    }
    return count;
  }

  return 0;
}

int SumNodes(ll_t *ll) {

  if (ll->head) {
    int count = 0;

    struct Node *head = ll->head;
    while (head) {
      count += head->data;
      head = head->next;
    }
    return count;
  }

  return 0;
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

int MaxNode(ll_t *ll) {
  int max = INT_MIN;

  struct Node *head = ll->head;

  while (head) {
    if (head->data > max) {
      max = head->data;
    }
    head = head->next;
  }
  return max;
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

int MinNode(ll_t *ll) {
  int min = INT_MAX;

  struct Node *head = ll->head;

  while (head) {
    if (head->data < min) {
      min = head->data;
    }
    head = head->next;
  }
  return min;
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
struct Node *Search(ll_t *ll, int key) {
  struct Node *head = ll->head;
  while (head) {
    if (head->data == key) {

      return head;
    }
    head = head->next;
  }
  return NULL;
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

struct Node *iSearch(ll_t *ll, int key) {

  struct Node *head = ll->head;
  struct Node *prevNode = NULL;

  while (head) {

    if (head->data == key) {
      if (prevNode) {
        prevNode->next = head->next;
        head->next = ll->head;
        ll->head = head;
      }
      return head;
    }

    prevNode = head;
    head = head->next;
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
static struct Node *createNode(ll_t *ll, int val) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (!node) {
    printf("error inserting node deleting everyhting");
    DeleteAllNodes(ll);
    free(ll);
    exit(1);
  }

  node->data = val;
  node->next = NULL;
  return node;
}

void insertNode(ll_t *ll, int index, int val) {
  struct Node *node = createNode(ll, val);

  if (index <= 0 || !ll->head) {
    node->next = ll->head;
    ll->head = node;
  } else {
    struct Node *nextNode = ll->head;
    for (int i = 1; i < index && nextNode->next; i++) {
      nextNode = nextNode->next;
    }
    node->next = nextNode->next;
    nextNode->next = node;
  }
}

void insertSorted(ll_t *ll, int val) {
  struct Node *node = createNode(ll, val);

  if (!ll->head) {
    ll->head = node;
    return;
  }
  if (ll->head->data > val) {
    node->next = ll->head;
    ll->head = node;
    return;
  }

  struct Node *currentNode = ll->head;
  struct Node *prevNode = ll->head;
  while (currentNode && currentNode->data < val) {
    prevNode = currentNode;
    currentNode = currentNode->next;
  }

  node->next = currentNode;
  prevNode->next = node;
}
