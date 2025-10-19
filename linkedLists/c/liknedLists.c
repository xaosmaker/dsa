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
  if (ll->head->data >= val) {
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

void DeleteNode(ll_t *ll, int val) {
  if (!ll->head) {
    return;
  }
  struct Node *node = ll->head;
  struct Node *prevNode = ll->head;

  if (node->data == val) {
    // delete the first node
    ll->head = node->next;
    free(node);
    return;
  }
  while (node) {

    if (node->data == val) {
      prevNode->next = node->next;
      free(node);
      return;
    }
    prevNode = node;
    node = node->next;
  }
}

_Bool isSortedLL(ll_t *ll) {

  struct Node *node = ll->head;
  struct Node *pNode = NULL;

  while (node) {
    if (pNode && pNode->data > node->data) {

      return 0;
    }
    pNode = node;
    node = node->next;
  }
  return 1;
}

void DeleteDublicates(ll_t *ll) {

  struct Node *node = ll->head;
  struct Node *prevNode = NULL;

  while (node) {
    if (prevNode && prevNode->data == node->data) {
      prevNode->next = node->next;
      free(node);
      node = prevNode;
    }
    prevNode = node;
    node = node->next;
  }
}

void reverseLLSlidingPointers(ll_t *ll) {
  struct Node *node = ll->head;
  struct Node *prevNode = NULL;
  struct Node *pre = NULL;

  while (node) {
    pre = prevNode;
    prevNode = node;
    node = node->next;

    prevNode->next = pre;
  }
  ll->head = prevNode;
}

void AppendLL(ll_t *ll, ll_t *second) {

  struct Node *node = ll->head;
  while (node->next) {
    node = node->next;
  }
  node->next = second->head;
  second->head = NULL;
}

void MergeLL(ll_t *ll, ll_t *second) {
  // TODO:need implementation;
  /*
   * merget the second ll to the first;
   * first check the  first node and make the changes
   * second check the elements witch is lower from the prev so make the changes
   */
}
bool isLoop() {
  /*
   * check if a ll is a loop
   * to achive this we need 2 pointers and the one move by 2 and the other by
   * one if the pointer  meet it is loop else if we finish on null is not
   */
  return 0;
}
