#ifndef LINKED_LIST_RECURSIVE_H
#define LINKED_LIST_RECURSIVE_H
#include "linkedList.h"



void DisplayNodesRec(struct Node *nd);
int rCountNodes(struct Node *nd);
int rSumNodes(struct Node *nd);
int rMaxNode(struct Node *nd);
int rMinNode(struct Node *nd);
struct Node *rSearch(struct Node *nd, int key);
struct Node *irSearch(ll_t *ll, int key);
void reverseLLRec(ll_t *ll);

#endif // LINKED_LIST_RECURSIVE_H

