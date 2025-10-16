#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct LinkedList{
  struct Node *head;
  int len;
} ll_t;


ll_t *CreateLL();

void AddNode(ll_t *ll, int n);
void DisplayNodes(ll_t *ll);
void DeleteAllNodes(ll_t *ll);
void DisplayNodesRec(struct Node *nd);
int CountNodes(ll_t *ll);
int rCountNodes(struct Node *nd);
int SumNodes(ll_t *ll);
int rSumNodes(struct Node *nd);
int MaxNode(ll_t *ll);
int rMaxNode(struct Node *nd);
int MinNode(ll_t *ll);
int rMinNode(struct Node *nd);

#endif // !LinkedList_h
