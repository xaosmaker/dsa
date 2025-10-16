#include "linkedList.h"
#include <limits.h>

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
